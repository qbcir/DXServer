#ifndef __DX_CHANGESPEEDDESC_H__
#define __DX_CHANGESPEEDDESC_H__

#include "GameActionDesc.h"
#include "NumericDesc.h"

class ChangeSpeedDesc : public GameActionDesc {
public:
    DX_CREATE_FROM_JSON_FUNC(GameActionDescPtr, ChangeSpeedDesc)
    DX_CREATE_FROM_LUA_FUNC(GameActionDescPtr, ChangeSpeedDesc)
    ActionPtr getAction();
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
    NumericDescPtr m_speed;
    NumericExprPtr m_term;
};

#endif /* __DX_CHANGESPEEDDESC_H__ */
