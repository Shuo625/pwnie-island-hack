#include "originalFunctions.h"
#include "utils.h"


struct OriginFunctions OriginFunctions = {
    .Player_Chat = (void (*)(Player*, const char*))gameGetAddressByName("_ZN6Player4ChatEPKc"),
    .World_Tick = (void (*)(float))gameGetAddressByName("_ZN5World4TickEf")
};