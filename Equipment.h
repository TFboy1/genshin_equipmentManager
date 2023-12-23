#pragma once
#ifndef Equipment_H
#define Equipment_H
// ANSI 转义码
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define ITALIC  "\033[3m"
#define UNDERLINE "\033[4m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<ctime> 
#include <cstdlib>
#include<windows.h>
#include<map>
#include "stats.h"
#include<random>
#include <string>
#include <fstream>
using namespace std;
class Equipment {
public:
    Equipment(int count = 1, int hp = 0, int atk = 0, int def = 0, double Hp = 0, double Atk = 0, double Def = 0,
        double energyRechange = 0, int elementalMastery = 0, double critRate = 0, double critDmg = 0, int id = 0);
    ~Equipment();
    void initializeAttributes();
    int  getequip();
    void false_equip();
    void true_equip();
    //void destroy_equip();
    void saveToFile();
    void setEquipt(const int &n);
    void loadFromFile(string& playerNameToFind);

   

    
   
    void setPlayerName(string playerName);
    void setPlayerId(int playerId);
    void showElements();
    string getPlayerName();

    private:
    int equip;//equip=0,表示未装备；equip=1，表示已装备
    
    protected:
         string playerName;
         int playerId;
         vector<Stats> attributes;
         const vector<string> elements = {
          "防御力", "生命值", "攻击力",  "能量充能效率", "元素精通", "暴击率", "暴击伤害"};
         

};

#endif
