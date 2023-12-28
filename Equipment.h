#pragma once
#ifndef Equipment_H
#define Equipment_H
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <map>
#include "stats.h"
#include <random>
#include <string>
#include <fstream>
using namespace std;
class Equipment
{
public:
    Equipment(int count = 1, int hp = 0, int atk = 0, int def = 0, double Hp = 0, double Atk = 0, double Def = 0,
              double energyRechange = 0, int elementalMastery = 0, double critRate = 0, double critDmg = 0, int id = 0);
    ~Equipment();

    void initializeAttributes();           //初始化装备属性
    int getequip();                        //获取装备状态
    void false_equip();                    //未装备
    void true_equip();                     //未装备
    void setEquipt(const int &n);          //设定装备
    void setPlayerName(string playerName); //设置玩家姓名
    void setPlayerId(int playerId);        //设置玩家ID
    void showElements();                   //展示圣遗物
    string getPlayerName();                //获取玩家姓名

private:
    int equip; // equip=0,表示未装备；equip=1，表示已装备

protected:
    string playerName;
    int playerId;
    vector<Stats> attributes;
    const vector<string> elements = {
        "生命值", "攻击力", "防御力", "无无无"};
};
#endif
