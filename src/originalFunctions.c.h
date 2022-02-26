#ifndef ORIGINAL_FUNCTIONS_H
#define ORIGINAL_FUNCTIONS_H


#include "utils.h"
#include "libGameLogic.h"


struct OriginFunctions {
    void (*Player_Chat)(Player*, const char*);
} OriginFunctions = {
    .Player_Chat = (void (*)(Player*, const char*))gameGetAddressByName("_ZN6Player4ChatEPKc")
};


#endif /* ORIGINAL_FUNCTIONS_H */