#include "Equipment.h"

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

void Equipment::saveToFile()
{
    string filename = "equipment.txt";
    ofstream outFile(filename, ios::app);

    if (!outFile.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    outFile << playerId << " ";
    outFile << equip << " ";

    for (size_t i = 0; i < attributes.size(); ++i)
    {

        outFile << attributes[i].getName() << " " << attributes[i].getStats() << " " << attributes[i].getEle();
    }
    outFile << endl;
    outFile.close();
}

void Equipment::setEquipt(const int &n)
{
    this->equip = n;
}

void Equipment::loadFromFile(string &playerNameToFind)
{
    std::string filename = "equipment.txt";
    std::ifstream inFile(filename);

    if (!inFile.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    attributes.clear();

    while (inFile >> playerName)
    {
        if (playerName == playerNameToFind)
        {
            inFile >> equip;
            while (true)
            {
                std::string attrName;
                int stats, ele;

                inFile >> attrName >> stats >> ele;

                if (inFile.fail())
                {
                    break;
                }

                Stats attr(attrName, stats, ele);
                attributes.push_back(attr);
            }
        }
    }

    inFile.close();
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
         << "生之花:"
         << "\033[0m" << '\n';

    std::cout << "\033[32m"
              << "主词条:"
              << "\033[0m" << '\n';
    while (true)
    {
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
    std::cout << "\033[32m"
              << "副词条:"
              << "\033[0m" << '\n';
    for (int i = 0; i < attributes.size(); i++)
    {
        if (attributes[i].getStats() > 0)
        {
            std::cout << attributes[i].getName() << ": " << attributes[i].getEle() << "%" << '\n';
        }
    }
    std::cout << '\n';
}
