#include"CardCharacter.h"
#include"CardDraw.h"
#include"Subject.h"
#include "Player.h"
#include "PlayerManager.h"
#include "PlayerFactory.h"
#include"Equipment.h"
#include"EquipmentManager.h"
#include "store.h"
#include"PremiumPlayer.h"
#include"CardDraw.h"

using namespace std;

class Game {
private:
    vector<Player*> players;
    PlayerManager playerManager;
    PlayerFactory playerFactory;
    Subject subject;
    
public:
    Game();
    ~Game();
    Player* createPlayer();//�������
    void equipmentSystem(Player* player);//ʥ�������˵�
    void CardDrawSystem(Player& player);//�鿨�˵�
    void playerSystem();//��Ҳ˵�
    void deletePlayer(); //ɾ����Ҳ˵�
    Player* chosePlayer();//ѡ����Ҳ˵�
    void startGame();//��ʼ��Ϸ�˵�
    void openStore(Player& player, PlayerManager& playerManager);//�̵�˵�
    void PremiumPlayerSystem();//�߼���Ҳ˵�
    void chargeSystem();//��ֵ�˵�
};
