#pragma once
#ifndef EQUIPMENTMANAGER_H
#define EQUIPMENTMANAGER_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include"Equipment.h"
#include <functional>
#include <random>
using namespace std;
class EquipmentManager :public Equipment {
public:
	EquipmentManager() {}
	//void getEquipment() {
	//	// ����һ�� vector������Ԫ���� std::function
	//	std::vector<std::function<void(CircletofLogos*)>> functionVector;

	//	// ʹ�� std::mem_fn ����Ա����ת��Ϊ�ɵ��õĶ���
	//	functionVector.push_back(std::mem_fn(&CircletofLogos::setcount));
	//	functionVector.push_back(std::mem_fn(&SandsofEon::setcount));
	//	functionVector.push_back(std::mem_fn(&GobletofEonothem::setcount));
	//	functionVector.push_back(std::mem_fn(&PlumeofDeath::setcount));
	//	functionVector.push_back(std::mem_fn(&FlowerofLife::setcount));
	//	// ʹ�������������
	//	std::random_device rd;
	//	std::mt19937 gen(rd());
	//	std::uniform_int_distribution<> dis(0, functionVector.size() - 1);

	//	// ���ѡ��һ������ִ��
	//	int randomIndex = dis(gen);
	//	Equipment equipment;
	//	functionVector[randomIndex](&equipment);

	//}//�����ȡһ��ʥ����
	void strengthenAll() {
		FlowerofLife::strengthen();
		PlumeofDeath::strengthen();
		SandsofEon::strengthen();
		GobletofEonothem::strengthen();
		CircletofLogos::strengthen();
	}//ǿ������ʥ���� 
	bool removeEquipment() {
		system("cls");
		if (FlowerofLife::getcount() == 0 && PlumeofDeath::getcount() == 0 && SandsofEon::getcount() == 0 && GobletofEonothem::getcount() == 0 && CircletofLogos::getcount() == 0) {
			cout << "���޿ɲ�ж��ʥ�����ȴ�����" << '\n';
			Sleep(2000);
			system("cls");
			return false;
		}
		int a; cout << "��ѡ�������ж��ʥ���ﲿλ:  �˳�������0" << '\n';
		if (FlowerofLife::getcount() == 1) cout << "��ж��֮����������1" << '\n';
		if (PlumeofDeath::getcount() == 1) cout << "��ж��֮��������2" << '\n';
		if (SandsofEon::getcount() == 1) cout << "��жʱ֮ɳ��������3" << '\n';
		if (GobletofEonothem::getcount() == 1) cout << "��ж��֮����������4" << '\n';
		if (CircletofLogos::getcount() == 1) cout << "��ж��֮�ڣ�������5" << '\n';
		cin >> a;
		if (a == 0) {
			system("cls");
			return false;
		}
		switch (a) {
		case 1:FlowerofLife::falsecount(); cout << "��ж��֮���ɹ�" << '\n'; break;
		case 2:PlumeofDeath::falsecount(); cout << "��ж��֮��ɹ�" << '\n'; break;
		case 3:SandsofEon::falsecount(); cout << "��жʱ֮ɳ�ɹ�" << '\n'; break;
		case 4:GobletofEonothem::falsecount(); cout << "��ж��֮���ɹ�" << '\n'; break;
		case 5:CircletofLogos::falsecount(); cout << "��ж��֮�ڳɹ�" << '\n'; break;
		}
		Sleep(2000);
		system("cls");
		return true;
	}//�ѵ�һ����λ��ʥ���� 
	bool addEquipment() {
		system("cls");
		if (FlowerofLife::getcount() == 1 && PlumeofDeath::getcount() == 1 && SandsofEon::getcount() == 1 && GobletofEonothem::getcount() == 1 && CircletofLogos::getcount() == 1) {
			cout << "���޿�װ����ʥ�����ȴ�����" << '\n';
			Sleep(2000);
			system("cls");
			return false;
		}
		int b; cout << "��ѡ������װ����ʥ���ﲿλ:  �˳�������0" << '\n';
		if (FlowerofLife::getcount() == 0) cout << "װ����֮����������1" << '\n';
		if (PlumeofDeath::getcount() == 0) cout << "װ����֮��������2" << '\n';
		if (SandsofEon::getcount() == 0) cout << "װ��ʱ֮ɳ��������3" << '\n';
		if (GobletofEonothem::getcount() == 0) cout << "װ����֮����������4" << '\n';
		if (CircletofLogos::getcount() == 0) cout << "װ����֮�ڣ�������5" << '\n';
		cin >> b;
		if (b == 0) {
			system("cls");
			return false;
		}
		switch (b) {
		case 1:FlowerofLife::truecount(); cout << "װ����֮���ɹ�" << '\n'; break;
		case 2:PlumeofDeath::truecount(); cout << "װ����֮��ɹ�" << '\n'; break;
		case 3:SandsofEon::truecount(); cout << "װ��ʱ֮ɳ�ɹ�" << '\n'; break;
		case 4:GobletofEonothem::truecount(); cout << "װ����֮���ɹ�" << '\n'; break;
		case 5: CircletofLogos::truecount(); cout << "װ����֮�ڳɹ�" << '\n'; break;
		}
		Sleep(2000);
		system("cls");
		return true;
	}//װ��һ����λ��ʥ���� 
	bool displayEquipment() {
		if (FlowerofLife::getcount() == 0 && PlumeofDeath::getcount() == 0 && SandsofEon::getcount() == 0 && GobletofEonothem::getcount() == 0 && CircletofLogos::getcount() == 0) {
			cout << "ʥ���ﶼ����ж����ȴ�����" << '\n';
			Sleep(2000);
			system("cls");
			return false;
		}
		if (FlowerofLife::getcount() == 1) this->getFlowerofLife();
		if (PlumeofDeath::getcount() == 1) this->getPlumeofDeath();
		if (SandsofEon::getcount() == 1) this->getSandsofEon();
		if (GobletofEonothem::getcount() == 1) this->getGobletofEonothem();
		if (CircletofLogos::getcount() == 1) this->getCircletofLogos();
		return true;
	}//չʾ����װ����ʥ���� 
	private:
		vector<Equipment> euipments;
};
#endif