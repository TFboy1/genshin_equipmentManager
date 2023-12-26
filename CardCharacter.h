#ifndef CARDCHARACTER_H
#define CARDCHARACTER_H
#include<iostream>
#include<string>
using namespace std;
class CardCharacter
{
public:
	CardCharacter(int id,const string &name,const string &element,int level,int HP,int attack,int defense);
	string GetName()const;//获取抽得的名字
	string GetElement()const;//获取抽得的属性
	int GetLevel()const;//获取抽得的等级
	int GetHP()const;//获取抽得的血量
	int GetATK()const;//获取抽得的名字ATK
	int GetDef()const;//获取抽得的Def
	~CardCharacter(){}
	int getId()const;//获取抽得的ID

private:
	string name;
	string element;
	int level;
	int HP;
	int attack;
	int defense;
	int id;
};

#endif