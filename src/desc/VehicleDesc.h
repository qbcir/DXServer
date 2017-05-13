#ifndef __dx_VEHICLEDESC_H__
#define __dx_VEHICLEDESC_H__

#include "GameObjectDesc.h"

class GameObject;
class VehicleDesc : public GameObjectDesc {
public:
    typedef std::shared_ptr<VehicleDesc> VehicleDescPtr;
    DX_CREATE_FROM_JSON_FUNC(VehicleDescPtr, VehicleDesc)
    DX_CREATE_FROM_LUA_FUNC(VehicleDescPtr, VehicleDesc)
    float getHealth() const;
    float getDamage() const;
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
    float m_health = 0;
    float m_damage = 0;
};
typedef VehicleDesc::VehicleDescPtr VehicleDescPtr;

#endif /* VEHICLEDESC_H */
