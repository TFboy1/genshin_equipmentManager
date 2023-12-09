#include"Player.h"
#include "PlayerManager.h"
#include <iostream>
#include <fstream>
//int PlayerManager::id = 0;
// 将玩家信息保存到文件
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

// 从文件中加载玩家信息
void PlayerManager::loadFromFile() {
    std::ifstream file("players.txt");
    
        
        players.clear(); // 清空原有玩家信息
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

// 构造函数中加载玩家信息
PlayerManager::PlayerManager() :id(0){

    loadFromFile();
}

// 析构函数中保存玩家信息
PlayerManager::~PlayerManager() {
    saveToFile();
}

// 添加玩家
void PlayerManager::addPlayer(Player* player) {
    int flag = 0;
    for (const auto& element : players) {
        if (element->Getname() == player->Getname())
        {
            cout<<"该玩家已存在"<<endl;
            flag = 1;
            break;

        }
            
    }
    if (flag == 0) {
        cout << "角色创建成功" << endl;
        id++;
        player->Setid(id);
    players.push_back(player);
    saveToFile(); // 添加玩家后保存到文件
  
    }
    
    
    
}

// 移除玩家
void PlayerManager::removePlayer(Player* player) {
    players.erase(std::remove(players.begin(), players.end(), player), players.end());
    saveToFile(); // 移除玩家后保存到文件
}

// 显示所有玩家
void PlayerManager::displayAllPlayers() const {
    for (const Player* player : players) {
        std::cout << "Player ID: " << player->Getid() << ", Name: " << player->Getname() << ", Level: " << player->Getlevel() << std::endl;
    }
}

// 根据ID获取玩家
Player* PlayerManager::getPlayerById(int id) {
    for (Player* player : players) {
        if (player->Getid() == id) {
            return player;
        }
    }
    return nullptr;
}



// 更新玩家信息
void PlayerManager::updatePlayer(Player* player) {
    cout << "更新后玩家信息: 玩家ID: " << player->Getid() << ", 姓名: " << player->Getname() << ", 等级: " << player->Getlevel() << endl;
    saveToFile();
}