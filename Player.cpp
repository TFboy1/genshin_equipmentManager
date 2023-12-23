#include"Player.h"
Player::Player() {
	equipmentManager.setPlayerName(name);
	equipments=equipmentManager.getEquipments();
	loadInventoryFromFile();
}

//��ȡid
int Player::Getid() const { return id; }

void Player::Setid(int id)
{
		this->id = id;
		//equipmentManager.getEquipments()[0].setPlayerId(id);
}

//��ȡname 
string Player::Getname() const { return name; }

//��ȡlevel
int Player::Getlevel() const { return level; }

// ���캯��
Player::Player(int id, string Name, int level,double balance)
	: id(id), name(Name), level(level), isPremiumPlayer(false), balance(balance){
	equipmentManager.setPlayerName(name);
	equipments = equipmentManager.getEquipments();
	equipmentManager.setPlayerId(id);
}

// ���Observer
void Player::addObserver(Observer* observer) {
	observers.push_back(observer);
}

// �Ƴ�Observer
void Player::removeObserver(Observer* observer) {
	observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

// ֪ͨObserver
void Player::notifyObservers() {
	for (Observer* observer : observers) {
		observer->update();
	}
}

// ������ҵȼ�
void Player::setLevel(int newLevel) {
	level = newLevel;
	notifyObservers();
}



// �����Ƿ��Ǹ߼����
void Player::setPremiumPlayer(bool premium) {
	isPremiumPlayer = premium;
	notifyObservers();
}

// ��ȡ���
double Player::getBalance() const {
	return balance;
}

// �������
void Player::setBalance(double amount) {
	balance = amount;
	notifyObservers();
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
		cout << "�ļ���ʧ�ܣ�" << endl;
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
		cout << "�޷����ļ� 'inventory.txt'��" << endl;
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
		cout << "�޷����ļ� 'inventory.txt'��" << endl;
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
		cout << "�޷����ļ� 'charactors.txt'��" << endl;
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
    cout << "��Ʒ����ӵ����Ŀ�档" << endl;
}