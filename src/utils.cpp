#include "utils.h"


void* getAddressByName(const char* name) {
    return dlsym(RTLD_NEXT, name);
}


// some utility functions
Player* getMyselfFromClientWorld() {
    ClientWorld* world = *((ClientWorld**)(getAddressByName("GameWorld")));

    // we know these names from the libGameLogic.h file.
    IPlayer* iplayer = world->m_activePlayer.m_object;
    Player* player = ((Player*)(iplayer));
    Actor* actor = ((Actor*)(iplayer));

    return player;
}