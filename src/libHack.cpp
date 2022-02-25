#include "libGameLogic.h" // <= this is the header for the target program that was reconstructed using gdb 

// Compile this code with:
// g++ speedBoost.cpp -shared -fPIC -o speedBoost.so
//
//To run copy the so file to the game dir and run:
// LD_PRELOAD=speedBoost.so ./PwnAdventure3-Linux-Shipping

// This method will be called everytime the user jumps (presses space).
void Player::SetJumpState(bool b) {

    // load a pointer to the GameWorld object:
    /*
    ClientWorld* world = *((ClientWorld**)(dlsym(RTLD_NEXT, "GameWorld")));

    // we know these names from the libGameLogic.h file.
    IPlayer* iplayer = world->m_activePlayer.m_object;
    Player* player = ((Player*)(iplayer));
    Actor* actor = ((Actor*)(iplayer));

    // print some data to the console that was used to start the program
    printf("[LO] %f \n", world->m_timeUntilNextNetTick);
    printf ("Speed %f\n", player->m_walkingSpeed);
    */

    // set the player jump to very high values. 
    // 
    this->m_jumpSpeed=5000;
    this->m_jumpHoldTime=20;

    // We now need to call the orginal Set Jump State method, otherwise the server
    // (and other players) will not see us jump. Here is a pointer we will set to
    // that function:
    void (*realSetJumpState)(Player*, bool);

    //To find the address of the real function we need to find its  orginal address
    //For this we need the "mangled" name, which we found open the libGameLogic.so 
    //file in IDA looking at the exprots and right clicking and deselecting "demangle"
    realSetJumpState =(void (*)(Player*, bool))dlsym(RTLD_NEXT, "_ZN6Player12SetJumpStateEb");

    //printf("realSetJumpState is at: %p\n", realSetJumpState);
    realSetJumpState(this, b); 
}


/*void Actor::PerformSetHealth(int32_t health) {
    void (*realPerformSetHealth)(int32_t);

    realPerformSetHealth = (void (*)(int32_t))dlsym(RTLD_NEXT, "_ZN5Actor16PerformSetHealthEi");

    realPerformSetHealth(100);

    printf("current health is %d\n", this->GetHealth());
}*/


void ServerWorld::SendHealthUpdateEvent(Actor *actor, int32_t health) {

}






// some utility functions
Player* getMyselfFromClient() {
    ClientWorld* world = *((ClientWorld**)(dlsym(RTLD_NEXT, "GameWorld")));

    // we know these names from the libGameLogic.h file.
    IPlayer* iplayer = world->m_activePlayer.m_object;
    Player* player = ((Player*)(iplayer));
    Actor* actor = ((Actor*)(iplayer));
}