#include "lua_dxserver_manual.h"
#include "auto/lua_dxserver_auto.hpp"
#include "../data/LuaParser.h"
#include "../desc/VehicleDesc.h"
#include "../desc/BulletDesc.h"
#include "../desc/PlayerDesc.h"
#include "../desc/GameObjectDesc.h"
#include "../behaviours/ActionDescs.h"

#define DX_LUA_CREATE_FROM_TABLE(klass) \
static int lua_dxserver_##klass##_create(lua_State* L) { \
    if (nullptr == L) \
        return 0; \
    int argc = 0; \
    tolua_Error tolua_err; \
    if (!tolua_isusertable(L,1,#klass,0,&tolua_err)) { \
        goto tolua_lerror; \
    } \
    argc = lua_gettop(L) - 1; \
    if (argc == 1) { \
        if (!toluafix_istable(L,2,"",0,&tolua_err)) { \
            goto tolua_lerror; \
        } \
        auto tolua_ret = klass::fromLua(L, 2); \
        std::cerr << "create: tolua_ret " << tolua_ret << std::endl; \
        dx_lua_push(L, tolua_ret); \
        return 1; \
    } \
    luaL_error(L, "'create' function of "#klass" has wrong number of arguments: %d, was expecting %d\n", argc, 1); \
    return 0; \
tolua_lerror: \
    tolua_error(L,"#ferror in function 'create'.",&tolua_err); \
    return 0; \
}

#define DX_FOR_EACH_DESC_CLASS() \
    PROCESS_DESC_CLASS(PlayerDesc) \
    PROCESS_DESC_CLASS(VehicleDesc) \
    PROCESS_DESC_CLASS(RepeatDesc) \
    PROCESS_DESC_CLASS(PlaceObjectDesc) \
    PROCESS_DESC_CLASS(PlaceVehicleDesc) \
    PROCESS_DESC_CLASS(FireBulletDesc) \
    PROCESS_DESC_CLASS(PlaceObjectRefDesc) \
    PROCESS_DESC_CLASS(PlaceVehicleRefDesc) \
    PROCESS_DESC_CLASS(FireBulletRefDesc) \
    PROCESS_DESC_CLASS(ChangeSpeedDesc) \
    PROCESS_DESC_CLASS(ChangeDirectionDesc) \
    PROCESS_DESC_CLASS(AccelDesc) \
    PROCESS_DESC_CLASS(VanishDesc) \
    PROCESS_DESC_CLASS(WaitDesc)

#define PROCESS_DESC_CLASS(klass) DX_LUA_CREATE_FROM_TABLE(klass)
    DX_FOR_EACH_DESC_CLASS()
#undef PROCESS_DESC_CLASS

#define DX_LUA_EXTEND_DESC(klass) \
static void extend##klass(lua_State* L) { \
    lua_pushstring(L, #klass); \
    lua_rawget(L, LUA_REGISTRYINDEX); \
    if (lua_istable(L,-1)) { \
        lua_pushstring(L, "create"); \
        lua_pushcfunction(L, lua_dxserver_##klass##_create); \
        lua_rawset(L,-3); \
    } \
    lua_pop(L, 1); \
}

#define PROCESS_DESC_CLASS(klass) DX_LUA_EXTEND_DESC(klass)
    DX_FOR_EACH_DESC_CLASS()
#undef PROCESS_DESC_CLASS

int register_all_dxserver_manual(lua_State* L) {
    if (nullptr == L)
        return 0;
#define PROCESS_DESC_CLASS(klass) extend##klass(L);
    DX_FOR_EACH_DESC_CLASS()
#undef PROCESS_DESC_CLASS
    return 0;
}

int register_dxserver_module(lua_State* L)
{
    lua_getglobal(L, "_G");
    if (lua_istable(L,-1))//stack:...,_G,
    {
        register_all_dxserver(L);
        register_all_dxserver_manual(L);
    }
    lua_pop(L, 1);
    return 1;
}
