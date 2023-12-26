#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include"EquipmentManager.h"
#include "Observer.h"
#include <sstream>
#include <fstream>
using namespace std;

class Player {
protected:
	int id;
    string name;
    int level;
    vector<Observer*> observers;
    bool isPremiumPlayer;
    double balance;
    EquipmentManager equipmentManager;
    vector<int> inventory;
    vector<int> charactors;

public:
    Player();
    int Getid() const; //��ȡid
    void Setid(int id);//����id
    string Getname() const;//��ȡname  
    int Getlevel() const;//��ȡlevel
    Player(int id, string name, int level,double balance);// ���캯��
    void setLevel(int newLevel);// ������ҵȼ�
    void setPremiumPlayer(bool premium);// �����Ƿ��Ǹ߼����
    double getBalance() const;// ��ȡ���
    void setBalance(double amount); // �������
    EquipmentManager getEquipmentManager();//��ȡ��Ҷ����װ������ϵͳ
    vector<Equipment>  getAllEquipment();
    vector<int> getInventory();//��ȡ����
    vector<int> getCharactors();//��ȡ�鿨��ɫ��Ϣ
    void saveInventoryToFile();//���汳����Ϣ���ļ���
    void loadInventoryFromFile();//���ر�����Ϣ�ļ�
    void saveCharactorsToFile();//����鿨��ɫ��Ϣ���ļ���
    void loadCharactorsFromFile();//���س鿨��ɫ��Ϣ�ļ�
    void addToInventory(int productId);//���浽����

private :
    vector<Equipment> equipments;
};
#endif