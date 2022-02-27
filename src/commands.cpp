#include "libGameLogic.h"
#include "utils.h"
#include "landmark.h"
#include "originalFunctions.h"


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