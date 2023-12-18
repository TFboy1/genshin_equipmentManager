#include"Player.h"
#include "PlayerManager.h"
#include <iostream>
#include <fstream>


// 将玩家信息保存到文件
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

// 从文件中加载玩家信息
void PlayerManager::loadFromFile() {
    ifstream file("players.txt");
    
        
        players.clear(); // 清空原有玩家信息
        if (file.is_open()) {
           
        int id, level,balance;
        std::string name;
        while (file >> id >> name >> level >> balance) {
            Player* player = new Player(id, name, level, balance);
            players.push_back(player);
        }
        for (const Player* player : players) {
            if(player->Getid()!=PlayerManager::id)
                PlayerManager::id++;
        }
        file.close();
    }
}
//void PlayerManager::saveToFile() const {
//    std::ofstream file("players.dat", std::ios::binary);
//
//    if (file.is_open()) {
//        // 保存玩家数量
//        int numPlayers = players.size();
//        file.write(reinterpret_cast<const char*>(&numPlayers), sizeof(int));
//
//        // 保存每个玩家
//        for (const Player* player : players) {
//            // 序列化 Player 对象
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
//        // 读取玩家数量
//        int numPlayers;
//        file.read(reinterpret_cast<char*>(&numPlayers), sizeof(int));
//
//        // 读取每个玩家
//        for (int i = 0; i < numPlayers; ++i) {
//            // 反序列化 Player 对象
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
// 构造函数中加载玩家信息
PlayerManager::PlayerManager() :id(0){

    loadFromFile();
}

// 析构函数中保存玩家信息
PlayerManager::~PlayerManager() {
    
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
    if (players.empty()) {
    cout<<"暂无玩家"<<endl;
    }
    for (const Player* player : players) {
        cout << "Player ID: " << player->Getid() << ", Name: " << player->Getname()<<"，level:"<<player->Getlevel() << "，balance:"<< player->getBalance()<<endl;
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