#ifndef __DX_DATAPARSER_H__
#define __DX_DATAPARSER_H__

#include "JSONParser.h"
#include "LuaParser.h"
#include "ByteParser.h"
#include "DataMacros.h"

#define DX_DEF_STRUCT_P(klass) \
    template<> StructP<klass>::FieldP_MapT StructP<klass>::FieldP_Map = StructP<klass>::FieldP_MapT(); \
    template<> StructLP<klass>::FieldP_MapT StructLP<klass>::FieldP_Map = StructLP<klass>::FieldP_MapT(); \
    template<> StructBP<klass>::FieldP_VecT StructBP<klass>::FieldP_Vec = StructBP<klass>::FieldP_VecT();
#define DX_ADD_OPT_FIELD_P(klass, member) \
    bool g_json_##klass##_##member##_added = StructP<klass>::addField(#member, &klass::member, false); \
    bool g_lua_##klass##_##member##_added = StructLP<klass>::addField(#member, &klass::member, false); \
    bool g_b_##klass##_##member##_added = StructBP<klass>::addField(&klass::member);
#define DX_ADD_FIELD_P(klass, member) \
    bool g_json_##klass##_##member##_added = StructP<klass>::addField(#member, &klass::member, true); \
    bool g_lua_##klass##_##member##_added = StructLP<klass>::addField(#member, &klass::member, true); \
    bool g_b_##klass##_##member##_added = StructBP<klass>::addField(&klass::member);
#define DX_ADD_OPT_REF_FIELD_P(klass, member) \
    bool g_json_##klass##_##member##_added = StructP<klass>::addRefField(#member, &klass::member, false); \
    bool g_lua_##klass##_##member##_added = StructLP<klass>::addRefField(#member, &klass::member, false); \
    bool g_b_##klass##_##member##_added = StructBP<klass>::addRefField(&klass::member);
#define DX_ADD_REF_FIELD_P(klass, member) \
    bool g_json_##klass##_##member##_added = StructP<klass>::addRefField(#member, &klass::member, true); \
    bool g_lua_##klass##_##member##_added = StructLP<klass>::addRefField(#member, &klass::member, true); \
    bool g_b_##klass##_##member##_added = StructBP<klass>::addRefField(&klass::member);

#endif /* __DX_DATAPARSER_H__ */
