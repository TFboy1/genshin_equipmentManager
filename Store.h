#ifndef STORE_H
#define STORE_H
#include <iostream>
#include <vector>
#include "player.h"
#include <fstream>
#include"PlayerManager.h"
using namespace std;

class Store {
private:
    struct Product {
        int id;
        string name;//��Ʒ����
        double price;
    };
    PlayerManager playerManager;
    vector<Product> products;
    Player& player;

public:
    
    Store(Player& player, PlayerManager& playerManager);
    ~Store();
    void showPurchaed();
    void openStore();

    //��Ʒ����
    void addProduct(int id, const string& name, double price);
    void discount();
    void rediscount();
    void removeProduct(int id);

    //������
    double getPlayerBalance() const;
    void deposit(double amount);
    bool withdraw(double amount);

    void displayProducts() const;//��ʾ��Ʒ��Ϣ

    bool purchaseProduct(int productId);//������Ʒ

    void saveProductsToFile();//������Ʒ��Ϣ���ļ���
    
    void loadProductsFromFile();//������Ʒ��Ϣ�ļ�
};

#endif
