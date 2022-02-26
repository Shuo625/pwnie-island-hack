#include "libGameLogic.h"
#include "utils.h"


void ServerWorld::SendHealthUpdateEvent(Actor *actor, int32_t health) {
    Player* myself = getMyselfFromClientWorld();

    void (*realSendHealthUpdateEvent)(Actor*, int32_t);

    realSendHealthUpdateEvent = (void (*)(Actor*, int32_t))getAddressByName("_ZN11ServerWorld21SendHealthUpdateEventEP5Actori");

    realSendHealthUpdateEvent((Actor*)myself, myself->GetMaxHealth());

    printf("use this f");
}
