#ifndef __DX_VEHICLE_H__
#define __DX_VEHICLE_H__

#include "GameObject.h"
#include "../desc/VehicleDesc.h"

class Vehicle : public GameObject {
public:
    static GameObjectPtr createFromDesc(const VehicleDescPtr& desc);
    virtual size_t writeTypeInfoBytes(bytes_t& buf);
protected:
    bool initFromDesc(const VehicleDescPtr& desc);
    float m_health = 0;
    float m_healthDec = 0;
    bool m_ignoreCollision = false;
    float m_damageOnCollision = 0;
    VehicleDescPtr m_vehicleDesc;
};

#endif /* __DX_VEHICLE_H__ */
