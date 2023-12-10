#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include"EquipmentManager.h"
#include "Observer.h"

#include <fstream>
using namespace std;



// Player类
class Player {
private:
    int id;
    string name;
    int level;
    vector<Observer*> observers;
    bool isPremiumPlayer;
    double balance;
    EquipmentManager equipmentManager;

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
    Player(int id, string name, int level);

    // 添加Observer
    void addObserver(Observer* observer);

    // 移除Observer
    void removeObserver(Observer* observer);

    // 通知Observer
    void notifyObservers();

   

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
void saveEquipment();
private :
    vector<Equipment> equipments;
};

#endif