#include"Player.h"
Player::Player() {
	equipmentManager.setPlayerName(name);
	equipments=equipmentManager.getEquipments();
}
//获取id
int Player::Getid() const { return id; }

void Player::Setid(int id)
{
		this->id = id;
}

//获取name 
string Player::Getname() const { return name; }

//获取level
int Player::Getlevel() const { return level; }

// 构造函数
Player::Player(int id, string Name, int level)
	: id(id), name(Name), level(level), isPremiumPlayer(false), balance(0.0) {
	equipmentManager.setPlayerName(name);
	equipments = equipmentManager.getEquipments();
}

// 添加Observer
void Player::addObserver(Observer* observer) {
	observers.push_back(observer);
}

// 移除Observer
void Player::removeObserver(Observer* observer) {
	observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

// 通知Observer
void Player::notifyObservers() {
	for (Observer* observer : observers) {
		observer->update();
	}
}

// 设置玩家等级
void Player::setLevel(int newLevel) {
	level = newLevel;
	notifyObservers();
}



// 设置是否是高级玩家
void Player::setPremiumPlayer(bool premium) {
	isPremiumPlayer = premium;
	notifyObservers();
}

// 获取余额
double Player::getBalance() const {
	return balance;
}

// 设置余额
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

void Player::saveEquipment()
{
	
}
