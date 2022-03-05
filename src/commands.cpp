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

// /showEggs
void commandShowEggs() {

    // Locations of the eggs were aquired by investigating positions of all actor objects, an egg is an actor
    // Construct a message string sent to python server
    std::string message = "";
    message += "/showEggs";
    message += " ";
    message += 'First Egg' + " ";
    message += std::to_string(11604.00) + " ";
    message += std::to_string(-13131.00) + " ";
    message += std::to_string(411.00);
    
    GameProtocol::call_remote_command(message, "127.0.0.1", 8081);

    // Construct a message string sent to python server
    std::string message = "";
    message += "/showEggs";
    message += " ";
    message += 'Second Egg' + " ";
    message += std::to_string(-72667.00) + " ";
    message += std::to_string(-53567.00) + " ";
    message += std::to_string(1645.00);
    
    GameProtocol::call_remote_command(message, "127.0.0.1", 8081);

    // Construct a message string sent to python server
    std::string message = "";
    message += "/showEggs";
    message += " ";
    message += 'Third Egg' + " ";
    message += std::to_string(-25045.00) + " ";
    message += std::to_string(-18085.00) + " ";
    message += std::to_string(260.00);
    
    GameProtocol::call_remote_command(message, "127.0.0.1", 8081);

    // Construct a message string sent to python server
    std::string message = "";
    message += "/showEggs";
    message += " ";
    message += 'Fourth Egg' + " ";
    message += std::to_string(60453.00) + " ";
    message += std::to_string(-17409.00) + " ";
    message += std::to_string(2939.00);
    
    GameProtocol::call_remote_command(message, "127.0.0.1", 8081);

    // Construct a message string sent to python server
    std::string message = "";
    message += "/showEggs";
    message += " ";
    message += 'Fifth Egg' + " ";
    message += std::to_string(48404.00) + " ";
    message += std::to_string(28117.00) + " ";
    message += std::to_string(704.00);
    
    GameProtocol::call_remote_command(message, "127.0.0.1", 8081);

    // Construct a message string sent to python server
    std::string message = "";
    message += "/showEggs";
    message += " ";
    message += 'Sixth Egg' + " ";
    message += std::to_string(65225.00) + " ";
    message += std::to_string(-5740.00) + " ";
    message += std::to_string(4928.00);
    
    GameProtocol::call_remote_command(message, "127.0.0.1", 8081);

    // Construct a message string sent to python server
    std::string message = "";
    message += "/showEggs";
    message += " ";
    message += 'Seventh Egg' + " ";
    message += std::to_string(-51570.00) + " ";
    message += std::to_string(-61215.00) + " ";
    message += std::to_string(5020.00);
    
    GameProtocol::call_remote_command(message, "127.0.0.1", 8081);

    // Construct a message string sent to python server
    std::string message = "";
    message += "/showEggs";
    message += " ";
    message += 'Eighth Egg' + " ";
    message += std::to_string(24512.00) + " ";
    message += std::to_string(69682.00) + " ";
    message += std::to_string(2659.00);
    
    GameProtocol::call_remote_command(message, "127.0.0.1", 8081);

    // Construct a message string sent to python server
    std::string message = "";
    message += "/showEggs";
    message += " ";
    message += 'Last Egg' + " ";
    message += std::to_string(-2778.00) + " ";
    message += std::to_string(-11035.00) + " ";
    message += std::to_string(10504.00);
    
    GameProtocol::call_remote_command(message, "127.0.0.1", 8081);


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