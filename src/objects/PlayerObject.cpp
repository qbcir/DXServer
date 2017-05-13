#include "PlayerObject.h"

GameObjectPtr PlayerObject::createFromDesc(const PlayerDescPtr& desc) {
    auto po = new (std::nothrow) PlayerObject();
    if (po && po->initFromDesc(desc)) {
        return GameObjectPtr(po);
    }
    if (po) delete po;
    return nullptr;
}

bool PlayerObject::initFromDesc(const PlayerDescPtr& desc) {
    auto& vehicleDesc = desc->getVehicleDesc();
    //CCASSERT(vehicleDesc != nullptr, "PlayerDesc.getVehicleDesc() == nullptr");
    if (!vehicleDesc) {
        return false;
    }
    if (!Vehicle::initFromDesc(vehicleDesc)) {
        return false;
    }
    m_playerDesc = desc;
    /*
    this->setCollisionMask(0);
    this->setCollisionClass(COLLISION_CLASS_PLAYER);
    this->enableCollisionsWith(COLLISION_CLASS_ENEMY_BULLET);
    this->enableCollisionsWith(COLLISION_CLASS_ENEMY);
    auto& weapons = m_playerDesc->getWeapons();
    for (auto i = 0; i < weapons.size(); i++) {
        m_weaponActionDescs.pushBack(weapons.at(i)->getActionDesc());
        m_fireActions.push_back(nullptr);
    }
    */
    return true;
}

size_t PlayerObject::writeTypeInfoBytes(bytes_t& buf) {
    size_t nb = 0;
    nb += dx_write_bytes<GameObjectType>(buf, GameObjectType::PLAYER);
    nb += dx_write_bytes<std::string>(buf, m_playerDesc->getLabel());
    return nb;
}

const float DIRECTION_N_ANGLE = 0;
static const std::vector<float> direction2angle {
    CC_DEGREES_TO_RADIANS(DIRECTION_N_ANGLE),       // N
    CC_DEGREES_TO_RADIANS(DIRECTION_N_ANGLE - 180), // S
    CC_DEGREES_TO_RADIANS(DIRECTION_N_ANGLE - 90),  // E
    CC_DEGREES_TO_RADIANS(DIRECTION_N_ANGLE + 90),  // W
    CC_DEGREES_TO_RADIANS(DIRECTION_N_ANGLE - 45),  // NE
    CC_DEGREES_TO_RADIANS(DIRECTION_N_ANGLE + 45),  // NW
    CC_DEGREES_TO_RADIANS(DIRECTION_N_ANGLE - 135), // SE
    CC_DEGREES_TO_RADIANS(DIRECTION_N_ANGLE + 135)  // SW
};

void PlayerObject::update(float dt) {
    InputPacketList& uipl = m_client->getInputPacketList();
    auto& inputPackets = uipl.getInputPackets();
    if (m_inputPacket) {
        m_prevInputDelta -= dt;
        if (m_prevInputDelta <= 0) {
            m_error += -m_prevInputDelta;
            uipl.setLastInputTimestamp(m_inputPacket->timestamp);
            inputPackets.pop_front();
            m_inputPacket = nullptr;
            std::cout << " rot=" << CC_RADIANS_TO_DEGREES(m_body->GetAngle()) << std::endl;
        } else {
            return;
        }
    }
    if (!m_inputPacket) {
        if (inputPackets.empty()) {
            return;
        }
        auto& inputPacket = inputPackets.front();
        m_inputPacket = &inputPacket;
        m_prevInputDelta = inputPacket.delta;
        m_prevInputDelta -= m_error;
        m_error = 0;
        std::cout << inputPackets.size() << " processing " << inputPacket.timestamp
                  << " m_prevInputDelta=" << inputPacket.delta << std::endl;
        float currRot = m_body->GetAngle();
        float angVel = 0;
        if (inputPacket.isKeyPressed(InputKey::LEFT)) {
            angVel = -20;
        } else if (inputPacket.isKeyPressed(InputKey::RIGHT)) {
            angVel = 20;
        }
        setAngVelocity(CC_DEGREES_TO_RADIANS(angVel));
        b2Vec2 speed {0.f, 30.f};
        b2Rot t(-currRot);
        if (inputPacket.isKeyPressed(InputKey::UP)) {
            speed.y = -30.f;
        } else if (inputPacket.isKeyPressed(InputKey::DOWN)) {
            speed.y = 30.f;
        } else {
            speed.y = 0.f;
        }
        setVelocity(b2Mul(t, speed));
    }
}

void PlayerObject::setClient(ClientProxyPtr client) {
    m_client = client;
}

void PlayerObject::fire() {
    /*
    auto currFireAction = m_fireActions.at(m_currWeaponIdx);
    if (!currFireAction || currFireAction->isDone()) {
        auto fireAction = m_weaponActionDescs.at(m_currWeaponIdx)->getAction();
        fireAction->retain();
        if (m_fireActions.at(m_currWeaponIdx)) {
            m_fireActions.at(m_currWeaponIdx)->release();
        }
        m_fireActions.at(m_currWeaponIdx) = fireAction;
        runAction(fireAction);
    }
    */
}
