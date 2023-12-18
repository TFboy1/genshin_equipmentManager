#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <vector>
#include "player.h" // ����Player���ͷ�ļ�
#include <fstream>
#include"PlayerManager.h"
using namespace std;

class Store {
private:
    struct Product {
        int id;
        string name;  // �����Ʒ����
        double price;
    };
    PlayerManager playerManager;
    vector<Product> products;
    Player& player; // ʹ������

public:
    
    Store(Player& player, PlayerManager& playerManager);
    // ���캯������Player������
    ~Store(); // ��������

    void showPurchaed();

    void openStore();

    // ��Ʒ����
    void addProduct(int id, const string& name, double price);  // �޸Ĳ����������Ʒ����
    void discount();
    void removeProduct(int id);

    // ������
    double getPlayerBalance() const;
    void deposit(double amount);
    bool withdraw(double amount);

    // ��ʾ��Ʒ��Ϣ
    void displayProducts() const;

    // ������Ʒ
    bool purchaseProduct(int productId);

    void manageStore();

    void saveProductsToFile();

    void loadProductsFromFile();
};

#endif // STORE_H
