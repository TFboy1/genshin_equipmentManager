#include "FlowerofLife.h"
#include <random>
using namespace std;
extern int s[4];
extern int s0[4];
FlowerofLife::FlowerofLife()
{

    initialElements();
}

FlowerofLife::~FlowerofLife() {}

void FlowerofLife::strengthen()
{
    for (int i = 0; i < 3; i++)
    {
        s0[i] = s[i];
        attributes[i].setEle(attributes[i].getEle() + rand() % 3);
        s[i] = attributes[i].getEle();
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
