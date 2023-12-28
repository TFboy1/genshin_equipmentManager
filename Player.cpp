#include "Player.h"
Player::Player()
{
	equipmentManager.setPlayerName(name);
	equipments = equipmentManager.getEquipments();
	loadInventoryFromFile();
}

//��ȡid
int Player::Getid() const { return id; }

void Player::Setid(int id)
{
	this->id = id;
}

//��ȡname
string Player::Getname() const { return name; }

int Player::Gethealth() const { return health; }

int Player::Getattack() const { return attack; }

int Player::Getdefense() const { return defense; }

//��ȡlevel
int Player::Getlevel() const { return level; }

// ���캯��
Player::Player(int id, string Name, int level, double balance, int health, int attack, int defense)
	: id(id), name(Name), level(level), isPremiumPlayer(false), balance(balance), health(health), attack(attack), defense(defense)
{
	equipmentManager.setPlayerName(name);
	equipments = equipmentManager.getEquipments();
	equipmentManager.setPlayerId(id);
}

// ������ҵȼ�
void Player::setLevel(int newLevel)
{
	level = newLevel;
}

void Player::increaseHealth()
{
	health += 2;
	cout << "����ֵǿ���ɹ�����ǰ����ֵ��" << health << endl;
}
void Player::increaseAttack()
{
	attack += 1;
	cout << "������ǿ���ɹ�����ǰ��������" << attack << endl;
}
void Player::increaseDefense()
{
	defense += 1;
	cout << "������ǿ���ɹ�����ǰ��������" << defense << endl;
}
// �����Ƿ��Ǹ߼����
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
// ��ȡ���
double Player::getBalance() const
{
	return balance;
}

// �������
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
		cout << "�ļ���ʧ�ܣ�" << endl;
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
		cout << "�޷����ļ� 'inventory.txt'��" << endl;
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
		cout << "�޷����ļ� 'inventory.txt'��" << endl;
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
		cout << "�޷����ļ� 'charactors.txt'��" << endl;
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
	cout << "��Ʒ����ӵ����Ŀ�档" << endl;
}