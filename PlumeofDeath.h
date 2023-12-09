#pragma once
#ifndef PLUMEOFDEATH_H
#define PLUMEOFDEATH_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include"EquipmentStats.h"
using namespace std;
//2.圣遗物部位：死之羽 
class PlumeofDeath :public EquipmentStats {
public:
	void getPlumeofDeath() {
		cout << "\033[33m" << "死之羽:" << "\033[0m" << '\n';
		this->getid();
		cout << "\033[32m" << "主词条:" << "\033[0m" << '\n';
		cout << "攻击力:" << this->ATK << '\n';
		cout << "\033[32m" << "副词条:" << "\033[0m" << '\n';
		this->getall();
		cout << '\n';
	}//输出死之羽 

	PlumeofDeath(int ATK = 47) :ATK(ATK) {
		Sleep(1000);
		srand((unsigned int)time(NULL));
		glossary = new int[4];
		glossary[0] = rand() % 9;
		do {
			glossary[1] = rand() % 9;
		} while (glossary[1] == glossary[0]);
		do {
			glossary[2] = rand() % 9;
		} while (glossary[2] == glossary[0] || glossary[2] == glossary[1]);
		do {
			glossary[3] = rand() % 9;
		} while (glossary[3] == glossary[0] || glossary[3] == glossary[1] || glossary[3] == glossary[2]);
		for (int i = 0; i < 4; i++) {
			switch (glossary[i]) {
			case 0:Strhp(); break;
			case 1:Strdef(); break;
			case 2:StrHp(); break;
			case 3:StrAtk(); break;
			case 4:StrDef(); break;
			case 5:StrenergyRechange(); break;
			case 6:StrelementalMastery(); break;
			case 7:StrcritRate(); break;
			default:StrcritDmg(); break;
			}
		}
	}//初始化死之羽的四个副词条

	~PlumeofDeath() {
		delete[] glossary;
	}//析构 

	bool strengthen() {
		Sleep(1000);
		if (this->returnid() == 20) {
			system("cls");
			cout << "圣遗物已经满级" << '\n';
			return false;
		};//判断是否满级 
		system("cls");
		cout << "\033[34m" << "强化后:" << "\033[0m" << '\n';
		this->ATK += 53;
		upid();
		int a;
		do {
			a = rand();
		} while (a != glossary[1] && a != glossary[2] && a != glossary[3] && a != glossary[0]);
		switch (a) {
		case 0:Strhp(); break;
		case 1:Strdef(); break;
		case 2:StrHp(); break;
		case 3:StrAtk(); break;
		case 4:StrDef(); break;
		case 5:StrenergyRechange(); break;
		case 6:StrelementalMastery(); break;
		case 7:StrcritRate(); break;
		default:StrcritDmg(); break;
		}
		return true;
	}//强化死之羽的一个词条


private://主词条 
	int ATK;//固定攻击力
	int* glossary;//词条数组 

};
#endif