#include "CardCharacter.h"
#include "CardDraw.h"
#include "Subject.h"
#include "Player.h"
#include "PlayerManager.h"
#include "PlayerFactory.h"
#include "Equipment.h"
#include "EquipmentManager.h"
#include "store.h"
#include "PremiumPlayer.h"
#include "CardDraw.h"
#include "FlowerofLife.h"

using namespace std;

class Game
{
private:
    vector<Player *> players;
    PlayerManager playerManager;
    PlayerFactory playerFactory;
    Subject subject;

public:
    Game();
    ~Game();
    Player *createPlayer();                                       //创建玩家
    void equipmentSystem(Player *player);                         //圣遗物管理菜单
    void CardDrawSystem(Player &player);                          //抽卡菜单
    void playerSystem();                                          //玩家菜单
    void deletePlayer();                                          //删除玩家菜单
    Player *chosePlayer();                                        //选择玩家菜单
    void startGame();                                             //开始游戏菜单
    void openStore(Player &player, PlayerManager &playerManager); //商店菜单
    void PremiumPlayerSystem();                                   //高级玩家菜单
    void chargeSystem();                                          //充值菜单
    void enhanceAttributesSystem(Player *player);                 //强化属性菜单
};
