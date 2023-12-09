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
//ʥ���︱���� 
class EquipmentStats {
public:
	EquipmentStats(int count=1, int hp = 0, int atk = 0, int def = 0, double Hp = 0, double Atk = 0, double Def = 0, double energyRechange = 0, int elementalMastery = 0,
		double critRate = 0, double critDmg = 0, int id = 0) :hp(hp), atk(atk), def(def), Hp(Hp), Atk(Atk), Def(Def), energyRechange(energyRechange), elementalMastery(elementalMastery),
		critRate(critRate), critDmg(critDmg), id(id), count(count) {}//��ʼ��ʥ���︱���� 
	~EquipmentStats() {}
	
	int getcount() {
		return count;
	}//����cout
	void truecount() {
		this->count = 1;
	} //��װ��
	void falsecount() {
		this->count = 0;
	}//δװ�� 

	void upid() {
		id += 4;
	}//�����ļ� 
	void getid() {
		cout << "�ȼ�:" << id << '\n';
	}//����ȼ� 
	int returnid() {
		return this->id;
	}//���صȼ� 

	void Strhp() {
		this->hp += 300;
	}//ǿ���̶�����ֵ

	void Stratk() {
		this->atk += 20;
	}//ǿ���̶�������

	void Strdef() {
		this->def += 24;
	}//ǿ���̶�������

	void StrHp() {
		this->Hp += 5.83;
	}//ǿ���ٷֱ�����ֵ

	void StrAtk() {
		this->Atk += 5.83;
	}//ǿ���ٷֱȹ�����

	void StrDef() {
		this->Def += 7.29;
	}//ǿ���ٷֱȷ�����

	void StrenergyRechange() {
		this->energyRechange += 6.48;
	}//ǿ��Ԫ�س���Ч��

	void StrelementalMastery() {
		this->elementalMastery += 24;
	}//ǿ��Ԫ�ؾ�ͨ

	void StrcritRate() {
		this->critRate += 3.89;
	}//ǿ��������

	void StrcritDmg() {
		this->critDmg += 7.77;
	}//ǿ�������˺� 

	void getall() {
		if (this->hp > 0)
			cout << "����ֵ:" << this->hp << '\n';
		if (this->atk > 0)
			cout << "������:" << this->atk << '\n';
		if (this->def > 0)
			cout << "������:" << this->def << '\n';
		if (this->Hp > 0)
			cout << "����ֵ:" << this->Hp << "%" << '\n';
		if (this->Atk > 0)
			cout << "������:" << this->Atk << "%" << '\n';
		if (this->Def > 0)
			cout << "������:" << this->Def << "%" << '\n';
		if (this->energyRechange > 0)
			cout << "Ԫ�س���Ч��:" << this->energyRechange << "%" << '\n';
		if (this->elementalMastery > 0)
			cout << "Ԫ�ؾ�ͨ:" << this->elementalMastery << '\n';
		if (this->critRate > 0)
			cout << "������:" << this->critRate << "%" << '\n';
		if (this->critDmg > 0)
			cout << "�����˺�:" << this->critDmg << "%" << '\n';
	}//�����Ч���� 

private://������ 

	string playerName;
	int hp;//�̶�����ֵ 
	int atk;//�̶������� 
	int def;//�̶������� 
	double Hp;//�ٷֱ�����ֵ 
	double Atk;//�ٷֱȹ����� 
	double Def;//�ٷֱȷ����� 
	double energyRechange;//Ԫ�س���Ч�� 
	int elementalMastery;//Ԫ�ؾ�ͨ 
	double critRate;//������ 
	double critDmg;//�����˺� 
	int id;//�ȼ�
	int count;//�Ƿ�װ�� 
};
#endif