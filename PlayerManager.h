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
    int id;
public:
    void saveToFile() const;//将玩家信息保存到文件
    void loadFromFile();//从文件中加载玩家信息
    PlayerManager();
    ~PlayerManager();
    void addPlayer(Player* player);//添加玩家
    void removePlayer(Player* player);//移除玩家
    void displayAllPlayers() const; //显示所有玩家
    Player* getPlayerById(int id);//根据ID获取玩家
    void updatePlayer(Player* player);//更新玩家信息
};
#endif