#include "GameObjectDesc.h"
#include "../data/DataParser.h"

GameObjectDesc::~GameObjectDesc() {}

bool GameObjectDesc::initFromJson(const rapidjson::Value& el) {
    DX_DESC_GET_MEMBER(el, string, label);
    DX_DESC_GET_MEMBER(el, SpriteDesc, sprite);
    DX_DESC_GET_OPT_MEMBER(el, vector<ScriptComponentDesc>, components);
    DX_DESC_GET_OPT_MEMBER(el, float, maxSpeed);
    //DX_DESC_GET_OPT_REF_MEMBER(el, GameAction, action);
    return true;
}

bool GameObjectDesc::initFromLua(lua_State *L, int idx) {
    DX_LUA_DESC_GET_MEMBER(L, idx, string, label);
    DX_LUA_DESC_GET_MEMBER(L, idx, SpriteDesc, sprite);
    DX_LUA_DESC_GET_OPT_MEMBER(L, idx, vector<ScriptComponentDesc>, components);
    DX_LUA_DESC_GET_OPT_MEMBER(L, idx, float, maxSpeed);
    //DX_LUA_DESC_GET_OPT_REF_MEMBER(L, idx, GameAction, action);
    return true;
}

const std::string& GameObjectDesc::getLabel() const {
    return m_label;
}

const SpriteDesc& GameObjectDesc::getSpriteDesc() const {
    return m_sprite;
}

const std::vector<ScriptComponentDesc>& GameObjectDesc::getComponentDescs() const {
    return m_components;
}

float GameObjectDesc::getMaxSpeed() const {
    return m_maxSpeed;
}

float GameObjectDesc::getMaxRotation() const {
    return m_maxRotation;
}

float GameObjectDesc::getMaxAngularAccel() const {
    return m_maxAngularAccel;
}

bool GameObjectDesc::hasMaxSpeed() const {
    return m_maxSpeed != std::numeric_limits<float>::max();
}

bool GameObjectDesc::hasMaxRotation() const {
    return m_maxRotation != std::numeric_limits<float>::max();
}

bool GameObjectDesc::hasMaxAngularAccel() const {
    return m_maxAngularAccel != std::numeric_limits<float>::max();
}

bool GameObjectDesc::getAutoUpdateDirection() const {
    return m_autoUpdateDirection;
}

