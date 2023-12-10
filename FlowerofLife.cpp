// FlowerofLife.cpp
#include "FlowerofLife.h"
#include <random>
using namespace std;
FlowerofLife::FlowerofLife() {
    for (const Stats& A : attributes) {
        attributess.push_back(A);
    }
    initialElements();
}

FlowerofLife::~FlowerofLife() {
    // Destructor code here
}

void FlowerofLife::showElements() {
    std::cout << "\033[33m" << "生之花:" << "\033[0m" << '\n';

    // Output main stats based on your logic
    std::cout << "\033[32m" << "主词条:" << "\033[0m" << '\n';

    // Output main stats based on your logic
    // ...
    while (true) {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<int> distribution(0, attributess.size() - 1);
        int n = distribution(gen);
        if (attributess[n].getStats() > 0)
        {
            std::cout << attributess[n].getName() << attributes[n].getEle() + 2 << "%" << '\n';
            break;
        }
    }
    std::cout << "\033[32m" << "副词条:" << "\033[0m" << '\n';
    for (int i = 0; i < attributess.size(); i++) {
        if (attributess[i].getStats() > 0) {
            std::cout << attributess[i].getName() << ": " << attributess[i].getEle() << "%" << '\n';
        }
    }
    std::cout << '\n';
}

void FlowerofLife::strengthen() {
    for (int i = 0; i < attributess.size(); i++) {
        if (attributess[i].getStats() > 0) {
            attributess[i].setEle(attributess[i].getEle() + rand() % 3);
        }
    }
    std::cout << YELLOW << "强化后:" << RESET << '\n';
    showElements();
}

void FlowerofLife::initialElements() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution(1, attributess.size() - 1);

    int n = 5;
    while (n--) {
        int x = distribution(gen);
        attributess[x - 1].setStats(1);
        attributess[x - 1].setEle(x);
    }
}
