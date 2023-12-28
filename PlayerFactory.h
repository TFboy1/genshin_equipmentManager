#pragma once
#include "Player.h"
class PlayerFactory
{
public:
	PlayerFactory();
	~PlayerFactory();

	static PlayerFactory getInstance();
	Player *createPlayer(string name, int level, double balance, int health, int attack, int defense);

private:
	static PlayerFactory instance;
	static int playerCounter;
};
