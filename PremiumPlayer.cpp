#include "PremiumPlayer.h"
PremiumPlayer::PremiumPlayer(Player &player, PlayerManager &playerManager) : player(player)
{
	id = player.Getid();
	name = player.Getname();
	level = player.Getlevel();
	balance = player.getBalance();
	isPremiumPlayer = false;
	this->playerManager = playerManager;
	store = new Store(player, playerManager);
}
PremiumPlayer::~PremiumPlayer() {}
void PremiumPlayer::addPremiumBenefits()
{

	int choice;
	cout << "��ѡ������Ҫ�ĸ߼���Ȩ�� �˳�������0" << '\n';
	cout << "[1]������ҵȼ�\n"
		 << "[2]ʹ���̳��ۿ�\n"
		 << "���ѡ��";
	cin >> choice;
	switch (choice)
	{
	case 0:
		cout << "�˳���Ȩѡ��\n";
		break;
	case 1:
	{
		int newLevel = player.Getlevel() + 2;
		player.setLevel(newLevel);
		playerManager.updatePlayer(&player);
		playerManager.saveToFile();
		cout << "������ҵȼ��ɹ�" << '\n';
		break;
	}
	case 2:
		system("cls");
		cout << "ʹ���̳��ۿ۳ɹ�" << '\n';
		accessGameStore();
		break;
	default:
		cout << "��Чѡ��������ѡ��\n";
	}
	Sleep(2000);
	system("cls");
}

void PremiumPlayer::accessGameStore()
{
	store->discount();
	store->openStore();
	store->rediscount();
}
