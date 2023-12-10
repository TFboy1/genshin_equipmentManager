// GobletofEonothem.cpp
#include "GobletofEonothem.h"
#include <random>


GobletofEonothem::GobletofEonothem()
{for (const Stats& A : attributes) {
    	attributess.push_back(A);
    }
    initialElements();
}

GobletofEonothem::~GobletofEonothem() {
    // Equipment class destructor will be automatically called
}

void GobletofEonothem::initialElements() {
    // Initialize elements with random values
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution(1, attributess.size() - 1);

    int n = 5;
    while (n--) {
        int x = distribution(gen);
        attributess[x-1].setStats(1);
        attributess[x-1].setEle(x);
    }
        
    
}
void GobletofEonothem::strengthen() {
    for (int i = 0; i < attributess.size(); i++) {
        if (attributess[i].getStats() > 0) {
            attributess[i].setEle(attributess[i].getEle() + rand() % 3);
        }
    }
    std::cout << YELLOW << "ǿ����:"<<RESET<< '\n';
    showElements();
}
void GobletofEonothem::showElements() {
    std::cout << "\033[33m" << "��֮��:" << "\033[0m" << '\n';
    
    std::cout << "\033[32m" << "������:" << "\033[0m" << '\n';
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
    std::cout << "\033[32m" << "������:" << "\033[0m" << '\n';
    for (int i = 0; i < attributess.size(); i++) {
        if (attributess[i].getStats() > 0) {
			std::cout << attributess[i].getName() << ": " << attributess[i].getEle() << "%" << '\n';
		}
	}
    std::cout << '\n';
}
