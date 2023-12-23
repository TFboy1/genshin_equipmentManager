
#pragma once
#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include"Player.h"

using namespace std;
class PlayerManager {
private:
    vector<Player*> players;
    /*static int id;*/
    int id;
public:
void saveToFile() const;
void loadFromFile();
PlayerManager();
~PlayerManager();
    // 添加玩家
    void addPlayer(Player* player);
//  移除玩家
void removePlayer(Player* player);

// 显示所有玩家
void displayAllPlayers() const;

// 根据ID获取玩家
Player* getPlayerById(int id);

// 更新玩家信息
void updatePlayer(Player* player);

};
#endif // PLAYERMANAGER_H