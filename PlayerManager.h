
#include <iostream>
#include <vector>
#include <algorithm>
#include"Player.h"

using namespace std;
class PlayerManager {
private:
    vector<Player*> players;
    void saveToFile() const;
    void loadFromFile();
    /*static int id;*/
    int id;
public:
PlayerManager();
~PlayerManager();
    // ������
    void addPlayer(Player* player);
    

//  �Ƴ����
void removePlayer(Player* player);

// ��ʾ�������
void displayAllPlayers() const;

// ����ID��ȡ���
Player* getPlayerById(int id);

// ���������Ϣ
void updatePlayer(Player* player);

};
