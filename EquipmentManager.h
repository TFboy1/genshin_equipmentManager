#pragma once
#ifndef EQUIPMENTMANAGER_H
#define EQUIPMENTMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include "Equipment.h"
#include "CircletofLogos.h"
#include "FlowerofLife.h"
#include "PlumeofDeath.h"
#include "SandsofEon.h"
#include "GobletofEonothem.h"
#include <functional>
#include <random>

using namespace std;

class EquipmentManager {
public:
    EquipmentManager() {
        loud();
    }

    void strengthenAll() {
        loud();
        flowerOfLife.strengthen();
        plumeOfDeath.strengthen();
        sandsofEon.strengthen();
        gobletofEonothem.strengthen();
        circletofLogos.strengthen();
        saveEquipment();
    }

    bool removeEquipment() {
        loud();
        system("cls");
        if (flowerOfLife.getcount() == 0 && plumeOfDeath.getcount() == 0 && sandsofEon.getcount() == 0 &&
            gobletofEonothem.getcount() == 0 && circletofLogos.getcount() == 0) {
            cout << "暂无可拆卸的圣遗物，请等待返回" << '\n';
            Sleep(2000);
            system("cls");
            return false;
        }
        int a;
        cout << "请选择您想拆卸的圣遗物部位:  退出请输入0" << '\n';
        if (flowerOfLife.getcount() == 1) cout << "拆卸生之花，请输入1" << '\n';
        if (plumeOfDeath.getcount() == 1) cout << "拆卸死之羽，请输入2" << '\n';
        if (sandsofEon.getcount() == 1) cout << "拆卸时之沙，请输入3" << '\n';
        if (gobletofEonothem.getcount() == 1) cout << "拆卸空之杯，请输入4" << '\n';
        if (circletofLogos.getcount() == 1) cout << "拆卸理之冠，请输入5" << '\n';
        cin >> a;
        if (a == 0) {
            system("cls");
            return false;
        }
        switch (a) {
        case 1: flowerOfLife.falsecount(); cout << "拆卸生之花成功" << '\n'; break;
        case 2: plumeOfDeath.falsecount(); cout << "拆卸死之羽成功" << '\n'; break;
        case 3: sandsofEon.falsecount(); cout << "拆卸时之沙成功" << '\n'; break;
        case 4: gobletofEonothem.falsecount(); cout << "拆卸空之杯成功" << '\n'; break;
        case 5: circletofLogos.falsecount(); cout << "拆卸理之冠成功" << '\n'; break;
        }
        Sleep(2000);
        system("cls");
        saveEquipment();
        return true;
    }

    bool addEquipment() {
        loud();
        system("cls");
        if (flowerOfLife.getcount() == 1 && plumeOfDeath.getcount() == 1 && sandsofEon.getcount() == 1 &&
            gobletofEonothem.getcount() == 1 && circletofLogos.getcount() == 1) {
            cout << "暂无可装备的圣遗物，请等待返回" << '\n';
            Sleep(2000);
            system("cls");
            return false;
        }
        int b;
        cout << "请选择您想装备的圣遗物部位:  退出请输入0" << '\n';
        if (flowerOfLife.getcount() == 0) cout << "装备生之花，请输入1" << '\n';
        if (plumeOfDeath.getcount() == 0) cout << "装备死之羽，请输入2" << '\n';
        if (sandsofEon.getcount() == 0) cout << "装备时之沙，请输入3" << '\n';
        if (gobletofEonothem.getcount() == 0) cout << "装备空之杯，请输入4" << '\n';
        if (circletofLogos.getcount() == 0) cout << "装备理之冠，请输入5" << '\n';
        cin >> b;
        if (b == 0) {
            system("cls");
            return false;
        }
        switch (b) {
        case 1: flowerOfLife.truecount(); cout << "装备生之花成功" << '\n'; break;
        case 2: plumeOfDeath.truecount(); cout << "装备死之羽成功" << '\n'; break;
        case 3: sandsofEon.truecount(); cout << "装备时之沙成功" << '\n'; break;
        case 4: gobletofEonothem.truecount(); cout << "装备空之杯成功" << '\n'; break;
        case 5: circletofLogos.truecount(); cout << "装备理之冠成功" << '\n'; break;
        }
        Sleep(2000);
        system("cls");
        saveEquipment();
        return true;
    }

    bool displayEquipment() {
        loud();
        if (flowerOfLife.getcount() == 0 && plumeOfDeath.getcount() == 0 && sandsofEon.getcount() == 0 &&
            gobletofEonothem.getcount() == 0 && circletofLogos.getcount() == 0) {
            cout << "圣遗物都被拆卸，请等待返回" << '\n';
            Sleep(2000);
            system("cls");
            return false;
        }
        if (flowerOfLife.getcount() == 1) flowerOfLife.showElements();
        if (plumeOfDeath.getcount() == 1) plumeOfDeath.showElements();
        if (sandsofEon.getcount() == 1) sandsofEon.showElements();
        if (gobletofEonothem.getcount() == 1) gobletofEonothem.showElements();
        if (circletofLogos.getcount() == 1) circletofLogos.showElements();
        saveEquipment();
        return true;
    }

    void saveEquipment() {
        loud();
        if (flowerOfLife.getcount() == 1) equipments.push_back(flowerOfLife);
        if (plumeOfDeath.getcount() == 1) equipments.push_back(plumeOfDeath);
        if (sandsofEon.getcount() == 1) equipments.push_back(sandsofEon);
        if (gobletofEonothem.getcount() == 1) equipments.push_back(gobletofEonothem);
        if (circletofLogos.getcount() == 1) equipments.push_back(circletofLogos);
        for (Equipment& equipment : equipments) {
        equipment.setPlayerName(playerName);
        equipment.saveToFile();
        }
    }

    vector<Equipment> getEquipments() {
        return equipments;
    }
    void setPlayerName(string playerName) {
        this->playerName = playerName;
    }
    string getPlayerName() {
		return playerName;
	}
    void loud() {
        for (Equipment& equipment : equipments) {
            equipment.loadFromFile(playerName);
        }
    }
private:
    FlowerofLife flowerOfLife;
    PlumeofDeath plumeOfDeath;
    SandsofEon sandsofEon;
    GobletofEonothem gobletofEonothem;
    CircletofLogos circletofLogos;
    vector<Equipment> equipments;
    string playerName;
    
};

#endif
