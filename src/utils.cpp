#include "utils.h"


/*
 * Game Helper Functions
 */

void* gameGetAddressByName(const char* name) {
    return dlsym(RTLD_NEXT, name);
}

Player* gameGetMyselfFromClientWorld() {
    ClientWorld* world = *((ClientWorld**)(gameGetAddressByName("GameWorld")));

    // we know these names from the libGameLogic.h file.
    IPlayer* iplayer = world->m_activePlayer.m_object;
    Player* player = ((Player*)(iplayer));
    Actor* actor = ((Actor*)(iplayer));

    return player;
}


/*
 * String Helper Functions
 */

std::vector<std::string> stringSplit(const std::string& s, const char delimiter) {
    std::string tmp;
    std::stringstream streamStr(s);

    std::vector<std::string> rst;

    while (getline(streamStr, tmp, delimiter)) {
        rst.push_back(tmp);
    }

    return rst;
}

std::string stringLStrip(const std::string& s, const char c) {
    std::string rst = s;
    size_t pos = 0;

    while (rst.at(pos) == c) {
        pos++;
    }

    rst.erase(0, pos);

    return rst;
}

std::string stringRStrip(const std::string& s, const char c) {
    std::string rst = s;
    size_t pos = rst.length() - 1;

    while (rst.at(pos) == c) {
        pos--;
    }

    rst.erase(pos + 1, rst.length());

    return rst;
}

std::string stringStrip(const std::string& s, const char c) {
    std::string rst = s;

    rst = stringLStrip(rst, c);
    rst = stringRStrip(rst, c);

    return rst;
}
