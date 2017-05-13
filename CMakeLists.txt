project(DXServer)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_C_FLAGS_DEBUG "-g -Wall -DCOCOS2D_DEBUG=1")
set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wno-deprecated-declarations -Wno-reorder")
set(APP_NAME DXServer)

include_directories("external/eigen")
include_directories("external/asio/include")
include_directories("external/lua/lua")
include_directories("external/lua/tolua")
include_directories("external/json")
include_directories("external")

add_subdirectory("external/lua/lua")
add_subdirectory("external/Box2D")

file(GLOB DX_LUA_SRC
    "external/lua/cjson/*.c"
    "external/lua/tolua/*.c"
)

include_directories(
    src
    src/utils
    src/data
    src/desc
    src/behaviours
    src/objects
)

set(DXSERVER_SRC
    src/utils/DataBuf.cpp
    src/utils/FileUtils.cpp
    src/utils/WeightedTimedMovingAverage.cpp
    src/desc/GameObjectDesc.cpp
    src/desc/VehicleDesc.cpp
    src/desc/BulletDesc.cpp
    src/desc/PlayerDesc.cpp
    src/desc/ScriptComponentDesc.cpp
    src/desc/SpriteDesc.cpp
    src/scripting/tolua_fix.cpp
    src/scripting/LuaRef.cpp
    src/scripting/LuaState.cpp
    src/scripting/DXServerLuaLoader.cpp
    src/scripting/lua_dxserver_manual.cpp
    src/scripting/auto/lua_dxserver_auto.cpp
    src/behaviours/Action.cpp
    src/behaviours/NumericDesc.cpp
    src/behaviours/GameActionDesc.cpp
    src/behaviours/PlaceObjectDesc.cpp
    src/behaviours/ActionDesc.cpp
    src/behaviours/RepeatDesc.cpp
    src/behaviours/ChangeSpeedDesc.cpp
    src/behaviours/ChangeDirectionDesc.cpp
    src/behaviours/AccelDesc.cpp
    src/behaviours/WaitDesc.cpp
    src/behaviours/VanishDesc.cpp
    src/objects/GameObject.cpp
    src/objects/Vehicle.cpp
    src/objects/Bullet.cpp
    src/objects/PlayerObject.cpp
    src/objects/ObjectManager.cpp
    src/Scene.cpp
    src/SceneManager.cpp
    src/InputPacket.cpp
    src/InputPacketList.cpp
    src/AckRange.cpp
    src/InFlightPacket.cpp
    src/DeliveryNotifier.cpp

    src/ReplicationCommand.cpp
    src/ReplicationManager.cpp
    src/ReplicationManagerTransmissionData.cpp
    src/ClientProxy.cpp
    src/Packet.cpp
    src/UDPSocket.cpp
    src/GameServer.cpp
    src/main.cpp
)

set(DXSERVER_HEADERS
    src/behaviours/ActionDescs.h
    src/objects/Objects.h
    src/data/TypeTraits.h
    src/data/ByteParser.h
    src/data/LuaParser.h
    src/data/JSONParser.h
    src/data/DataParser.h
    src/data/DataMacros.h
    src/NetTypes.h
    src/TransmissionData.h
)

add_executable(${APP_NAME} ${DX_LUA_SRC} ${DXSERVER_SRC} ${DXSERVER_HEADERS})
add_dependencies(${APP_NAME} lua)
target_link_libraries(${APP_NAME} pthread lua box2d)

macro(pre_build TARGET_NAME)
  add_custom_target( ${TARGET_NAME}_PRE_BUILD ALL )
  add_custom_command(
    TARGET ${TARGET_NAME}_PRE_BUILD
    ${ARGN}
    PRE_BUILD
    COMMENT "${TARGET_NAME}_PRE_BUILD ..."
    )
  add_custom_target(${TARGET_NAME}_CORE_PRE_BUILD)
  add_dependencies(${TARGET_NAME}_PRE_BUILD ${TARGET_NAME}_CORE_PRE_BUILD)
  add_dependencies(${TARGET_NAME} ${TARGET_NAME}_PRE_BUILD)
endmacro()

set(APP_BIN_DIR "${CMAKE_BINARY_DIR}/bin")
set_target_properties(${APP_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${APP_BIN_DIR})

pre_build(${APP_NAME}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${APP_BIN_DIR}/lua
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/lua ${APP_BIN_DIR}/lua
)
