#include "GameObject.h"
#include "../data/DataParser.h"
#include <cmath>

void GameObject::runAction(const ActionPtr& action) {
    m_actions.emplace_back(action);
}

GameObjectPtr GameObject::createFromDesc(const GameObjectDescPtr& desc) {
    auto obj = new (std::nothrow) GameObject();
    if (obj && obj->initFromDesc(desc)) {
        return GameObjectPtr(obj);
    }
    if (obj) delete obj;
    return nullptr;
}

bool GameObject::initFromDesc(const GameObjectDescPtr& desc) {
    m_objDesc = desc;
    //this->setMaxSpeed(desc->getMaxSpeed());
    return true;
}

void GameObject::update(float dt) {
    std::vector<ActionPtr> activeActions;
    for (auto action : m_actions) {
        action->update(dt);
        if (!action->isDone()) {
            activeActions.emplace_back(action);
        }
    }
    m_actions.swap(activeActions);
    auto a = m_body->GetAngle();
    a = std::fmod(a, M_2_PI);
    if (a < 0) a += M_2_PI;
    m_body->SetTransform(m_body->GetPosition(), a);
}

void GameObject::setPosition(const b2Vec2& pos) {
    m_body->SetTransform(pos, m_body->GetAngle());
}

void GameObject::setVelocity(const b2Vec2 &vel) {
    m_body->SetLinearVelocity(vel);
}

void GameObject::setAccel(const b2Vec2 &accel) {
}

void GameObject::applyAccel(const b2Vec2 &accel) {
    //auto mass = m_body->GetMass(); mass = 1
    m_body->ApplyForceToCenter(accel, true);
}

void GameObject::setSpeed(float speed) {
    auto lv = m_body->GetLinearVelocity();
    lv.Normalize();
    lv *= speed;
    m_body->SetLinearVelocity(lv);
}

void GameObject::setAngVelocity(float rotation) {
    m_body->SetAngularVelocity(rotation);
}

void GameObject::setDirection(float direction) {
    /*
    auto v = m_body->GetLinearVelocity();
    auto speed = v.Length();
    m_vel = Eigen::Vector2f { 1.0f, 0 };
    changeDirection(direction);
    m_vel *= speed;
    */
}

void GameObject::changeDirection(float delta) {
    //auto v = m_body->GetLinearVelocity();

}

const b2Vec2& GameObject::getPosition() const {
    return m_body->GetPosition();
}

const b2Vec2& GameObject::getVelocity() const {
    return m_body->GetLinearVelocity();
}

float GameObject::getSpeed() const {
    auto vel = m_body->GetLinearVelocity();
    return vel.Length();
}

float GameObject::getDirection() const {
    auto v = m_body->GetLinearVelocity();
    auto d = std::atan2(v.y, v.x);
    return CC_RADIANS_TO_DEGREES(d);
}

bool GameObject::isDead() const {
    return m_dead;
}

void GameObject::setDead() {
    m_dead = true;
}

void GameObject::setDead(bool dead) {
    m_dead = dead;
}

int GameObject::getCollisionClass() const {
    return m_collisionClass;
}

void GameObject::setCollisionClass(int klass) {
    m_collisionClass = klass;
}

uint32_t GameObject::getCollisionMask() const {
    return m_collisionMask;
}

void GameObject::setCollisionMask(uint32_t mask) {
    m_collisionMask = mask;
}

void GameObject::enableCollisionsWith(int klass) {
    m_collisionMask |= (uint32_t(1) << klass);
}

bool GameObject::canCollideWith(int klass) const {
    if (klass == -1) {
        return false;
    }
    return (m_collisionMask >> klass) & 1;
}

bool GameObject::canCollideWith(GameObjectPtr &obj) const {
    int cc = obj->getCollisionClass();
    return canCollideWith(cc);
}

void GameObject::onCollision(GameObjectPtr &obj) {
}

void GameObject::setIdxInScene(int idx) {
    m_idxInScene = idx;
}

int GameObject::getIdxInScene() const {
    return m_idxInScene;
}

size_t GameObject::writeTypeInfoBytes(bytes_t& buf) {
    size_t nb = 0;
    nb += dx_write_bytes<GameObjectType>(buf, GameObjectType::GENERIC);
    nb += dx_write_bytes<std::string>(buf, m_objDesc->getLabel());
    return nb;
}

size_t GameObject::writeStateBytes(bytes_t &buf, state_mask_t state) {
    auto pos = m_body->GetPosition();
    std::cout << __func__ << " pos.x=" << pos.x << " pos.y=" << pos.y << std::endl;
    dx_write_bytes<b2Vec2>(buf, m_body->GetPosition());
    dx_write_bytes<b2Vec2>(buf, m_body->GetLinearVelocity());
    dx_write_bytes<float>(buf, m_body->GetAngle());
    dx_write_bytes<float>(buf, m_body->GetAngularVelocity());
}

state_mask_t GameObject::getFullStateMask() const {
    return 0xFFFFFFFF;
}

net_id_t GameObject::getNetId() const {
    return m_netId;
}

void GameObject::setNetId(net_id_t id) {
    m_netId = id;
}

void GameObject::setBody(b2Body* b) {
    m_body = b;
}

b2Body* GameObject::getBody() {
    return m_body;
}
