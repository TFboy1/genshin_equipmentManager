// PlayerObserver class
#include"Observer.h"
#include "Subject.h"
#include <iostream>

class PlayerObserver : public Observer {
private:
    int playerId;

public:
    PlayerObserver(int id) : playerId(id) {}

    void update() override {
        std::cout << "Player Observer " << playerId << " received update from the subject." << std::endl;
        
    }
};