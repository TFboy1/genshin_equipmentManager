#ifndef RECHARGEMANAGER_H
#define RECHARGEMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

class RechargeManager {
private:
    Player* player;
    double rechargeOption;
    vector<pair<string, double>> availableItems;
    bool isBalanceSufficient(Player& player, double cost)
    {
        return player.getBalance() >= cost;
    }
public:
    RechargeManager() : rechargeOption(0.0) {
        availableItems = { {"Item1", 50.0}, {"Item2", 100.0}, {"Item3", 200.0} };
    }

    void setrechargeOption(double newrechargeOption)
    {
        rechargeOption = newrechargeOption;
    }

    void recharge(Player& player, double amount);
    //{
        // Recharge player's balance
    //}

    void openGameStore(Player& player);
    //{
        // Implement opening game store logic
   // }

    void purchaseItem(Player& player, Equipment item);
    // {
         // Implement player purchasing item logic
     //}

    void displayAvailableItems(Player& player);
    //{
        // Implement displaying available items logic
   // }
    void selectRechargeOption();
    // {
     //}
};
#endif
