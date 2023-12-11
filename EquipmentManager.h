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
            cout << "���޿ɲ�ж��ʥ�����ȴ�����" << '\n';
            Sleep(2000);
            system("cls");
            return false;
        }
        int a;
        cout << "��ѡ�������ж��ʥ���ﲿλ:  �˳�������0" << '\n';
        if (flowerOfLife.getcount() == 1) cout << "��ж��֮����������1" << '\n';
        if (plumeOfDeath.getcount() == 1) cout << "��ж��֮��������2" << '\n';
        if (sandsofEon.getcount() == 1) cout << "��жʱ֮ɳ��������3" << '\n';
        if (gobletofEonothem.getcount() == 1) cout << "��ж��֮����������4" << '\n';
        if (circletofLogos.getcount() == 1) cout << "��ж��֮�ڣ�������5" << '\n';
        cin >> a;
        if (a == 0) {
            system("cls");
            return false;
        }
        switch (a) {
        case 1: flowerOfLife.falsecount(); cout << "��ж��֮���ɹ�" << '\n'; break;
        case 2: plumeOfDeath.falsecount(); cout << "��ж��֮��ɹ�" << '\n'; break;
        case 3: sandsofEon.falsecount(); cout << "��жʱ֮ɳ�ɹ�" << '\n'; break;
        case 4: gobletofEonothem.falsecount(); cout << "��ж��֮���ɹ�" << '\n'; break;
        case 5: circletofLogos.falsecount(); cout << "��ж��֮�ڳɹ�" << '\n'; break;
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
            cout << "���޿�װ����ʥ�����ȴ�����" << '\n';
            Sleep(2000);
            system("cls");
            return false;
        }
        int b;
        cout << "��ѡ������װ����ʥ���ﲿλ:  �˳�������0" << '\n';
        if (flowerOfLife.getcount() == 0) cout << "װ����֮����������1" << '\n';
        if (plumeOfDeath.getcount() == 0) cout << "װ����֮��������2" << '\n';
        if (sandsofEon.getcount() == 0) cout << "װ��ʱ֮ɳ��������3" << '\n';
        if (gobletofEonothem.getcount() == 0) cout << "װ����֮����������4" << '\n';
        if (circletofLogos.getcount() == 0) cout << "װ����֮�ڣ�������5" << '\n';
        cin >> b;
        if (b == 0) {
            system("cls");
            return false;
        }
        switch (b) {
        case 1: flowerOfLife.truecount(); cout << "װ����֮���ɹ�" << '\n'; break;
        case 2: plumeOfDeath.truecount(); cout << "װ����֮��ɹ�" << '\n'; break;
        case 3: sandsofEon.truecount(); cout << "װ��ʱ֮ɳ�ɹ�" << '\n'; break;
        case 4: gobletofEonothem.truecount(); cout << "װ����֮���ɹ�" << '\n'; break;
        case 5: circletofLogos.truecount(); cout << "װ����֮�ڳɹ�" << '\n'; break;
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
            cout << "ʥ���ﶼ����ж����ȴ�����" << '\n';
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
