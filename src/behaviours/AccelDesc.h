#ifndef __DX_ACCELDESC_H__
#define __DX_ACCELDESC_H__

#include "GameActionDesc.h"
#include "NumericDesc.h"

class AccelDesc : public GameActionDesc {
public:
    DX_CREATE_FROM_JSON_FUNC(GameActionDescPtr, AccelDesc)
    DX_CREATE_FROM_LUA_FUNC(GameActionDescPtr, AccelDesc)
    ActionPtr getAction();
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
    NumericDescPtr m_horizontal;
    NumericDescPtr m_vertical;
    NumericExprPtr m_term;
};

#endif /* __DX_ACCELDESC_H__ */
