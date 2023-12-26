#include "PlayerFactory.h"
PlayerFactory PlayerFactory::instance;
int PlayerFactory::playerCounter = 0;
Player *PlayerFactory::createPlayer(string name, int level = 0, double balance = 0)
{
    Player *player = new Player(playerCounter++, name, level, balance);
    return player;
}
PlayerFactory::PlayerFactory() {}
PlayerFactory::~PlayerFactory() {}
PlayerFactory PlayerFactory::getInstance()
{
    return instance;
}