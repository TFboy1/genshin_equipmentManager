// CircletofLogos.cpp
#include "CircletofLogos.h"
#include <random>

CircletofLogos::CircletofLogos() {
 
    initialElements();
}

CircletofLogos::~CircletofLogos() {
    // Destructor code here
}

void CircletofLogos::showElements() {
    std::cout << "\033[33m" << "理之冠:" << "\033[0m" << '\n';

    // Output main stats based on your logic
    std::cout << "\033[32m" << "主词条:" << "\033[0m" << '\n';

    // Output main stats based on your logic
    // ...
    while (true) {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<int> distribution(0, attributes.size() - 1);
        int n = distribution(gen);
        if (attributes[n].getStats() > 0)
        {
            std::cout << attributes[n].getName() << attributes[n].getEle() + 2 << "%" << '\n';
            break;
        }
    }
    
   

    std::cout << "\033[32m" << "副词条:" << "\033[0m" << '\n';
    for (int i = 0; i < attributes.size(); i++) {
        if (attributes[i].getStats() > 0) {
            std::cout << attributes[i].getName() << ": " << attributes[i].getEle() << "%" << '\n';
        }
    }
    std::cout << '\n';
}

void CircletofLogos::strengthen() {
    for (int i = 0; i < attributes.size(); i++) {
        if (attributes[i].getStats() > 0) {
            attributes[i].setEle(attributes[i].getEle() + rand() % 3);
        }
    }
    std::cout << YELLOW << "强化后:" << RESET << '\n';
    showElements();
}

void CircletofLogos::initialElements() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution(1, attributes.size() - 1);

    int n = 5;
    while (n--) {
        int x = distribution(gen);
        attributes[x - 1].setStats(1);
        attributes[x - 1].setEle(x);
    }
}
