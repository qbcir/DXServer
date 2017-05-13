#ifndef __dx_GAMEOBJECT_H__
#define __dx_GAMEOBJECT_H__

#include "../NetTypes.h"
#include "../scripting/LuaRef.h"
#include "../desc/GameObjectDesc.h"
#include "../behaviours/Action.h"
#include "Box2D/Box2D.h"
#include <memory>

#define CC_DEGREES_TO_RADIANS(__ANGLE__) ((__ANGLE__) * 0.01745329252f) // PI / 180
#define CC_RADIANS_TO_DEGREES(__ANGLE__) ((__ANGLE__) * 57.29577951f) // PI * 180

class GameObject;
class Component {
public:
    virtual void update(float dt) = 0;
protected:
    GameObject* m_owner = nullptr;
};
typedef std::shared_ptr<Component> ComponentPtr;

enum class GameObjectType : uint8_t {
    GENERIC,
    VEHICLE,
    BULLET,
    PLAYER
};

class GameObject : public LuaRef {
public:
    typedef std::shared_ptr<GameObject> GameObjectPtr;
    static GameObjectPtr createFromDesc(const GameObjectDescPtr& desc);
    virtual ~GameObject() {}
    //
    virtual size_t writeTypeInfoBytes(bytes_t& buf);
    virtual size_t writeStateBytes(bytes_t& buf, state_mask_t state);
    virtual state_mask_t getFullStateMask() const;
    net_id_t getNetId() const;
    void setNetId(net_id_t id);
    void runAction(const ActionPtr& action);
    void setBody(b2Body* b);
    b2Body* getBody();
    virtual void update(float dt);
    void setPosition(const b2Vec2 &pos);
    void setVelocity(const b2Vec2 &vel);
    void setAccel(const b2Vec2 & accel);
    void applyAccel(const b2Vec2 & accel);
    void setSpeed(float speed);
    void setAngVelocity(float rotation);
    void setDirection(float direction);
    void changeDirection(float delta);
    const b2Vec2& getPosition() const;
    const b2Vec2& getVelocity() const;
    float getSpeed() const;
    float getDirection() const;
    bool isDead() const;
    void setDead();
    void setDead(bool dead);
    int getCollisionClass() const;
    void setCollisionClass(int klass);
    uint32_t getCollisionMask() const;
    void setCollisionMask(uint32_t mask);
    void enableCollisionsWith(int klass);
    bool canCollideWith(int klass) const;
    bool canCollideWith(GameObjectPtr& obj) const;
    void onCollision(GameObjectPtr& obj);
    void setIdxInScene(int idx);
    int getIdxInScene() const;
protected:
    bool initFromDesc(const GameObjectDescPtr& desc);
    int m_idxInScene = -1;
    bool m_dead = false;
    int m_collisionClass = -1;
    uint32_t m_collisionMask = 0;
    net_id_t m_netId = 0;
    GameObjectDescPtr m_objDesc;
    b2Body* m_body = nullptr;
    std::vector<ComponentPtr> m_components;
    std::vector<ActionPtr> m_actions;
};
typedef GameObject::GameObjectPtr GameObjectPtr;

#endif /* __dx_GAMEOBJECT_H__ */
