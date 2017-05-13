#include "ReplicationCommand.h"

ReplicaCommand::ReplicaCommand()
{}

ReplicaCommand::ReplicaCommand(state_mask_t dirtyState) :
    m_action(ReplicaActionType::CREATE),
    m_dirtyState(dirtyState)
{}

void ReplicaCommand::addDirtyState(state_mask_t dirtyState) {
    m_dirtyState |= dirtyState;
}

bool ReplicaCommand::hasDirtyState() const {
    return m_action == ReplicaActionType::DESTROY || m_dirtyState != 0;
}

ReplicaActionType ReplicaCommand::getActionType() const {
    return m_action;
}

state_mask_t ReplicaCommand::getDirtyState() const {
    return m_dirtyState;
}

void ReplicaCommand::clearDirtyState(state_mask_t stateToClear) {
    m_dirtyState &= ~stateToClear;
    if (m_action == ReplicaActionType::DESTROY) {
        m_action = ReplicaActionType::UPDATE;
    }
}

void ReplicaCommand::handleCreateAckd() {
    if (m_action == ReplicaActionType::CREATE) {
        m_action = ReplicaActionType::UPDATE;
    }
}

void ReplicaCommand::setDestroy() {
    m_action = ReplicaActionType::DESTROY;
}
