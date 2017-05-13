#ifndef __DX_ACTIONDESC_H__
#define __DX_ACTIONDESC_H__

#include "GameActionDesc.h"

class ActionDesc : public GameActionDesc {
public:
    static ActionPtr createFromActions(const std::string& label,
        const std::vector<GameActionDescPtr*>& actions);
    DX_CREATE_FROM_JSON_FUNC(GameActionDescPtr, ActionDesc)
    DX_CREATE_FROM_LUA_FUNC(GameActionDescPtr, ActionDesc)
    ActionPtr getAction();
    const std::string& getLabel() const;
    void setLabel(const std::string& label);
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
    std::string m_label;
    std::vector<GameActionDescPtr> m_actions;
};
typedef std::shared_ptr<ActionDesc> ActionDescPtr;

class ActionRefDesc : public GameActionDesc {
public:
    DX_CREATE_FROM_JSON_FUNC(GameActionDescPtr, ActionRefDesc)
    DX_CREATE_FROM_LUA_FUNC(GameActionDescPtr, ActionRefDesc)
    ActionPtr getAction();
    const std::string& getLabel() const;
    void setLabel(const std::string& label);
protected:
    bool initFromJson(const rapidjson::Value& el);
    bool initFromLua(lua_State* L, int idx);
    std::string m_label;
};

#endif /* __DX_ACTIONDESC_H__ */
