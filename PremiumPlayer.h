#ifndef PREMIUMPLAYER_H
#define PREMIUMPLAYER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include"Player.h"
#include"PlayerManager.h"
#include "Store.h"

using namespace std;

class PremiumPlayer:public Player{
private:
    Store *store;
    PlayerManager playerManager;
    Player &player;

public:
    PremiumPlayer(Player& player, PlayerManager& playerManager);
    ~PremiumPlayer();
    void addPremiumBenefits();//高级玩家特权菜单
    void accessGameStore();//访问游戏商店
};

#endif