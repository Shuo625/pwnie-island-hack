#include "libGameLogic.h"
#include "utils.h"


void ServerWorld::SendLastHitByItemEvent(Player *player, IItem *item) {
    printf("use 1");
}


void ClientWorld::SendLastHitByItemEvent(Player *player, IItem *item) {
    printf("use two");
}


void Player::PerformSetLastHitByItem(IItem *item) {
    printf("use three");
}

//void GameServerConnection::OnHealthUpdateEvent(Player *) {}