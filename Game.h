#include"CardCharacter.h"
#include"CardDraw.h"
#include"Subject.h"
#include "Player.h"
#include "PlayerManager.h"
#include "PlayerFactory.h"
#include "PlayerObserver.h"
#include"Equipment.h"
#include"EquipmentManager.h"
#include "store.h"
#include"PremiumPlayer.h"
#include"CardDraw.h"
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
    void CardDrawSystem(Player& player);
    
    
    void playerSystem();
    void deletePlayer();
    Player* chosePlayer();
    void startGame();
    void openStore(Player& player, PlayerManager& playerManager);
    
    void PremiumPlayerSystem();
    void chargeSystem();
};
