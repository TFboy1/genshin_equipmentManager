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
    EquipmentManager() {
        //loud();
    }

    /*bool devastateEquipment() {
        loud();
        if (flowerOfLife.getequip() !=0 ) {
            cout << "暂无可摧毁的圣遗物，请等待返回" << '\n';
            Sleep(2000);
            system("cls");
            return false;
        }
        int c;
        cout << "请确认您想摧毁圣遗物:  退出请输入0" << '\n';
        if (flowerOfLife.getequip() == 0) cout << "确认摧毁生之花，请输入1" << '\n';
        cin >> c;
        if (c== 0) {
            system("cls");
            return false;
        }
        else {
            switch (c) {
            case 1: flowerOfLife.destroy_equip(); cout << "摧毁生之花成功" << '\n'; break;
            }
        }
        Sleep(2000);
        system("cls");
        saveEquipment();
        return true;

    }*/
    void setPlayerId(int id)
    {
        this->playerId = id;
    }
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

    bool removeEquipment() {
        //loud();
        system("cls");
        //cout << flowerOfLife.getequip() << '\n';
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
        //saveEquipment();
        return true;
    }

    bool addEquipment() {
        //loud();
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
        //saveEquipment();
        return true;
    }

    bool displayEquipment() {
        //loud();
        if (flowerOfLife.getequip() == 0 ) {
            cout << "圣遗物已经被拆卸，请等待返回" << '\n';
            Sleep(2000);
            system("cls");
            return false;
        }
        if (flowerOfLife.getequip() == 1)
        flowerOfLife.showElements();
        
        //saveEquipment();
        return true;
    }

    void saveEquipment() {
        //loud();
        //if (flowerOfLife.getequip() == 1) 
        equipments.push_back(flowerOfLife);
        
        for (Equipment& equipment : equipments) {
        equipment.setPlayerName(playerName);
        equipment.setPlayerId(playerId);
        equipment.saveToFile();
        }
    }

    vector<Equipment> getEquipments() {
        Equipment temp;
        equipments.push_back(temp);
        return equipments;
    }
    void initEquipments(int id) {
        equipments.push_back(flowerOfLife);
        for (Equipment& equipment : equipments) {
            equipment.setPlayerId(id);
            equipment.saveToFile();
        }
    }
    void setPlayerName(string playerName) {
        this->playerName = playerName;
    }
    string getPlayerName() {
		return playerName;
	}

    /*void setPlayerId(int playerId)
    {
        this->playerId = playerId;
    }*/

    /*void loud() {
        for (Equipment& equipment : equipments) {
            equipment.loadFromFile(playerName);
        }
    }*/
   
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

                //stoi是将一个字符串转化为数字
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
