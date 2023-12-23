// SandsofEon.cpp
#include "SandsofEon.h"
#include <random>

SandsofEon::SandsofEon() {
    
      
    initialElements();
}

SandsofEon::~SandsofEon() {
    // Destructor code here
}

//void SandsofEon::showElements() {
//    std::cout << "\033[33m" << "时之沙:" << "\033[0m" << '\n';
//
//    // Output main stats based on your logic
//    std::cout << "\033[32m" << "主词条:" << "\033[0m" << '\n';
//
//    // Output main stats based on your logic
//    // ...
//    while (true) {
//        std::random_device rd;
//        std::mt19937 gen(rd());
//
//        std::uniform_int_distribution<int> distribution(0, attributes.size() - 1);
//        int n = distribution(gen);
//        if (attributes[n].getStats() > 0)
//        {std::cout << attributes[n].getName() << attributes[n].getEle() + 2 << "%" << '\n';
//        break;
//        }
//    }
//    std::cout << "\033[32m" << "副词条:" << "\033[0m" << '\n';
//    for (int i = 0; i < attributes.size(); i++) {
//        if (attributes[i].getStats() > 0) {
//            std::cout << attributes[i].getName() << ": " << attributes[i].getEle() << "%" << '\n';
//        }
//    }
//    std::cout << '\n';
//}

void SandsofEon::strengthen() {
    for (int i = 0; i < attributes.size(); i++) {
        if (attributes[i].getStats() > 0) {
            attributes[i].setEle(attributes[i].getEle() + rand() % 3);
        }
    }
    std::cout << YELLOW << "强化后:" << RESET << '\n';
    showElements(3);
}

void SandsofEon::initialElements() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution(1, attributes.size()-1);

    int n = 5;
    while (n--) {
        int x = distribution(gen);
        attributes[x - 1].setStats(1);
        attributes[x - 1].setEle(x);
    }
}
