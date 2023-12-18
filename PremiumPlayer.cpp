#include "PremiumPlayer.h"
// PremiumPlayer ��ĳ�Ա����ʵ��
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
		cout << "��ѡ������Ҫ�ĸ߼���Ȩ�� �˳�������0" << '\n';
		cout << "������ҵȼ���������1\n"
			<< "ʹ���̳��ۿۣ�������2\n"
			<< "���ѡ��";
		cin >> choice;
		switch (choice) {
		case 0:
			cout << "�˳���Ȩѡ��\n";
			break;
		case 1: {
			int newLevel=player.Getlevel()+2;
			player.setLevel(newLevel);
			playerManager.updatePlayer(&player);
			playerManager.saveToFile();
		cout << "������ҵȼ��ɹ�" << '\n';
			break;
		}
		case 2:
			
			cout << "ʹ���̳��ۿ۳ɹ�" << '\n';
			accessGameStore();
			break;
		default:
			cout << "��Чѡ��������ѡ��\n";
		}
		Sleep(2000);
		system("cls");
	/*} while (choice != 0);*/
    // �ṩ�߼������Ȩ�Ĵ���
}

//void PremiumPlayer::displayEquipment() {
//	cout << "��ѡ������Ҫ��ʾ���װ�����˳�������0\n";
//	int a;
//	do {
//		cout << "չʾʥ����1��������1\n"
//			<< "չ��ʥ����2��������2\n"
//			<< "չ��ʥ����3��������3\n"
//			<< "���ѡ��";
//		cin >> a;
//
//		switch (a) {
//		case 0:
//			cout << "�˳���ʾ���װ��\n";
//			break;
//		case 1:
//			cout << "չʾʥ����1�ɹ�" << '\n';
//			break;
//		case 2:
//			cout << "չʾʥ����2�ɹ�" << '\n';
//			break;
//		case 3:
//			cout << "չʾʥ����3�ɹ�" << '\n';
//			break;
//		default:
//			cout << "��Чѡ��������ѡ��\n";
//		}
//		Sleep(2000);
//		system("cls");
//	} while (a != 0);
//    // ��ʾ���װ���Ĵ���
//}

void PremiumPlayer::accessGameStore() {
store->discount();
store->openStore();
		
    // ������Ϸ�̵�Ĵ���
}
