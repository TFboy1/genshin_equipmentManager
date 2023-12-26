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
	cout << "请选择你需要的高级特权： 退出请输入0" << '\n';
	cout << "升级玩家等级，请输入1\n"
		 << "使用商城折扣，请输入2\n"
		 << "你的选择：";
	cin >> choice;
	switch (choice)
	{
	case 0:
		cout << "退出特权选择\n";
		break;
	case 1:
	{
		int newLevel = player.Getlevel() + 2;
		player.setLevel(newLevel);
		playerManager.updatePlayer(&player);
		playerManager.saveToFile();
		cout << "升级玩家等级成功" << '\n';
		break;
	}
	case 2:

		cout << "使用商城折扣成功" << '\n';
		accessGameStore();
		break;
	default:
		cout << "无效选择，请重新选择\n";
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
