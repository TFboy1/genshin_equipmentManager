#pragma once
#ifndef FLOWEROFLIFE_H
#define FLOWEROFLIFE_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include"EquipmentStats.h"
using namespace std;
//1.圣遗物部位：生之花 
using namespace std;
class FlowerofLife :public EquipmentStats {
public:
	void getFlowerofLife() {
		cout << "\033[33m" << "生之花:" << "\033[0m" << '\n';
		this->getid();
		cout << "\033[32m" << "主词条:" << "\033[0m" << '\n';
		cout << "生命值:" << this->HP << '\n';
		cout << "\033[32m" << "副词条:" << "\033[0m" << '\n';
		this->getall();
		cout << '\n';
	}//输出生之花 

	FlowerofLife(int HP = 717) :HP(HP) {
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
			case 0:Stratk(); break;
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
		//this->getFlowerofLife();
	}//初始化生之花的四个副词条

	~FlowerofLife() {
		delete[] glossary;
	}//析构 

	bool strengthen() {
		if (this->returnid() == 20) {
			system("cls");
			cout << "圣遗物已经满级" << '\n';
			return false;
		};//判断是否满级 
		system("cls");
		cout << "\033[34m" << "强化后:" << "\033[0m" << '\n';
		this->HP += 816;//提升主词条 
		upid();//提升四级 
		int a;
		do {
			a = rand();
		} while (a != glossary[1] && a != glossary[2] && a != glossary[3] && a != glossary[0]);
		switch (a) {
		case 0:Stratk(); break;
		case 1:Strdef(); break;
		case 2:StrHp(); break;
		case 3:StrAtk(); break;
		case 4:StrDef(); break;
		case 5:StrenergyRechange(); break;
		case 6:StrelementalMastery(); break;
		case 7:StrcritRate(); break;
		default:StrcritDmg(); break;
		}//提升副词条 
		//this->getFlowerofLife();
		return true;
	}//强化生之花的一个词条

private://主词条  
	int HP;//固定生命值 
	int* glossary;//词条数组 
};
#endif