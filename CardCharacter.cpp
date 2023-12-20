#include "CardCharacter.h"


CardCharacter::CardCharacter(int id, const string& name, const string& element, int level, int HP, int attack, int defense)
	:id(id), name(name), element(element), level(level), HP(HP), attack(attack), defense(defense)
{
}

string CardCharacter::GetName()const
{
	return name;
}

string CardCharacter::GetElement()const
{
	return element;
}

int CardCharacter::GetLevel()const
{
	return level;
}

int CardCharacter::GetHP()const
{
	return HP;
}

int CardCharacter::GetATK()const
{
	return attack;
}

int CardCharacter::GetDef()const
{
	return defense;
}

int CardCharacter::getId() const
{
	return id;
}
