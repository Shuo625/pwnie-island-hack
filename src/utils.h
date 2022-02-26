#ifndef UTILS_H
#define UTILS_H


#include <dlfcn.h>

#include "libGameLogic.h"


void* getAddressByName(const char* name);
Player* getMyselfFromClientWorld();


#endif /* UTILS_H */