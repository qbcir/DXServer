#ifndef __dx_JSONPARSER_H__
#define __dx_JSONPARSER_H__

#include "document.h"
#include "TypeTraits.h"

template<typename T, DX_ENABLE_IF_IS_CLASS(T)>
bool dx_json_check_type(const rapidjson::Value &el) {
    return el.IsObject();
}

template<typename T, DX_ENABLE_IF_IS_INT(T)>
bool dx_json_check_type(const rapidjson::Value &el) {
    return el.IsInt();
}

template<typename T, DX_ENABLE_IF_IS_FLOAT(T)>
bool dx_json_check_type(const rapidjson::Value &el) {
    return el.IsDouble() || el.IsInt();
}

template<typename T, DX_ENABLE_IF_IS_VEC(T)>
bool dx_json_check_type(const rapidjson::Value &el) {
    return el.IsArray();
}

template<typename T, DX_ENABLE_IF_IS_MAT(T)>
bool dx_json_check_type(const rapidjson::Value &el) {
    return el.IsArray();
}

template<>
inline bool dx_json_check_type<std::string>(const rapidjson::Value &el) {
    return el.IsString();
}

template<typename T> class StructP;
template<typename T>
DX_ENABLE_IF_IS_CLASS_TYPE(T) parseEl(const rapidjson::Value &el) {
    T v;
    StructP<T>::parse(&v, el);
    return v;
}

template<typename VecT>
DX_ENABLE_IF_IS_VEC_TYPE(VecT) parseEl(const rapidjson::Value &el) {
    typedef typename VecT::value_type T;
    VecT vs;
    auto end_it = el.End();
    for (auto it = el.Begin(); it != end_it; ++it) {
        auto v = parseEl<T>(*it);
        vs.emplace_back(v);
    }
    return vs;
}

template<typename MatT>
DX_ENABLE_IF_IS_MAT_TYPE(MatT) parseEl(const rapidjson::Value &el) {
    // FIXME
    return MatT();
}

template<>
inline std::string parseEl<std::string>(const rapidjson::Value& el) {
    return std::string(el.GetString());
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type parseEl(const rapidjson::Value &el) {
    return el.IsInt() ? static_cast<T>(el.GetInt()) : static_cast<T>(el.GetDouble());
}

template<typename T>
typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type parseEl(const rapidjson::Value &el) {
    return T(el.GetInt());
}

template<>
inline bool parseEl<bool>(const rapidjson::Value &el) {
    return el.GetBool();
}

template<typename T>
class FieldP_ {
public:
    FieldP_(bool required) :
        m_required(required)
    {}
    virtual ~FieldP_() {}
    virtual bool parse(T* obj, const rapidjson::Value& el) = 0;
    bool required() const { return m_required; }
protected:
    bool m_required = false;
};

template<typename T1,
         typename T2>
class FieldP : public FieldP_<T1> {
public:
  FieldP(T2 T1::*ptr) :
        FieldP_<T1>(false),
        m_ptr(ptr)
  {}
  FieldP(T2 T1::* ptr, bool required) :
      FieldP_<T1>(required),
      m_ptr(ptr)
  {}
  bool parse(T1* obj, const rapidjson::Value& el) {
      if (!dx_json_check_type<T2>(el)) {
          return false;
      }
      (obj->*(m_ptr)) = parseEl<T2>(el);
      return true;
  }
protected:
  T2 T1::* m_ptr = nullptr;
};

template <typename T1,
          typename T2>
class RefFieldP : FieldP_<T1> {
public:
  RefFieldP(T2 T1::*ptr) :
      FieldP_<T1>(false),
      m_ptr(ptr)
  {}
  RefFieldP(T2 T1::* ptr, bool required) :
      FieldP_<T1>(required),
      m_ptr(ptr)
  {}
  bool parse(T1* obj, const rapidjson::Value& el) {
      if (!dx_json_check_type<T2>(el)) {
          return false;
      }
      auto ptr = parseEl<T2>(el);
      auto prev = obj->*(m_ptr);
      if (prev) {
          CC_SAFE_RELEASE_NULL(prev);
      }
      (obj->*(m_ptr)) = ptr;
      return true;
  }
protected:
  T2 T1::* m_ptr = nullptr;
};

template<typename T>
class StructP {
    typedef std::unique_ptr<FieldP_<T>> FieldP_Ptr;
    typedef std::unordered_map<std::string, FieldP_Ptr> FieldP_MapT;
    static FieldP_MapT FieldP_Map;
public:
    template<typename T2>
    static bool addField(const std::string& key, T2 T::* ptr, bool required) {
        FieldP_Map.emplace(key, FieldP_Ptr(new FieldP<T, T2>(ptr, required)));
        return true;
    }
    template<typename T2>
    static bool addRefField(const std::string& key, T2 T::* ptr, bool required) {
        FieldP_Map.emplace(key, FieldP_Ptr(new RefFieldP<T, T2>(ptr, required)));
        return true;
    }
    static bool parse(T* obj, const rapidjson::Value& el) {
        if (!dx_json_check_type<T>(el)) {
            //cocos2d::log("Invalid object type: %u", el.GetType());
            return false;
        }
        auto fp_begin = std::begin(FieldP_Map);
        auto fp_end = std::end(FieldP_Map);
        auto member_end = el.MemberEnd();
        for (auto fp_it = fp_begin; fp_it != fp_end; ++fp_it) {
            auto key = fp_it->first.c_str();
            auto& fp = fp_it->second;
            auto member_it = el.FindMember(key);
            if (member_it != member_end) {
                if (!fp->parse(obj, member_it->value)) {
                    //cocos2d::log("Error parsing field %s", key);
                    return false;
                }
            } else if (fp->required()) {
                //cocos2d::log("Required field %s is missing", key);
                return false;
            }
        }
        return true;
    }
};

#define DX_DESC_GET_MEMBER(el, klass, member) \
    do { \
        using namespace std; \
        auto member##_it = el.FindMember(#member); \
        if (member##_it == el.MemberEnd()) { \
            return false; \
        } else { \
            m_##member = parseEl<klass>(member##_it->value); \
        } \
    } while (0)

#define DX_DESC_GET_OPT_MEMBER(el, klass, member) \
    do { \
        using namespace std; \
        auto member##_it = el.FindMember(#member); \
        if (member##_it != el.MemberEnd()) { \
            m_##member = parseEl<klass>(member##_it->value); \
        } \
    } while(0)

#define DX_DESC_GET_REF_MEMBER(el, klass, member) \
    do { \
        auto klass##_##member##_it = el.FindMember(#member); \
        if (klass##_##member##_it == el.MemberEnd()) { \
            return false; \
        } else { \
            m_##member = klass::fromJson(klass##_##member##_it->value); \
            if (!m_##member) { \
                return false; \
            } \
        } \
    } while(0)

#define DX_DESC_GET_OPT_REF_MEMBER(el, klass, member) \
    do { \
        auto klass##_##member##_it = el.FindMember(#member); \
        if (klass##_##member##_it != el.MemberEnd()) { \
            m_##member = klass::fromJson(klass##_##member##_it->value); \
            if (!m_##member) { \
                return false; \
            } \
        } \
    } while (0)

#define DX_DESC_GET_VEC(el, klass, member, vec) \
    do { \
        auto klass##_##vec##_it = el.FindMember(#member); \
        if (klass##_##vec##_it == el.MemberEnd()) { \
            return false; \
        } else { \
            if (!klass##_##vec##_it->value.IsArray()) { \
                return false; \
            } \
            auto klass##_end_it = klass##_##vec##_it->value.End(); \
            for (auto klass##_it = klass##_##vec##_it->value.Begin(); \
                 klass##_it != klass##_end_it; \
                 ++klass##_it) { \
                auto klass##_obj = klass::fromJson(*klass##_it); \
                if (!klass##_obj) { \
                    return false; \
                } \
                vec.push_back(klass##_obj); \
            } \
        } \
    } while (0)

#define DX_DESC_GET_OPT_VEC(el, klass, member, vec) \
    do { \
        auto klass##_##vec##_it = el.FindMember(#member); \
        if (klass##_##vec##_it != el.MemberEnd()) { \
            if (!klass##_##vec##_it->value.IsArray()) { \
                return false; \
            } \
            auto klass##_end_it = klass##_##vec##_it->value.End(); \
            for (auto klass##_it = klass##_##vec##_it->value.Begin(); \
                 klass##_it != klass##_end_it; \
                 ++klass##_it) { \
                auto klass##_obj = klass::fromJson(*klass##_it); \
                if (!klass##_obj) { \
                    return false; \
                } \
                vec.pushBack(klass##_obj); \
            } \
        } \
    } while (0)

#define DX_DESC_PROCESS_VEC(el, klass, member, P) \
    do { \
        auto klass##_##member##_it = el.FindMember(#member); \
            return false; \
        } else { \
            auto objMgr = ObjectManager::getInstance(); \
            auto klass##_end_it = klass##_##member##_it->value.End(); \
            for (auto klass##_it = klass##_##member##_it->value.Begin(); \
                 klass##_it != klass##_end_it; \
                 ++klass##_it) { \
                auto klass##_obj = klass::fromJson(*klass##_it); \
                if (!klass##_obj) { \
                    return false; \
                } \
                P() \
            } \
        } \
    } while (0)

#define DX_DESC_PROCESS_OPT_VEC(el, klass, member, P) \
    do { \
        auto klass##_##member##_it = el.FindMember(#member); \
        if (klass##_##member##_it != el.MemberEnd()) { \
            auto objMgr = ObjectManager::getInstance(); \
            auto klass##_end_it = klass##_##member##_it->value.End(); \
            for (auto klass##_it = klass##_##member##_it->value.Begin(); \
                 klass##_it != klass##_end_it; \
                 ++klass##_it) { \
                auto klass##_obj = klass::fromJson(*klass##_it); \
                if (!klass##_obj) { \
                    return false; \
                } \
                P() \
            } \
        } \
    } while (0)

#endif /* __dx_JSONPARSER_H__ */
