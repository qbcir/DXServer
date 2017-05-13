#include "PlayerDesc.h"

const std::string& PlayerDesc::getLabel() const {
    return m_label;
}

const VehicleDescPtr& PlayerDesc::getVehicleDesc() const {
    return m_vehicleDesc;
}

bool PlayerDesc::initFromJson(const rapidjson::Value& el) {
    return false;
}

bool PlayerDesc::initFromLua(lua_State *L, int idx) {
    DX_LUA_DESC_GET_MEMBER(L, idx, string, label);
    DX_LUA_DESC_GET_REF_MEMBER(L, idx, VehicleDesc, vehicleDesc);
    return true;
}
