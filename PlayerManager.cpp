#include "Player.h"
#include "PlayerManager.h"
#include <iostream>
#include <fstream>

// 将玩家信息保存到文件
void PlayerManager::saveToFile() const
{
    std::ofstream file("players.txt");
    if (file.is_open())
    {

        for (Player *player : players)
        {
            file << player->Getid() << " " << player->Getname() << " " << player->Getlevel() << " " << player->getBalance() << " " << player->Gethealth()
                 << " " << player->Getattack() << " " << player->Getdefense()
                 << "\n";
        }
        file.close();
    }
    else
    {
        std::cout << "Unable to open file for writing." << std::endl;
    }
}

// 从文件中加载玩家信息
void PlayerManager::loadFromFile()
{
    ifstream file("players.txt");

    players.clear(); // 清空原有玩家信息
    if (file.is_open())
    {
        int max = 0;
        int id, level, balance, health, attack, defense;
        std::string name;
        while (file >> id >> name >> level >> balance >> health >> attack >> defense)
        {
            Player *player = new Player(id, name, level, balance, health, attack, defense);
            players.push_back(player);
        }
        for (const Player *player : players)
        {
            if (player->Getid() > max)
                max = player->Getid();
        }
        PlayerManager::id = max;
        file.close();
    }
}

PlayerManager::PlayerManager() : id(0)
{
    loadFromFile();
}

// 析构函数中保存玩家信息
PlayerManager::~PlayerManager()
{
}

// 添加玩家
void PlayerManager::addPlayer(Player *player)
{
    int flag = 0;
    for (const auto &element : players)
    {
        if (element->Getname() == player->Getname())
        {
            cout << "该玩家已存在" << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "角色创建成功" << endl;
        id++;
        player->Setid(id);
        player->getEquipmentManager().initEquipments(id);
        players.push_back(player);
        saveToFile(); // 添加玩家后保存到文件
    }
}

// 移除玩家
void PlayerManager::removePlayer(Player *player)
{
    players.erase(std::remove(players.begin(), players.end(), player), players.end());
    saveToFile(); // 移除玩家后保存到文件
}

// 显示所有玩家
void PlayerManager::displayAllPlayers() const
{
    if (players.empty())
    {
        cout << "暂无玩家" << endl;
    }
    for (const Player *player : players)
    {
        cout << "Player ID: " << player->Getid() << ", Name: " << player->Getname() << "，level:" << player->Getlevel() << "，balance:" << player->getBalance()
             << ", Health: " << player->Gethealth() << ", Attack: " << player->Getattack() << ", Defense: " << player->Getdefense()
             << endl;
    }
}

// 根据ID获取玩家
Player *PlayerManager::getPlayerById(int id)
{
    for (Player *player : players)
    {
        if (player->Getid() == id)
        {
            return player;
        }
    }
    return nullptr;
}

// 更新玩家信息
void PlayerManager::updatePlayer(Player *player)
{
    cout << "更新后玩家信息: 玩家ID: " << player->Getid() << ", 姓名: " << player->Getname() << ", 等级: " << player->Getlevel() << endl;
    saveToFile();
}