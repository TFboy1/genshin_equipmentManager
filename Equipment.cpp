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
