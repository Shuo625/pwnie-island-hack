#ifndef ORIGINAL_FUNCTIONS_H
#define ORIGINAL_FUNCTIONS_H


#include "libGameLogic.h"


struct OriginFunctions {
    void (*Player_Chat)(Player*, const char*);
};

extern struct OriginFunctions OriginFunctions;


#endif /* ORIGINAL_FUNCTIONS_H */