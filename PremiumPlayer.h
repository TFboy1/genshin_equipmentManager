#ifndef PREMIUMPLAYER_H
#define PREMIUMPLAYER_H

#include"Player.h"

using namespace std;

class PremiumPlayer : public Player {
public:
	PremiumPlayer(Player* player)
		: Player(player->Getid(), player->Getname(), player->Getlevel()), player(player) {}

	void addPremiumBenefits() {
		// Implement premium benefits

	}

	void displayEquipment() {
		// Implement equipment display logic

	}

	void accessGameStore() {
		// Implement game store access logic

	}

private:
	Player* player;
};
#endif
