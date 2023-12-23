#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include"EquipmentManager.h"
#include "Observer.h"
#include <sstream>

#include <fstream>
using namespace std;



// Player类
class Player {
protected:
	int id;
    string name;
    int level;
    vector<Observer*> observers;
    bool isPremiumPlayer;
    double balance;
    EquipmentManager equipmentManager;
    vector<int> inventory;  // 存储购买的商品ID
    vector<int> charactors;
public:
    Player();
    //获取id
    int Getid() const;
    void Setid(int id);
  
    //获取name 
    string Getname() const;

    //获取level
    int Getlevel() const;

    // 构造函数
    Player(int id, string name, int level,double balance);

    // 设置玩家等级
    void setLevel(int newLevel);
    

// 设置是否是高级玩家
void setPremiumPlayer(bool premium);

// 获取余额
double getBalance() const;

// 设置余额
void setBalance(double amount); 
EquipmentManager getEquipmentManager();
vector<Equipment>  getAllEquipment();
vector<int> getInventory();
vector<int> getCharactors();
void saveInventoryToFile();
void loadInventoryFromFile();
void saveCharactorsToFile();
void loadCharactorsFromFile();
//背包
void addToInventory(int productId);

private :
    vector<Equipment> equipments;
};
#endif