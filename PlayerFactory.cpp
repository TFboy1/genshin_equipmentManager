#include "PlayerFactory.h"
PlayerFactory PlayerFactory::instance;
int PlayerFactory::playerCounter = 0;
Player *PlayerFactory::createPlayer(string name, int level = 0, double balance = 0, int health = 50, int attack = 5, int defense = 5)
{
    Player *player = new Player(playerCounter++, name, level, balance, health, attack, defense);
    return player;
}
PlayerFactory::PlayerFactory() {}
PlayerFactory::~PlayerFactory() {}
PlayerFactory PlayerFactory::getInstance()
{
    return instance;
}