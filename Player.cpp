#include"Player.h"

//��ȡid
int Player::Getid() const { return id; }

void Player::Setid(int id)
{
		this->id = id;
}

//��ȡname 
string Player::Getname() const { return name; }

//��ȡlevel
int Player::Getlevel() const { return level; }

// ���캯��
Player::Player(int id, string Name, int level)
	: id(id), name(Name), level(level), isPremiumPlayer(false), balance(0.0) {
	
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
