#include "libGameLogic.h"
#include "utils.h"
#include "commands.h"
#include "originalFunctions.c.h"


bool _isCommand(const std::string& s) {
    return s.length() > 0 && s.at(0) == '/';
}

std::string _getCommandOperation(const std::string& commandStr) {
    size_t pos = 0;
    std::string operation;

    while (commandStr.at(pos) != ' ') {
        pos++;
    }

    operation = commandStr.substr(0, pos);

    return operation;
}

std::vector<std::string> _getCommandArguments(const std::string& commandStr) {
    size_t pos = 0;
    std::string argumentsStr;
    std::vector<std::string> arguments;

    while (commandStr.at(pos) != ' ') {
        pos++;
    }

    argumentsStr = commandStr.substr(pos + 1);

    arguments = stringSplit(argumentsStr, ' ');

    return arguments;
}

void _executeCommand(std::string commandStr) {
    std::string operation;
    std::vector<std::string> arguments;

    operation = _getCommandOperation(commandStr);
    arguments = _getCommandArguments(commandStr);

    if (operation == "/setWalkSpeed") {
        float walkSpeed = std::stof(arguments[0]);
        commandSetWalkSpeed(walkSpeed);

        std::cout << "Command: /setWalkSpeed " << walkSpeed << std::endl;
    } else if (operation == "/setJumpSpeed") {
        float jumpSpeed = std::stof(arguments[0]);
        commandSetJumpSpeed(jumpSpeed);

        std::cout << "Command: /setJumpSpeed " << jumpSpeed << std::endl;
    } else if (operation == "/setJumpHoldTime") {
        float jumpHoldTime = std::stof(arguments[0]);
        commandSetJumpHoldTime(jumpHoldTime);

        std::cout << "Command: /setJumpHoldTime " << jumpHoldTime << std::endl;
    }
}

// You had better not change this function. Do everything you want in _executeCommand().
void Player::Chat(const char* text) {
    std::string textStr(text);

    // Notice that length of text could be 0
    if (textStr.length() == 0) {
        OriginFunctions.Player_Chat(this, text);
        return;
    }

    textStr = stringStrip(textStr, ' ');

    if (_isCommand(textStr)) {
        _executeCommand(textStr);
    } else {
        OriginFunctions.Player_Chat(this, text);
    }
}