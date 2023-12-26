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
        string name;//商品名称
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

    //商品管理
    void addProduct(int id, const string& name, double price);
    void discount();
    void rediscount();
    void removeProduct(int id);

    //余额管理
    double getPlayerBalance() const;
    void deposit(double amount);
    bool withdraw(double amount);

    void displayProducts() const;//显示商品信息

    bool purchaseProduct(int productId);//购买商品

    void saveProductsToFile();//保存商品信息到文件中
    
    void loadProductsFromFile();//加载商品信息文件
};

#endif
