#include "GameServer.h"

int main(int argc, char *argv[]) {
    auto netMgr = GameServer::getInstance();
    netMgr->start();
    GameServer::releaseInstance();
    return 0;
}
