#pragma once
#ifndef GOBLETOFEONOTHEM_H
#define GOBLETOFEONOTHEM_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include"EquipmentStats.h"
using namespace std;
class GobletofEonothem :public EquipmentStats {
public:
	void getGobletofEonothem() {
		cout << "\033[33m" << "��֮��:" << "\033[0m" << '\n';
		this->getid();
		cout << "\033[32m" << "������:" << "\033[0m" << '\n';
		if (this->HP > 0) cout << "����ֵ:" << this->HP << "%" << '\n';
		else if (this->ATK > 0) cout << "������:" << this->ATK << "%" << '\n';
		else if (this->DEF > 0) cout << "������:" << this->DEF << "%" << '\n';
		else if (this->DMGBonus > 0) cout << "Ԫ���˺��ӳ�:" << this->DMGBonus << "%" << '\n';
		else if (this->ElementalMastery > 0) cout << "Ԫ�ؾ�ͨ:" << this->ElementalMastery << '\n';
		cout << "\033[32m" << "������:" << "\033[0m" << '\n';
		this->getall();
		cout << '\n';
	}

	GobletofEonothem(double HP = 0, double ATK = 0, double DEF = 0, double DMGBonus = 0, int ElementalMastery = 0) :HP(HP), ATK(ATK), DEF(DEF), DMGBonus(DMGBonus), ElementalMastery(ElementalMastery) {
		Sleep(1000);
		srand((unsigned int)time(NULL));
		glossary = new int[5];
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

		glossary[4] = rand() % 5;
		if (glossary[4] == 0) {
			this->HP = 7;
			for (int i = 0; i < 4; i++) {
				switch (glossary[i]) {
				case 0:Strhp(); break;
				case 1:Strdef(); break;
				case 2:Stratk(); break;
				case 3:StrAtk(); break;
				case 4:StrDef(); break;
				case 5:StrenergyRechange(); break;
				case 6:StrelementalMastery(); break;
				case 7:StrcritRate(); break;
				default:StrcritDmg(); break;
				}
			}
		}
		else if (glossary[4] == 1) {
			this->ATK = 7;
			for (int i = 0; i < 4; i++) {
				switch (glossary[i]) {
				case 0:Strhp(); break;
				case 1:Strdef(); break;
				case 2:Stratk(); break;
				case 3:StrHp(); break;
				case 4:StrDef(); break;
				case 5:StrenergyRechange(); break;
				case 6:StrelementalMastery(); break;
				case 7:StrcritRate(); break;
				default:StrcritDmg(); break;
				}
			}
		}
		else if (glossary[4] == 2) {
			this->DEF = 8.7;
			for (int i = 0; i < 4; i++) {
				switch (glossary[i]) {
				case 0:Strhp(); break;
				case 1:Strdef(); break;
				case 2:Stratk(); break;
				case 3:StrHp(); break;
				case 4:StrAtk(); break;
				case 5:StrenergyRechange(); break;
				case 6:StrelementalMastery(); break;
				case 7:StrcritRate(); break;
				default:StrcritDmg(); break;
				}
			}
		}
		else if (glossary[4] == 3) {
			this->DMGBonus = 7;
			for (int i = 0; i < 4; i++) {
				switch (glossary[i]) {
				case 0:Strhp(); break;
				case 1:Strdef(); break;
				case 2:StrHp(); break;
				case 3:StrAtk(); break;
				case 4:StrDef(); break;
				case 5:Stratk(); break;
				case 6:StrelementalMastery(); break;
				case 7:StrcritRate(); break;
				default:StrcritDmg(); break;
				}
			}
		}
		else if (glossary[4] == 4) {
			this->ElementalMastery = 28;
			for (int i = 0; i < 4; i++) {
				switch (glossary[i]) {
				case 0:Strhp(); break;
				case 1:Strdef(); break;
				case 2:StrHp(); break;
				case 3:StrAtk(); break;
				case 4:StrDef(); break;
				case 5:StrenergyRechange(); break;
				case 6:Stratk(); break;
				case 7:StrcritRate(); break;
				default:StrcritDmg(); break;
				}
			}
		}
	}//��ʼ����֮�����ĸ���������һ�������� 

	~GobletofEonothem() {
		delete[] glossary;
	}
	bool strengthen() {
		Sleep(1000);
		if (this->returnid() == 20) {
			system("cls");
			cout << "ʥ�����Ѿ�����" << '\n';
			return false;
		};//�ж��Ƿ����� 
		system("cls");
		cout << "\033[34m" << "ǿ����:" << "\033[0m" << '\n';
		if (glossary[4] == 0) {
			this->HP += 7.92;
			upid();
			int a;
			do {
				a = rand();
			} while (a != glossary[1] && a != glossary[2] && a != glossary[3] && a != glossary[0]);
			switch (a) {
			case 0:Strhp(); break;
			case 1:Strdef(); break;
			case 2:Stratk(); break;
			case 3:StrAtk(); break;
			case 4:StrDef(); break;
			case 5:StrenergyRechange(); break;
			case 6:StrelementalMastery(); break;
			case 7:StrcritRate(); break;
			default:StrcritDmg(); break;
			}
			return true;
		}//if
		else if (glossary[4] == 1) {
			this->ATK += 7.92;
			upid();
			int a;
			do {
				a = rand();
			} while (a != glossary[1] && a != glossary[2] && a != glossary[3] && a != glossary[0]);
			switch (a) {
			case 0:Strhp(); break;
			case 1:Strdef(); break;
			case 2:Stratk(); break;
			case 3:StrHp(); break;
			case 4:StrDef(); break;
			case 5:StrenergyRechange(); break;
			case 6:StrelementalMastery(); break;
			case 7:StrcritRate(); break;
			default:StrcritDmg(); break;
			}
			return true;
		}//else if 
		else if (glossary[4] == 2) {
			this->DEF += 9.62;
			upid();
			int a;
			do {
				a = rand();
			} while (a != glossary[1] && a != glossary[2] && a != glossary[3] && a != glossary[0]);
			switch (a) {
			case 0:Strhp(); break;
			case 1:Strdef(); break;
			case 2:Stratk(); break;
			case 3:StrHp(); break;
			case 4:StrAtk(); break;
			case 5:StrenergyRechange(); break;
			case 6:StrelementalMastery(); break;
			case 7:StrcritRate(); break;
			default:StrcritDmg(); break;
			}
			return true;
		}//else if 
		else if (glossary[4] == 3) {
			this->DMGBonus += 7.92;
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
			case 5:Stratk(); break;
			case 6:StrelementalMastery(); break;
			case 7:StrcritRate(); break;
			default:StrcritDmg(); break;
			}
			return true;
		}//else if 
		else if (glossary[4] == 4) {
			this->ElementalMastery += 32;
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
			case 6:Stratk(); break;
			case 7:StrcritRate(); break;
			default:StrcritDmg(); break;
			}
			return true;
		}//else if 
	}//ǿ����֮����һ�������� 

private:
	int* glossary;
	double HP;
	double ATK;
	double DEF;
	double DMGBonus;
	int ElementalMastery;
};
#endif