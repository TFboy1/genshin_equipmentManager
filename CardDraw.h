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
	void saveCharactorsToFile();//抽卡信息保存
	CardCharacter drawCard();//抽卡系统
	void DisplayDrawnCards() const;//抽卡信息展示
	~CardDraw(){}
	
private:
	vector<CardCharacter> CardPool;
	vector<CardCharacter> drawnCards;
	Player& player;
};
#endif