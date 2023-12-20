#ifndef CARDDRAW_H
#define CARDDRAW_H

#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include"CardCharacter.h"
#include "Player.h"
using namespace std;
class CardDraw
{
public:
	CardDraw(Player& player);
	void saveCharactorsToFile();

	
	CardCharacter drawCard();
	void DisplayDrawnCards() const;
	~CardDraw(){}
	
private:
	vector<CardCharacter> CardPool;
	vector<CardCharacter> drawnCards;
	Player& player;
	
};
#endif // CARDDRAW_H