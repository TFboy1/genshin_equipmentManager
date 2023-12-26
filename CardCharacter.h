#ifndef CARDCHARACTER_H
#define CARDCHARACTER_H
#include<iostream>
#include<string>
using namespace std;
class CardCharacter
{
public:
	CardCharacter(int id,const string &name,const string &element,int level,int HP,int attack,int defense);
	string GetName()const;//��ȡ��õ�����
	string GetElement()const;//��ȡ��õ�����
	int GetLevel()const;//��ȡ��õĵȼ�
	int GetHP()const;//��ȡ��õ�Ѫ��
	int GetATK()const;//��ȡ��õ�����ATK
	int GetDef()const;//��ȡ��õ�Def
	~CardCharacter(){}
	int getId()const;//��ȡ��õ�ID

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