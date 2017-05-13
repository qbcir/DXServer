#ifndef __DX_LUAPARSER_H__
#define __DX_LUAPARSER_H__

extern "C" {
#include "lua.h"
}
#include "TypeTraits.h"
#include "tolua++.h"
#include "../scripting/tolua_fix.h"
#include "../scripting/LuaState.h"
#include "../scripting/LuaRef.h"
#include <cxxabi.h>
#include <iostream>

template<typename P, DX_ENABLE_IF_IS_LUA_ENABLED_SHARED_PTR(P)>
bool dx_lua_check_type(lua_State *L, int idx) {
    typedef typename P::element_type T;
    tolua_Error err;
    int status = -4;
    char *type_name = abi::__cxa_demangle(typeid(T).name(), 0, 0, &status);
    bool res = tolua_isusertype(L, idx, type_name, 0, &err);
    free(type_name);
    return res;
}

template<typename P, DX_ENABLE_IF_IS_PTR(P)>
bool dx_lua_check_type(lua_State *L, int idx) {
    tolua_Error err;
    return tolua_isusertype(L, idx, typeid(P).name(), 0, &err);
}

template<typename T, DX_ENABLE_IF_IS_CLASS(T)>
bool dx_lua_check_type(lua_State *L, int idx) {
    return lua_istable(L, idx);
}

template<typename T, DX_ENABLE_IF_IS_INT(T)>
bool dx_lua_check_type(lua_State *L, int idx) {
    return lua_isnumber(L, idx);
}

template<typename T, DX_ENABLE_IF_IS_FLOAT(T)>
bool dx_lua_check_type(lua_State *L, int idx) {
    return lua_isnumber(L, idx);
}

template<typename T, DX_ENABLE_IF_IS_ENUM(T)>
bool dx_lua_check_type(lua_State *L, int idx) {
    return lua_isnumber(L, idx);
}

template<typename T, DX_ENABLE_IF_IS_VEC(T)>
bool dx_lua_check_type(lua_State *L, int idx) {
    return lua_istable(L, idx);
}

template<typename T, DX_ENABLE_IF_IS_FUNC(T)>
bool dx_lua_check_type(lua_State *L, int idx) {
    return lua_isfunction(L, idx);
}

template<typename T, DX_ENABLE_IF_IS_MAT(T)>
bool dx_lua_check_type(lua_State *L, int idx) {
    return lua_istable(L, idx);
}

template<>
inline bool dx_lua_check_type<std::string>(lua_State *L, int idx) {
    return lua_isstring(L, idx);
}

/*
 * template<typename T> T dx_lua_parse(lua_State *L, int idx);
 */

template<typename T> class StructLP;
template<typename T>
DX_ENABLE_IF_IS_CLASS_TYPE(T) dx_lua_parse(lua_State *L, int idx) {
    T v;
    StructLP<T>::parse(&v, L, idx);
    return v;
}

template<typename VecT>
DX_ENABLE_IF_IS_VEC_TYPE(VecT) dx_lua_parse(lua_State *L, int idx) {
    typedef typename VecT::value_type T;
    VecT vs;
    int N = lua_objlen(L, idx);
    for (int n = 1; n <= N; n++) {
        lua_pushinteger(L, n);
        lua_gettable(L, (idx < 0 ? idx - 1 : idx));
        auto v = dx_lua_parse<T>(L, -1);
        vs.emplace_back(v);
        lua_pop(L, 1);
    }
    return vs;
}

template<typename T>
DX_ENABLE_IF_IS_FLOAT_TYPE(T) dx_lua_parse(lua_State *L, int idx) {
    return T(lua_tonumber(L, idx));
}

template<typename T>
DX_ENABLE_IF_IS_ENUM_TYPE(T) dx_lua_parse(lua_State *L, int idx) {
    return static_cast<T>(lua_tointeger(L, idx));
}

template<typename T>
DX_ENABLE_IF_IS_INT_TYPE(T) dx_lua_parse(lua_State *L, int idx) {
    return T(lua_tointeger(L, idx));
}

template<typename MatT>
DX_ENABLE_IF_IS_MAT_TYPE(MatT) dx_lua_parse(lua_State *L, int idx) {
    typedef dx_eigen_matrix_traits<MatT> TraitsT;
    typedef typename TraitsT::value_type T;
    MatT m;
    for (int i = 1; i <= TraitsT::rows; ++i) {
        lua_pushinteger(L, i);
        lua_gettable(L, (idx < 0 ? idx - 1 : idx));
        for (int j = 1; j <= TraitsT::rows; ++j) {
            lua_pushinteger(L, i);
            lua_gettable(L, -2);
            m(i, j) = dx_lua_parse<T>(L, -1);
            lua_pop(L, 1);
        }
        lua_pop(L, 1);
    }
    return m;
}

template<>
inline Eigen::Vector2f dx_lua_parse<Eigen::Vector2f>(lua_State *L, int idx) {
    Eigen::Vector2f v;
    lua_gettable(L, (idx < 0 ? idx - 1 : idx));
    lua_pushstring(L, "x");
    lua_gettable(L, -2);
    v[0] = dx_lua_parse<float>(L, -1);
    lua_pop(L, 1);
    lua_pushstring(L, "y");
    lua_gettable(L, -2);
    v[1] = dx_lua_parse<float>(L, -1);
    lua_pop(L, 2);
    return v;
}

template<typename P>
DX_ENABLE_IF_IS_LUA_ENABLED_SHARED_PTR_TYPE(P) dx_lua_parse(lua_State *L, int idx) {
    typedef typename P::element_type T;
    P* ptr = static_cast<P*>(tolua_tousertype(L, idx, 0));
    return P(*ptr);
}

template<>
inline std::string dx_lua_parse<std::string>(lua_State *L, int idx) {
    return std::string(lua_tostring(L, idx));
}

template<>
inline bool dx_lua_parse<bool>(lua_State *L, int idx) {
    return lua_toboolean(L, idx);
}

template<typename T, DX_ENABLE_IF_IS_CLASS(T)>
void dx_lua_push(lua_State* L, const T &v) {
    StructLP<T>::push(&v, L);
}

template<typename T,
         typename std::enable_if<std::is_enum<T>::value, T>::type Unused = T()>
void dx_lua_push(lua_State* L, const T& v) {
    lua_pushinteger(L, static_cast<int>(v));
}

template<typename T, DX_ENABLE_IF_IS_INT(T)>
void dx_lua_push(lua_State* L, const T& v) {
    lua_pushinteger(L, v);
}

template<typename T, DX_ENABLE_IF_IS_FLOAT(T)>
void dx_lua_push(lua_State* L, const T& v) {
    lua_pushnumber(L, v);
}

template<typename MatT, DX_ENABLE_IF_IS_MAT(MatT)>
void dx_lua_push(lua_State* L, const MatT &m) {
    typedef dx_eigen_matrix_traits<MatT> TraitsT;
    typedef typename TraitsT::value_type T;
    lua_newtable(L);
    for (int i = 1; i <= TraitsT::rows; ++i) {
        lua_pushnumber(L, lua_Number(i));
        lua_newtable(L);
        for (int j = 1; j <= TraitsT::columns; ++j) {
            lua_pushnumber(L, lua_Number(j));
            lua_pushnumber(L, lua_Number(m(i, j)));
            lua_rawset(L, -3);
        }
        lua_rawset(L, -3);
    }
}

template<typename VecT, DX_ENABLE_IF_IS_VEC(VecT)>
void dx_lua_push(lua_State* L, const VecT &vs) {
    typedef typename VecT::value_type T;
    lua_newtable(L);
    int idx = 1;
    for (auto& v : vs) {
        lua_pushnumber(L, (lua_Number)idx);
        dx_lua_push<int>(L, idx);
        dx_lua_push<T>(L, v);
        lua_rawset(L, -3);
        ++idx;
    }
}

template<typename P, DX_ENABLE_IF_IS_PTR(P)>
void dx_lua_push(lua_State *L, const P &v) {
    int status = -4;
    char *type_name = abi::__cxa_demangle(typeid(*v).name(), 0, 0, &status);
    tolua_pushusertype(L, (void*)v, type_name);
    free(type_name);
}

template<typename P, DX_ENABLE_IF_IS_LUA_ENABLED_SHARED_PTR(P)>
void dx_lua_push(lua_State *L, const P &v) {
    typedef typename P::element_type T;
    int status = -4;
    char *type_name = abi::__cxa_demangle(typeid(T).name(), 0, 0, &status);
    P* udptr = (P*)lua_newuserdata(L, sizeof(P));
    P* ptr = new (udptr) P(v);
    tolua_pushusertype(L, (void*)ptr, type_name);
    tolua_register_gc(L , lua_gettop(L));
    lua_remove(L, -2);
    free(type_name);
}

template<>
inline void dx_lua_push(lua_State *L, const bool &v) {
    lua_pushboolean(L, v);
}

template<>
inline void dx_lua_push(lua_State* L, const std::string& v) {
    lua_pushstring(L, v.c_str());
}

template<>
inline void dx_lua_push(lua_State* L, const Eigen::Vector2f& v) {
    lua_newtable(L);
    lua_pushstring(L, "x");
    lua_pushnumber(L, lua_Number(v[0]));
    lua_rawset(L, -3);
    lua_pushstring(L, "y");
    lua_pushnumber(L, lua_Number(v[1]));
    lua_rawset(L, -3);
}

template<typename R>
inline R dx_call_lua_function_by_handler(
        lua_State *L, int handler, int nargs) {
    toluafix_get_function_by_refid(L, handler);
    if (nargs > 0) {
        lua_insert(L, -(nargs + 1));
    }
    int traceback = 0;
    lua_getglobal(L, "__G__TRACKBACK__");
    if (!lua_isfunction(L, -1)) {
        lua_pop(L, 1);                        /* L: ... func arg1 arg2 ... */
    } else {
        lua_insert(L, -(nargs + 2));          /* L: ... G func arg1 arg2 ... */
        traceback = -(nargs + 2);
    }
    int error = lua_pcall(L, nargs, 1, traceback); /* L: ... [G] ret */
    if (error) {
        if (traceback == 0) {                      /* L: ... error */
            // Error
            lua_pop(L, 1);
        } else {                                   /* L: ... G error */
            lua_pop(L, 2);
        }
    }
    R res = dx_lua_parse<R>(L, -1);
    lua_pop(L, 1);
    if (traceback) {
        lua_pop(L, 1);
    }
    return res;
}

template<>
inline void dx_call_lua_function_by_handler<void>(
        lua_State *L, int handler, int nargs) {
    toluafix_get_function_by_refid(L, handler);
    if (nargs > 0) {
        lua_insert(L, -(nargs + 1));
    }
    int traceback = 0;
    lua_getglobal(L, "__G__TRACKBACK__");
    if (!lua_isfunction(L, -1)) {
        lua_pop(L, 1);                        /* L: ... func arg1 arg2 ... */
    } else {
        lua_insert(L, -(nargs + 2));          /* L: ... G func arg1 arg2 ... */
        traceback = -(nargs + 2);
    }
    int error = lua_pcall(L, nargs, 1, traceback); /* L: ... [G] ret */
    if (error) {
        if (traceback == 0) {                      /* L: ... error */
            // Error
            lua_pop(L, 1);
        } else {                                   /* L: ... G error */
            lua_pop(L, 2);
        }
    }
    lua_pop(L, 1);
    if (traceback) {
        lua_pop(L, 1);
    }
}

template<typename R, typename Head, typename ...Tail>
inline R dx_call_lua_function_by_handler(
        lua_State *L, int handler, int nargs, Head arg, Tail... args) {
    dx_lua_push<Head>(L, arg);
    return dx_call_lua_function_by_handler<R, Tail...>(L, handler, nargs + 1, args...);
}

template<typename T> struct dx_lua_func_wrapper;
template<typename R, typename ...Args>
struct dx_lua_func_wrapper<std::function<R(Args...)>> : public std::function<R(Args...)> {
    typedef std::function<R(Args...)> func_t;
    dx_lua_func_wrapper(int handler) : func_t([=](Args... args) -> R {
            auto L = LuaState::get();
            return dx_call_lua_function_by_handler<R, Args...>(L, handler, 0, args...);
    }) {}
};

template<typename T>
DX_ENABLE_IF_IS_FUNC_TYPE(T) dx_lua_parse(lua_State *L, int idx) {
    int fidx = (idx < 0 ? lua_gettop(L) + idx + 1 : idx);
    int handler = toluafix_ref_function(L,fidx,0);
    return dx_lua_func_wrapper<T>(handler);
}

template<typename T>
class FieldLP_ {
public:
    FieldLP_(bool required) :
        m_required(required)
    {}
    virtual ~FieldLP_() {}
    virtual void push(const T* obj, lua_State *L) = 0;
    virtual bool parse(T* obj, lua_State *L, int idx) = 0;
    bool required() const { return m_required; }
protected:
    bool m_required = false;
};

template<typename T1,
         typename T2>
class FieldLP : public FieldLP_<T1> {
public:
  FieldLP(T2 T1::*ptr) :
        FieldLP_<T1>(false),
        m_ptr(ptr)
  {}
  FieldLP(T2 T1::* ptr, bool required) :
      FieldLP_<T1>(required),
      m_ptr(ptr)
  {}
  void push(const T1* obj, lua_State *L) {
      dx_lua_push<T2>(L, (obj->*(m_ptr)));
  }
  bool parse(T1* obj, lua_State *L, int idx) {
      if (!dx_lua_check_type<T2>(L, idx)) {
          return false;
      }
      (obj->*(m_ptr)) = dx_lua_parse<T2>(L, idx);
      return true;
  }
protected:
  T2 T1::* m_ptr = nullptr;
};

template <typename T1,
          typename T2>
class RefFieldLP : FieldLP_<T1> {
public:
  RefFieldLP(T2 T1::*ptr) :
      FieldLP_<T1>(false),
      m_ptr(ptr)
  {}
  RefFieldLP(T2 T1::* ptr, bool required) :
      FieldLP_<T1>(required),
      m_ptr(ptr)
  {}
  bool parse(T1* obj, lua_State *L, int idx) {
      if (!dx_lua_check_type<T2>(L, idx)) {
          return false;
      }
      auto ptr = dx_lua_parse<T2>(L, idx);
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
class StructLP {
    typedef std::unique_ptr<FieldLP_<T>> FieldLP_Ptr;
    typedef std::unordered_map<std::string, FieldLP_Ptr> FieldP_MapT;
    static FieldP_MapT FieldP_Map;
public:
    template<typename T2>
    static bool addField(const std::string& key, T2 T::* ptr, bool required) {
        FieldP_Map.emplace(key, FieldLP_Ptr(new FieldLP<T, T2>(ptr, required)));
        return true;
    }
    template<typename T2>
    static bool addRefField(const std::string& key, T2 T::* ptr, bool required) {
        FieldP_Map.emplace(key, FieldLP_Ptr(new RefFieldLP<T, T2>(ptr, required)));
        return true;
    }
    static void push(const T* obj, lua_State *L) {
        lua_newtable(L);
        auto fp_begin = std::begin(FieldP_Map);
        auto fp_end = std::end(FieldP_Map);
        for (auto fp_it = fp_begin; fp_it != fp_end; ++fp_it) {
            auto key = fp_it->first.c_str();
            auto& fp = fp_it->second;
            lua_pushstring(L, key);
            fp->push(obj, L);
            lua_rawset(L, -3);
        }
    }
    static bool parse(T* obj, lua_State *L, int idx) {
        if (!dx_lua_check_type<T>(L, idx)) {
            return false;
        }
        auto fp_begin = std::begin(FieldP_Map);
        auto fp_end = std::end(FieldP_Map);
        for (auto fp_it = fp_begin; fp_it != fp_end; ++fp_it) {
            auto key = fp_it->first.c_str();
            auto& fp = fp_it->second;
            lua_pushstring(L, key);
            lua_gettable(L, (idx < 0 ? idx - 1 : idx));
            if (!lua_isnil(L, -1)) {
                if (!fp->parse(obj, L, -1)) {
                    lua_pop(L, 1);
                    return false;
                }
            } else if (fp->required()) {
                lua_pop(L, 1);
                return false;
            }
            lua_pop(L, 1);
        }
        return true;
    }
};

#define DX_LUA_DESC_GET_MEMBER(L, idx, klass, member) \
    do { \
        using namespace std; \
        lua_pushstring(L, #member); \
        lua_gettable(L, (idx < 0 ? idx - 1 : idx)); \
        if (lua_isnil(L, -1)) { \
            lua_pop(L, 1); \
            return false; \
        } else { \
            m_##member = dx_lua_parse<klass>(L, -1); \
            lua_pop(L, 1); \
        } \
    } while (0)

#define DX_LUA_DESC_GET_OPT_MEMBER(L, idx, klass, member) \
    do { \
        using namespace std; \
        lua_pushstring(L, #member); \
        lua_gettable(L, (idx < 0 ? idx - 1 : idx)); \
        if (!lua_isnil(L, -1)) { \
            m_##member = dx_lua_parse<klass>(L, -1); \
        } \
        lua_pop(L, 1); \
    } while(0)

#define DX_LUA_DESC_GET_REF_MEMBER(L, idx, klass, member) \
    do { \
        lua_pushstring(L, #member); \
        lua_gettable(L, (idx < 0 ? idx - 1 : idx)); \
        if (lua_isnil(L, -1)) { \
            lua_pop(L, 1); \
            return false; \
        } else { \
            m_##member = klass::fromLua(L, -1); \
            lua_pop(L, 1); \
            if (!m_##member) { \
                return false; \
            } \
        } \
    } while(0)

#define DX_LUA_DESC_GET_OPT_REF_MEMBER(L, idx, klass, member) \
    do { \
        lua_pushstring(L, #member); \
        lua_gettable(L, (idx < 0 ? idx - 1 : idx)); \
        if (!lua_isnil(L, -1)) { \
            m_##member = klass::fromLua(L, -1); \
            if (!m_##member) { \
                lua_pop(L, 1); \
                return false; \
            } \
        } \
        lua_pop(L, 1); \
    } while (0)

#define DX_LUA_DESC_GET_VEC(L, idx, klass, member, vec) \
    do { \
        lua_pushstring(L, #member); \
        lua_gettable(L, (idx < 0 ? idx - 1 : idx)); \
        if (lua_isnil(L, -1)) { \
            lua_pop(L, 1); \
            return false; \
        } else { \
            int N = lua_objlen(L, -1); \
            for (int n = 1; n <= N; n++) { \
                lua_pushinteger(L, n); \
                lua_gettable(L, -2); \
                auto klass##_obj = klass::fromLua(L, -1); \
                if (!klass##_obj) { \
                    lua_pop(L, 2); \
                    return false; \
                } \
                vec.push_back(klass##_obj); \
                lua_pop(L, 1); \
            } \
        } \
        lua_pop(L, 1); \
    } while (0)

#define DX_LUA_DESC_GET_OPT_VEC(el, klass, member, vec) \
    do { \
        lua_pushstring(L, #member); \
        lua_gettable(L, (idx < 0 ? idx - 1 : idx)); \
        if (!lua_isnil(L, lua_gettop(L))) { \
            int N = lua_objlen(L, -1); \
            for (int n = 1; n <= N; n++) { \
                lua_pushinteger(L, n); \
                lua_gettable(L, -2); \
                auto klass##_obj = klass::fromLua(L, -1); \
                if (!klass##_obj) { \
                    return false; \
                    lua_pop(L, 2); \
                } \
                vec.pushBack(klass##_obj); \
                lua_pop(L, 1); \
            } \
        } \
        lua_pop(L, 1); \
    } while (0)

#define DX_LUA_DESC_PROCESS_VEC(L, idx, klass, member, P) \
    do { \
        lua_pushstring(L, #member); \
        lua_gettable(L, (idx < 0 ? idx - 1 : idx)); \
        if (lua_isnil(L, -1)) { \
            lua_pop(L, 1); \
            return false; \
        } else { \
            auto objMgr = ObjectManager::getInstance(); \
            int N = lua_objlen(L, -1); \
            for (int n = 1; n <= N; n++) { \
                lua_pushinteger(L, n); \
                lua_gettable(L, -2); \
                auto klass##_obj = klass::fromLua(L, -1); \
                if (!klass##_obj) { \
                    lua_pop(L, 2); \
                    return false; \
                } \
                P() \
                lua_pop(L, 1); \
            } \
        } \
        lua_pop(L, 1); \
    } while (0)

#define DX_LUA_DESC_PROCESS_OPT_VEC(L, idx, klass, member, P) \
    do { \
        lua_pushstring(L, #member); \
        lua_gettable(L, (idx < 0 ? idx - 1 : idx)); \
        if (!lua_isnil(L, -1)) { \
            auto objMgr = ObjectManager::getInstance(); \
            int N = lua_objlen(L, -1); \
            for (int n = 1; n <= N; n++) { \
                lua_pushinteger(L, n); \
                lua_gettable(L, -2); \
                auto klass##_obj = klass::fromLua(L, lua_gettop(L)); \
                if (!klass##_obj) { \
                    lua_pop(L, 2); \
                    return false; \
                } \
                P() \
                lua_pop(L, 1); \
            } \
        } \
        lua_pop(L, 1); \
    } while (0)

template<typename T>
bool dx_luaval_to_native(lua_State* L, int idx, T* v) {
    if (!dx_lua_check_type<T>(L, idx)) {
        return false;
    }
    *v = (T)dx_lua_parse<T>(L, idx);
    return true;
}

#endif /* __DX_LUAPARSER_H__ */
