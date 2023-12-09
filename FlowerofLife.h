#pragma once
#ifndef FLOWEROFLIFE_H
#define FLOWEROFLIFE_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include"EquipmentStats.h"
using namespace std;
//1.ʥ���ﲿλ����֮�� 
using namespace std;
class FlowerofLife :public EquipmentStats {
public:
	void getFlowerofLife() {
		cout << "\033[33m" << "��֮��:" << "\033[0m" << '\n';
		this->getid();
		cout << "\033[32m" << "������:" << "\033[0m" << '\n';
		cout << "����ֵ:" << this->HP << '\n';
		cout << "\033[32m" << "������:" << "\033[0m" << '\n';
		this->getall();
		cout << '\n';
	}//�����֮�� 

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
	}//��ʼ����֮�����ĸ�������

	~FlowerofLife() {
		delete[] glossary;
	}//���� 

	bool strengthen() {
		if (this->returnid() == 20) {
			system("cls");
			cout << "ʥ�����Ѿ�����" << '\n';
			return false;
		};//�ж��Ƿ����� 
		system("cls");
		cout << "\033[34m" << "ǿ����:" << "\033[0m" << '\n';
		this->HP += 816;//���������� 
		upid();//�����ļ� 
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
		}//���������� 
		//this->getFlowerofLife();
		return true;
	}//ǿ����֮����һ������

private://������  
	int HP;//�̶�����ֵ 
	int* glossary;//�������� 
};
#endif