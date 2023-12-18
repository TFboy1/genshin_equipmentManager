#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <vector>
#include "player.h" // 引用Player类的头文件
#include <fstream>
#include"PlayerManager.h"
using namespace std;

class Store {
private:
    struct Product {
        int id;
        string name;  // 添加商品名称
        double price;
    };
    PlayerManager playerManager;
    vector<Product> products;
    Player& player; // 使用引用

public:
    
    Store(Player& player, PlayerManager& playerManager);
    // 构造函数接受Player的引用
    ~Store(); // 析构函数

    void showPurchaed();

    void openStore();

    // 商品管理
    void addProduct(int id, const string& name, double price);  // 修改参数，添加商品名称
    void discount();
    void removeProduct(int id);

    // 余额管理
    double getPlayerBalance() const;
    void deposit(double amount);
    bool withdraw(double amount);

    // 显示商品信息
    void displayProducts() const;

    // 购买商品
    bool purchaseProduct(int productId);

    void manageStore();

    void saveProductsToFile();

    void loadProductsFromFile();
};

#endif // STORE_H
