#ifndef __DX_GAMEACTIONDESC_H__
#define __DX_GAMEACTIONDESC_H__

#include "../scripting/LuaRef.h"
#include "../data/DataParser.h"
#include "Action.h"
#include <string>
#include <memory>

#define DX_ENABLE_IF_GAME_ACTION_DESC_SUBCLASS(T) \
    typename std::enable_if<std::is_base_of<GameActionDesc, T>::value, T>::type* = nullptr

enum class GameActionType {
    ACTION,
    ACTIONREF,
    FIRE,
    FIREREF,
    CHANGE_SPEED,
    CHANGE_DIRECTION,
    ACCEL,
    VANISH,
    WAIT,
    REPEAT,
    FOREVER,
    WHILE,
    INVALID = -1
};

class GameActionDesc : public LuaRef {
public:
    typedef std::shared_ptr<GameActionDesc> GameActionDescPtr;
    virtual ~GameActionDesc() {}
    virtual ActionPtr getAction() = 0;
    template<typename T, DX_ENABLE_IF_GAME_ACTION_DESC_SUBCLASS(T)>
    static GameActionDescPtr create(const rapidjson::Value& el) {
        return T::fromJson(el);
    }
    template<typename T, DX_ENABLE_IF_GAME_ACTION_DESC_SUBCLASS(T)>
    static GameActionDescPtr create(lua_State* L, int idx) {
        return T::fromLua(L, idx);
    }
    typedef GameActionDescPtr (*GameActionCreator)(const rapidjson::Value& el);
    typedef std::unordered_map<std::string, GameActionCreator> GameActionCreatorMapT;
    typedef GameActionDescPtr (*GameActionCreatorLua)(lua_State* L, int idx);
    typedef std::unordered_map<std::string, GameActionCreatorLua> GameActionCreatorLuaMapT;
    static GameActionCreatorMapT GameActionCreatorMap;
    static GameActionCreatorLuaMapT GameActionCreatorLuaMap;
    static GameActionDescPtr fromLua(const std::string& filename);
    static GameActionDescPtr fromLua(lua_State* L, int idx);
    static GameActionDescPtr fromJson(const rapidjson::Value& el);
    GameActionType getType() const;
    void setType(GameActionType type);
protected:
    GameActionType m_type;
};
typedef GameActionDesc::GameActionDescPtr GameActionDescPtr;

#endif /* __DX_GAMEACTIONDESC_H__ */
