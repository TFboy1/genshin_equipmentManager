#include "FlowerofLife.h"
#include <random>
using namespace std;
FlowerofLife::FlowerofLife()
{

    initialElements();
}

FlowerofLife::~FlowerofLife() {}

void FlowerofLife::strengthen()
{
    for (int i = 0; i < attributes.size(); i++)
    {
        if (attributes[i].getStats() > 0)
        {
            attributes[i].setEle(attributes[i].getEle() + rand() % 3);
        }
    }
    std::cout << YELLOW << "Ç¿»¯ºó:" << RESET << '\n';
    showElements();
}

void FlowerofLife::initialElements()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution(1, attributes.size() - 1);

    int n = 5;
    while (n--)
    {
        int x = distribution(gen);
        attributes[x - 1].setStats(1);
        attributes[x - 1].setEle(x);
    }
}
