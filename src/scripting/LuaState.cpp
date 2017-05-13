#include "../GameServer.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
#include "tolua++.h"
#include "tolua_fix.h"
#include "DXServerLuaLoader.h"
#include "lua_dxserver_manual.h"

int lua_print(lua_State * luastate) {
    int nargs = lua_gettop(luastate);
    std::string t;
    for (int i=1; i <= nargs; i++) {
        if (lua_istable(luastate, i))
            t += "table";
        else if (lua_isnone(luastate, i))
            t += "none";
        else if (lua_isnil(luastate, i))
            t += "nil";
        else if (lua_isboolean(luastate, i))
        {
            if (lua_toboolean(luastate, i) != 0)
                t += "true";
            else
                t += "false";
        }
        else if (lua_isfunction(luastate, i))
            t += "function";
        else if (lua_islightuserdata(luastate, i))
            t += "lightuserdata";
        else if (lua_isthread(luastate, i))
            t += "thread";
        else {
            const char * str = lua_tostring(luastate, i);
            if (str)
                t += lua_tostring(luastate, i);
            else
                t += lua_typename(luastate, lua_type(luastate, i));
        }
        if (i!=nargs)
            t += "\t";
    }
    std::cout <<  "[LUA-print] " << t << std::endl;
    return 0;
}

LuaState* LuaState::getInstance() {
    GameServer::getInstance()->getLuaState();
}

LuaState::~LuaState() {
    if (m_state) {
        lua_close(m_state);
    }
}

void LuaState::init() {
    m_state = lua_open();
    luaL_openlibs(m_state);
    toluafix_open(m_state);
    // Register our version of the global "print" function
    const luaL_reg global_functions [] = {
        {"print", lua_print},
        {nullptr, nullptr}
    };
    luaL_register(m_state, "_G", global_functions);
    addLuaLoader(dx_server_lua_loader);
    register_dxserver_module(m_state);
}

lua_State* LuaState::get() {
    return GameServer::getInstance()->getLuaState()->m_state;
}

void LuaState::addSearchPath(const char* path) {
    lua_getglobal(m_state, "package");                        /* L: package */
    lua_getfield(m_state, -1, "path");                        /* get package.path, L: package path */
    const char* cur_path =  lua_tostring(m_state, -1);
    lua_pushfstring(m_state, "%s;%s/?.lua", cur_path, path);  /* L: package path newpath */
    lua_setfield(m_state, -3, "path");                        /* package.path = newpath, L: package path */
    lua_pop(m_state, 2);                                      /* L: - */
}

void LuaState::addLuaLoader(lua_CFunction func) {
    if (!func) return;
    // stack content after the invoking of the function
    // get loader table
    lua_getglobal(m_state, "package");                                  /* L: package */
    lua_getfield(m_state, -1, "loaders");                               /* L: package, loaders */
    // insert loader into index 2
    lua_pushcfunction(m_state, func);                                   /* L: package, loaders, func */
    for (int i = (int)(lua_objlen(m_state, -2) + 1); i > 2; --i) {
        lua_rawgeti(m_state, -2, i - 1);                                /* L: package, loaders, func, function */
        // we call lua_rawgeti, so the loader table now is at -3
        lua_rawseti(m_state, -3, i);                                    /* L: package, loaders, func */
    }
    lua_rawseti(m_state, -2, 2);                                        /* L: package, loaders */
    // set loaders into package
    lua_setfield(m_state, -2, "loaders");                               /* L: package */
    lua_pop(m_state, 1);
}

static const std::string BYTECODE_FILE_EXT    = ".luac";
static const std::string NOT_BYTECODE_FILE_EXT = ".lua";

int LuaState::executeScriptFile(const char* filename) {
    //CCAssert(filename, "CCLuaStack::executeScriptFile() - invalid filename");
    std::string buf(filename);
    //
    // remove .lua or .luac
    //
    size_t pos = buf.rfind(BYTECODE_FILE_EXT);
    if (pos != std::string::npos) {
        buf = buf.substr(0, pos);
    }
    else {
        pos = buf.rfind(NOT_BYTECODE_FILE_EXT);
        if (pos == buf.length() - NOT_BYTECODE_FILE_EXT.length())
        {
            buf = buf.substr(0, pos);
        }
    }
    FileUtils *utils = FileUtils::getInstance();
    //
    // 1. check .lua suffix
    // 2. check .luac suffix
    //
    std::string tmpfilename = buf + NOT_BYTECODE_FILE_EXT;
    if (utils->isFileExist(tmpfilename)) {
        buf = tmpfilename;
    }
    else {
        tmpfilename = buf + BYTECODE_FILE_EXT;
        if (utils->isFileExist(tmpfilename))
        {
            buf = tmpfilename;
        }
    }
    std::string fullPath = utils->fullPathForFilename(buf);
    std::cout << fullPath << std::endl;
    DataBuf data = utils->getDataFromFile(fullPath);
    int rn = 0;
    if (!data.isNull()) {
        if (luaL_loadbuffer(m_state, (const char*)data.getData(),
                (int)data.getSize(), fullPath.c_str()) == 0) {
            rn = executeFunction(0);
        }
    }
    return rn;
}

int LuaState::executeFunction(int numArgs) {
    int functionIndex = -(numArgs + 1);
    if (!lua_isfunction(m_state, functionIndex)) {
        //CCLOG("value at stack [%d] is not function", functionIndex);
        lua_pop(m_state, numArgs + 1); // remove function and arguments
        return 0;
    }
    int traceback = 0;
    lua_getglobal(m_state, "__G__TRACKBACK__");                         /* L: ... func arg1 arg2 ... G */
    if (!lua_isfunction(m_state, -1)) {
        lua_pop(m_state, 1);                                            /* L: ... func arg1 arg2 ... */
    }
    else {
        lua_insert(m_state, functionIndex - 1);                         /* L: ... G func arg1 arg2 ... */
        traceback = functionIndex - 1;
    }
    int error = 0;
    ++m_callFromLua;
    error = lua_pcall(m_state, numArgs, 1, traceback);                  /* L: ... [G] ret */
    --m_callFromLua;
    if (error) {
        if (traceback == 0) {
            std::cerr << "[LUA ERROR] " << lua_tostring(m_state, - 1) << std::endl;        /* L: ... error */
            lua_pop(m_state, 1); // remove error message from stack
        }
        else {                                                            /* L: ... G error */
            lua_pop(m_state, 2); // remove __G__TRACKBACK__ and error message from stack
        }
        return 0;
    }
    // get return value
    int ret = 0;
    if (lua_isnumber(m_state, -1)) {
        ret = (int)lua_tointeger(m_state, -1);
    }
    else if (lua_isboolean(m_state, -1)) {
        ret = (int)lua_toboolean(m_state, -1);
    }
    // remove return value from stack
    lua_pop(m_state, 1);                                                /* L: ... [G] */
    if (traceback) {
        lua_pop(m_state, 1); // remove __G__TRACKBACK__ from stack      /* L: ... */
    }
    return ret;
}

