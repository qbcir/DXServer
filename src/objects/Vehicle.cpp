#include "Vehicle.h"

GameObjectPtr Vehicle::createFromDesc(const VehicleDescPtr& desc) {
    auto v = new (std::nothrow) Vehicle();
    if (v && v->initFromDesc(desc)) {
        return GameObjectPtr(v);
    }
    if (v) delete v;
    return nullptr;
}

bool Vehicle::initFromDesc(const VehicleDescPtr& desc) {
    if (!GameObject::initFromDesc(desc)) {
        return false;
    }
    m_vehicleDesc = desc;
    m_health = desc->getHealth();
    //this->setCollisionClass(COLLISION_CLASS_ENEMY);
    //this->enableCollisionsWith(COLLISION_CLASS_PLAYER);
    //this->enableCollisionsWith(COLLISION_CLASS_PLAYER_BULLET);
    return true;
}

size_t Vehicle::writeTypeInfoBytes(bytes_t& buf) {
    size_t nb = 0;
    nb += dx_write_bytes<GameObjectType>(buf, GameObjectType::VEHICLE);
    nb += dx_write_bytes<std::string>(buf, m_vehicleDesc->getLabel());
    return nb;
}

