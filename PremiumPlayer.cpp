#include "PremiumPlayer.h"
// PremiumPlayer 类的成员函数实现
PremiumPlayer::PremiumPlayer(Player& player,PlayerManager& playerManager):player(player) {
	id = player.Getid();
	name = player.Getname();
	level = player.Getlevel();
	balance = player.getBalance();
	isPremiumPlayer = false;
	this->playerManager = playerManager;
	store=new Store(player,playerManager);
}
PremiumPlayer::~PremiumPlayer(){}
void PremiumPlayer::addPremiumBenefits() {
	
	int choice;
	/*do {*/
		cout << "请选择你需要的高级特权： 退出请输入0" << '\n';
		cout << "升级玩家等级，请输入1\n"
			<< "使用商城折扣，请输入2\n"
			<< "你的选择：";
		cin >> choice;
		switch (choice) {
		case 0:
			cout << "退出特权选择\n";
			break;
		case 1: {
			int newLevel=player.Getlevel()+2;
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
	/*} while (choice != 0);*/
    // 提供高级玩家特权的代码
}

//void PremiumPlayer::displayEquipment() {
//	cout << "请选择你需要显示玩家装备：退出请输入0\n";
//	int a;
//	do {
//		cout << "展示圣遗物1，请输入1\n"
//			<< "展现圣遗物2，请输入2\n"
//			<< "展现圣遗物3，请输入3\n"
//			<< "你的选择：";
//		cin >> a;
//
//		switch (a) {
//		case 0:
//			cout << "退出显示玩家装备\n";
//			break;
//		case 1:
//			cout << "展示圣遗物1成功" << '\n';
//			break;
//		case 2:
//			cout << "展示圣遗物2成功" << '\n';
//			break;
//		case 3:
//			cout << "展示圣遗物3成功" << '\n';
//			break;
//		default:
//			cout << "无效选择，请重新选择\n";
//		}
//		Sleep(2000);
//		system("cls");
//	} while (a != 0);
//    // 显示玩家装备的代码
//}

void PremiumPlayer::accessGameStore() {
store->discount();
store->openStore();
		
    // 访问游戏商店的代码
}
