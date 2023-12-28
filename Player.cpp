#include "Player.h"
Player::Player()
{
	equipmentManager.setPlayerName(name);
	equipments = equipmentManager.getEquipments();
	loadInventoryFromFile();
}

//获取id
int Player::Getid() const { return id; }

void Player::Setid(int id)
{
	this->id = id;
}

//获取name
string Player::Getname() const { return name; }

int Player::Gethealth() const { return health; }

int Player::Getattack() const { return attack; }

int Player::Getdefense() const { return defense; }

//获取level
int Player::Getlevel() const { return level; }

// 构造函数
Player::Player(int id, string Name, int level, double balance, int health, int attack, int defense)
	: id(id), name(Name), level(level), isPremiumPlayer(false), balance(balance), health(health), attack(attack), defense(defense)
{
	equipmentManager.setPlayerName(name);
	equipments = equipmentManager.getEquipments();
	equipmentManager.setPlayerId(id);
}

// 设置玩家等级
void Player::setLevel(int newLevel)
{
	level = newLevel;
}

void Player::increaseHealth()
{
	health += 2;
	cout << "生命值强化成功，当前生命值：" << health << endl;
}
void Player::increaseAttack()
{
	attack += 1;
	cout << "攻击力强化成功，当前攻击力：" << attack << endl;
}
void Player::increaseDefense()
{
	defense += 1;
	cout << "防御力强化成功，当前防御力：" << defense << endl;
}
// 设置是否是高级玩家
void Player::setPremiumPlayer(bool premium)
{
	isPremiumPlayer = premium;
}

void Player::addHealth(int h)
{
	health += h;
}
void Player::addAttack(int a)
{
	attack += a;
}
void Player::addDefense(int d)
{
	defense += d;
}
// 获取余额
double Player::getBalance() const
{
	return balance;
}

// 设置余额
void Player::setBalance(double amount)
{
	balance = amount;
}

EquipmentManager Player::getEquipmentManager()
{
	return equipmentManager;
}

vector<Equipment> Player::getAllEquipment()
{
	return equipments;
}

vector<int> Player::getInventory()
{
	return inventory;
}

vector<int> Player::getCharactors()
{
	return charactors;
}

void Player::saveInventoryToFile()
{
	ofstream fout("inventory.txt", ios::app);
	if (!fout)
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	int i = inventory.size() - 1;
	fout << name << "," << inventory[i] << endl;
	fout.close();
}

void Player::loadInventoryFromFile()
{
	ifstream fin("inventory.txt");
	if (!fin.is_open())
	{
		cout << "无法打开文件 'inventory.txt'！" << endl;
		return;
	}

	inventory.clear();

	string line;
	while (getline(fin, line))
	{
		stringstream ss(line);
		string playerName;
		string productId;

		getline(ss, playerName, ',');
		getline(ss, productId);

		if (playerName == this->name)
		{
			inventory.push_back(stoi(productId));
		}
	}

	fin.close();
}

void Player::saveCharactorsToFile()
{
	ifstream fin("inventory.txt");
	if (!fin.is_open())
	{
		cout << "无法打开文件 'inventory.txt'！" << endl;
		return;
	}

	inventory.clear();

	string line;
	while (getline(fin, line))
	{
		stringstream ss(line);
		string playerName;
		string productId;

		getline(ss, playerName, ',');
		getline(ss, productId);

		if (playerName == this->name)
		{
			inventory.push_back(stoi(productId));
		}
	}

	fin.close();
}

void Player::loadCharactorsFromFile()
{
	ifstream fin("charactors.txt");
	if (!fin.is_open())
	{
		cout << "无法打开文件 'charactors.txt'！" << endl;
		return;
	}

	charactors.clear();

	string line;
	while (getline(fin, line))
	{
		stringstream ss(line);
		string playerName;
		string characterId;

		getline(ss, playerName, ',');
		getline(ss, characterId);

		if (playerName == this->name)
		{
			charactors.push_back(stoi(characterId));
		}
	}

	fin.close();
}

void Player::addToInventory(int productId)
{
	inventory.push_back(productId);
	saveInventoryToFile();
	cout << "商品已添加到您的库存。" << endl;
}