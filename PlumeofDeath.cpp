#include "PlumeofDeath.h"
#include <random>

PlumeofDeath::PlumeofDeath()
{
    attributes[2].setStats(1);
    initialElements();
}

PlumeofDeath::~PlumeofDeath()
{
}

void PlumeofDeath::showElements()
{
    std::cout << "\033[33m" << "¿ÕÖ®±­:" << "\033[0m" << '\n';

    std::cout << "\033[32m" << "Ö÷´ÊÌõ:" << "\033[0m" << '\n';

    std::cout << attributes[2].getName() << attributes[2].getEle() + 2 << "%" << '\n';

    std::cout << "\033[32m" << "¸±´ÊÌõ:" << "\033[0m" << '\n';
    for (int i = 0; i < attributes.size(); i++) {
        if (attributes[i].getStats() > 0) {
            std::cout << attributes[i].getName() << ": " << attributes[i].getEle() << "%" << '\n';
        }
    }
    std::cout << '\n';
}

void  PlumeofDeath::strengthen()
{
    for (int i = 0; i < attributes.size(); i++) {
        if (attributes[i].getStats() > 0) {
            attributes[i].setEle(attributes[i].getEle() + rand() % 3);
        }
    }
    std::cout << YELLOW << "Ç¿»¯ºó:" << RESET << '\n';
    showElements();

}

void PlumeofDeath::initialElements()
{// Initialize elements with random values
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