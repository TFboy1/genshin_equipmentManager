#include "Equipment.h"
extern int s[4];
Equipment::Equipment(int count, int hp, int atk, int def, double Hp, double Atk, double Def,
                     double energyRechange, int elementalMastery, double critRate, double critDmg, int id)
    : equip(equip)
{
    initializeAttributes();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, attributes.size() - 1);
}

int Equipment::getequip()
{
    return equip;
}

void Equipment::false_equip()
{
    equip = 0;
}

void Equipment::true_equip()
{
    equip = 1;
}

void Equipment::setEquipt(const int &n)
{
    this->equip = n;
}

void Equipment::setPlayerName(string playerName)
{
    this->playerName = playerName;
}
string Equipment::getPlayerName()
{
    return playerName;
}
Equipment::~Equipment() {}

void Equipment::initializeAttributes()
{
    for (const std::string &element : elements)
    {
        attributes.emplace_back(element, 0, 0);
    }
}

void Equipment::setPlayerId(int playerId)
{
    this->playerId = playerId;
}

void Equipment::showElements()
{

    cout << "\033[33m"
         << "ÉúÖ®»¨:"
         << "\033[0m" << '\n';

    for (int i = 0; i < 3; i++)
    {
        std::cout << attributes[i].getName() << ": " << attributes[i].getEle() << '\n';
    }
    std::cout << '\n';
}
