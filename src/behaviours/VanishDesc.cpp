#include "VanishDesc.h"
#include "Action.h"
#include "GameObject.h"

ActionPtr VanishDesc::getAction() {
    return CallFuncN::create([](GameObject* tgt) {
        tgt->setDead(true);
    });
}

bool VanishDesc::initFromJson(const rapidjson::Value& el) {
    return true;
}

bool VanishDesc::initFromLua(lua_State* L, int idx) {
    return true;
}
