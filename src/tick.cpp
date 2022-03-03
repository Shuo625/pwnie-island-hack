#include "libGameLogic.h"
#include "originalFunctions.h"
#include "gameProtocol.h"
#include "utils.h"


void World::Tick(float f) {
    Player *myself = gameGetMyselfFromClientWorld();
    Vector3 position = myself->GetPosition();
    
    std::string message = "/updateMyselfPosition ";
    message += std::to_string(position.x);
    message += " ";
    message += std::to_string(position.y);
    message += " ";
    message += std::to_string(position.z);

    GameProtocol::call_remote_command(message);

    OriginFunctions.World_Tick(f);
}
