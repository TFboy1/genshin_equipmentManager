#ifndef CARDDRAW_H
#define CARDDRAW_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "CardCharacter.h"
#include "Player.h"
using namespace std;
class CardDraw
{
public:
	CardDraw(Player &player);
	~CardDraw() {}

	void saveCharactorsToFile();	//�鿨��Ϣ����
	CardCharacter drawCard();		//�鿨ϵͳ
	void DisplayDrawnCards() const; //�鿨��Ϣչʾ

private:
	vector<CardCharacter> CardPool;
	vector<CardCharacter> drawnCards;
	Player &player;
};
#endif