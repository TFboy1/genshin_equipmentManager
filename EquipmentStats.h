#pragma once
#ifndef EQUIPMENTSTATS_H
#define EQUIPMENTSTATS_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<ctime> 
#include<windows.h>
using namespace std;
//圣遗物副词条 
class EquipmentStats {
public:
	EquipmentStats(int count = 1, int hp = 0, int atk = 0, int def = 0, double Hp = 0, double Atk = 0, double Def = 0, double energyRechange = 0, int elementalMastery = 0,
		double critRate = 0, double critDmg = 0, int id = 0) :hp(hp), atk(atk), def(def), Hp(Hp), Atk(Atk), Def(Def), energyRechange(energyRechange), elementalMastery(elementalMastery),
		critRate(critRate), critDmg(critDmg), id(id), count(count) {}//初始化圣遗物副词条 
	~EquipmentStats() {}
	void setcount() {
		this->count = 0;
	}//设置count
	int getcount() {
		return count;
	}//返回cout
	void truecount() {
		this->count = 1;
	} //已装备
	void falsecount() {
		this->count = 0;
	}//未装备 

	void upid() {
		id += 4;
	}//提升四级 
	void getid() {
		cout << "等级:" << id << '\n';
	}//输出等级 
	int returnid() {
		return this->id;
	}//返回等级 

	void Strhp() {
		this->hp += 300;
	}//强化固定生命值

	void Stratk() {
		this->atk += 20;
	}//强化固定攻击力

	void Strdef() {
		this->def += 24;
	}//强化固定防御力

	void StrHp() {
		this->Hp += 5.83;
	}//强化百分比生命值

	void StrAtk() {
		this->Atk += 5.83;
	}//强化百分比攻击力

	void StrDef() {
		this->Def += 7.29;
	}//强化百分比防御力

	void StrenergyRechange() {
		this->energyRechange += 6.48;
	}//强化元素充能效率

	void StrelementalMastery() {
		this->elementalMastery += 24;
	}//强化元素精通

	void StrcritRate() {
		this->critRate += 3.89;
	}//强化暴击率

	void StrcritDmg() {
		this->critDmg += 7.77;
	}//强化暴击伤害 

	void getall() {
		if (this->hp > 0)
			cout << "生命值:" << this->hp << '\n';
		if (this->atk > 0)
			cout << "攻击力:" << this->atk << '\n';
		if (this->def > 0)
			cout << "防御力:" << this->def << '\n';
		if (this->Hp > 0)
			cout << "生命值:" << this->Hp << "%" << '\n';
		if (this->Atk > 0)
			cout << "攻击力:" << this->Atk << "%" << '\n';
		if (this->Def > 0)
			cout << "防御力:" << this->Def << "%" << '\n';
		if (this->energyRechange > 0)
			cout << "元素充能效率:" << this->energyRechange << "%" << '\n';
		if (this->elementalMastery > 0)
			cout << "元素精通:" << this->elementalMastery << '\n';
		if (this->critRate > 0)
			cout << "暴击率:" << this->critRate << "%" << '\n';
		if (this->critDmg > 0)
			cout << "暴击伤害:" << this->critDmg << "%" << '\n';
	}//输出有效词条 

private://副词条 

	string playerName;
	int hp;//固定生命值 
	int atk;//固定攻击力 
	int def;//固定防御力 
	double Hp;//百分比生命值 
	double Atk;//百分比攻击力 
	double Def;//百分比防御力 
	double energyRechange;//元素充能效率 
	int elementalMastery;//元素精通 
	double critRate;//暴击率 
	double critDmg;//暴击伤害 
	int id;//等级
	int count;//是否装备 
};
#endif