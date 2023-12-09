#include"Player.h"
#include "PlayerManager.h"
#include <iostream>
#include <fstream>
//int PlayerManager::id = 0;
// �������Ϣ���浽�ļ�
void PlayerManager::saveToFile() const {
    std::ofstream file("players.txt");
    if (file.is_open()) {
        

        for (const Player* player : players) {
            file << player->Getid() << " " << player->Getname() << " " << player->Getlevel() << "\n";
        }
        file.close();
    }
    else {
        std::cout << "Unable to open file for writing." << std::endl;
    }
}

// ���ļ��м��������Ϣ
void PlayerManager::loadFromFile() {
    std::ifstream file("players.txt");
    
        
        players.clear(); // ���ԭ�������Ϣ
        if (file.is_open()) {
           
        int id, level;
        std::string name;
        while (file >> id >> name >> level) {
            Player* player = new Player(id, name, level);
            players.push_back(player);
        }
        for (const Player* player : players) {
            if(player->Getid()!=PlayerManager::id)
                PlayerManager::id++;
        }
        file.close();
    }
}

// ���캯���м��������Ϣ
PlayerManager::PlayerManager() :id(0){

    loadFromFile();
}

// ���������б��������Ϣ
PlayerManager::~PlayerManager() {
    saveToFile();
}

// ������
void PlayerManager::addPlayer(Player* player) {
    int flag = 0;
    for (const auto& element : players) {
        if (element->Getname() == player->Getname())
        {
            cout<<"������Ѵ���"<<endl;
            flag = 1;
            break;

        }
            
    }
    if (flag == 0) {
        cout << "��ɫ�����ɹ�" << endl;
        id++;
        player->Setid(id);
    players.push_back(player);
    saveToFile(); // �����Һ󱣴浽�ļ�
  
    }
    
    
    
}

// �Ƴ����
void PlayerManager::removePlayer(Player* player) {
    players.erase(std::remove(players.begin(), players.end(), player), players.end());
    saveToFile(); // �Ƴ���Һ󱣴浽�ļ�
}

// ��ʾ�������
void PlayerManager::displayAllPlayers() const {
    for (const Player* player : players) {
        std::cout << "Player ID: " << player->Getid() << ", Name: " << player->Getname() << ", Level: " << player->Getlevel() << std::endl;
    }
}

// ����ID��ȡ���
Player* PlayerManager::getPlayerById(int id) {
    for (Player* player : players) {
        if (player->Getid() == id) {
            return player;
        }
    }
    return nullptr;
}



// ���������Ϣ
void PlayerManager::updatePlayer(Player* player) {
    cout << "���º������Ϣ: ���ID: " << player->Getid() << ", ����: " << player->Getname() << ", �ȼ�: " << player->Getlevel() << endl;
    saveToFile();
}