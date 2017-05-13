#ifndef __DX_VANISHDESC_H__
#define __DX_VANISHDESC_H__

#include "GameActionDesc.h"

class VanishDesc : public GameActionDesc {
public:
    DX_CREATE_FROM_JSON_FUNC(GameActionDescPtr, VanishDesc)
    DX_CREATE_FROM_LUA_FUNC(GameActionDescPtr, VanishDesc)
    ActionPtr getAction();
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
};

#endif /* __DX_VANISHDESC_H__ */
