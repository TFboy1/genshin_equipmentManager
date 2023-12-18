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



// Player��
class Player {
protected:
    int id;
    string name;
    int level;
    vector<Observer*> observers;
    bool isPremiumPlayer;
    double balance;
    EquipmentManager equipmentManager;
    vector<int> inventory;  // �洢�������ƷID

public:
    Player();
    //��ȡid
    int Getid() const;
    void Setid(int id);
  
    //��ȡname 
    string Getname() const;

    //��ȡlevel
    int Getlevel() const;

    // ���캯��
    Player(int id, string name, int level,double balance);

    // ���Observer
    void addObserver(Observer* observer);

    // �Ƴ�Observer
    void removeObserver(Observer* observer);

    // ֪ͨObserver
    void notifyObservers();

   

    // ������ҵȼ�
    void setLevel(int newLevel);
    

// �����Ƿ��Ǹ߼����
void setPremiumPlayer(bool premium);

// ��ȡ���
double getBalance() const;

// �������
void setBalance(double amount); 
EquipmentManager getEquipmentManager();
vector<Equipment>  getAllEquipment();
vector<int> getInventory();
void saveInventoryToFile();
void loadInventoryFromFile();

//����
void addToInventory(int productId);

private :
    vector<Equipment> equipments;
};
#endif