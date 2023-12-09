#pragma once
// Game.h
#include"Subject.h"

#include "Player.h"

#include "PlayerManager.h"
#include "PlayerFactory.h"
#include "PlayerObserver.h"
#include"Equipment.h"
#include"EquipmentManager.h"
using namespace std;
class Game {
private:
    std::vector<Player*> players;
    PlayerManager playerManager;
    PlayerFactory playerFactory;
    Subject subject;
public:
    Game();
    ~Game();
    Player* createPlayer();
    void equipmentSystem(Player* player);

    void playerSystem();
    void deletePlayer();
    Player* chosePlayer();
    void startGame();
    
};
