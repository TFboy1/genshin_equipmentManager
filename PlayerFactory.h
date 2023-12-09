#pragma once
#include"Player.h"
class PlayerFactory{
public:
	PlayerFactory();
	static PlayerFactory getInstance();
	Player* createPlayer(string name,int level);
	~PlayerFactory();
	
private:
	static PlayerFactory instance;
	static int playerCounter;



};

