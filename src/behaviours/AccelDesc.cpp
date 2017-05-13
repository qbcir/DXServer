#include "AccelDesc.h"

bool AccelDesc::initFromJson(const rapidjson::Value& el) {
    DX_DESC_GET_OPT_REF_MEMBER(el, HorizontalDesc, horizontal);
    DX_DESC_GET_OPT_REF_MEMBER(el, VerticalDesc, vertical);
    DX_DESC_GET_REF_MEMBER(el, NumericExpr, term);
    return true;
}

bool AccelDesc::initFromLua(lua_State* L, int idx) {
    DX_LUA_DESC_GET_OPT_REF_MEMBER(L, idx, HorizontalDesc, horizontal);
    DX_LUA_DESC_GET_OPT_REF_MEMBER(L, idx, VerticalDesc, vertical);
    DX_LUA_DESC_GET_REF_MEMBER(L, idx, NumericExpr, term);
    return true;
}

ActionPtr AccelDesc::getAction() {
}
