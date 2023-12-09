#ifndef RECHARGEMANAGER_H
#define RECHARGEMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include"Player.h"
using namespace std;

class RechargeManager {
private:
    Player* player; // Composition: RechargeManager has a Player

public:
    RechargeManager(Player* p);
    void recharge(double amount);

    void openGameStore();
    void purchaseItem(Equipment item);

    void displayAvailableItems();
};
#endif