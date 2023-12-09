#pragma once
#ifndef CIRCLETOFLOGOS_H
#define CIRCLETOFLOGOS_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include"EquipmentStats.h"
using namespace std;
//5.圣遗物部位：理之冠
class CircletofLogos :public EquipmentStats {
public:
	void getCircletofLogos() {
		cout << "\033[33m" << "理之冠:" << "\033[0m" << '\n';
		this->getid();
		cout << "\033[32m" << "主词条:" << "\033[0m" << '\n';
		if (this->HP > 0) cout << "生命值:" << this->HP << "%" << '\n';
		else if (this->ATK > 0) cout << "攻击力:" << this->ATK << "%" << '\n';
		else if (this->DEF > 0) cout << "防御力:" << this->DEF << "%" << '\n';
		else if (this->HealingBonus > 0) cout << "治疗加成:" << this->HealingBonus << "%" << '\n';
		else if (this->ElementalMastery > 0) cout << "元素精通:" << this->ElementalMastery << '\n';
		else if (this->CRITRate > 0) cout << "暴击率:" << this->CRITRate << "%" << '\n';
		else if (this->CRITDmg > 0) cout << "暴击伤害:" << this->CRITDmg << "%" << '\n';
		cout << "\033[32m" << "副词条:" << "\033[0m" << '\n';
		this->getall();
		cout << '\n';
	}

	CircletofLogos(double HP = 0, double ATK = 0, double DEF = 0, double CRITRate = 0, double CRITDmg = 0, double HealingBonus = 0, int ElementalMastery = 0) :HP(HP), ATK(ATK), DEF(DEF), CRITRate(CRITRate), CRITDmg(CRITDmg), HealingBonus(HealingBonus), ElementalMastery(ElementalMastery) {
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

		glossary[4] = rand() % 7;
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
			this->HealingBonus = 5.4;
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
		else if (glossary[4] == 5) {
			this->CRITRate = 4.7;
			for (int i = 0; i < 4; i++) {
				switch (glossary[i]) {
				case 0:Strhp(); break;
				case 1:Strdef(); break;
				case 2:StrHp(); break;
				case 3:StrAtk(); break;
				case 4:StrDef(); break;
				case 5:StrenergyRechange(); break;
				case 6:Stratk(); break;
				case 7:StrelementalMastery(); break;
				default:StrcritDmg(); break;
				}
			}
		}
		else if (glossary[4] == 6) {
			this->CRITDmg = 9.3;
			for (int i = 0; i < 4; i++) {
				switch (glossary[i]) {
				case 0:Strhp(); break;
				case 1:Strdef(); break;
				case 2:StrHp(); break;
				case 3:StrAtk(); break;
				case 4:StrDef(); break;
				case 5:StrenergyRechange(); break;
				case 6:Stratk(); break;
				case 7:StrelementalMastery(); break;
				default:StrcritRate(); break;
				}
			}
		}
	}//初始化理之冠的四个副词条和一个主词条 

	~CircletofLogos() {
		delete[] glossary;
	}

	bool strengthen() {
		Sleep(1000);
		if (this->returnid() == 20) {
			system("cls");
			cout << "圣遗物已经满级" << '\n';
			return false;
		};//判断是否满级 
		system("cls");
		cout << "\033[34m" << "强化后:" << "\033[0m" << '\n';
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
			this->HealingBonus += 6.1;
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
		else if (glossary[4] == 5) {
			this->CRITRate += 5.28;
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
			case 7:StrelementalMastery(); break;
			default:StrcritDmg(); break;
			}
			return true;
		}//else if 
		else if (glossary[4] == 6) {
			this->CRITDmg += 10.58;
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
			case 7:StrelementalMastery(); break;
			default:StrcritRate(); break;
			}
			return true;
		}//else if 
	}//强化理之冠的一个副词条

private:
	int* glossary;
	double HP;
	double ATK;
	double DEF;
	double CRITRate;
	double CRITDmg;
	double HealingBonus;
	int ElementalMastery;
};
#endif