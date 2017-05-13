#ifndef __DX_CHANGEDIRECTIONDESC_H__
#define __DX_CHANGEDIRECTIONDESC_H__

#include "GameActionDesc.h"
#include "NumericDesc.h"

class ChangeDirectionDesc : public GameActionDesc {
public:
    DX_CREATE_FROM_JSON_FUNC(GameActionDescPtr, ChangeDirectionDesc)
    DX_CREATE_FROM_LUA_FUNC(GameActionDescPtr, ChangeDirectionDesc)
    ActionPtr getAction();
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
    NumericDescPtr m_direction;
    NumericExprPtr m_term;
};

#endif /* __DX_CHANGEDIRECTIONDESC_H__ */
