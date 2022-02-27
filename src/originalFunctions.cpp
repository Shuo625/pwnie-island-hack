#include "originalFunctions.h"
#include "utils.h"


struct OriginFunctions OriginFunctions = {
    .Player_Chat = (void (*)(Player*, const char*))gameGetAddressByName("_ZN6Player4ChatEPKc")
};