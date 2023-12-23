// Equipment.cpp
#include "Equipment.h"

Equipment::Equipment(int count, int hp, int atk, int def, double Hp, double Atk, double Def,
    double energyRechange, int elementalMastery, double critRate, double critDmg, int id)
    : equip(equip) {
    
    // Initialize attributes
    initializeAttributes();
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution(0, attributes.size() - 1);
}
int Equipment::getequip() {
	return equip;
}
void Equipment::false_equip() {
	equip = 0;
}
void Equipment::true_equip() {
	equip= 1;
}
//void Equipment::destroy_equip() {
//    equip = 2;
//}



void Equipment::saveToFile()
{
    string filename="equipment.txt";
    ofstream outFile(filename,ios::app);

    if (!outFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    // Write basic information to file
    outFile << playerId << " ";
    outFile<< equip<<" ";
    

    // Write attributes to file
   
    for (size_t i = 0; i < attributes.size(); ++i) {
        
        outFile << attributes[i].getName()<<" " << attributes[i].getStats() <<" " << attributes[i].getEle() ;
    }
    outFile << endl;

    outFile.close();
}
void Equipment::setEquipt(const int& n)
{
    this->equip = n;
}
void Equipment::loadFromFile(string& playerNameToFind) {
    std::string filename = "equipment.txt";
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Clear existing attributes before loading new ones
    attributes.clear();

    // Read basic information from file
    while (inFile >> playerName) {
        if (playerName == playerNameToFind) {
            inFile >> equip;
            // Read attributes from file
            while (true) {
                std::string attrName;
                int stats, ele;

                inFile >> attrName >> stats >> ele;

                if (inFile.fail()) {
                    // If reading attributes fails, break from the loop
                    break;
                }

                Stats attr(attrName, stats, ele);
                attributes.push_back(attr);
            }
        }
       

        
    }

    inFile.close();
}


//void Equipment::loadFromFile(string name) {
//    string filename = "equipment.txt";
//    ifstream inFile(filename);
//
//    if (!inFile.is_open()) {
//        cerr << "Error opening file: " << filename << endl;
//        return;
//    }
//
//    // Clear existing attributes
//    attributes.clear();
//
//    while (inFile >> playerName) {
//        // Read basic information from file
//        if (playerName == name) {
//            if (inFile >> count) {
//                // Read attributes from file
//                string attrName;
//                int stats, ele;
//                while (inFile >> attrName >> stats >> ele) {
//                    // Assuming you have a constructor for Stats that takes name, stats, and ele
//                    Stats stat(attrName, stats, ele);
//
//                    // Add the Stats object to the vector
//                    attributes.push_back(stat);
//                }
//            }
//        }
//        
//    }
//
//    inFile.close();
//}
//void Equipment::loadFromFile(string name) {
//    string filename = "equipment.txt";
//    ifstream inFile(filename, ios::binary);
//
//    if (!inFile.is_open()) {
//        cerr << "Error opening file: " << filename << endl;
//        return;
//    }
//
//    // Clear existing attributes
//    attributes.clear();
//
//
//
//    while (inFile >> playerName) {
//        // Read basic information from file
//        if (playerName == name) {
//           
//
//            if (inFile >> equip) {
//                
//
//                // Read attributes from file
//                string attrName;
//                int stats, ele;
//                while (inFile >> attrName >> stats >> ele) {
//                    // Assuming you have a constructor for Stats that takes name, stats, and ele
//                    Stats stat(attrName, stats, ele);
//
//                    // Add the Stats object to the vector
//                    attributes.push_back(stat);
//
//                    
//                }
//
//               
//            }
//            else {
//                cerr << "Error reading count for player: " << playerName << endl;
//            }
//        }
//    }
//
//    
//
//    inFile.close();
//}



void Equipment::setPlayerName(string playerName)
{
    this->playerName=playerName;
}
string Equipment::getPlayerName()
{
    return playerName;
}
Equipment::~Equipment() {
    // Destructor
}

void Equipment::initializeAttributes() {
    // Set initial values for each attribute
    for (const std::string& element : elements) {
        attributes.emplace_back(element, 0, 0);
    }
}

void Equipment::setPlayerId(int playerId)
{
    this->playerId = playerId;
}
// Additional member functions and implementations can be added as needed



void Equipment::showElements() {
    
    cout << "\033[33m" << "生之花:" << "\033[0m" << '\n'; 
    
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
