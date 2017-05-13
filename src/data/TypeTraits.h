#ifndef __dx_TYPETRAITS_H__
#define __dx_TYPETRAITS_H__

#include <vector>
#include <unordered_map>
#include <memory>
#include <cmath>
#include <limits>
#include <functional>
#include <type_traits>
#include "Dense"

template<typename T>
struct dx_is_eigen_matrix {
    static const bool value = false;
};

template<typename Scalar, int R, int C, int Opts, int MaxR, int MaxC>
struct dx_is_eigen_matrix<Eigen::Matrix<Scalar,R,C,Opts,MaxR,MaxC>> {
    static const bool value = true;
};

template<typename T>
struct dx_eigen_matrix_traits {};

template<typename Scalar, int R, int C, int Opts, int MaxR, int MaxC>
struct dx_eigen_matrix_traits<Eigen::Matrix<Scalar,R,C,Opts,MaxR,MaxC>> {
    typedef Scalar value_type;
    static const int rows = R;
    static const int columns = C;
};


template<typename T>
struct dx_is_ref {
    static const bool value = false;
};

template<typename T>
struct dx_is_ref<std::shared_ptr<T>> {
    static const bool value = true;
};

template<typename T>
struct dx_is_vec {
    static const bool value = false;
};

template<typename T>
struct dx_is_vec<std::vector<T>> {
    static const bool value = true;
};

template<typename T>
struct dx_is_func {
    static const bool value = false;
};

template<typename R, typename ...Args>
struct dx_is_func<std::function<R(Args...)>> {
    static const bool value = true;
};

template<typename T>
struct dx_is_class {
    static const bool value = std::is_class<T>::value
            && !dx_is_ref<T>::value
            && !dx_is_func<T>::value
            && !dx_is_vec<T>::value
            && !dx_is_eigen_matrix<T>::value;
};

#define DX_ENABLE_IF_IS_FUNC_TYPE(T) \
    typename std::enable_if<dx_is_func<T>::value, T>::type
#define DX_ENABLE_IF_IS_LUA_ENABLED_SHARED_PTR_TYPE(T) \
    typename std::enable_if<dx_is_ref<T>::value, T>::type
#define DX_ENABLE_IF_IS_CLASS_TYPE(T) \
    typename std::enable_if<dx_is_class<T>::value, T>::type
#define DX_ENABLE_IF_IS_PTR_TYPE(T) \
    typename std::enable_if<std::is_pointer<T>::value, T>::type
#define DX_ENABLE_IF_IS_INT_TYPE(T) \
    typename std::enable_if<std::is_integral<T>::value && !std::is_enum<T>::value, T>::type
#define DX_ENABLE_IF_IS_ENUM_TYPE(T) \
    typename std::enable_if<std::is_enum<T>::value, T>::type
#define DX_ENABLE_IF_IS_UINT_TYPE(T) \
    typename std::enable_if<std::is_integral<T>::value && std::is_unsigned<T>::value, T>::type
#define DX_ENABLE_IF_IS_SINT_TYPE(T) \
    typename std::enable_if<std::is_integral<T>::value && std::is_signed<T>::value, T>::type
#define DX_ENABLE_IF_IS_FLOAT_TYPE(T) \
    typename std::enable_if<std::is_floating_point<T>::value ,T>::type
#define DX_ENABLE_IF_IS_VEC_TYPE(T) \
    typename std::enable_if<dx_is_vec<T>::value, T>::type
#define DX_ENABLE_IF_IS_MAT_TYPE(T) \
    typename std::enable_if<dx_is_eigen_matrix<T>::value, T>::type
#define DX_ENABLE_IF_IS_FUNC(T) \
    DX_ENABLE_IF_IS_FUNC_TYPE(T)* = nullptr
#define DX_ENABLE_IF_IS_LUA_ENABLED_SHARED_PTR(T) \
    DX_ENABLE_IF_IS_LUA_ENABLED_SHARED_PTR_TYPE(T)* = nullptr
#define DX_ENABLE_IF_IS_CLASS(T) \
    DX_ENABLE_IF_IS_CLASS_TYPE(T)* = nullptr
#define DX_ENABLE_IF_IS_PTR(T) \
    DX_ENABLE_IF_IS_PTR_TYPE(T)* = nullptr
#define DX_ENABLE_IF_IS_FLOAT(T) \
    DX_ENABLE_IF_IS_FLOAT_TYPE(T)* = nullptr
#define DX_ENABLE_IF_IS_INT(T) \
    DX_ENABLE_IF_IS_INT_TYPE(T)* = nullptr
#define DX_ENABLE_IF_IS_ENUM(T) \
    DX_ENABLE_IF_IS_ENUM_TYPE(T)* = nullptr
#define DX_ENABLE_IF_IS_SINT(T) \
    DX_ENABLE_IF_IS_SINT_TYPE(T)* = nullptr
#define DX_ENABLE_IF_IS_UINT(T) \
    DX_ENABLE_IF_IS_UINT_TYPE(T)* = nullptr
#define DX_ENABLE_IF_IS_VEC(T) \
    DX_ENABLE_IF_IS_VEC_TYPE(T)* = nullptr
#define DX_ENABLE_IF_IS_MAT(T) \
    DX_ENABLE_IF_IS_MAT_TYPE(T)* = nullptr


#endif /* __dx_TYPETRAITS_H__ */
