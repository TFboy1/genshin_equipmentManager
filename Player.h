#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include "EquipmentManager.h"
#include "Observer.h"
#include <sstream>
#include <fstream>
using namespace std;

class Player
{
protected:
    int id;
    string name;
    int level;
    vector<Observer *> observers;
    bool isPremiumPlayer;
    double balance;
    EquipmentManager equipmentManager;
    vector<int> inventory;
    vector<int> charactors;
    int health;
    int attack;
    int defense;

public:
    Player();
    int Getid() const;  //获取id
    void Setid(int id); //设置id
    int Gethealth() const;//获取生命值
    int Getattack() const;//获取攻击力
    int Getdefense() const;//获取防御力
    string Getname() const;//获取name
    int Getlevel() const;//获取level
    Player(int id, string name, int level, double balance, int health, int attack, int defense); // 构造函数
    void setLevel(int newLevel);// 设置玩家等级
    void setPremiumPlayer(bool premium);// 设置是否是高级玩家
    double getBalance() const;// 获取余额
    void setBalance(double amount);// 设置余额
    EquipmentManager getEquipmentManager();//获取玩家对象的装备管理系统
    vector<Equipment> getAllEquipment();
    vector<int> getInventory();//获取背包
    vector<int> getCharactors();//获取抽卡角色信息
    void saveInventoryToFile();//保存背包信息到文件中
    void loadInventoryFromFile();//加载背包信息文件
    void saveCharactorsToFile();//保存抽卡角色信息到文件中
    void loadCharactorsFromFile();//加载抽卡角色信息文件
    void addToInventory(int productId); //保存到背包
    void increaseHealth();
    void increaseAttack();
    void increaseDefense();
    void addHealth(int);
    void addAttack(int);
    void addDefense(int);

private:
    vector<Equipment> equipments;
};
#endif