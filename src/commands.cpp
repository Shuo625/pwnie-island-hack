#include <chrono>

#include "libGameLogic.h"
#include "utils.h"
#include "landmark.h"
#include "originalFunctions.h"
#include "gameProtocol.h"


// /setWalkSpeed arg
void commandSetWalkSpeed(float walkSpeed) {
    Player *myself = gameGetMyselfFromClientWorld();
    myself->m_walkingSpeed = walkSpeed;
}

// /setJumpSpeed arg
void commandSetJumpSpeed(float jumpSpeed) {
    Player *myself = gameGetMyselfFromClientWorld();
    myself->m_jumpSpeed = jumpSpeed;
}

// /setJumpHoldTime arg
void commandSetJumpHoldTime(float jumpHoldTime) {
    Player *myself = gameGetMyselfFromClientWorld();
    myself->m_jumpHoldTime = jumpHoldTime;
}

// /saveLandmark name
void commandSaveLandmark(const std::string& name) {
    Player *myself = gameGetMyselfFromClientWorld();
    Landmark *currentLandmark = new Landmark(name, myself->GetPosition());
    landmarkSave(currentLandmark);

    // Construct a message string sent to python server
    Vector3 position = myself->GetPosition();

    std::string message = "";
    message += "/saveLandmark";
    message += " ";
    message += name + " ";
    message += std::to_string(position.x) + " ";
    message += std::to_string(position.y) + " ";
    message += std::to_string(position.z);
    
    GameProtocol::call_remote_command(message, "127.0.0.1", 8081);
}

// /showLandmark
void commandShowLandmark() {
    Player *myself = gameGetMyselfFromClientWorld();

    std::string text = "";

    for (auto it = savedLandmarks.begin(); it != savedLandmarks.end(); it++) {
        text += it->first;
        text += " ";
    }

    OriginFunctions.Player_Chat(myself, text.c_str());
}

// /teleportToLandmark name
void commandTeleportToLandmark(const std::string& name) {
    Player *myself = gameGetMyselfFromClientWorld();
    Landmark* landmark = landmarkGetByName(name);
    myself->SetPosition(landmark->position);
}

// /printPosition
void commandPrintPosition() {
    Player *myself = gameGetMyselfFromClientWorld();
    Vector3 position = myself->GetPosition();
    std::cout << "Current position " << position.x << " " << position.y << " " << position.z << std::endl;
}


// commands used by server
void commandTeleportToPosition(std::vector<std::string> arguments) {
    float x, y, z;
    x = std::stof(arguments[0]);
    y = std::stof(arguments[1]);
    z = std::stof(arguments[2]);

    Vector3 position(x, y, z);

    Player *myself = gameGetMyselfFromClientWorld();
    myself->SetPosition(position);
}

void commandHello(std::vector<std::string> arguments) {
    std::cout << arguments[0] << std::endl;
}

// /updateMyselfPosition
void updateMyselfPosition() {
    int SLEEP_TIME = 1500;

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
        Player *myself = gameGetMyselfFromClientWorld();
        Vector3 position = myself->GetPosition();
        
        std::string message = "/updateMyselfPosition ";
        message += std::to_string(position.x);
        message += " ";
        message += std::to_string(position.y);
        message += " ";
        message += std::to_string(position.z);

        GameProtocol::call_remote_command(message);
    }
}

// /startServer
void commandStartServer() {
    GameProtocol gameprotocol("127.0.0.1", 8080, 1024);

    // Register supported commands
    gameprotocol.registerCommand("/teleport", commandTeleportToPosition);
    gameprotocol.registerCommand("/hello", commandHello);
    
    std::thread server(gameprotocol);
    server.detach();

    std::thread t(updateMyselfPosition);
    t.detach();
}