#ifndef __DX_PLAYEROBJECT_H__
#define __DX_PLAYEROBJECT_H__

#include "Vehicle.h"
#include "../ClientProxy.h"
#include "../desc/PlayerDesc.h"

class PlayerObject : public Vehicle {
public:
    static GameObjectPtr createFromDesc(const PlayerDescPtr& desc);
    virtual size_t writeTypeInfoBytes(bytes_t& buf);
    void update(float dt);
    void setClient(ClientProxyPtr client);
protected:
    bool initFromDesc(const PlayerDescPtr& desc);
    PlayerDescPtr m_playerDesc;
private:
    void fire();
    float m_lastProcessedInput = 0;
    float m_prevInputDelta = 0;
    ClientProxyPtr m_client;
    size_t m_currWeaponIdx = 0;
    InputPacket* m_inputPacket = nullptr;
    float m_error = 0;
    //std::vector<Action*> m_fireActions;
};
typedef std::shared_ptr<PlayerObject> PlayerObjectPtr;

#endif /* __DX_PLAYEROBJECT_H__ */
