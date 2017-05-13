#include "ChangeDirectionDesc.h"

bool ChangeDirectionDesc::initFromJson(const rapidjson::Value& el) {
    DX_DESC_GET_REF_MEMBER(el, DirectionDesc, direction);
    DX_DESC_GET_REF_MEMBER(el, NumericExpr, term);
    return true;
}

bool ChangeDirectionDesc::initFromLua(lua_State* L, int idx) {
    DX_LUA_DESC_GET_REF_MEMBER(L, idx, DirectionDesc, direction);
    DX_LUA_DESC_GET_REF_MEMBER(L, idx, NumericExpr, term);
    return true;
}

ActionPtr ChangeDirectionDesc::getAction() {
}
