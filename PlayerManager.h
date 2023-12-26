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
    void saveToFile() const;//�������Ϣ���浽�ļ�
    void loadFromFile();//���ļ��м��������Ϣ
    PlayerManager();
    ~PlayerManager();
    void addPlayer(Player* player);//������
    void removePlayer(Player* player);//�Ƴ����
    void displayAllPlayers() const; //��ʾ�������
    Player* getPlayerById(int id);//����ID��ȡ���
    void updatePlayer(Player* player);//���������Ϣ
};
#endif