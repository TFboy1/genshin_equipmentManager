#include"Player.h"
#include "PlayerManager.h"
#include <iostream>
#include <fstream>


// �������Ϣ���浽�ļ�
void PlayerManager::saveToFile() const {
    std::ofstream file("players.txt");
    if (file.is_open()) {
        

        for (Player* player : players) {
            file << player->Getid() << " " << player->Getname() << " " << player->Getlevel() << " " << player->getBalance() << "\n";
            
            
        }
        file.close();
    }
    else {
        std::cout << "Unable to open file for writing." << std::endl;
    }
}

// ���ļ��м��������Ϣ
void PlayerManager::loadFromFile() {
    ifstream file("players.txt");
    
    int max=0;
        players.clear(); // ���ԭ�������Ϣ
        if (file.is_open()) {
           
        int id, level,balance;
        std::string name;
        while (file >> id >> name >> level >> balance) {
            Player* player = new Player(id, name, level, balance);
            players.push_back(player);
        }
        for (const Player* player : players) {
            if (player->Getid() > max)
                max = player->Getid();
        }

        PlayerManager::id=++max;

        file.close();
    }
}
//void PlayerManager::saveToFile() const {
//    std::ofstream file("players.dat", std::ios::binary);
//
//    if (file.is_open()) {
//        // �����������
//        int numPlayers = players.size();
//        file.write(reinterpret_cast<const char*>(&numPlayers), sizeof(int));
//
//        // ����ÿ�����
//        for (const Player* player : players) {
//            // ���л� Player ����
//            file.write(reinterpret_cast<const char*>(player), sizeof(Player));
//        }
//
//        file.close();
//    }
//    else {
//        std::cout << "Unable to open file for writing." << std::endl;
//    }
//}
//
//void PlayerManager::loadFromFile() {
//    std::ifstream file("players.dat", std::ios::binary);
//
//    players.clear();
//
//    if (file.is_open()) {
//        // ��ȡ�������
//        int numPlayers;
//        file.read(reinterpret_cast<char*>(&numPlayers), sizeof(int));
//
//        // ��ȡÿ�����
//        for (int i = 0; i < numPlayers; ++i) {
//            // �����л� Player ����
//            Player* player = new Player();
//            file.read(reinterpret_cast<char*>(player), sizeof(Player));
//            players.push_back(player);
//        }
//        for (const Player* player : players) {
//            id++;
//        }
//
//        file.close();
//    }
//}
// ���캯���м��������Ϣ
PlayerManager::PlayerManager() :id(0){

    loadFromFile();
}

// ���������б��������Ϣ
PlayerManager::~PlayerManager() {
    
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
    if (players.empty()) {
    cout<<"�������"<<endl;
    }
    for (const Player* player : players) {
        cout << "Player ID: " << player->Getid() << ", Name: " << player->Getname()<<"��level:"<<player->Getlevel() << "��balance:"<< player->getBalance()<<endl;
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