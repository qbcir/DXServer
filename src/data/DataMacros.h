#ifndef __DX_DATAMACROS_H__
#define __DX_DATAMACROS_H__

#define DX_CREATE_FROM_JSON_STR_FUNC(klass) \
static klass* fromJsonStr(const std::string& s) { \
    rapidjson::Document doc; \
    doc.Parse(s.c_str()); \
    auto errCode = doc.GetParseError(); \
    if (errCode != rapidjson::kParseErrorNone) { \
        return nullptr; \
    } \
    const rapidjson::Value& el = *static_cast<const rapidjson::Value*>(&doc); \
    return fromJson(el); \
}

#define DX_CREATE_FROM_JSON_FUNC(ret, klass) \
static ret fromJson(const rapidjson::Value& el) { \
    klass* v = new (std::nothrow) klass(); \
    if (v && v->initFromJson(el)) { \
        return ret(v); \
    } \
    if (v) delete v; \
    return ret(); \
}

#define DX_CREATE_FROM_LUA_FUNC(ret, klass) \
static ret fromLua(lua_State* L, int idx) { \
    klass* v = new (std::nothrow) klass(); \
    if (v && v->initFromLua(L, idx)) { \
        return ret(v); \
    } \
    if (v) delete v; \
    return ret(); \
}

#endif // __DX_DATAMACROS_H__
