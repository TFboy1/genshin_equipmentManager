//#pragma once
//#ifndef EQUIPMENTMANAGER_H
//#define EQUIPMENTMANAGER_H
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//#include"Equipment.h"
//#include <functional>
//#include <random>
//using namespace std;
//class EquipmentManager :public Equipment {
//public:
//	EquipmentManager() {}
//	//void getEquipment() {
//	//	// 定义一个 vector，其中元素是 std::function
//	//	std::vector<std::function<void(CircletofLogos*)>> functionVector;
//
//	//	// 使用 std::mem_fn 将成员函数转换为可调用的对象
//	//	functionVector.push_back(std::mem_fn(&CircletofLogos::setcount));
//	//	functionVector.push_back(std::mem_fn(&SandsofEon::setcount));
//	//	functionVector.push_back(std::mem_fn(&GobletofEonothem::setcount));
//	//	functionVector.push_back(std::mem_fn(&PlumeofDeath::setcount));
//	//	functionVector.push_back(std::mem_fn(&FlowerofLife::setcount));
//	//	// 使用随机数生成器
//	//	std::random_device rd;
//	//	std::mt19937 gen(rd());
//	//	std::uniform_int_distribution<> dis(0, functionVector.size() - 1);
//
//	//	// 随机选择一个函数执行
//	//	int randomIndex = dis(gen);
//	//	Equipment equipment;
//	//	functionVector[randomIndex](&equipment);
//
//	//}//随机获取一个圣遗物
//	void strengthenAll() {
//		FlowerofLife::strengthen();
//		PlumeofDeath::strengthen();
//		SandsofEon::strengthen();
//		GobletofEonothem::strengthen();
//		CircletofLogos::strengthen();
//	}//强化所有圣遗物 
//	bool removeEquipment() {
//		system("cls");
//		if (FlowerofLife::getcount() == 0 && PlumeofDeath::getcount() == 0 && SandsofEon::getcount() == 0 && GobletofEonothem::getcount() == 0 && CircletofLogos::getcount() == 0) {
//			cout << "暂无可拆卸的圣遗物，请等待返回" << '\n';
//			Sleep(2000);
//			system("cls");
//			return false;
//		}
//		int a; cout << "请选择您想拆卸的圣遗物部位:  退出请输入0" << '\n';
//		if (FlowerofLife::getcount() == 1) cout << "拆卸生之花，请输入1" << '\n';
//		if (PlumeofDeath::getcount() == 1) cout << "拆卸死之羽，请输入2" << '\n';
//		if (SandsofEon::getcount() == 1) cout << "拆卸时之沙，请输入3" << '\n';
//		if (GobletofEonothem::getcount() == 1) cout << "拆卸空之杯，请输入4" << '\n';
//		if (CircletofLogos::getcount() == 1) cout << "拆卸理之冠，请输入5" << '\n';
//		cin >> a;
//		if (a == 0) {
//			system("cls");
//			return false;
//		}
//		switch (a) {
//		case 1:FlowerofLife::falsecount(); cout << "拆卸生之花成功" << '\n'; break;
//		case 2:PlumeofDeath::falsecount(); cout << "拆卸死之羽成功" << '\n'; break;
//		case 3:SandsofEon::falsecount(); cout << "拆卸时之沙成功" << '\n'; break;
//		case 4:GobletofEonothem::falsecount(); cout << "拆卸空之杯成功" << '\n'; break;
//		case 5:CircletofLogos::falsecount(); cout << "拆卸理之冠成功" << '\n'; break;
//		}
//		Sleep(2000);
//		system("cls");
//		return true;
//	}//脱掉一个部位的圣遗物 
//	bool addEquipment() {
//		system("cls");
//		if (FlowerofLife::getcount() == 1 && PlumeofDeath::getcount() == 1 && SandsofEon::getcount() == 1 && GobletofEonothem::getcount() == 1 && CircletofLogos::getcount() == 1) {
//			cout << "暂无可装备的圣遗物，请等待返回" << '\n';
//			Sleep(2000);
//			system("cls");
//			return false;
//		}
//		int b; cout << "请选择您想装备的圣遗物部位:  退出请输入0" << '\n';
//		if (FlowerofLife::getcount() == 0) cout << "装备生之花，请输入1" << '\n';
//		if (PlumeofDeath::getcount() == 0) cout << "装备死之羽，请输入2" << '\n';
//		if (SandsofEon::getcount() == 0) cout << "装备时之沙，请输入3" << '\n';
//		if (GobletofEonothem::getcount() == 0) cout << "装备空之杯，请输入4" << '\n';
//		if (CircletofLogos::getcount() == 0) cout << "装备理之冠，请输入5" << '\n';
//		cin >> b;
//		if (b == 0) {
//			system("cls");
//			return false;
//		}
//		switch (b) {
//		case 1:FlowerofLife::truecount(); cout << "装备生之花成功" << '\n'; break;
//		case 2:PlumeofDeath::truecount(); cout << "装备死之羽成功" << '\n'; break;
//		case 3:SandsofEon::truecount(); cout << "装备时之沙成功" << '\n'; break;
//		case 4:GobletofEonothem::truecount(); cout << "装备空之杯成功" << '\n'; break;
//		case 5: CircletofLogos::truecount(); cout << "装备理之冠成功" << '\n'; break;
//		}
//		Sleep(2000);
//		system("cls");
//		return true;
//	}//装备一个部位的圣遗物 
//	bool displayEquipment() {
//		if (FlowerofLife::getcount() == 0 && PlumeofDeath::getcount() == 0 && SandsofEon::getcount() == 0 && GobletofEonothem::getcount() == 0 && CircletofLogos::getcount() == 0) {
//			cout << "圣遗物都被拆卸，请等待返回" << '\n';
//			Sleep(2000);
//			system("cls");
//			return false;
//		}
//		if (FlowerofLife::getcount() == 1) this->getFlowerofLife();
//		if (PlumeofDeath::getcount() == 1) this->getPlumeofDeath();
//		if (SandsofEon::getcount() == 1) this->getSandsofEon();
//		if (GobletofEonothem::getcount() == 1) this->getGobletofEonothem();
//		if (CircletofLogos::getcount() == 1) this->getCircletofLogos();
//		return true;
//	}//展示所有装备的圣遗物 
//	private:
//		vector<Equipment> euipments;
//};
//#endif

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

class EquipmentManager : public Equipment {
public:
    EquipmentManager() {}

   
    void strengthenAll() {
        flowerOfLife.strengthen();
        plumeOfDeath.strengthen();
        sandsofEon.strengthen();
        gobletofEonothem.strengthen();
        circletofLogos.strengthen();
    }

    bool removeEquipment() {
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
        return true;
    }

    bool addEquipment() {
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
        return true;
    }

    bool displayEquipment() {
        if (flowerOfLife.getcount() == 0 && plumeOfDeath.getcount() == 0 && sandsofEon.getcount() == 0 &&
            gobletofEonothem.getcount() == 0 && circletofLogos.getcount() == 0) {
            cout << "圣遗物都被拆卸，请等待返回" << '\n';
            Sleep(2000);
            system("cls");
            return false;
        }
        if (flowerOfLife.getcount() == 1) this->getFlowerofLife();
        if (plumeOfDeath.getcount() == 1) this->getPlumeofDeath();
        if (sandsofEon.getcount() == 1) this->getSandsofEon();
        if (gobletofEonothem.getcount() == 1) this->getGobletofEonothem();
        if (circletofLogos.getcount() == 1) this->getCircletofLogos();
        return true;
    }

private:
    FlowerofLife flowerOfLife;
    PlumeofDeath plumeOfDeath;
    SandsofEon sandsofEon;
    GobletofEonothem gobletofEonothem;
    CircletofLogos circletofLogos;
};

#endif
