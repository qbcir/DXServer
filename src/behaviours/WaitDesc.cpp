#include "WaitDesc.h"

bool WaitDesc::initFromJson(const rapidjson::Value& el) {
    DX_DESC_GET_REF_MEMBER(el, NumericExpr, term);
    return true;
}

bool WaitDesc::initFromLua(lua_State* L, int idx) {
    DX_LUA_DESC_GET_REF_MEMBER(L, idx, NumericExpr, term);
    return true;
}

ActionPtr WaitDesc::getAction() {
    float dt = m_term->eval();
    return DelayTime::create(dt);
}
