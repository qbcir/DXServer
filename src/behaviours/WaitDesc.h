#ifndef __DX_WAITDESC_H__
#define __DX_WAITDESC_H__

#include "GameActionDesc.h"
#include "NumericDesc.h"
#include "Action.h"

class WaitDesc : public GameActionDesc {
public:
    DX_CREATE_FROM_JSON_FUNC(GameActionDescPtr, WaitDesc)
    DX_CREATE_FROM_LUA_FUNC(GameActionDescPtr, WaitDesc)
    ActionPtr getAction();
private:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
    NumericExprPtr m_term;
};

#endif /* __DX_WAITDESC_H__ */
