#include "ActionDesc.h"
#include "../objects/ObjectManager.h"

ActionPtr ActionDesc::createFromActions(
        const std::string& label,
        const std::vector<GameActionDescPtr*>& actions) {

}

ActionPtr ActionDesc::getAction() {
    std::vector<ActionPtr> currSpawn;
    std::vector<ActionPtr> seq;
    for (const GameActionDescPtr& ga : m_actions) {
        ActionPtr action = ga->getAction();
        if (!action) {
            std::cerr << "internal action is null" << std::endl;
            //cocos2d::log("internal action is null");
            return nullptr;
        }
        currSpawn.push_back(action);
        if (ga->getType() == GameActionType::WAIT) {
            auto spawn = Spawn::create(currSpawn);
            seq.push_back(spawn);
            currSpawn.clear();
        }
    }
    if (!currSpawn.empty()) {
        auto spawn = Spawn::create(currSpawn);
        seq.push_back(spawn);
    }
    auto actionSeq = Sequence::create(seq);
    if (!actionSeq) {
        //cocos2d::log("'ActionDesc' generates null action sequence");
        return nullptr;
    }
    return actionSeq;
}

const std::string& ActionDesc::getLabel() const {
    return m_label;
}

void ActionDesc::setLabel(const std::string& label) {
    m_label = label;
}

bool ActionDesc::initFromJson(const rapidjson::Value& el) {
    DX_DESC_GET_MEMBER(el, string, label);
    DX_DESC_GET_VEC(el, GameActionDesc, actions, m_actions);
    return true;
}

bool ActionDesc::initFromLua(lua_State* L, int idx) {
    DX_LUA_DESC_GET_MEMBER(L, idx, string, label);
    DX_LUA_DESC_GET_VEC(L, idx, GameActionDesc, actions, m_actions);
    return true;
}

ActionPtr ActionRefDesc::getAction() {
    return CallFuncN::create([=](GameObject* tgt) {
        auto objMgr = ObjectManager::getInstance();
        auto actionDesc = objMgr->getActionDesc(m_label);
        auto inner = actionDesc->getAction();
        tgt->runAction(inner);
    });
}

const std::string& ActionRefDesc::getLabel() const {
    return m_label;
}

void ActionRefDesc::setLabel(const std::string& label) {
    m_label = label;
}

bool ActionRefDesc::initFromJson(const rapidjson::Value& el) {
    DX_DESC_GET_MEMBER(el, string, label);
    return true;
}

bool ActionRefDesc::initFromLua(lua_State* L, int idx) {
    DX_LUA_DESC_GET_MEMBER(L, idx, string, label);
    return true;
}

