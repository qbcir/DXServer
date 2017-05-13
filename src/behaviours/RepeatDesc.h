#ifndef __DX_REPEATDESC_H__
#define __DX_REPEATDESC_H__

#include "GameActionDesc.h"
#include "NumericDesc.h"

class RepeatDesc : public GameActionDesc {
public:
    DX_CREATE_FROM_JSON_FUNC(GameActionDescPtr, RepeatDesc)
    DX_CREATE_FROM_LUA_FUNC(GameActionDescPtr, RepeatDesc)
    ActionPtr getAction();
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
    NumericExprPtr m_times;
    std::vector<GameActionDescPtr> m_actions;
};

#endif /* __DX_REPEATDESC_H__ */
