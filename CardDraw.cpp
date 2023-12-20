#include "CardDraw.h"
#include<cstdlib>
#include<ctime>
#include"CardCharacter.h"
using namespace std;
CardDraw::CardDraw(Player &player):player(player)
{
	
    const char name1[] = "����";
    const char name2[] = "����";
    const char name3[] = "�׵�Ӱ";
    const char name4[] = "��������";
    const char name5[] = "�����";
    const char name6[] = "����";
    const char name7[] = "�µ�";
    const char name8[] = "����类�";
    const char name9[] = "��¬��";
    const char name10[] = "������";
    const char name11[] = "��ϣ��";
    const char name12[] = "��ŵ";
    const char name13[] = "ɺ�����ĺ�";
    const char name14[] = "ܽ����";
    const char name15[] = "��ά����";
    const char name16[] = "��ŷ˹��";
    const char name17[] = "����";
    const char name18[] = "��¶";
    const char name19[] = "����һ��";
    const char name20[] = "ɢ��";
    const char element1[] = "��";
    const char element2[] = "��";
    const char element3[] = "��";
    const char element4[] = "��";
    const char element5[] = "ˮ";
    const char element6[] = "��";
    const char element7[] = "��";
    CardCharacter member1(1, name1, element1, 1, 500, 700, 240);
    CardCharacter member2(2, name2, element2, 1, 500, 700, 150);
    CardCharacter member3(3, name3, element1, 1, 500, 1000, 200);
    CardCharacter member4(4, name4, element1, 1, 500, 1200, 200);
    CardCharacter member5(5, name5, element3, 1, 700, 800, 500);
    CardCharacter member6(6, name6, element4, 1, 500, 700, 800);
    CardCharacter member7(7, name7, element7, 1, 500, 700, 400);
    CardCharacter member8(8, name8, element6, 1, 500, 800, 500);
    CardCharacter member9(9, name9, element2, 1, 500, 700, 400);
    CardCharacter member10(10, name10, element3, 1, 500, 800, 400);
    CardCharacter member11(11, name11, element2, 1, 500, 700, 500);
    CardCharacter member12(12, name12, element1, 1, 500, 1000, 400);
    CardCharacter member13(13, name13, element5, 1, 800, 600, 700);
    CardCharacter member14(14, name14, element5, 1, 700, 600, 700);
    CardCharacter member15(15, name15, element5, 1, 500, 1100, 500);
    CardCharacter member16(16, name16, element6, 1, 600, 1000, 600);
    CardCharacter member17(17, name17, element2, 1, 500, 900, 600);
    CardCharacter member18(18, name18, element5, 1, 700, 800, 700);
    CardCharacter member19(19, name19, element4, 1, 500, 900, 500);
    CardCharacter member20(20, name20, element1, 1, 700, 900, 700);

    CardPool.push_back(member1);
    CardPool.push_back(member2);
    CardPool.push_back(member3);
    CardPool.push_back(member4);
    CardPool.push_back(member5);
    CardPool.push_back(member6);
    CardPool.push_back(member7);
    CardPool.push_back(member8);
    CardPool.push_back(member9);
    CardPool.push_back(member10);
    CardPool.push_back(member11);
    CardPool.push_back(member12);
    CardPool.push_back(member13);
    CardPool.push_back(member14);
    CardPool.push_back(member15);
    CardPool.push_back(member16);
    CardPool.push_back(member17);
    CardPool.push_back(member18);
    CardPool.push_back(member19);
    CardPool.push_back(member20);
    player.loadCharactorsFromFile();
}

void CardDraw::saveCharactorsToFile()
{
    
    std::ofstream outputFile("charactors.txt", std::ios::out);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing: charactors.txt" << std::endl;
        return;
    }

    // Iterate through characters and write only the IDs to the file
    for (const auto& character : drawnCards) {
        outputFile <<player.Getname()<<"," << character.getId() << std::endl;
    }

    outputFile.close();
    
}


CardCharacter CardDraw::drawCard()
{
	int randomIndex = rand() % CardPool.size();
	CardCharacter drawnCard = CardPool[randomIndex];
	drawnCards.push_back(drawnCard);
    saveCharactorsToFile();
	return drawnCard;
}



void CardDraw::DisplayDrawnCards() const
{
    player.loadCharactorsFromFile();
	cout << "���س�ȡ��¼" << endl;
    for(auto&charactor: player.getCharactors())
	for (const auto& card : CardPool) {
        if (card.getId() == charactor) {
            cout << "��ɫ����" << card.GetName() << endl;
            cout << "��ɫ���ԣ�" << card.GetElement() << endl;
            cout << "��ɫ�ȼ���" << card.GetLevel() << endl;
            cout << "��ɫ����ֵ��" << card.GetHP() << endl;
            cout << "��ɫ��������" << card.GetATK() << endl;
            cout << "��ɫ����ֵ��" << card.GetDef() << endl;
        }
		
	}
}

