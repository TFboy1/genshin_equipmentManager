#pragma once
#ifndef Equipment_H
#define Equipment_H
// ANSI ת����
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
    int  getcount();
    void falsecount();
    void truecount();
    void saveToFile();
    void loadFromFile(string name);
    void setPlayerName(string playerName);
   
    string getPlayerName();

    private:
    int count;
    
    protected:
         string playerName;
         vector<Stats> attributes;
         const vector<string> elements = {
          "������", "����ֵ", "������",  "��������Ч��", "Ԫ�ؾ�ͨ", "������", "�����˺�"};


};

#endif
