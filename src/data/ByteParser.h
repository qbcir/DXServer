#ifndef __dx_BYTEPARSER_H__
#define __dx_BYTEPARSER_H__

#include "TypeTraits.h"
#include <memory>
#include <iostream>


typedef std::vector<uint8_t> BytesT;

template<typename T> class StructBP;
//
template<typename T, DX_ENABLE_IF_IS_CLASS(T)>
size_t dx_write_bytes(BytesT& buf, const T& v) {
    return StructBP<T>::write(buf, &v);
}
//
template<typename P, DX_ENABLE_IF_IS_LUA_ENABLED_SHARED_PTR_TYPE(P)>
size_t dx_write_bytes(BytesT& buf, const P& v) {
    typedef typename P::element_type T;
    return dx_write_bytes<T>(buf, *v.get());
}
//
template<typename T, DX_ENABLE_IF_IS_INT(T)>
size_t dx_write_bytes(BytesT& buf, const T& v) {
    uint8_t size = v < 0 ? 0x80 : 0;
    size_t size_idx = buf.size();
    T v_ = v < 0 ? -v : v;
    buf.emplace_back(0);
    for (uint8_t i = 0; i < sizeof(T); ++i) {
        const uint8_t byte = v_ & 0xFF;
        buf.emplace_back(byte);
        v_ >>= 8;
        if (v_ == 0) {
            ++i; size |= i;
            break;
        }
    }
    buf.at(size_idx) = size;
    return sizeof(T) + 1;
}
//
template<typename E, DX_ENABLE_IF_IS_ENUM(E)>
size_t dx_write_bytes(BytesT& buf, const E& v) {
    typedef typename std::underlying_type<E>::type T;
    return dx_write_bytes<T>(buf, static_cast<T>(v));
}
//
template<typename T, DX_ENABLE_IF_IS_FLOAT(T)>
size_t dx_write_bytes(BytesT& buf, const T& v) {
    int64_t mantissa = 0;
    int16_t exponent;
    const int digits = std::max(std::numeric_limits<T>::digits, 63);
    if (v == std::numeric_limits<T>::infinity()) {
        exponent = 32000;
    } else if (v == -std::numeric_limits<T>::infinity()) {
        exponent = 32001;
    } else if (v < std::numeric_limits<T>::infinity()) {
        int exp;
        mantissa = static_cast<int64_t>(std::frexp(v, &exp)*((uint64_t)1<<digits));
        exponent = exp - digits;
        // Compact the representation a bit by shifting off any low order bytes
        // which are zero in the mantissa.  This makes the numbers in mantissa and
        // exponent generally smaller which can make serialization and other things
        // more efficient in some cases.
        for (int i = 0; i < 8 && ((mantissa & 0xFF) == 0); ++i) {
            mantissa >>= 8;
            exponent += 8;
        }
    } else {
        exponent = 32002;
    }
    size_t nb = 0;
    nb += dx_write_bytes<int64_t>(buf, mantissa);
    nb += dx_write_bytes<int16_t>(buf, exponent);
    return nb;
}
//
template<typename MatT, DX_ENABLE_IF_IS_MAT(MatT)>
size_t dx_write_bytes(BytesT &buf, const MatT &v) {
    typedef dx_eigen_matrix_traits<MatT> TraitsT;
    typedef typename TraitsT::value_type T;
    for (int i = 0; i < TraitsT::rows; ++i) {
        for (int j = 0; j < TraitsT::columns; ++j) {
            dx_write_bytes<T>(buf, v(i, j));
        }
    }
}
//
template<typename VecT, DX_ENABLE_IF_IS_VEC(VecT)>
size_t dx_write_bytes(BytesT &buf, const VecT &vs) {
    typedef typename VecT::value_type T;
    size_t nb = 0;
    nb += dx_write_bytes<size_t>(buf, vs.size());
    for (size_t i = 0; i < vs.size(); ++i) {
        nb += dx_write_bytes<T>(buf, vs[i]);
    }
    return nb;
}
//
template<>
inline size_t dx_write_bytes<std::string>(BytesT &buf, const std::string& s) {
    size_t nb = 0;
    size_t len = s.size();
    nb += dx_write_bytes<size_t>(buf, len);
    for (size_t i = 0; i < len; ++i) {
        nb += dx_write_bytes<char>(buf, s[i]);
    }
    return nb;
}
/*
 *
 */
//
template<typename T>
DX_ENABLE_IF_IS_CLASS_TYPE(T) dx_read_bytes(uint8_t* &p) {
    T v;
    StructBP<T>::read(&v, p);
    return v;
}
//
template<typename T>
DX_ENABLE_IF_IS_INT_TYPE(T) dx_read_bytes(uint8_t* &p) {
    T v = 0;
    auto size = *p; ++p;
    bool is_neg = size & 0x80;
    size &= 0xF;
    for (size_t i = 0; i < size; ++i, ++p) {
        v |= ((*p) << (i * 8));
    }
    if (is_neg) v = -v;
    return v;
}
//
template<typename E>
DX_ENABLE_IF_IS_ENUM_TYPE(E) dx_read_bytes(uint8_t* &p) {
    typedef typename std::underlying_type<E>::type T;
    auto v = dx_read_bytes<T>(p);
    return static_cast<E>(v);
}
//
template<typename T>
DX_ENABLE_IF_IS_FLOAT_TYPE(T) dx_read_bytes(uint8_t* &p) {
    auto mantissa = dx_read_bytes<int64_t>(p);
    auto exponent = dx_read_bytes<int16_t>(p);
    if (exponent < 32000) {
        return std::ldexp((T)mantissa, exponent);
    } else if (exponent == 32000) {
        return std::numeric_limits<T>::infinity();
    } else if (exponent == 32001) {
        return -std::numeric_limits<T>::infinity();
    } else {
        return std::numeric_limits<T>::quiet_NaN();
    }
}
//
template<typename MatT>
DX_ENABLE_IF_IS_MAT_TYPE(MatT) dx_read_bytes(uint8_t* &p) {
    MatT mat;
    typedef dx_eigen_matrix_traits<MatT> TraitsT;
    typedef typename TraitsT::value_type T;
    for (int i = 0; i < TraitsT::rows; ++i) {
        for (int j = 0; j < TraitsT::columns; ++j) {
            mat(i, j) = dx_read_bytes<T>(p);
        }
    }
    return mat;
}
//
template<typename VecT>
DX_ENABLE_IF_IS_VEC_TYPE(VecT) dx_read_bytes(uint8_t* &p) {
    typedef typename VecT::value_type T;
    VecT vs;
    size_t size = dx_read_bytes<size_t>(p);
    for (size_t i = 0; i < size; ++i) {
        auto el = dx_read_bytes<T>(p);
        vs.emplace_back(el);
    }
    return vs;
}
//
template<>
inline std::string dx_read_bytes<std::string>(uint8_t* &p) {
    auto chs = dx_read_bytes<std::vector<char>>(p);
    return std::string(chs.data(), chs.size());
}
//
template<typename T>
class FieldBP_ {
public:
    virtual ~FieldBP_() {}
    virtual size_t write(BytesT& buf, const T* obj) = 0;
    virtual void read(T* obj, uint8_t* &p) = 0;
};
//
template<typename T1,
         typename T2>
class FieldBP : public FieldBP_<T1> {
public:
  FieldBP(T2 T1::*ptr) :
        m_ptr(ptr)
  {}
  size_t write(BytesT& buf, const T1* obj) {
      return dx_write_bytes<T2>(buf, obj->*(m_ptr));
  }
  void read(T1* obj, uint8_t* &p) {
      (obj->*(m_ptr)) = dx_read_bytes<T2>(p);
  }
protected:
  T2 T1::* m_ptr = nullptr;
};
//
template<typename T>
class StructBP {
    typedef std::unique_ptr<FieldBP_<T>> FieldBP_Ptr;
    typedef std::vector<FieldBP_Ptr> FieldP_VecT;
    static FieldP_VecT FieldP_Vec;
public:
    template<typename T2>
    static bool addField(T2 T::* ptr) {
        FieldP_Vec.emplace_back(FieldBP_Ptr(new FieldBP<T, T2>(ptr)));
        return true;
    }
    static size_t write(BytesT& buf, const T* obj) {
        size_t nb = 0;
        auto fp_begin = std::begin(FieldP_Vec);
        auto fp_end = std::end(FieldP_Vec);
        for (auto fp_it = fp_begin; fp_it != fp_end; ++fp_it) {
            nb += (*fp_it)->write(buf, obj);
        }
        return nb;
    }
    static void read(T* obj, uint8_t* &p) {
        auto fp_begin = std::begin(FieldP_Vec);
        auto fp_end = std::end(FieldP_Vec);
        for (auto fp_it = fp_begin; fp_it != fp_end; ++fp_it) {
            (*fp_it)->read(obj, p);
        }
    }
};

#endif /* __dx_BYTEPARSER_H__ */
