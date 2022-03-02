#ifndef UTILS_H
#define UTILS_H


#include <dlfcn.h>

#include "libGameLogic.h"


void* gameGetAddressByName(const char* name);
Player* gameGetMyselfFromClientWorld();


std::vector<std::string> stringSplit(const std::string& s, const char delimiter);
std::string stringLStrip(const std::string& s, const char c);
std::string stringRStrip(const std::string& s, const char c);
std::string stringStrip(const std::string& s, const char c);
std::string stringJoin(const char c, const std::vector<std::string>& strs);

#endif /* UTILS_H */