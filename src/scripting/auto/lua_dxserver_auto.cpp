#include "lua_dxserver_auto.hpp"
#include "GameServer.h"
#include "Scene.h"
#include "FileUtils.h"
#include "ObjectManager.h"
#include "Objects.h"
#include "ActionDescs.h"
#include "LuaParser.h"


static int lua_dxserver_ScriptComponentDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ScriptComponentDesc)\n");
    return 0;
}

int lua_register_dxserver_ScriptComponentDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ScriptComponentDesc");
    tolua_cclass(tolua_S,"ScriptComponentDesc","ScriptComponentDesc","",nullptr);

    tolua_beginmodule(tolua_S,"ScriptComponentDesc");
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_GameObjectDesc_getAutoUpdateDirection(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObjectDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObjectDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObjectDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObjectDesc_getAutoUpdateDirection'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObjectDesc_getAutoUpdateDirection'", nullptr);
            return 0;
        }
        bool ret = cobj->getAutoUpdateDirection();
        dx_lua_push<bool>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObjectDesc:getAutoUpdateDirection",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObjectDesc_getAutoUpdateDirection'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObjectDesc_getComponentDescs(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObjectDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObjectDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObjectDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObjectDesc_getComponentDescs'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObjectDesc_getComponentDescs'", nullptr);
            return 0;
        }
        const std::vector<ScriptComponentDesc, std::allocator<ScriptComponentDesc> >& ret = cobj->getComponentDescs();
        dx_lua_push<std::vector<ScriptComponentDesc, std::allocator<ScriptComponentDesc> >>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObjectDesc:getComponentDescs",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObjectDesc_getComponentDescs'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObjectDesc_getMaxRotation(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObjectDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObjectDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObjectDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObjectDesc_getMaxRotation'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObjectDesc_getMaxRotation'", nullptr);
            return 0;
        }
        float ret = cobj->getMaxRotation();
        dx_lua_push<float>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObjectDesc:getMaxRotation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObjectDesc_getMaxRotation'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObjectDesc_hasMaxSpeed(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObjectDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObjectDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObjectDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObjectDesc_hasMaxSpeed'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObjectDesc_hasMaxSpeed'", nullptr);
            return 0;
        }
        bool ret = cobj->hasMaxSpeed();
        dx_lua_push<bool>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObjectDesc:hasMaxSpeed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObjectDesc_hasMaxSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObjectDesc_hasMaxRotation(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObjectDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObjectDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObjectDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObjectDesc_hasMaxRotation'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObjectDesc_hasMaxRotation'", nullptr);
            return 0;
        }
        bool ret = cobj->hasMaxRotation();
        dx_lua_push<bool>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObjectDesc:hasMaxRotation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObjectDesc_hasMaxRotation'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObjectDesc_hasMaxAngularAccel(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObjectDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObjectDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObjectDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObjectDesc_hasMaxAngularAccel'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObjectDesc_hasMaxAngularAccel'", nullptr);
            return 0;
        }
        bool ret = cobj->hasMaxAngularAccel();
        dx_lua_push<bool>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObjectDesc:hasMaxAngularAccel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObjectDesc_hasMaxAngularAccel'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObjectDesc_getMaxSpeed(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObjectDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObjectDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObjectDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObjectDesc_getMaxSpeed'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObjectDesc_getMaxSpeed'", nullptr);
            return 0;
        }
        float ret = cobj->getMaxSpeed();
        dx_lua_push<float>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObjectDesc:getMaxSpeed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObjectDesc_getMaxSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObjectDesc_getLabel(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObjectDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObjectDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObjectDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObjectDesc_getLabel'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObjectDesc_getLabel'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getLabel();
        dx_lua_push<std::string>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObjectDesc:getLabel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObjectDesc_getLabel'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObjectDesc_getMaxAngularAccel(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObjectDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObjectDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObjectDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObjectDesc_getMaxAngularAccel'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObjectDesc_getMaxAngularAccel'", nullptr);
            return 0;
        }
        float ret = cobj->getMaxAngularAccel();
        dx_lua_push<float>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObjectDesc:getMaxAngularAccel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObjectDesc_getMaxAngularAccel'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObjectDesc_getSpriteDesc(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObjectDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObjectDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObjectDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObjectDesc_getSpriteDesc'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObjectDesc_getSpriteDesc'", nullptr);
            return 0;
        }
        const SpriteDesc& ret = cobj->getSpriteDesc();
        dx_lua_push<SpriteDesc>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObjectDesc:getSpriteDesc",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObjectDesc_getSpriteDesc'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_GameObjectDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameObjectDesc)\n");
    auto ptr = (std::shared_ptr<GameObjectDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_GameObjectDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"GameObjectDesc");
    tolua_cclass(tolua_S,"GameObjectDesc","GameObjectDesc","LuaRef",lua_dxserver_GameObjectDesc_finalize);

    tolua_beginmodule(tolua_S,"GameObjectDesc");
        tolua_function(tolua_S,"getAutoUpdateDirection",lua_dxserver_GameObjectDesc_getAutoUpdateDirection);
        tolua_function(tolua_S,"getComponentDescs",lua_dxserver_GameObjectDesc_getComponentDescs);
        tolua_function(tolua_S,"getMaxRotation",lua_dxserver_GameObjectDesc_getMaxRotation);
        tolua_function(tolua_S,"hasMaxSpeed",lua_dxserver_GameObjectDesc_hasMaxSpeed);
        tolua_function(tolua_S,"hasMaxRotation",lua_dxserver_GameObjectDesc_hasMaxRotation);
        tolua_function(tolua_S,"hasMaxAngularAccel",lua_dxserver_GameObjectDesc_hasMaxAngularAccel);
        tolua_function(tolua_S,"getMaxSpeed",lua_dxserver_GameObjectDesc_getMaxSpeed);
        tolua_function(tolua_S,"getLabel",lua_dxserver_GameObjectDesc_getLabel);
        tolua_function(tolua_S,"getMaxAngularAccel",lua_dxserver_GameObjectDesc_getMaxAngularAccel);
        tolua_function(tolua_S,"getSpriteDesc",lua_dxserver_GameObjectDesc_getSpriteDesc);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_GameObject_canCollideWith(lua_State* tolua_S)
{
    int argc = 0;
    GameObject* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GameObject*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_canCollideWith'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            std::shared_ptr<GameObject> arg0;
            ok &= dx_luaval_to_native<std::shared_ptr<GameObject>>(tolua_S, 2, &arg0);

            if (!ok) { break; }
            bool ret = cobj->canCollideWith(arg0);
            dx_lua_push<bool>(tolua_S, ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            int arg0;
            ok &= dx_luaval_to_native<int>(tolua_S, 2, &arg0);

            if (!ok) { break; }
            bool ret = cobj->canCollideWith(arg0);
            dx_lua_push<bool>(tolua_S, ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "GameObject:canCollideWith",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_canCollideWith'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_getDirection(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_getDirection'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_getDirection'", nullptr);
            return 0;
        }
        float ret = cobj->getDirection();
        dx_lua_push<float>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:getDirection",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_getDirection'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_setCollisionMask(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_setCollisionMask'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        unsigned int arg0;

        ok &= dx_luaval_to_native<unsigned int>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_setCollisionMask'", nullptr);
            return 0;
        }
        cobj->setCollisionMask(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:setCollisionMask",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_setCollisionMask'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_onCollision(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_onCollision'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::shared_ptr<GameObject> arg0;

        ok &= dx_luaval_to_native<std::shared_ptr<GameObject>>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_onCollision'", nullptr);
            return 0;
        }
        cobj->onCollision(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:onCollision",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_onCollision'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_setVelocity(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_setVelocity'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        b2Vec2 arg0;

        ok &= dx_luaval_to_native<b2Vec2>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_setVelocity'", nullptr);
            return 0;
        }
        cobj->setVelocity(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:setVelocity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_setVelocity'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_setAccel(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_setAccel'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        b2Vec2 arg0;

        ok &= dx_luaval_to_native<b2Vec2>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_setAccel'", nullptr);
            return 0;
        }
        cobj->setAccel(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:setAccel",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_setAccel'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_setCollisionClass(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_setCollisionClass'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        int arg0;

        ok &= dx_luaval_to_native<int>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_setCollisionClass'", nullptr);
            return 0;
        }
        cobj->setCollisionClass(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:setCollisionClass",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_setCollisionClass'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_enableCollisionsWith(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_enableCollisionsWith'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        int arg0;

        ok &= dx_luaval_to_native<int>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_enableCollisionsWith'", nullptr);
            return 0;
        }
        cobj->enableCollisionsWith(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:enableCollisionsWith",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_enableCollisionsWith'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_getVelocity(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_getVelocity'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_getVelocity'", nullptr);
            return 0;
        }
        const b2Vec2& ret = cobj->getVelocity();
        dx_lua_push<b2Vec2>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:getVelocity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_getVelocity'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_setDirection(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_setDirection'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        float arg0;

        ok &= dx_luaval_to_native<float>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_setDirection'", nullptr);
            return 0;
        }
        cobj->setDirection(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:setDirection",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_setDirection'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_setNetId(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_setNetId'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        unsigned long long arg0;

        ok &= dx_luaval_to_native<unsigned long long>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_setNetId'", nullptr);
            return 0;
        }
        cobj->setNetId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:setNetId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_setNetId'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_isDead(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_isDead'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_isDead'", nullptr);
            return 0;
        }
        bool ret = cobj->isDead();
        dx_lua_push<bool>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:isDead",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_isDead'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_writeStateBytes(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_writeStateBytes'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) {
        std::vector<unsigned char, std::allocator<unsigned char> > arg0;
        unsigned int arg1;

        ok &= dx_luaval_to_native<std::vector<unsigned char, std::allocator<unsigned char> >>(tolua_S, 2, &arg0);

        ok &= dx_luaval_to_native<unsigned int>(tolua_S, 3, &arg1);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_writeStateBytes'", nullptr);
            return 0;
        }
        unsigned long ret = cobj->writeStateBytes(arg0, arg1);
        dx_lua_push<unsigned long>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:writeStateBytes",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_writeStateBytes'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_setIdxInScene(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_setIdxInScene'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        int arg0;

        ok &= dx_luaval_to_native<int>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_setIdxInScene'", nullptr);
            return 0;
        }
        cobj->setIdxInScene(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:setIdxInScene",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_setIdxInScene'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_getCollisionMask(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_getCollisionMask'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_getCollisionMask'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getCollisionMask();
        dx_lua_push<unsigned int>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:getCollisionMask",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_getCollisionMask'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_update(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_update'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        float arg0;

        ok &= dx_luaval_to_native<float>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_update'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_getFullStateMask(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_getFullStateMask'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_getFullStateMask'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getFullStateMask();
        dx_lua_push<unsigned int>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:getFullStateMask",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_getFullStateMask'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_setPosition(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_setPosition'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        b2Vec2 arg0;

        ok &= dx_luaval_to_native<b2Vec2>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_setPosition'", nullptr);
            return 0;
        }
        cobj->setPosition(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:setPosition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_setPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_changeDirection(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_changeDirection'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        float arg0;

        ok &= dx_luaval_to_native<float>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_changeDirection'", nullptr);
            return 0;
        }
        cobj->changeDirection(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:changeDirection",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_changeDirection'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_getPosition(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_getPosition'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_getPosition'", nullptr);
            return 0;
        }
        const b2Vec2& ret = cobj->getPosition();
        dx_lua_push<b2Vec2>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:getPosition",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_getPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_getSpeed(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_getSpeed'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_getSpeed'", nullptr);
            return 0;
        }
        float ret = cobj->getSpeed();
        dx_lua_push<float>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:getSpeed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_getSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_applyAccel(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_applyAccel'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        b2Vec2 arg0;

        ok &= dx_luaval_to_native<b2Vec2>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_applyAccel'", nullptr);
            return 0;
        }
        cobj->applyAccel(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:applyAccel",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_applyAccel'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_setDead(lua_State* tolua_S)
{
    int argc = 0;
    GameObject* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GameObject*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_setDead'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            bool arg0;
            ok &= dx_luaval_to_native<bool>(tolua_S, 2, &arg0);

            if (!ok) { break; }
            cobj->setDead(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj->setDead();
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "GameObject:setDead",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_setDead'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_writeTypeInfoBytes(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_writeTypeInfoBytes'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::vector<unsigned char, std::allocator<unsigned char> > arg0;

        ok &= dx_luaval_to_native<std::vector<unsigned char, std::allocator<unsigned char> >>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_writeTypeInfoBytes'", nullptr);
            return 0;
        }
        unsigned long ret = cobj->writeTypeInfoBytes(arg0);
        dx_lua_push<unsigned long>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:writeTypeInfoBytes",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_writeTypeInfoBytes'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_setSpeed(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_setSpeed'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        float arg0;

        ok &= dx_luaval_to_native<float>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_setSpeed'", nullptr);
            return 0;
        }
        cobj->setSpeed(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:setSpeed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_setSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_getCollisionClass(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_getCollisionClass'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_getCollisionClass'", nullptr);
            return 0;
        }
        int ret = cobj->getCollisionClass();
        dx_lua_push<int>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:getCollisionClass",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_getCollisionClass'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_getNetId(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_getNetId'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_getNetId'", nullptr);
            return 0;
        }
        unsigned long long ret = cobj->getNetId();
        dx_lua_push<unsigned long long>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:getNetId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_getNetId'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_getIdxInScene(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_getIdxInScene'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_getIdxInScene'", nullptr);
            return 0;
        }
        int ret = cobj->getIdxInScene();
        dx_lua_push<int>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:getIdxInScene",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_getIdxInScene'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_setAngVelocity(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameObject_setAngVelocity'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        float arg0;

        ok &= dx_luaval_to_native<float>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_setAngVelocity'", nullptr);
            return 0;
        }
        cobj->setAngVelocity(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameObject:setAngVelocity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_setAngVelocity'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameObject_createFromDesc(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameObject",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::shared_ptr<GameObjectDesc> arg0;
        ok &= dx_luaval_to_native<std::shared_ptr<GameObjectDesc>>(tolua_S, 2, &arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameObject_createFromDesc'", nullptr);
            return 0;
        }
        std::shared_ptr<GameObject> ret = GameObject::createFromDesc(arg0);
        dx_lua_push<std::shared_ptr<GameObject>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GameObject:createFromDesc",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameObject_createFromDesc'.",&tolua_err);
#endif
    return 0;
}
static int lua_dxserver_GameObject_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameObject)\n");
    auto ptr = (std::shared_ptr<GameObject>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_GameObject(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"GameObject");
    tolua_cclass(tolua_S,"GameObject","GameObject","LuaRef",lua_dxserver_GameObject_finalize);

    tolua_beginmodule(tolua_S,"GameObject");
        tolua_function(tolua_S,"canCollideWith",lua_dxserver_GameObject_canCollideWith);
        tolua_function(tolua_S,"getDirection",lua_dxserver_GameObject_getDirection);
        tolua_function(tolua_S,"setCollisionMask",lua_dxserver_GameObject_setCollisionMask);
        tolua_function(tolua_S,"onCollision",lua_dxserver_GameObject_onCollision);
        tolua_function(tolua_S,"setVelocity",lua_dxserver_GameObject_setVelocity);
        tolua_function(tolua_S,"setAccel",lua_dxserver_GameObject_setAccel);
        tolua_function(tolua_S,"setCollisionClass",lua_dxserver_GameObject_setCollisionClass);
        tolua_function(tolua_S,"enableCollisionsWith",lua_dxserver_GameObject_enableCollisionsWith);
        tolua_function(tolua_S,"getVelocity",lua_dxserver_GameObject_getVelocity);
        tolua_function(tolua_S,"setDirection",lua_dxserver_GameObject_setDirection);
        tolua_function(tolua_S,"setNetId",lua_dxserver_GameObject_setNetId);
        tolua_function(tolua_S,"isDead",lua_dxserver_GameObject_isDead);
        tolua_function(tolua_S,"writeStateBytes",lua_dxserver_GameObject_writeStateBytes);
        tolua_function(tolua_S,"setIdxInScene",lua_dxserver_GameObject_setIdxInScene);
        tolua_function(tolua_S,"getCollisionMask",lua_dxserver_GameObject_getCollisionMask);
        tolua_function(tolua_S,"update",lua_dxserver_GameObject_update);
        tolua_function(tolua_S,"getFullStateMask",lua_dxserver_GameObject_getFullStateMask);
        tolua_function(tolua_S,"setPosition",lua_dxserver_GameObject_setPosition);
        tolua_function(tolua_S,"changeDirection",lua_dxserver_GameObject_changeDirection);
        tolua_function(tolua_S,"getPosition",lua_dxserver_GameObject_getPosition);
        tolua_function(tolua_S,"getSpeed",lua_dxserver_GameObject_getSpeed);
        tolua_function(tolua_S,"applyAccel",lua_dxserver_GameObject_applyAccel);
        tolua_function(tolua_S,"setDead",lua_dxserver_GameObject_setDead);
        tolua_function(tolua_S,"writeTypeInfoBytes",lua_dxserver_GameObject_writeTypeInfoBytes);
        tolua_function(tolua_S,"setSpeed",lua_dxserver_GameObject_setSpeed);
        tolua_function(tolua_S,"getCollisionClass",lua_dxserver_GameObject_getCollisionClass);
        tolua_function(tolua_S,"getNetId",lua_dxserver_GameObject_getNetId);
        tolua_function(tolua_S,"getIdxInScene",lua_dxserver_GameObject_getIdxInScene);
        tolua_function(tolua_S,"setAngVelocity",lua_dxserver_GameObject_setAngVelocity);
        tolua_function(tolua_S,"createFromDesc", lua_dxserver_GameObject_createFromDesc);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_VehicleDesc_getDamage(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<VehicleDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"VehicleDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<VehicleDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_VehicleDesc_getDamage'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_VehicleDesc_getDamage'", nullptr);
            return 0;
        }
        float ret = cobj->getDamage();
        dx_lua_push<float>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "VehicleDesc:getDamage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_VehicleDesc_getDamage'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_VehicleDesc_getHealth(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<VehicleDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"VehicleDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<VehicleDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_VehicleDesc_getHealth'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_VehicleDesc_getHealth'", nullptr);
            return 0;
        }
        float ret = cobj->getHealth();
        dx_lua_push<float>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "VehicleDesc:getHealth",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_VehicleDesc_getHealth'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_VehicleDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (VehicleDesc)\n");
    auto ptr = (std::shared_ptr<VehicleDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_VehicleDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"VehicleDesc");
    tolua_cclass(tolua_S,"VehicleDesc","VehicleDesc","GameObjectDesc",lua_dxserver_VehicleDesc_finalize);

    tolua_beginmodule(tolua_S,"VehicleDesc");
        tolua_function(tolua_S,"getDamage",lua_dxserver_VehicleDesc_getDamage);
        tolua_function(tolua_S,"getHealth",lua_dxserver_VehicleDesc_getHealth);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_Vehicle_writeTypeInfoBytes(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<Vehicle> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Vehicle",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<Vehicle>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_Vehicle_writeTypeInfoBytes'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::vector<unsigned char, std::allocator<unsigned char> > arg0;

        ok &= dx_luaval_to_native<std::vector<unsigned char, std::allocator<unsigned char> >>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_Vehicle_writeTypeInfoBytes'", nullptr);
            return 0;
        }
        unsigned long ret = cobj->writeTypeInfoBytes(arg0);
        dx_lua_push<unsigned long>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Vehicle:writeTypeInfoBytes",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_Vehicle_writeTypeInfoBytes'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_Vehicle_createFromDesc(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Vehicle",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::shared_ptr<VehicleDesc> arg0;
        ok &= dx_luaval_to_native<std::shared_ptr<VehicleDesc>>(tolua_S, 2, &arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_Vehicle_createFromDesc'", nullptr);
            return 0;
        }
        std::shared_ptr<GameObject> ret = Vehicle::createFromDesc(arg0);
        dx_lua_push<std::shared_ptr<GameObject>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "Vehicle:createFromDesc",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_Vehicle_createFromDesc'.",&tolua_err);
#endif
    return 0;
}
static int lua_dxserver_Vehicle_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Vehicle)\n");
    auto ptr = (std::shared_ptr<Vehicle>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_Vehicle(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Vehicle");
    tolua_cclass(tolua_S,"Vehicle","Vehicle","GameObject",lua_dxserver_Vehicle_finalize);

    tolua_beginmodule(tolua_S,"Vehicle");
        tolua_function(tolua_S,"writeTypeInfoBytes",lua_dxserver_Vehicle_writeTypeInfoBytes);
        tolua_function(tolua_S,"createFromDesc", lua_dxserver_Vehicle_createFromDesc);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_PlayerDesc_getVehicleDesc(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<PlayerDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PlayerDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<PlayerDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_PlayerDesc_getVehicleDesc'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_PlayerDesc_getVehicleDesc'", nullptr);
            return 0;
        }
        const std::shared_ptr<VehicleDesc>& ret = cobj->getVehicleDesc();
        dx_lua_push<std::shared_ptr<VehicleDesc>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PlayerDesc:getVehicleDesc",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_PlayerDesc_getVehicleDesc'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_PlayerDesc_getLabel(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<PlayerDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PlayerDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<PlayerDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_PlayerDesc_getLabel'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_PlayerDesc_getLabel'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getLabel();
        dx_lua_push<std::string>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PlayerDesc:getLabel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_PlayerDesc_getLabel'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_PlayerDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PlayerDesc)\n");
    auto ptr = (std::shared_ptr<PlayerDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_PlayerDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"PlayerDesc");
    tolua_cclass(tolua_S,"PlayerDesc","PlayerDesc","LuaRef",lua_dxserver_PlayerDesc_finalize);

    tolua_beginmodule(tolua_S,"PlayerDesc");
        tolua_function(tolua_S,"getVehicleDesc",lua_dxserver_PlayerDesc_getVehicleDesc);
        tolua_function(tolua_S,"getLabel",lua_dxserver_PlayerDesc_getLabel);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_PlayerObject_writeTypeInfoBytes(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<PlayerObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PlayerObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<PlayerObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_PlayerObject_writeTypeInfoBytes'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::vector<unsigned char, std::allocator<unsigned char> > arg0;

        ok &= dx_luaval_to_native<std::vector<unsigned char, std::allocator<unsigned char> >>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_PlayerObject_writeTypeInfoBytes'", nullptr);
            return 0;
        }
        unsigned long ret = cobj->writeTypeInfoBytes(arg0);
        dx_lua_push<unsigned long>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PlayerObject:writeTypeInfoBytes",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_PlayerObject_writeTypeInfoBytes'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_PlayerObject_setClient(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<PlayerObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PlayerObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<PlayerObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_PlayerObject_setClient'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::shared_ptr<ClientProxy> arg0;

        ok &= dx_luaval_to_native<std::shared_ptr<ClientProxy>>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_PlayerObject_setClient'", nullptr);
            return 0;
        }
        cobj->setClient(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PlayerObject:setClient",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_PlayerObject_setClient'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_PlayerObject_update(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<PlayerObject> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PlayerObject",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<PlayerObject>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_PlayerObject_update'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        float arg0;

        ok &= dx_luaval_to_native<float>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_PlayerObject_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PlayerObject:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_PlayerObject_update'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_PlayerObject_createFromDesc(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"PlayerObject",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::shared_ptr<PlayerDesc> arg0;
        ok &= dx_luaval_to_native<std::shared_ptr<PlayerDesc>>(tolua_S, 2, &arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_PlayerObject_createFromDesc'", nullptr);
            return 0;
        }
        std::shared_ptr<GameObject> ret = PlayerObject::createFromDesc(arg0);
        dx_lua_push<std::shared_ptr<GameObject>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "PlayerObject:createFromDesc",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_PlayerObject_createFromDesc'.",&tolua_err);
#endif
    return 0;
}
static int lua_dxserver_PlayerObject_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PlayerObject)\n");
    auto ptr = (std::shared_ptr<PlayerObject>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_PlayerObject(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"PlayerObject");
    tolua_cclass(tolua_S,"PlayerObject","PlayerObject","Vehicle",lua_dxserver_PlayerObject_finalize);

    tolua_beginmodule(tolua_S,"PlayerObject");
        tolua_function(tolua_S,"writeTypeInfoBytes",lua_dxserver_PlayerObject_writeTypeInfoBytes);
        tolua_function(tolua_S,"setClient",lua_dxserver_PlayerObject_setClient);
        tolua_function(tolua_S,"update",lua_dxserver_PlayerObject_update);
        tolua_function(tolua_S,"createFromDesc", lua_dxserver_PlayerObject_createFromDesc);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_Scene_addGameObject(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<Scene> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<Scene>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_Scene_addGameObject'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::shared_ptr<GameObject> arg0;

        ok &= dx_luaval_to_native<std::shared_ptr<GameObject>>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_Scene_addGameObject'", nullptr);
            return 0;
        }
        cobj->addGameObject(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Scene:addGameObject",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_Scene_addGameObject'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_Scene_update(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<Scene> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<Scene>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_Scene_update'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        float arg0;

        ok &= dx_luaval_to_native<float>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_Scene_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Scene:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_Scene_update'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_Scene_removeGameObject(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<Scene> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<Scene>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_Scene_removeGameObject'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::shared_ptr<GameObject> arg0;

        ok &= dx_luaval_to_native<std::shared_ptr<GameObject>>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_Scene_removeGameObject'", nullptr);
            return 0;
        }
        cobj->removeGameObject(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Scene:removeGameObject",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_Scene_removeGameObject'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_Scene_createGameObject(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<Scene> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<Scene>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_Scene_createGameObject'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) {
        std::string arg0;
        GameObjectType arg1;

        ok &= dx_luaval_to_native<std::string>(tolua_S, 2, &arg0);

        ok &= dx_luaval_to_native<GameObjectType>(tolua_S, 3, &arg1);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_Scene_createGameObject'", nullptr);
            return 0;
        }
        std::shared_ptr<GameObject> ret = cobj->createGameObject(arg0, arg1);
        dx_lua_push<std::shared_ptr<GameObject>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Scene:createGameObject",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_Scene_createGameObject'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_Scene_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Scene",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_Scene_create'", nullptr);
            return 0;
        }
        std::shared_ptr<Scene> ret = Scene::create();
        dx_lua_push<std::shared_ptr<Scene>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "Scene:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_Scene_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_dxserver_Scene_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Scene)\n");
    auto ptr = (std::shared_ptr<Scene>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_Scene(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Scene");
    tolua_cclass(tolua_S,"Scene","Scene","LuaRef",lua_dxserver_Scene_finalize);

    tolua_beginmodule(tolua_S,"Scene");
        tolua_function(tolua_S,"addGameObject",lua_dxserver_Scene_addGameObject);
        tolua_function(tolua_S,"update",lua_dxserver_Scene_update);
        tolua_function(tolua_S,"removeGameObject",lua_dxserver_Scene_removeGameObject);
        tolua_function(tolua_S,"createGameObject",lua_dxserver_Scene_createGameObject);
        tolua_function(tolua_S,"create", lua_dxserver_Scene_create);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_BulletDesc_isEnemy(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<BulletDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BulletDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<BulletDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_BulletDesc_isEnemy'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_BulletDesc_isEnemy'", nullptr);
            return 0;
        }
        bool ret = cobj->isEnemy();
        dx_lua_push<bool>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "BulletDesc:isEnemy",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_BulletDesc_isEnemy'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_BulletDesc_setEnemy(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<BulletDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BulletDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<BulletDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_BulletDesc_setEnemy'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        float arg0;

        ok &= dx_luaval_to_native<float>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_BulletDesc_setEnemy'", nullptr);
            return 0;
        }
        cobj->setEnemy(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "BulletDesc:setEnemy",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_BulletDesc_setEnemy'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_BulletDesc_getDamage(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<BulletDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BulletDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<BulletDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_BulletDesc_getDamage'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_BulletDesc_getDamage'", nullptr);
            return 0;
        }
        float ret = cobj->getDamage();
        dx_lua_push<float>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "BulletDesc:getDamage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_BulletDesc_getDamage'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_BulletDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (BulletDesc)\n");
    auto ptr = (std::shared_ptr<BulletDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_BulletDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"BulletDesc");
    tolua_cclass(tolua_S,"BulletDesc","BulletDesc","GameObjectDesc",lua_dxserver_BulletDesc_finalize);

    tolua_beginmodule(tolua_S,"BulletDesc");
        tolua_function(tolua_S,"isEnemy",lua_dxserver_BulletDesc_isEnemy);
        tolua_function(tolua_S,"setEnemy",lua_dxserver_BulletDesc_setEnemy);
        tolua_function(tolua_S,"getDamage",lua_dxserver_BulletDesc_getDamage);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_ObjectManager_removeGameObjectDesc(lua_State* tolua_S)
{
    int argc = 0;
    ObjectManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ObjectManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ObjectManager_removeGameObjectDesc'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::shared_ptr<GameObjectDesc> arg0;

        ok &= dx_luaval_to_native<std::shared_ptr<GameObjectDesc>>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_removeGameObjectDesc'", nullptr);
            return 0;
        }
        std::shared_ptr<GameObjectDesc> ret = cobj->removeGameObjectDesc(arg0);
        dx_lua_push<std::shared_ptr<GameObjectDesc>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjectManager:removeGameObjectDesc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_removeGameObjectDesc'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_ObjectManager_getGameObjectDesc(lua_State* tolua_S)
{
    int argc = 0;
    ObjectManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ObjectManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ObjectManager_getGameObjectDesc'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::string arg0;

        ok &= dx_luaval_to_native<std::string>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_getGameObjectDesc'", nullptr);
            return 0;
        }
        std::shared_ptr<GameObjectDesc> ret = cobj->getGameObjectDesc(arg0);
        dx_lua_push<std::shared_ptr<GameObjectDesc>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjectManager:getGameObjectDesc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_getGameObjectDesc'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_ObjectManager_removeVehicleDesc(lua_State* tolua_S)
{
    int argc = 0;
    ObjectManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ObjectManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ObjectManager_removeVehicleDesc'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::shared_ptr<VehicleDesc> arg0;

        ok &= dx_luaval_to_native<std::shared_ptr<VehicleDesc>>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_removeVehicleDesc'", nullptr);
            return 0;
        }
        std::shared_ptr<VehicleDesc> ret = cobj->removeVehicleDesc(arg0);
        dx_lua_push<std::shared_ptr<VehicleDesc>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjectManager:removeVehicleDesc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_removeVehicleDesc'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_ObjectManager_addBulletDesc(lua_State* tolua_S)
{
    int argc = 0;
    ObjectManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ObjectManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ObjectManager_addBulletDesc'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::shared_ptr<BulletDesc> arg0;

        ok &= dx_luaval_to_native<std::shared_ptr<BulletDesc>>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_addBulletDesc'", nullptr);
            return 0;
        }
        std::shared_ptr<BulletDesc> ret = cobj->addBulletDesc(arg0);
        dx_lua_push<std::shared_ptr<BulletDesc>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjectManager:addBulletDesc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_addBulletDesc'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_ObjectManager_clearPlayerDescs(lua_State* tolua_S)
{
    int argc = 0;
    ObjectManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ObjectManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ObjectManager_clearPlayerDescs'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_clearPlayerDescs'", nullptr);
            return 0;
        }
        cobj->clearPlayerDescs();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjectManager:clearPlayerDescs",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_clearPlayerDescs'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_ObjectManager_getVehicleDesc(lua_State* tolua_S)
{
    int argc = 0;
    ObjectManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ObjectManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ObjectManager_getVehicleDesc'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::string arg0;

        ok &= dx_luaval_to_native<std::string>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_getVehicleDesc'", nullptr);
            return 0;
        }
        std::shared_ptr<VehicleDesc> ret = cobj->getVehicleDesc(arg0);
        dx_lua_push<std::shared_ptr<VehicleDesc>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjectManager:getVehicleDesc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_getVehicleDesc'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_ObjectManager_clearGameObjectDescs(lua_State* tolua_S)
{
    int argc = 0;
    ObjectManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ObjectManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ObjectManager_clearGameObjectDescs'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_clearGameObjectDescs'", nullptr);
            return 0;
        }
        cobj->clearGameObjectDescs();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjectManager:clearGameObjectDescs",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_clearGameObjectDescs'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_ObjectManager_createObject(lua_State* tolua_S)
{
    int argc = 0;
    ObjectManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ObjectManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ObjectManager_createObject'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) {
        std::string arg0;
        GameObjectType arg1;

        ok &= dx_luaval_to_native<std::string>(tolua_S, 2, &arg0);

        ok &= dx_luaval_to_native<GameObjectType>(tolua_S, 3, &arg1);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_createObject'", nullptr);
            return 0;
        }
        std::shared_ptr<GameObject> ret = cobj->createObject(arg0, arg1);
        dx_lua_push<std::shared_ptr<GameObject>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjectManager:createObject",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_createObject'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_ObjectManager_clearVehicleDescs(lua_State* tolua_S)
{
    int argc = 0;
    ObjectManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ObjectManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ObjectManager_clearVehicleDescs'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_clearVehicleDescs'", nullptr);
            return 0;
        }
        cobj->clearVehicleDescs();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjectManager:clearVehicleDescs",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_clearVehicleDescs'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_ObjectManager_removeBulletDesc(lua_State* tolua_S)
{
    int argc = 0;
    ObjectManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ObjectManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ObjectManager_removeBulletDesc'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::shared_ptr<BulletDesc> arg0;

        ok &= dx_luaval_to_native<std::shared_ptr<BulletDesc>>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_removeBulletDesc'", nullptr);
            return 0;
        }
        std::shared_ptr<BulletDesc> ret = cobj->removeBulletDesc(arg0);
        dx_lua_push<std::shared_ptr<BulletDesc>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjectManager:removeBulletDesc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_removeBulletDesc'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_ObjectManager_addGameObjectDesc(lua_State* tolua_S)
{
    int argc = 0;
    ObjectManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ObjectManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ObjectManager_addGameObjectDesc'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::shared_ptr<GameObjectDesc> arg0;

        ok &= dx_luaval_to_native<std::shared_ptr<GameObjectDesc>>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_addGameObjectDesc'", nullptr);
            return 0;
        }
        std::shared_ptr<GameObjectDesc> ret = cobj->addGameObjectDesc(arg0);
        dx_lua_push<std::shared_ptr<GameObjectDesc>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjectManager:addGameObjectDesc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_addGameObjectDesc'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_ObjectManager_removePlayerDesc(lua_State* tolua_S)
{
    int argc = 0;
    ObjectManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ObjectManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ObjectManager_removePlayerDesc'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::shared_ptr<PlayerDesc> arg0;

        ok &= dx_luaval_to_native<std::shared_ptr<PlayerDesc>>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_removePlayerDesc'", nullptr);
            return 0;
        }
        std::shared_ptr<PlayerDesc> ret = cobj->removePlayerDesc(arg0);
        dx_lua_push<std::shared_ptr<PlayerDesc>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjectManager:removePlayerDesc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_removePlayerDesc'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_ObjectManager_getPlayerDesc(lua_State* tolua_S)
{
    int argc = 0;
    ObjectManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ObjectManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ObjectManager_getPlayerDesc'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::string arg0;

        ok &= dx_luaval_to_native<std::string>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_getPlayerDesc'", nullptr);
            return 0;
        }
        std::shared_ptr<PlayerDesc> ret = cobj->getPlayerDesc(arg0);
        dx_lua_push<std::shared_ptr<PlayerDesc>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjectManager:getPlayerDesc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_getPlayerDesc'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_ObjectManager_addVehicleDesc(lua_State* tolua_S)
{
    int argc = 0;
    ObjectManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ObjectManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ObjectManager_addVehicleDesc'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::shared_ptr<VehicleDesc> arg0;

        ok &= dx_luaval_to_native<std::shared_ptr<VehicleDesc>>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_addVehicleDesc'", nullptr);
            return 0;
        }
        std::shared_ptr<VehicleDesc> ret = cobj->addVehicleDesc(arg0);
        dx_lua_push<std::shared_ptr<VehicleDesc>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjectManager:addVehicleDesc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_addVehicleDesc'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_ObjectManager_addPlayerDesc(lua_State* tolua_S)
{
    int argc = 0;
    ObjectManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ObjectManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ObjectManager_addPlayerDesc'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::shared_ptr<PlayerDesc> arg0;

        ok &= dx_luaval_to_native<std::shared_ptr<PlayerDesc>>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_addPlayerDesc'", nullptr);
            return 0;
        }
        std::shared_ptr<PlayerDesc> ret = cobj->addPlayerDesc(arg0);
        dx_lua_push<std::shared_ptr<PlayerDesc>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjectManager:addPlayerDesc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_addPlayerDesc'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_ObjectManager_getBulletDesc(lua_State* tolua_S)
{
    int argc = 0;
    ObjectManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ObjectManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ObjectManager_getBulletDesc'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::string arg0;

        ok &= dx_luaval_to_native<std::string>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_getBulletDesc'", nullptr);
            return 0;
        }
        std::shared_ptr<BulletDesc> ret = cobj->getBulletDesc(arg0);
        dx_lua_push<std::shared_ptr<BulletDesc>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjectManager:getBulletDesc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_getBulletDesc'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_ObjectManager_clearBulletDescs(lua_State* tolua_S)
{
    int argc = 0;
    ObjectManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (ObjectManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ObjectManager_clearBulletDescs'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_clearBulletDescs'", nullptr);
            return 0;
        }
        cobj->clearBulletDescs();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ObjectManager:clearBulletDescs",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_clearBulletDescs'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_ObjectManager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ObjectManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ObjectManager_getInstance'", nullptr);
            return 0;
        }
        ObjectManager* ret = ObjectManager::getInstance();
        dx_lua_push<ObjectManager*>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ObjectManager:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ObjectManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_dxserver_ObjectManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ObjectManager)\n");
    return 0;
}

int lua_register_dxserver_ObjectManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ObjectManager");
    tolua_cclass(tolua_S,"ObjectManager","ObjectManager","",nullptr);

    tolua_beginmodule(tolua_S,"ObjectManager");
        tolua_function(tolua_S,"removeGameObjectDesc",lua_dxserver_ObjectManager_removeGameObjectDesc);
        tolua_function(tolua_S,"getGameObjectDesc",lua_dxserver_ObjectManager_getGameObjectDesc);
        tolua_function(tolua_S,"removeVehicleDesc",lua_dxserver_ObjectManager_removeVehicleDesc);
        tolua_function(tolua_S,"addBulletDesc",lua_dxserver_ObjectManager_addBulletDesc);
        tolua_function(tolua_S,"clearPlayerDescs",lua_dxserver_ObjectManager_clearPlayerDescs);
        tolua_function(tolua_S,"getVehicleDesc",lua_dxserver_ObjectManager_getVehicleDesc);
        tolua_function(tolua_S,"clearGameObjectDescs",lua_dxserver_ObjectManager_clearGameObjectDescs);
        tolua_function(tolua_S,"createObject",lua_dxserver_ObjectManager_createObject);
        tolua_function(tolua_S,"clearVehicleDescs",lua_dxserver_ObjectManager_clearVehicleDescs);
        tolua_function(tolua_S,"removeBulletDesc",lua_dxserver_ObjectManager_removeBulletDesc);
        tolua_function(tolua_S,"addGameObjectDesc",lua_dxserver_ObjectManager_addGameObjectDesc);
        tolua_function(tolua_S,"removePlayerDesc",lua_dxserver_ObjectManager_removePlayerDesc);
        tolua_function(tolua_S,"getPlayerDesc",lua_dxserver_ObjectManager_getPlayerDesc);
        tolua_function(tolua_S,"addVehicleDesc",lua_dxserver_ObjectManager_addVehicleDesc);
        tolua_function(tolua_S,"addPlayerDesc",lua_dxserver_ObjectManager_addPlayerDesc);
        tolua_function(tolua_S,"getBulletDesc",lua_dxserver_ObjectManager_getBulletDesc);
        tolua_function(tolua_S,"clearBulletDescs",lua_dxserver_ObjectManager_clearBulletDescs);
        tolua_function(tolua_S,"getInstance", lua_dxserver_ObjectManager_getInstance);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_GameServer_sendOutgoingPackets(lua_State* tolua_S)
{
    int argc = 0;
    GameServer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GameServer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameServer_sendOutgoingPackets'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_sendOutgoingPackets'", nullptr);
            return 0;
        }
        cobj->sendOutgoingPackets();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameServer:sendOutgoingPackets",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_sendOutgoingPackets'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameServer_getFileUtils(lua_State* tolua_S)
{
    int argc = 0;
    GameServer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GameServer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameServer_getFileUtils'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_getFileUtils'", nullptr);
            return 0;
        }
        FileUtils* ret = cobj->getFileUtils();
        dx_lua_push<FileUtils*>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameServer:getFileUtils",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_getFileUtils'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameServer_run(lua_State* tolua_S)
{
    int argc = 0;
    GameServer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GameServer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameServer_run'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_run'", nullptr);
            return 0;
        }
        cobj->run();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameServer:run",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_run'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameServer_setOnNewClientCb(lua_State* tolua_S)
{
    int argc = 0;
    GameServer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GameServer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameServer_setOnNewClientCb'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::function<std::shared_ptr<PlayerObject> ()> arg0;

        ok &= dx_luaval_to_native<std::function<std::shared_ptr<PlayerObject> ()>>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_setOnNewClientCb'", nullptr);
            return 0;
        }
        cobj->setOnNewClientCb(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameServer:setOnNewClientCb",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_setOnNewClientCb'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameServer_getGameObject(lua_State* tolua_S)
{
    int argc = 0;
    GameServer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GameServer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameServer_getGameObject'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        unsigned long long arg0;

        ok &= dx_luaval_to_native<unsigned long long>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_getGameObject'", nullptr);
            return 0;
        }
        std::shared_ptr<GameObject> ret = cobj->getGameObject(arg0);
        dx_lua_push<std::shared_ptr<GameObject>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameServer:getGameObject",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_getGameObject'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameServer_removeGameObject(lua_State* tolua_S)
{
    int argc = 0;
    GameServer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GameServer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameServer_removeGameObject'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::shared_ptr<GameObject> arg0;

        ok &= dx_luaval_to_native<std::shared_ptr<GameObject>>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_removeGameObject'", nullptr);
            return 0;
        }
        cobj->removeGameObject(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameServer:removeGameObject",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_removeGameObject'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameServer_unregisterGameObject(lua_State* tolua_S)
{
    int argc = 0;
    GameServer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GameServer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameServer_unregisterGameObject'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::shared_ptr<GameObject> arg0;

        ok &= dx_luaval_to_native<std::shared_ptr<GameObject>>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_unregisterGameObject'", nullptr);
            return 0;
        }
        cobj->unregisterGameObject(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameServer:unregisterGameObject",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_unregisterGameObject'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameServer_getObjectManager(lua_State* tolua_S)
{
    int argc = 0;
    GameServer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GameServer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameServer_getObjectManager'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_getObjectManager'", nullptr);
            return 0;
        }
        ObjectManager* ret = cobj->getObjectManager();
        dx_lua_push<ObjectManager*>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameServer:getObjectManager",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_getObjectManager'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameServer_checkForDisconnects(lua_State* tolua_S)
{
    int argc = 0;
    GameServer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GameServer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameServer_checkForDisconnects'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_checkForDisconnects'", nullptr);
            return 0;
        }
        cobj->checkForDisconnects();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameServer:checkForDisconnects",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_checkForDisconnects'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameServer_start(lua_State* tolua_S)
{
    int argc = 0;
    GameServer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GameServer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameServer_start'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_start'", nullptr);
            return 0;
        }
        cobj->start();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameServer:start",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_start'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameServer_getScene(lua_State* tolua_S)
{
    int argc = 0;
    GameServer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GameServer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameServer_getScene'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_getScene'", nullptr);
            return 0;
        }
        std::shared_ptr<Scene> ret = cobj->getScene();
        dx_lua_push<std::shared_ptr<Scene>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameServer:getScene",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_getScene'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameServer_addGameObject(lua_State* tolua_S)
{
    int argc = 0;
    GameServer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GameServer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameServer_addGameObject'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::shared_ptr<GameObject> arg0;

        ok &= dx_luaval_to_native<std::shared_ptr<GameObject>>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_addGameObject'", nullptr);
            return 0;
        }
        cobj->addGameObject(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameServer:addGameObject",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_addGameObject'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameServer_setStateDirty(lua_State* tolua_S)
{
    int argc = 0;
    GameServer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GameServer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameServer_setStateDirty'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) {
        unsigned long long arg0;
        unsigned int arg1;

        ok &= dx_luaval_to_native<unsigned long long>(tolua_S, 2, &arg0);

        ok &= dx_luaval_to_native<unsigned int>(tolua_S, 3, &arg1);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_setStateDirty'", nullptr);
            return 0;
        }
        cobj->setStateDirty(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameServer:setStateDirty",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_setStateDirty'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameServer_registerGameObject(lua_State* tolua_S)
{
    int argc = 0;
    GameServer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GameServer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameServer_registerGameObject'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::shared_ptr<GameObject> arg0;

        ok &= dx_luaval_to_native<std::shared_ptr<GameObject>>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_registerGameObject'", nullptr);
            return 0;
        }
        cobj->registerGameObject(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameServer:registerGameObject",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_registerGameObject'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameServer_getLuaState(lua_State* tolua_S)
{
    int argc = 0;
    GameServer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (GameServer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameServer_getLuaState'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_getLuaState'", nullptr);
            return 0;
        }
        LuaState* ret = cobj->getLuaState();
        dx_lua_push<LuaState*>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameServer:getLuaState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_getLuaState'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_GameServer_getTimestamp(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_getTimestamp'", nullptr);
            return 0;
        }
        float ret = GameServer::getTimestamp();
        dx_lua_push<float>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GameServer:getTimestamp",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_getTimestamp'.",&tolua_err);
#endif
    return 0;
}
int lua_dxserver_GameServer_releaseInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_releaseInstance'", nullptr);
            return 0;
        }
        GameServer::releaseInstance();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GameServer:releaseInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_releaseInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_dxserver_GameServer_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameServer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameServer_getInstance'", nullptr);
            return 0;
        }
        GameServer* ret = GameServer::getInstance();
        dx_lua_push<GameServer*>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GameServer:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameServer_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_dxserver_GameServer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameServer)\n");
    return 0;
}

int lua_register_dxserver_GameServer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"GameServer");
    tolua_cclass(tolua_S,"GameServer","GameServer","",nullptr);

    tolua_beginmodule(tolua_S,"GameServer");
        tolua_function(tolua_S,"sendOutgoingPackets",lua_dxserver_GameServer_sendOutgoingPackets);
        tolua_function(tolua_S,"getFileUtils",lua_dxserver_GameServer_getFileUtils);
        tolua_function(tolua_S,"run",lua_dxserver_GameServer_run);
        tolua_function(tolua_S,"setOnNewClientCb",lua_dxserver_GameServer_setOnNewClientCb);
        tolua_function(tolua_S,"getGameObject",lua_dxserver_GameServer_getGameObject);
        tolua_function(tolua_S,"removeGameObject",lua_dxserver_GameServer_removeGameObject);
        tolua_function(tolua_S,"unregisterGameObject",lua_dxserver_GameServer_unregisterGameObject);
        tolua_function(tolua_S,"getObjectManager",lua_dxserver_GameServer_getObjectManager);
        tolua_function(tolua_S,"checkForDisconnects",lua_dxserver_GameServer_checkForDisconnects);
        tolua_function(tolua_S,"start",lua_dxserver_GameServer_start);
        tolua_function(tolua_S,"getScene",lua_dxserver_GameServer_getScene);
        tolua_function(tolua_S,"addGameObject",lua_dxserver_GameServer_addGameObject);
        tolua_function(tolua_S,"setStateDirty",lua_dxserver_GameServer_setStateDirty);
        tolua_function(tolua_S,"registerGameObject",lua_dxserver_GameServer_registerGameObject);
        tolua_function(tolua_S,"getLuaState",lua_dxserver_GameServer_getLuaState);
        tolua_function(tolua_S,"getTimestamp", lua_dxserver_GameServer_getTimestamp);
        tolua_function(tolua_S,"releaseInstance", lua_dxserver_GameServer_releaseInstance);
        tolua_function(tolua_S,"getInstance", lua_dxserver_GameServer_getInstance);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_Bullet_writeTypeInfoBytes(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<Bullet> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bullet",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<Bullet>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_Bullet_writeTypeInfoBytes'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) {
        std::vector<unsigned char, std::allocator<unsigned char> > arg0;

        ok &= dx_luaval_to_native<std::vector<unsigned char, std::allocator<unsigned char> >>(tolua_S, 2, &arg0);
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_Bullet_writeTypeInfoBytes'", nullptr);
            return 0;
        }
        unsigned long ret = cobj->writeTypeInfoBytes(arg0);
        dx_lua_push<unsigned long>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Bullet:writeTypeInfoBytes",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_Bullet_writeTypeInfoBytes'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_Bullet_createFromDesc(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Bullet",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::shared_ptr<BulletDesc> arg0;
        ok &= dx_luaval_to_native<std::shared_ptr<BulletDesc>>(tolua_S, 2, &arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_Bullet_createFromDesc'", nullptr);
            return 0;
        }
        std::shared_ptr<GameObject> ret = Bullet::createFromDesc(arg0);
        dx_lua_push<std::shared_ptr<GameObject>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "Bullet:createFromDesc",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_Bullet_createFromDesc'.",&tolua_err);
#endif
    return 0;
}
static int lua_dxserver_Bullet_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Bullet)\n");
    auto ptr = (std::shared_ptr<Bullet>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_Bullet(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Bullet");
    tolua_cclass(tolua_S,"Bullet","Bullet","GameObject",lua_dxserver_Bullet_finalize);

    tolua_beginmodule(tolua_S,"Bullet");
        tolua_function(tolua_S,"writeTypeInfoBytes",lua_dxserver_Bullet_writeTypeInfoBytes);
        tolua_function(tolua_S,"createFromDesc", lua_dxserver_Bullet_createFromDesc);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_GameActionDesc_getAction(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<GameActionDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameActionDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<GameActionDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_GameActionDesc_getAction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_GameActionDesc_getAction'", nullptr);
            return 0;
        }
        std::shared_ptr<Action> ret = cobj->getAction();
        dx_lua_push<std::shared_ptr<Action>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameActionDesc:getAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_GameActionDesc_getAction'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_GameActionDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameActionDesc)\n");
    auto ptr = (std::shared_ptr<GameActionDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_GameActionDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"GameActionDesc");
    tolua_cclass(tolua_S,"GameActionDesc","GameActionDesc","LuaRef",lua_dxserver_GameActionDesc_finalize);

    tolua_beginmodule(tolua_S,"GameActionDesc");
        tolua_function(tolua_S,"getAction",lua_dxserver_GameActionDesc_getAction);
    tolua_endmodule(tolua_S);
    return 1;
}

static int lua_dxserver_ActionDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ActionDesc)\n");
    auto ptr = (std::shared_ptr<ActionDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_ActionDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ActionDesc");
    tolua_cclass(tolua_S,"ActionDesc","ActionDesc","GameActionDesc",lua_dxserver_ActionDesc_finalize);

    tolua_beginmodule(tolua_S,"ActionDesc");
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_NumericDesc_getType(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<NumericDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NumericDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<NumericDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_NumericDesc_getType'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_NumericDesc_getType'", nullptr);
            return 0;
        }
        NumericDescType ret = cobj->getType();
        dx_lua_push<NumericDescType>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "NumericDesc:getType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_NumericDesc_getType'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_NumericDesc_eval(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<NumericDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NumericDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<NumericDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_NumericDesc_eval'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_NumericDesc_eval'", nullptr);
            return 0;
        }
        float ret = cobj->eval();
        dx_lua_push<float>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "NumericDesc:eval",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_NumericDesc_eval'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_NumericDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (NumericDesc)\n");
    auto ptr = (std::shared_ptr<NumericDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_NumericDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"NumericDesc");
    tolua_cclass(tolua_S,"NumericDesc","NumericDesc","LuaRef",lua_dxserver_NumericDesc_finalize);

    tolua_beginmodule(tolua_S,"NumericDesc");
        tolua_function(tolua_S,"getType",lua_dxserver_NumericDesc_getType);
        tolua_function(tolua_S,"eval",lua_dxserver_NumericDesc_eval);
    tolua_endmodule(tolua_S);
    return 1;
}

static int lua_dxserver_SpeedDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SpeedDesc)\n");
    auto ptr = (std::shared_ptr<SpeedDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_SpeedDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SpeedDesc");
    tolua_cclass(tolua_S,"SpeedDesc","SpeedDesc","NumericDesc",lua_dxserver_SpeedDesc_finalize);

    tolua_beginmodule(tolua_S,"SpeedDesc");
    tolua_endmodule(tolua_S);
    return 1;
}

static int lua_dxserver_DirectionDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DirectionDesc)\n");
    auto ptr = (std::shared_ptr<DirectionDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_DirectionDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"DirectionDesc");
    tolua_cclass(tolua_S,"DirectionDesc","DirectionDesc","NumericDesc",lua_dxserver_DirectionDesc_finalize);

    tolua_beginmodule(tolua_S,"DirectionDesc");
    tolua_endmodule(tolua_S);
    return 1;
}

static int lua_dxserver_HorizontalDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (HorizontalDesc)\n");
    auto ptr = (std::shared_ptr<HorizontalDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_HorizontalDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"HorizontalDesc");
    tolua_cclass(tolua_S,"HorizontalDesc","HorizontalDesc","NumericDesc",lua_dxserver_HorizontalDesc_finalize);

    tolua_beginmodule(tolua_S,"HorizontalDesc");
    tolua_endmodule(tolua_S);
    return 1;
}

static int lua_dxserver_VerticalDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (VerticalDesc)\n");
    auto ptr = (std::shared_ptr<VerticalDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_VerticalDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"VerticalDesc");
    tolua_cclass(tolua_S,"VerticalDesc","VerticalDesc","NumericDesc",lua_dxserver_VerticalDesc_finalize);

    tolua_beginmodule(tolua_S,"VerticalDesc");
    tolua_endmodule(tolua_S);
    return 1;
}

static int lua_dxserver_OrientationDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (OrientationDesc)\n");
    auto ptr = (std::shared_ptr<OrientationDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_OrientationDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"OrientationDesc");
    tolua_cclass(tolua_S,"OrientationDesc","OrientationDesc","NumericDesc",lua_dxserver_OrientationDesc_finalize);

    tolua_beginmodule(tolua_S,"OrientationDesc");
    tolua_endmodule(tolua_S);
    return 1;
}

static int lua_dxserver_RotationDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (RotationDesc)\n");
    auto ptr = (std::shared_ptr<RotationDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_RotationDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"RotationDesc");
    tolua_cclass(tolua_S,"RotationDesc","RotationDesc","NumericDesc",lua_dxserver_RotationDesc_finalize);

    tolua_beginmodule(tolua_S,"RotationDesc");
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_PositionDesc_eval(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<PositionDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PositionDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<PositionDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_PositionDesc_eval'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_PositionDesc_eval'", nullptr);
            return 0;
        }
        Eigen::Vector2f ret = cobj->eval();
        dx_lua_push<Eigen::Vector2f>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PositionDesc:eval",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_PositionDesc_eval'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_PositionDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PositionDesc)\n");
    auto ptr = (std::shared_ptr<PositionDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_PositionDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"PositionDesc");
    tolua_cclass(tolua_S,"PositionDesc","PositionDesc","LuaRef",lua_dxserver_PositionDesc_finalize);

    tolua_beginmodule(tolua_S,"PositionDesc");
        tolua_function(tolua_S,"eval",lua_dxserver_PositionDesc_eval);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_AccelDesc_getAction(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<AccelDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AccelDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<AccelDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_AccelDesc_getAction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_AccelDesc_getAction'", nullptr);
            return 0;
        }
        std::shared_ptr<Action> ret = cobj->getAction();
        dx_lua_push<std::shared_ptr<Action>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "AccelDesc:getAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_AccelDesc_getAction'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_AccelDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AccelDesc)\n");
    auto ptr = (std::shared_ptr<AccelDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_AccelDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"AccelDesc");
    tolua_cclass(tolua_S,"AccelDesc","AccelDesc","GameActionDesc",lua_dxserver_AccelDesc_finalize);

    tolua_beginmodule(tolua_S,"AccelDesc");
        tolua_function(tolua_S,"getAction",lua_dxserver_AccelDesc_getAction);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_ChangeDirectionDesc_getAction(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<ChangeDirectionDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ChangeDirectionDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<ChangeDirectionDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ChangeDirectionDesc_getAction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ChangeDirectionDesc_getAction'", nullptr);
            return 0;
        }
        std::shared_ptr<Action> ret = cobj->getAction();
        dx_lua_push<std::shared_ptr<Action>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ChangeDirectionDesc:getAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ChangeDirectionDesc_getAction'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_ChangeDirectionDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ChangeDirectionDesc)\n");
    auto ptr = (std::shared_ptr<ChangeDirectionDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_ChangeDirectionDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ChangeDirectionDesc");
    tolua_cclass(tolua_S,"ChangeDirectionDesc","ChangeDirectionDesc","GameActionDesc",lua_dxserver_ChangeDirectionDesc_finalize);

    tolua_beginmodule(tolua_S,"ChangeDirectionDesc");
        tolua_function(tolua_S,"getAction",lua_dxserver_ChangeDirectionDesc_getAction);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_ChangeSpeedDesc_getAction(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<ChangeSpeedDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ChangeSpeedDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<ChangeSpeedDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_ChangeSpeedDesc_getAction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_ChangeSpeedDesc_getAction'", nullptr);
            return 0;
        }
        std::shared_ptr<Action> ret = cobj->getAction();
        dx_lua_push<std::shared_ptr<Action>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ChangeSpeedDesc:getAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_ChangeSpeedDesc_getAction'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_ChangeSpeedDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ChangeSpeedDesc)\n");
    auto ptr = (std::shared_ptr<ChangeSpeedDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_ChangeSpeedDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ChangeSpeedDesc");
    tolua_cclass(tolua_S,"ChangeSpeedDesc","ChangeSpeedDesc","GameActionDesc",lua_dxserver_ChangeSpeedDesc_finalize);

    tolua_beginmodule(tolua_S,"ChangeSpeedDesc");
        tolua_function(tolua_S,"getAction",lua_dxserver_ChangeSpeedDesc_getAction);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_PlaceObjectDesc_getAction(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<PlaceObjectDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PlaceObjectDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<PlaceObjectDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_PlaceObjectDesc_getAction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_PlaceObjectDesc_getAction'", nullptr);
            return 0;
        }
        std::shared_ptr<Action> ret = cobj->getAction();
        dx_lua_push<std::shared_ptr<Action>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PlaceObjectDesc:getAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_PlaceObjectDesc_getAction'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_PlaceObjectDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PlaceObjectDesc)\n");
    auto ptr = (std::shared_ptr<PlaceObjectDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_PlaceObjectDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"PlaceObjectDesc");
    tolua_cclass(tolua_S,"PlaceObjectDesc","PlaceObjectDesc","PlaceDescBase",lua_dxserver_PlaceObjectDesc_finalize);

    tolua_beginmodule(tolua_S,"PlaceObjectDesc");
        tolua_function(tolua_S,"getAction",lua_dxserver_PlaceObjectDesc_getAction);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_PlaceVehicleDesc_getAction(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<PlaceVehicleDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PlaceVehicleDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<PlaceVehicleDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_PlaceVehicleDesc_getAction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_PlaceVehicleDesc_getAction'", nullptr);
            return 0;
        }
        std::shared_ptr<Action> ret = cobj->getAction();
        dx_lua_push<std::shared_ptr<Action>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PlaceVehicleDesc:getAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_PlaceVehicleDesc_getAction'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_PlaceVehicleDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PlaceVehicleDesc)\n");
    auto ptr = (std::shared_ptr<PlaceVehicleDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_PlaceVehicleDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"PlaceVehicleDesc");
    tolua_cclass(tolua_S,"PlaceVehicleDesc","PlaceVehicleDesc","PlaceDescBase",lua_dxserver_PlaceVehicleDesc_finalize);

    tolua_beginmodule(tolua_S,"PlaceVehicleDesc");
        tolua_function(tolua_S,"getAction",lua_dxserver_PlaceVehicleDesc_getAction);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_FireBulletDesc_getAction(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<FireBulletDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"FireBulletDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<FireBulletDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_FireBulletDesc_getAction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_FireBulletDesc_getAction'", nullptr);
            return 0;
        }
        std::shared_ptr<Action> ret = cobj->getAction();
        dx_lua_push<std::shared_ptr<Action>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "FireBulletDesc:getAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_FireBulletDesc_getAction'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_FireBulletDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (FireBulletDesc)\n");
    auto ptr = (std::shared_ptr<FireBulletDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_FireBulletDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"FireBulletDesc");
    tolua_cclass(tolua_S,"FireBulletDesc","FireBulletDesc","PlaceDescBase",lua_dxserver_FireBulletDesc_finalize);

    tolua_beginmodule(tolua_S,"FireBulletDesc");
        tolua_function(tolua_S,"getAction",lua_dxserver_FireBulletDesc_getAction);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_PlaceObjectRefDesc_getActionName(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<PlaceObjectRefDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PlaceObjectRefDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<PlaceObjectRefDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_PlaceObjectRefDesc_getActionName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_PlaceObjectRefDesc_getActionName'", nullptr);
            return 0;
        }
        const std::string ret = cobj->getActionName();
        dx_lua_push<std::string>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PlaceObjectRefDesc:getActionName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_PlaceObjectRefDesc_getActionName'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_PlaceObjectRefDesc_getAction(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<PlaceObjectRefDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PlaceObjectRefDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<PlaceObjectRefDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_PlaceObjectRefDesc_getAction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_PlaceObjectRefDesc_getAction'", nullptr);
            return 0;
        }
        std::shared_ptr<Action> ret = cobj->getAction();
        dx_lua_push<std::shared_ptr<Action>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PlaceObjectRefDesc:getAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_PlaceObjectRefDesc_getAction'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_PlaceObjectRefDesc_getLabel(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<PlaceObjectRefDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PlaceObjectRefDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<PlaceObjectRefDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_PlaceObjectRefDesc_getLabel'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_PlaceObjectRefDesc_getLabel'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getLabel();
        dx_lua_push<std::string>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PlaceObjectRefDesc:getLabel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_PlaceObjectRefDesc_getLabel'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_PlaceObjectRefDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PlaceObjectRefDesc)\n");
    auto ptr = (std::shared_ptr<PlaceObjectRefDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_PlaceObjectRefDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"PlaceObjectRefDesc");
    tolua_cclass(tolua_S,"PlaceObjectRefDesc","PlaceObjectRefDesc","PlaceDescBase",lua_dxserver_PlaceObjectRefDesc_finalize);

    tolua_beginmodule(tolua_S,"PlaceObjectRefDesc");
        tolua_function(tolua_S,"getActionName",lua_dxserver_PlaceObjectRefDesc_getActionName);
        tolua_function(tolua_S,"getAction",lua_dxserver_PlaceObjectRefDesc_getAction);
        tolua_function(tolua_S,"getLabel",lua_dxserver_PlaceObjectRefDesc_getLabel);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_PlaceVehicleRefDesc_getActionName(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<PlaceVehicleRefDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PlaceVehicleRefDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<PlaceVehicleRefDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_PlaceVehicleRefDesc_getActionName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_PlaceVehicleRefDesc_getActionName'", nullptr);
            return 0;
        }
        const std::string ret = cobj->getActionName();
        dx_lua_push<std::string>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PlaceVehicleRefDesc:getActionName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_PlaceVehicleRefDesc_getActionName'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_PlaceVehicleRefDesc_getAction(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<PlaceVehicleRefDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PlaceVehicleRefDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<PlaceVehicleRefDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_PlaceVehicleRefDesc_getAction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_PlaceVehicleRefDesc_getAction'", nullptr);
            return 0;
        }
        std::shared_ptr<Action> ret = cobj->getAction();
        dx_lua_push<std::shared_ptr<Action>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PlaceVehicleRefDesc:getAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_PlaceVehicleRefDesc_getAction'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_PlaceVehicleRefDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PlaceVehicleRefDesc)\n");
    auto ptr = (std::shared_ptr<PlaceVehicleRefDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_PlaceVehicleRefDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"PlaceVehicleRefDesc");
    tolua_cclass(tolua_S,"PlaceVehicleRefDesc","PlaceVehicleRefDesc","PlaceObjectRefDesc",lua_dxserver_PlaceVehicleRefDesc_finalize);

    tolua_beginmodule(tolua_S,"PlaceVehicleRefDesc");
        tolua_function(tolua_S,"getActionName",lua_dxserver_PlaceVehicleRefDesc_getActionName);
        tolua_function(tolua_S,"getAction",lua_dxserver_PlaceVehicleRefDesc_getAction);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_FireBulletRefDesc_getActionName(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<FireBulletRefDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"FireBulletRefDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<FireBulletRefDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_FireBulletRefDesc_getActionName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_FireBulletRefDesc_getActionName'", nullptr);
            return 0;
        }
        const std::string ret = cobj->getActionName();
        dx_lua_push<std::string>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "FireBulletRefDesc:getActionName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_FireBulletRefDesc_getActionName'.",&tolua_err);
#endif

    return 0;
}
int lua_dxserver_FireBulletRefDesc_getAction(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<FireBulletRefDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"FireBulletRefDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<FireBulletRefDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_FireBulletRefDesc_getAction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_FireBulletRefDesc_getAction'", nullptr);
            return 0;
        }
        std::shared_ptr<Action> ret = cobj->getAction();
        dx_lua_push<std::shared_ptr<Action>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "FireBulletRefDesc:getAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_FireBulletRefDesc_getAction'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_FireBulletRefDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (FireBulletRefDesc)\n");
    auto ptr = (std::shared_ptr<FireBulletRefDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_FireBulletRefDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"FireBulletRefDesc");
    tolua_cclass(tolua_S,"FireBulletRefDesc","FireBulletRefDesc","PlaceObjectRefDesc",lua_dxserver_FireBulletRefDesc_finalize);

    tolua_beginmodule(tolua_S,"FireBulletRefDesc");
        tolua_function(tolua_S,"getActionName",lua_dxserver_FireBulletRefDesc_getActionName);
        tolua_function(tolua_S,"getAction",lua_dxserver_FireBulletRefDesc_getAction);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_RepeatDesc_getAction(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<RepeatDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"RepeatDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<RepeatDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_RepeatDesc_getAction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_RepeatDesc_getAction'", nullptr);
            return 0;
        }
        std::shared_ptr<Action> ret = cobj->getAction();
        dx_lua_push<std::shared_ptr<Action>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "RepeatDesc:getAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_RepeatDesc_getAction'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_RepeatDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (RepeatDesc)\n");
    auto ptr = (std::shared_ptr<RepeatDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_RepeatDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"RepeatDesc");
    tolua_cclass(tolua_S,"RepeatDesc","RepeatDesc","GameActionDesc",lua_dxserver_RepeatDesc_finalize);

    tolua_beginmodule(tolua_S,"RepeatDesc");
        tolua_function(tolua_S,"getAction",lua_dxserver_RepeatDesc_getAction);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_VanishDesc_getAction(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<VanishDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"VanishDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<VanishDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_VanishDesc_getAction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_VanishDesc_getAction'", nullptr);
            return 0;
        }
        std::shared_ptr<Action> ret = cobj->getAction();
        dx_lua_push<std::shared_ptr<Action>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "VanishDesc:getAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_VanishDesc_getAction'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_VanishDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (VanishDesc)\n");
    auto ptr = (std::shared_ptr<VanishDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_VanishDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"VanishDesc");
    tolua_cclass(tolua_S,"VanishDesc","VanishDesc","GameActionDesc",lua_dxserver_VanishDesc_finalize);

    tolua_beginmodule(tolua_S,"VanishDesc");
        tolua_function(tolua_S,"getAction",lua_dxserver_VanishDesc_getAction);
    tolua_endmodule(tolua_S);
    return 1;
}

int lua_dxserver_WaitDesc_getAction(lua_State* tolua_S)
{
    int argc = 0;
    std::shared_ptr<WaitDesc> cobj;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"WaitDesc",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = dx_lua_parse<std::shared_ptr<WaitDesc>>(tolua_S, 1); 
#if COCOS2D_DEBUG >= 1
    if (!cobj) {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dxserver_WaitDesc_getAction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) {
        if(!ok) {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dxserver_WaitDesc_getAction'", nullptr);
            return 0;
        }
        std::shared_ptr<Action> ret = cobj->getAction();
        dx_lua_push<std::shared_ptr<Action>>(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "WaitDesc:getAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dxserver_WaitDesc_getAction'.",&tolua_err);
#endif

    return 0;
}
static int lua_dxserver_WaitDesc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (WaitDesc)\n");
    auto ptr = (std::shared_ptr<WaitDesc>*)tolua_tousertype(tolua_S,1,0);
    ptr->~shared_ptr();
    return 0;
}

int lua_register_dxserver_WaitDesc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"WaitDesc");
    tolua_cclass(tolua_S,"WaitDesc","WaitDesc","GameActionDesc",lua_dxserver_WaitDesc_finalize);

    tolua_beginmodule(tolua_S,"WaitDesc");
        tolua_function(tolua_S,"getAction",lua_dxserver_WaitDesc_getAction);
    tolua_endmodule(tolua_S);
    return 1;
}
TOLUA_API int register_all_dxserver(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"dx",0);
	tolua_beginmodule(tolua_S,"dx");

	lua_register_dxserver_GameObject(tolua_S);
	lua_register_dxserver_Vehicle(tolua_S);
	lua_register_dxserver_PlayerObject(tolua_S);
	lua_register_dxserver_GameActionDesc(tolua_S);
	lua_register_dxserver_ActionDesc(tolua_S);
	lua_register_dxserver_PlaceVehicleDesc(tolua_S);
	lua_register_dxserver_NumericDesc(tolua_S);
	lua_register_dxserver_HorizontalDesc(tolua_S);
	lua_register_dxserver_DirectionDesc(tolua_S);
	lua_register_dxserver_PlayerDesc(tolua_S);
	lua_register_dxserver_WaitDesc(tolua_S);
	lua_register_dxserver_GameObjectDesc(tolua_S);
	lua_register_dxserver_ScriptComponentDesc(tolua_S);
	lua_register_dxserver_PlaceObjectRefDesc(tolua_S);
	lua_register_dxserver_FireBulletRefDesc(tolua_S);
	lua_register_dxserver_GameServer(tolua_S);
	lua_register_dxserver_PlaceVehicleRefDesc(tolua_S);
	lua_register_dxserver_ChangeDirectionDesc(tolua_S);
	lua_register_dxserver_VehicleDesc(tolua_S);
	lua_register_dxserver_RotationDesc(tolua_S);
	lua_register_dxserver_AccelDesc(tolua_S);
	lua_register_dxserver_PlaceObjectDesc(tolua_S);
	lua_register_dxserver_RepeatDesc(tolua_S);
	lua_register_dxserver_VerticalDesc(tolua_S);
	lua_register_dxserver_PositionDesc(tolua_S);
	lua_register_dxserver_VanishDesc(tolua_S);
	lua_register_dxserver_Bullet(tolua_S);
	lua_register_dxserver_ObjectManager(tolua_S);
	lua_register_dxserver_SpeedDesc(tolua_S);
	lua_register_dxserver_FireBulletDesc(tolua_S);
	lua_register_dxserver_ChangeSpeedDesc(tolua_S);
	lua_register_dxserver_Scene(tolua_S);
	lua_register_dxserver_BulletDesc(tolua_S);
	lua_register_dxserver_OrientationDesc(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

