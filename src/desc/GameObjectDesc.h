#ifndef __DX_GAMEOBJECTDESC_H__
#define __DX_GAMEOBJECTDESC_H__

#include "ScriptComponentDesc.h"
#include "SpriteDesc.h"
#include "../data/DataParser.h"
#include "../scripting/LuaRef.h"
#include <memory>

class GameObjectDesc : public LuaRef {
public:
    typedef std::shared_ptr<GameObjectDesc> GameObjectDescPtr;
    virtual ~GameObjectDesc();
    DX_CREATE_FROM_JSON_FUNC(GameObjectDescPtr, GameObjectDesc)
    DX_CREATE_FROM_LUA_FUNC(GameObjectDescPtr, GameObjectDesc)
    //GameAction* getAction();
    const std::string& getLabel() const;
    const SpriteDesc& getSpriteDesc() const;
    const std::vector<ScriptComponentDesc>& getComponentDescs() const;
    bool hasMaxSpeed() const;
    float getMaxSpeed() const;
    bool hasMaxRotation() const;
    float getMaxRotation() const;
    bool hasMaxAngularAccel() const;
    float getMaxAngularAccel() const;
    bool getAutoUpdateDirection() const;
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
    std::string m_label;
    SpriteDesc m_sprite;
    std::vector<ScriptComponentDesc> m_components;
    //GameAction* m_action = nullptr;
    float m_maxSpeed = std::numeric_limits<float>::max();
    float m_maxRotation = std::numeric_limits<float>::max();
    float m_maxAngularAccel = std::numeric_limits<float>::max();
    bool m_autoUpdateDirection = false;
};

typedef std::shared_ptr<GameObjectDesc> GameObjectDescPtr;

#endif /* __DX_GAMEOBJECTDESC_H__ */
