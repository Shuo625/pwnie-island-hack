#include "libGameLogic.h" // <= this is the header for the target program that was reconstructed using gdb 
#include "utils.h"

// Compile this code with:
// g++ speedBoost.cpp -shared -fPIC -o speedBoost.so
//
//To run copy the so file to the game dir and run:
// LD_PRELOAD=speedBoost.so ./PwnAdventure3-Linux-Shipping

// This method will be called everytime the user jumps (presses space).
void Player::SetJumpState(bool b) {
    // set the player jump to very high values.  
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
