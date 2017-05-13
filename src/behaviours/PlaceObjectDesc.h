#ifndef __DX_PLACEOBJECTDESC_H__
#define __DX_PLACEOBJECTDESC_H__

#include "GameActionDesc.h"
#include "NumericDesc.h"
#include "../objects/Vehicle.h"
#include "../objects/Bullet.h"

class PlaceDescBase : public GameActionDesc {
public:
    virtual float evalSpeed(const GameObjectPtr& p);
    virtual float evalDirection(const Eigen::Vector2f& pos, const GameObjectPtr& p);
    virtual void placeObject(const GameObjectPtr& obj, GameObject* tgt);
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
    PositionDescPtr m_position;
    NumericDescPtr m_rotation;
    NumericDescPtr m_orientation;
    NumericDescPtr m_speed;
    NumericDescPtr m_direction;
    std::vector<std::string> m_components;
};

class PlaceObjectDesc : public PlaceDescBase {
public:
    DX_CREATE_FROM_JSON_FUNC(GameActionDescPtr, PlaceObjectDesc)
    DX_CREATE_FROM_LUA_FUNC(GameActionDescPtr, PlaceObjectDesc)
    ActionPtr getAction();
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
    GameObjectDescPtr m_objectDesc;
};

class PlaceVehicleDesc : public PlaceDescBase {
public:
    DX_CREATE_FROM_JSON_FUNC(GameActionDescPtr, PlaceVehicleDesc)
    DX_CREATE_FROM_LUA_FUNC(GameActionDescPtr, PlaceVehicleDesc)
    ActionPtr getAction();
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
    VehicleDescPtr m_vehicleDesc;
};

class FireBulletDesc : public PlaceDescBase {
public:
    DX_CREATE_FROM_JSON_FUNC(GameActionDescPtr, FireBulletDesc)
    DX_CREATE_FROM_LUA_FUNC(GameActionDescPtr, FireBulletDesc)
    ActionPtr getAction();
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
    BulletDescPtr m_bulletDesc;
};

class PlaceObjectRefDesc : public PlaceDescBase {
public:
    DX_CREATE_FROM_JSON_FUNC(GameActionDescPtr, PlaceObjectRefDesc)
    DX_CREATE_FROM_LUA_FUNC(GameActionDescPtr, PlaceObjectRefDesc)
    const std::string& getLabel();
    virtual ActionPtr getAction();
    virtual const std::string getActionName() { return "placeObjectRef"; }
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
    std::string m_label;
};

class PlaceVehicleRefDesc : public PlaceObjectRefDesc {
public:
    DX_CREATE_FROM_JSON_FUNC(GameActionDescPtr, PlaceVehicleRefDesc)
    DX_CREATE_FROM_LUA_FUNC(GameActionDescPtr, PlaceVehicleRefDesc)
    ActionPtr getAction();
    const std::string getActionName() { return "placeVehicleRef"; }
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
};

class FireBulletRefDesc : public PlaceObjectRefDesc {
public:
    DX_CREATE_FROM_JSON_FUNC(GameActionDescPtr, FireBulletRefDesc)
    DX_CREATE_FROM_LUA_FUNC(GameActionDescPtr, FireBulletRefDesc)
    ActionPtr getAction();
    const std::string getActionName() { return "fireBulletRef"; }
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
};

#endif /* __DX_PLACEOBJECTDESC_H__ */
