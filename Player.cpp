#include"Player.h"
Player::Player() {
	equipmentManager.setPlayerName(name);
	equipments=equipmentManager.getEquipments();
	loadInventoryFromFile();
}

//获取id
int Player::Getid() const { return id; }

void Player::Setid(int id)
{
		this->id = id;
		//equipmentManager.getEquipments()[0].setPlayerId(id);
}

//获取name 
string Player::Getname() const { return name; }

//获取level
int Player::Getlevel() const { return level; }

// 构造函数
Player::Player(int id, string Name, int level,double balance)
	: id(id), name(Name), level(level), isPremiumPlayer(false), balance(balance){
	equipmentManager.setPlayerName(name);
	equipments = equipmentManager.getEquipments();
	equipmentManager.setPlayerId(id);
}


// 设置玩家等级
void Player::setLevel(int newLevel) {
	level = newLevel;
	
}



// 设置是否是高级玩家
void Player::setPremiumPlayer(bool premium) {
	isPremiumPlayer = premium;
	
}

// 获取余额
double Player::getBalance() const {
	return balance;
}

// 设置余额
void Player::setBalance(double amount) {
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
	if (!fout) {
		cout << "文件打开失败！" << endl;
		return;
	}
	for (int i = 0; i < inventory.size(); i++) {
		fout<<name<<"," << inventory[i] << endl;
	}
	fout.close();
}

void Player::loadInventoryFromFile()
{
	ifstream fin("inventory.txt");
	if (!fin.is_open()) {
		cout << "无法打开文件 'inventory.txt'！" << endl;
		return;
	}

	inventory.clear();  // Clear existing inventory before loading from file

	string line;
	while (getline(fin, line)) {
		stringstream ss(line);
		string playerName;
		string productId;

		getline(ss, playerName, ',');
		getline(ss, productId);

		// Assuming the loaded inventory belongs to the current player
		if (playerName == this->name) {
			inventory.push_back(stoi(productId));
		}
	}

	fin.close();
}

void Player::saveCharactorsToFile()
{
	ifstream fin("inventory.txt");
	if (!fin.is_open()) {
		cout << "无法打开文件 'inventory.txt'！" << endl;
		return;
	}

	inventory.clear();  // Clear existing inventory before loading from file

	string line;
	while (getline(fin, line)) {
		stringstream ss(line);
		string playerName;
		string productId;

		getline(ss, playerName, ',');
		getline(ss, productId);

		// Assuming the loaded inventory belongs to the current player
		if (playerName == this->name) {
			inventory.push_back(stoi(productId));
		}
	}

	fin.close();
}

void Player::loadCharactorsFromFile() {
	ifstream fin("charactors.txt");  // Change the file name to "charactors.txt"
	if (!fin.is_open()) {
		cout << "无法打开文件 'charactors.txt'！" << endl;
		return;
	}

	charactors.clear();  // Clear existing characters before loading from file

	string line;
	while (getline(fin, line)) {
		stringstream ss(line);
		string playerName;
		string characterId;

		getline(ss, playerName, ',');
		getline(ss, characterId);

		// Assuming the loaded characters belong to the current player
		if (playerName == this->name) {
			charactors.push_back(stoi(characterId));
		}
	}

	fin.close();
}

void Player::addToInventory(int productId) {
    inventory.push_back(productId);
	saveInventoryToFile();
    cout << "商品已添加到您的库存。" << endl;
}