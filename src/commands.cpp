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

void commandTeleportToPosition(std::vector<std::string> arguments) {
    int x, y, z;
    x = std::stof(arguments[0]);
    y = std::stof(arguments[1]);
    z = std::stof(arguments[2]);

    Vector3 position(x, y, z);

    Player *myself = gameGetMyselfFromClientWorld();
    myself->SetPosition(position);
}

void commandTest(std::vector<std::string> arguments) {
    std::cout << arguments[0] << std::endl;
}

// /startServer
void commandStartServer() {
    std::string host = "127.0.0.1";
    GameProtocol gameprotocol(host, 8080, 1024);

    gameprotocol.registerCommand("/teleport", commandTeleportToPosition);
    gameprotocol.registerCommand("/hello", commandTest);
    std::thread server(gameprotocol);
}