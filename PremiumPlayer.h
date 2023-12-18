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
    // ¹¹Ôìº¯Êý
   /* PremiumPlayer(Player& player);*/
    PremiumPlayer(Player& player, PlayerManager& playerManager);
    ~PremiumPlayer();
    void addPremiumBenefits();
    void accessGameStore();
    PlayerManager getPlayerManager();
};

#endif // PREMIUM_PLAYER_H