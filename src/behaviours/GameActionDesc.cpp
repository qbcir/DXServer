#include "GameActionDesc.h"
#include "AccelDesc.h"
#include "ActionDesc.h"
#include "ChangeDirectionDesc.h"
#include "ChangeSpeedDesc.h"
#include "PlaceObjectDesc.h"
#include "RepeatDesc.h"
#include "VanishDesc.h"
#include "WaitDesc.h"

GameActionType GameActionDesc::getType() const {
    return m_type;
}

void GameActionDesc::setType(GameActionType type) {
    m_type = type;
}

GameActionDescPtr GameActionDesc::fromLua(const std::string& filename) {

}

GameActionDescPtr GameActionDesc::fromLua(lua_State* L, int idx) {

}

GameActionDescPtr GameActionDesc::fromJson(const rapidjson::Value& el) {

}

#define GAME_ACTION_CREATORS() \
    GAME_ACTION_CREATOR(repeat, RepeatDesc) \
    GAME_ACTION_CREATOR(actionRef, ActionRefDesc) \
    GAME_ACTION_CREATOR(placeObject, PlaceObjectDesc) \
    GAME_ACTION_CREATOR(placeVehicle, PlaceVehicleDesc) \
    GAME_ACTION_CREATOR(fireBullet, FireBulletDesc) \
    GAME_ACTION_CREATOR(placeObjectRef, PlaceObjectRefDesc) \
    GAME_ACTION_CREATOR(placeVehicleRef, PlaceVehicleRefDesc) \
    GAME_ACTION_CREATOR(fireBulletRef, FireBulletRefDesc) \
    GAME_ACTION_CREATOR(changeSpeed, ChangeSpeedDesc) \
    GAME_ACTION_CREATOR(changeDirection, ChangeDirectionDesc) \
    GAME_ACTION_CREATOR(accel, AccelDesc) \
    GAME_ACTION_CREATOR(vanish, VanishDesc) \
    GAME_ACTION_CREATOR(wait, WaitDesc) \
    GAME_ACTION_CREATOR(action, ActionDesc)

#define GAME_ACTION_CREATOR(name, type) { #name, &GameActionDesc::create<type> },
GameActionDesc::GameActionCreatorMapT GameActionDesc::GameActionCreatorMap = {
    GAME_ACTION_CREATORS()
};

GameActionDesc::GameActionCreatorLuaMapT GameActionDesc::GameActionCreatorLuaMap = {
    GAME_ACTION_CREATORS()
};

#undef GAME_ACTION_CREATOR
