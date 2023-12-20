#ifndef CARDCHARACTER_H
#define CARDCHARACTER_H
#include<iostream>
#include<string>
using namespace std;
class CardCharacter
{
public:
	CardCharacter(int id,const string &name,const string &element,int level,int HP,int attack,int defense);
	string GetName()const;
	string GetElement()const;
	int GetLevel()const;
	int GetHP()const;
	int GetATK()const;
	int GetDef()const;
	~CardCharacter(){}
	int getId()const;

private:
	string name;
	string element;
	int level;
	int HP;
	int attack;
	int defense;
	int id;
};

#endif // CARDCHARACTER_H