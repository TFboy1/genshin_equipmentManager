
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
    // ������
    void addPlayer(Player* player);
//  �Ƴ����
void removePlayer(Player* player);

// ��ʾ�������
void displayAllPlayers() const;

// ����ID��ȡ���
Player* getPlayerById(int id);

// ���������Ϣ
void updatePlayer(Player* player);

};
#endif // PLAYERMANAGER_H