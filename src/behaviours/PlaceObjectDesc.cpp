#include "PlaceObjectDesc.h"
#include "../objects/ObjectManager.h"

float PlaceDescBase::evalSpeed(const GameObjectPtr& p) {
    if (!m_speed) {
        return 0;
    }
    switch (m_speed->getType()) {
        case NumericDescType::ABSOLUTE :
            return m_speed->eval();
        case NumericDescType::RELATIVE :
            return m_speed->eval() + p->getSpeed();
        default:
            return 0;
    }
}

float PlaceDescBase::evalDirection(const Eigen::Vector2f& pos, const GameObjectPtr& p) {
    if (!m_direction) {
        if (p) {
            return p->getDirection();
        } else {
            return 90;
        }
    }
    switch (m_direction->getType()) {
        case NumericDescType::ABSOLUTE :
            return m_direction->eval();
        case NumericDescType::RELATIVE :
            return m_direction->eval() + p->getDirection();
        default:
            return 0;
    }
}

void PlaceDescBase::placeObject(const GameObjectPtr& obj, GameObject *tgt) {

}

bool PlaceDescBase::initFromJson(const rapidjson::Value& el) {
    DX_DESC_GET_OPT_REF_MEMBER(el, RotationDesc, rotation);
    DX_DESC_GET_OPT_REF_MEMBER(el, OrientationDesc, orientation);
    DX_DESC_GET_OPT_REF_MEMBER(el, PositionDesc, position);
    DX_DESC_GET_OPT_REF_MEMBER(el, SpeedDesc, speed);
    DX_DESC_GET_OPT_REF_MEMBER(el, DirectionDesc, direction);
    return true;
}

bool PlaceDescBase::initFromLua(lua_State* L, int idx) {
    DX_LUA_DESC_GET_OPT_REF_MEMBER(L, idx, RotationDesc, rotation);
    DX_LUA_DESC_GET_OPT_REF_MEMBER(L, idx, OrientationDesc, orientation);
    DX_LUA_DESC_GET_OPT_REF_MEMBER(L, idx, PositionDesc, position);
    DX_LUA_DESC_GET_OPT_REF_MEMBER(L, idx, SpeedDesc, speed);
    DX_LUA_DESC_GET_OPT_REF_MEMBER(L, idx, DirectionDesc, direction);
    return true;
}

bool PlaceObjectDesc::initFromJson(const rapidjson::Value& el) {
    if (!PlaceDescBase::initFromJson(el)) {
        return false;
    }
    DX_DESC_GET_REF_MEMBER(el, GameObjectDesc, objectDesc);
    return true;
}

bool PlaceObjectDesc::initFromLua(lua_State* L, int idx) {
    if (!PlaceDescBase::initFromLua(L, idx)) {
        return false;
    }
    DX_LUA_DESC_GET_REF_MEMBER(L, idx, GameObjectDesc, objectDesc);
    return true;
}

ActionPtr PlaceObjectDesc::getAction() {
    return CallFuncN::create([=](GameObject* tgt) {
        auto go = GameObject::createFromDesc(m_objectDesc);
        //CCASSERT(go != nullptr, "Can't create 'GameObject' from 'GameObjectDesc'");
        this->placeObject(go, tgt);
    });
}

bool PlaceVehicleDesc::initFromJson(const rapidjson::Value& el) {
    if (!PlaceDescBase::initFromJson(el)) {
        return false;
    }
    DX_DESC_GET_REF_MEMBER(el, VehicleDesc, vehicleDesc);
    return true;
}

bool PlaceVehicleDesc::initFromLua(lua_State* L, int idx) {
    if (!PlaceDescBase::initFromLua(L, idx)) {
        return false;
    }
    DX_LUA_DESC_GET_REF_MEMBER(L, idx, VehicleDesc, vehicleDesc);
    return true;
}

ActionPtr PlaceVehicleDesc::getAction() {
    return CallFuncN::create([=](GameObject* tgt) {
        auto go = Vehicle::createFromDesc(m_vehicleDesc);
        //CCASSERT(go != nullptr, "Can't create 'Vehicle' from 'VehicleDesc'");
        this->placeObject(go, tgt);
    });
}


bool FireBulletDesc::initFromJson(const rapidjson::Value& el) {
    if (!PlaceDescBase::initFromJson(el)) {
        return false;
    }
    DX_DESC_GET_REF_MEMBER(el, BulletDesc, bulletDesc);
    return true;
}

bool FireBulletDesc::initFromLua(lua_State* L, int idx) {
    if (!PlaceDescBase::initFromLua(L, idx)) {
        return false;
    }
    DX_LUA_DESC_GET_REF_MEMBER(L, idx, BulletDesc, bulletDesc);
    return true;
}

ActionPtr FireBulletDesc::getAction() {
    return CallFuncN::create([=](GameObject* tgt) {
        auto go = Bullet::createFromDesc(m_bulletDesc);
        //CCASSERT(go != nullptr, "Can't create 'Bullet' from 'BulletDesc'");
        this->placeObject(go, tgt);
    });
}

const std::string& PlaceObjectRefDesc::getLabel() {
    return m_label;
}

bool PlaceObjectRefDesc::initFromJson(const rapidjson::Value& el) {
    if (!PlaceDescBase::initFromJson(el)) {
        return false;
    }
    DX_DESC_GET_MEMBER(el, string, label);
    return true;
}

bool PlaceObjectRefDesc::initFromLua(lua_State* L, int idx) {
    if (!PlaceDescBase::initFromLua(L, idx)) {
        return false;
    }
    DX_LUA_DESC_GET_MEMBER(L, idx, string, label);
    return true;
}

ActionPtr PlaceObjectRefDesc::getAction() {
    return CallFuncN::create([=](GameObject* tgt) {
        auto objMgr = ObjectManager::getInstance();
        auto objDesc = objMgr->getGameObjectDesc(m_label);
        //CCASSERT(objDesc != nullptr, cocos2d::StringUtils::format("No 'GameObject' defined for %s", m_label.c_str()));
        auto go = GameObject::createFromDesc(objDesc);
        //CCASSERT(go != nullptr, "Can't create 'GameObject' from 'GameObjectDesc'");
        this->placeObject(go, tgt);
    });
}

bool PlaceVehicleRefDesc::initFromJson(const rapidjson::Value& el) {
    if (!PlaceObjectRefDesc::initFromJson(el)) {
        return false;
    }
    return true;
}

bool PlaceVehicleRefDesc::initFromLua(lua_State* L, int idx) {
    if (!PlaceObjectRefDesc::initFromLua(L, idx)) {
        return false;
    }
    return true;
}

ActionPtr PlaceVehicleRefDesc::getAction() {
    return CallFuncN::create([=](GameObject* tgt) {
        auto objMgr = ObjectManager::getInstance();
        auto vDesc = objMgr->getVehicleDesc(m_label);
        //CCASSERT(vDesc != nullptr, cocos2d::StringUtils::format(
        //    "No 'VehicleDesc' defined for '%s'", m_label.c_str()).c_str());
        auto v = Vehicle::createFromDesc(vDesc);
        //CCASSERT(v != nullptr, "Can't create 'Vehicle' from 'VehicleDesc'");
        this->placeObject(v, tgt);
    });
}

bool FireBulletRefDesc::initFromJson(const rapidjson::Value& el) {
    if (!PlaceObjectRefDesc::initFromJson(el)) {
        return false;
    }
    return true;
}

bool FireBulletRefDesc::initFromLua(lua_State* L, int idx) {
    if (!PlaceObjectRefDesc::initFromLua(L, idx)) {
        return false;
    }
    return true;
}

ActionPtr FireBulletRefDesc::getAction() {
    return CallFuncN::create([=](GameObject* tgt) {
        auto objMgr = ObjectManager::getInstance();
        auto bDesc = objMgr->getBulletDesc(m_label);
        //CCASSERT(bDesc != nullptr, cocos2d::StringUtils::format(
        //    "No 'BulletDesc' defined for '%s'", m_label.c_str()).c_str());
        auto b = Bullet::createFromDesc(bDesc);
        //CCASSERT(b != nullptr, "Can't create 'Bullet' from 'BulletDesc'");
        this->placeObject(b, tgt);
    });
}
