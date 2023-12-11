// Equipment.cpp
#include "Equipment.h"

Equipment::Equipment(int count, int hp, int atk, int def, double Hp, double Atk, double Def,
    double energyRechange, int elementalMastery, double critRate, double critDmg, int id)
    : count(count) {
    
    // Initialize attributes
    initializeAttributes();
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution(0, attributes.size() - 1);
}
int Equipment::getcount() {
	return count;
}
void Equipment::falsecount() {
	count = 0;
}
void Equipment::truecount() {
	count = 1;
}
void Equipment::saveToFile()
{
    string filename="equipment.dat";
    ofstream outFile(filename, ios::binary);

    if (!outFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    // Write basic information to file
    outFile << playerName << " ";
    outFile<< count<<" ";
    

    // Write attributes to file
   
    for (size_t i = 0; i < attributes.size(); ++i) {
        
        outFile << attributes[i].getName()<<" " << attributes[i].getStats() <<" " << attributes[i].getEle() << endl;
    }

    outFile.close();
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
void Equipment::loadFromFile(string name) {
    string filename = "equipment.dat";
    ifstream inFile(filename, ios::binary);

    if (!inFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    // Clear existing attributes
    attributes.clear();



    while (inFile >> playerName) {
        // Read basic information from file
        if (playerName == name) {
           

            if (inFile >> count) {
                

                // Read attributes from file
                string attrName;
                int stats, ele;
                while (inFile >> attrName >> stats >> ele) {
                    // Assuming you have a constructor for Stats that takes name, stats, and ele
                    Stats stat(attrName, stats, ele);

                    // Add the Stats object to the vector
                    attributes.push_back(stat);

                    
                }

               
            }
            else {
                cerr << "Error reading count for player: " << playerName << endl;
            }
        }
    }

    

    inFile.close();
}



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

// Additional member functions and implementations can be added as needed
