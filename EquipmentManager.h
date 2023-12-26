#pragma once
#ifndef EQUIPMENTMANAGER_H
#define EQUIPMENTMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include "Equipment.h"
#include "FlowerofLife.h"
#include <functional>
#include <random>
#include<sstream>

using namespace std;

class EquipmentManager {
public:
    EquipmentManager() {}

    //设置玩家ID
    void setPlayerId(int id)
    {
        this->playerId = id;
    }

    //强化圣遗物
   bool strengthenAll() {
        int d;
        cout << "请确认您想强化圣遗物:  退出请输入0" << '\n';
        cout<< "确认强化生之花，请输入1" << '\n';
        cin >> d;
        if (d == 0) {
            system("cls");
            return false;
        }
        else {
            switch (d) {
            case 1:  flowerOfLife.strengthen(); break;
            }
        }
        Sleep(2000);
        system("cls");
        
        return true;
    }

   //拆卸圣遗物
    bool removeEquipment() {
        system("cls");
        if (flowerOfLife.getequip() !=1) {
            cout << "暂无可拆卸的圣遗物，请等待返回" << '\n';
            Sleep(2000);
            system("cls");
            return false;
        }
        int a;
        cout << "请确认您想拆卸圣遗物:  退出请输入0" << '\n';
        if (flowerOfLife.getequip() == 1) cout << "确认拆卸生之花，请输入1" << '\n';
        
        cin >> a;
        if (a == 0) {
            system("cls");
            return false;
        }
        switch (a) {
        case 1: flowerOfLife.false_equip(); 
            equipments.push_back(flowerOfLife);
            equipments[0].setEquipt(0);
            cout << "拆卸生之花成功" << '\n'; break;
        
        }
        Sleep(2000);
        system("cls");
        return true;
    }


    //装备圣遗物
    bool addEquipment() {
        system("cls");
        if (flowerOfLife.getequip() !=0 ) {
            cout << "暂无可装备的圣遗物，请等待返回" << '\n';
            Sleep(2000);
            system("cls");
            return false;
        }
        int b;
        cout << "请确认您想装备圣遗物:  退出请输入0" << '\n';
        if (flowerOfLife.getequip() == 0) cout << "确认装备生之花，请输入1" << '\n';
        
        cin >> b;
        if (b == 0) {
            system("cls");
            return false;
        }
        switch (b) {
        case 1: flowerOfLife.true_equip();
            equipments.push_back(flowerOfLife);
            equipments[0].setEquipt(1);
            cout << "装备生之花成功" << '\n'; break;
        
        }
        Sleep(2000);
        system("cls");
        return true;
    }

    //拆卸圣遗物
    bool displayEquipment() {
        if (flowerOfLife.getequip() == 0 ) {
            cout << "圣遗物已经被拆卸，请等待返回" << '\n';
            Sleep(2000);
            system("cls");
            return false;
        }
        if (flowerOfLife.getequip() == 1)
        flowerOfLife.showElements();
        return true;
    }

    //保存装备信息
    void saveEquipment() {
        equipments.push_back(flowerOfLife);
        
        for (Equipment& equipment : equipments) {
        equipment.setPlayerName(playerName);
        equipment.setPlayerId(playerId);
        equipment.saveToFile();
        }
    }

    //获取装备信息
    vector<Equipment> getEquipments() {
        Equipment temp;
        equipments.push_back(temp);
        return equipments;
    }

    //初始化装备
    void initEquipments(int id) {
        equipments.push_back(flowerOfLife);
        for (Equipment& equipment : equipments) {
            equipment.setPlayerId(id);
            equipment.saveToFile();
        }
    }

    //设置玩家姓名
    void setPlayerName(string playerName) {
        this->playerName = playerName;
    }

    //获取玩家姓名
    string getPlayerName() {
		return playerName;
	}
   
    //从文件中读取装备信息
    void readEquipment() {
        ifstream file("equipment.txt");
        if (file.is_open()) {
            
            std::string line;
            while (getline(file,line) ){
                istringstream ss(line);
                vector<string> words;
                string word;
                while (ss >> word) {
                    words.push_back(word);
                }

                if (std::stoi(words[0]) == this->playerId) {
                    Equipment temp;
                    temp.setPlayerId(std::stoi(words[0]));
                    temp.setEquipt(std::stoi(words[1]));
                    equipments.push_back(temp);
                    flowerOfLife.setPlayerId(std::stoi(words[0]));
                    flowerOfLife.setEquipt(std::stoi(words[1]));

                }
            }
            file.close();
        }
    }

private:
    FlowerofLife flowerOfLife;
    vector<Equipment> equipments;
    string playerName; 
    int playerId;
};

#endif
