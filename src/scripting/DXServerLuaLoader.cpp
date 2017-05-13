#include "DXServerLuaLoader.h"
#include <string>
#include <algorithm>
#include "LuaState.h"
#include "../utils/FileUtils.h"

extern "C"
{
    int dx_server_lua_loader(lua_State *L) {
        static const std::string BYTECODE_FILE_EXT    = ".luac";
        static const std::string NOT_BYTECODE_FILE_EXT = ".lua";
        std::string filename(luaL_checkstring(L, 1));
        size_t pos = filename.rfind(BYTECODE_FILE_EXT);
        if (pos != std::string::npos) {
            filename = filename.substr(0, pos);
        }
        else {
            pos = filename.rfind(NOT_BYTECODE_FILE_EXT);
            if (pos == filename.length() - NOT_BYTECODE_FILE_EXT.length())
            {
                filename = filename.substr(0, pos);
            }
        }
        pos = filename.find_first_of(".");
        while (pos != std::string::npos) {
            filename.replace(pos, 1, "/");
            pos = filename.find_first_of(".");
        }
        // search file in package.path
        unsigned char* chunk = nullptr;
        ssize_t chunkSize = 0;
        std::string chunkName;
        FileUtils* utils = FileUtils::getInstance();

        lua_getglobal(L, "package");
        lua_getfield(L, -1, "path");
        std::string searchpath(lua_tostring(L, -1));
        lua_pop(L, 1);
        size_t begin = 0;
        size_t next = searchpath.find_first_of(";", 0);
        do {
            if (next == std::string::npos)
                next = searchpath.length();
            std::string prefix = searchpath.substr(begin, next);
            if (prefix[0] == '.' && prefix[1] == '/') {
                prefix = prefix.substr(2);
            }
            pos = prefix.find("?.lua");
            chunkName = prefix.substr(0, pos) + filename + BYTECODE_FILE_EXT;
            if (utils->isFileExist(chunkName)) {
                chunk = utils->getFileData(chunkName.c_str(), "rb", &chunkSize);
                break;
            }
            else {
                chunkName = prefix.substr(0, pos) + filename + NOT_BYTECODE_FILE_EXT;
                if (utils->isFileExist(chunkName)) {
                    chunk = utils->getFileData(chunkName.c_str(), "rb", &chunkSize);
                    break;
                }
            }
            begin = next + 1;
            next = searchpath.find_first_of(";", begin);
        } while (begin < (int)searchpath.length());
        if (chunk) {
            LuaState* ls = LuaState::getInstance();
            auto r = luaL_loadbuffer(ls->get(), (char*)chunk, (int)chunkSize,
                chunkName.c_str());
            free(chunk);
        }
        else {
            //CCLOG("can not get file data of %s", chunkName.c_str());
            return 0;
        }
        return 1;
    }
}
