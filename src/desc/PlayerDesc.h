#ifndef __DX_PLAYERDESC_H__
#define __DX_PLAYERDESC_H__

#include "VehicleDesc.h"

class PlayerDesc : public LuaRef {
public:
    DX_CREATE_FROM_JSON_FUNC(std::shared_ptr<PlayerDesc>, PlayerDesc)
    DX_CREATE_FROM_LUA_FUNC(std::shared_ptr<PlayerDesc>, PlayerDesc)
    const std::string& getLabel() const;
    const VehicleDescPtr& getVehicleDesc() const;
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State *L, int idx);
    std::string m_label;
    VehicleDescPtr m_vehicleDesc;
};

typedef std::shared_ptr<PlayerDesc> PlayerDescPtr;

#endif /* __DX_PLAYERDESC_H__ */
