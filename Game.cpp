#include "Game.h"
extern int s[4];
extern int s0[4];
Game::Game()
{
    std::cout << RED << BOLD << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << RESET << std::endl;
    std::cout << RED << BOLD << "�U " << RESET << "ԭ��" << RED << "����" << RESET << "����                " << RED << BOLD << " �U" << RESET << std::endl;
    std::cout << RED << BOLD << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << RESET << std::endl;
    std::cout << "��ӭ����" << BLUE << BOLD << " ģ��ԭ��ϵͳ��" << RESET << std::endl;
}

Game::~Game()
{
    std::cout << BLUE << BOLD << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << RESET << std::endl;
    std::cout << BLUE << BOLD << "�U " << RESET << ITALIC << "ǰ�������Ժ�����̽���ɣ���" << RESET << BLUE << BOLD << "               �U" << RESET << std::endl;
    std::cout << BLUE << BOLD << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << RESET << std::endl;
}

Player *Game::createPlayer()
{
    string name;
    int level = 0;
    double balance = 0;
    int health = 10, attack = 2, defense = 2;
    cout << "�������ɫ����" << endl;
    cin >> name;
    Player *player = playerFactory.createPlayer(name, level, balance, health, attack, defense);
    playerManager.addPlayer(player);
    cout << "��ʾ��ʱ�������" << endl;
    playerManager.displayAllPlayers();
    return player;
}
void Game::deletePlayer()
{
    int id;
    cout << "������Ҫɾ���Ľ�ɫid" << endl;
    cin >> id;
    Player *player = playerManager.getPlayerById(id);
    playerManager.removePlayer(player);
    cout << "ɾ���ɹ�" << endl;
}
Player *Game::chosePlayer()
{
    int id;
    while (true)
    {
        cout << "������Ҫѡ��Ľ�ɫid:" << endl;
        cin >> id;
        const std::type_info &idType = typeid(id);

        Player *player = playerManager.getPlayerById(id);
        if (player == nullptr)
        {

            return nullptr;
        }
        else
        {
            break;
        }
    }
    Player *player = playerManager.getPlayerById(id);
    return player;
}
void Game::equipmentSystem(Player *player)
{
    int a = 1;
    EquipmentManager M = player->getEquipmentManager();
    M.setPlayerName(player->Getname());
    M.setPlayerId(player->Getid());
    M.readEquipment();
    do
    {
        std::cout << BLUE << BOLD << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << RESET << std::endl;
        std::cout << BLUE << BOLD << "�U     ����ʥ�������˵�:          �U" << RESET << std::endl;
        std::cout << BLUE << BOLD << "�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g" << RESET << std::endl;
        std::cout << BLUE << BOLD << "�U 1. ��жʥ����                    �U" << std::endl
                  << "�U 2. װ��ʥ����                    �U" << std::endl
                  << "�U 3. ǿ��ʥ����                    �U" << std::endl
                  << "�U 4. չʾʥ����                    �U" << std::endl
                  << "�U 0. �˳�                          �U" << RESET << std::endl;
        std::cout << BLUE << BOLD << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << RESET << std::endl;

        cin >> a;
        switch (a)
        {
        case 1:
        {
            M.removeEquipment();
            player->addHealth(-s[0]);
            player->addAttack(-s[1]);
            player->addDefense(-s[2]);
            playerManager.saveToFile();
            break;
        }
        case 2:
            M.addEquipment();
            playerManager.saveToFile();
            break;
        case 3:
            if (M.getEquipments().empty())
            {
                system("cls");
                M.displayEquipment();
                break;
            }
            else
            {
                system("cls");
                M.strengthenAll();
                player->addHealth(s[0] - s0[0]);
                player->addAttack(s[1] - s0[1]);
                player->addDefense(s[2] - s0[2]);
                player->setBalance(player->getBalance() - 200);
                cout << "ǿ���ɹ�������$200,��ǰ��$" << player->getBalance() << endl;
                playerManager.saveToFile();
                break;
            }
        case 4:
            system("cls");
            M.displayEquipment();
            break;
        case 0:
            system("cls");
            break;
        default:
            cout << "�������" << endl;
            break;
        }
    } while (a);
}
void Game::enhanceAttributesSystem(Player *player)
{
    int choice;
    do
    {
        std::cout << YELLOW << BOLD << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << RESET << std::endl;
        std::cout << YELLOW << BOLD << "�U       ǿ�������̵�               �U" << RESET << std::endl;
        std::cout << YELLOW << BOLD << "�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g" << RESET << std::endl;
        std::cout << YELLOW << BOLD << "�U 1. ����2������ֵ($150)           �U" << std::endl
                  << "�U 2. ����1�㹥����($100)           �U" << std::endl
                  << "�U 3. ����1�������($100)           �U" << std::endl
                  << "�U 0. �����ϼ��˵�                  �U" << RESET << std::endl;
        std::cout << YELLOW << BOLD << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << RESET << std::endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            if (player->getBalance() >= 150)
            {
                player->increaseHealth();
                player->setBalance(player->getBalance() - 150);
                cout << "��ǰ��$" << player->getBalance() << endl;
            }
            else
                cout << "����" << endl;
            break;
        case 2:
            system("cls");
            if (player->getBalance() >= 100)
            {
                player->increaseAttack();
                player->setBalance(player->getBalance() - 100);
                cout << "��ǰ��$" << player->getBalance() << endl;
            }
            else
                cout << "����" << endl;
            break;
        case 3:
            system("cls");
            if (player->getBalance() >= 100)
            {
                player->increaseDefense();
                player->setBalance(player->getBalance() - 100);
                cout << "��ǰ��$" << player->getBalance() << endl;
            }
            else
                cout << "����" << endl;
            break;
        case 0:
            system("cls");
            break;
        default:
            cout << "�����������������" << endl;
            break;
        }
        playerManager.saveToFile();
    } while (choice != 0);
}

void Game::CardDrawSystem(Player &player)
{
    int a;
    int b;

    CardDraw Drawer(player);

    std::cout << MAGENTA << BOLD << "��ӭ����ԭ���ɫ���س鿨����" << RESET << std::endl;
    do
    {
        std::cout << CYAN << BOLD << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << RESET << std::endl;
        std::cout << CYAN << BOLD << "�U           �鿨ϵͳ               �U" << RESET << std::endl;
        std::cout << CYAN << BOLD << "�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g" << RESET << std::endl;
        std::cout << CYAN << BOLD << "�U 1. ��ȡ��ɫ                      �U" << std::endl
                  << "�U 2. չʾ��ɫ��ȡ��ʷ��¼          �U" << std::endl
                  << "�U 0. �˳�                          �U" << RESET << std::endl;
        std::cout << CYAN << BOLD << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << RESET << std::endl;
        cin >> a;
        int ischange = 0;
        switch (a)
        {
        case 1:
            system("cls");
            cout << "���������ȡ�Ĵ���(ÿ�λ���$200)" << endl;
            cin >> b;
            for (int i = 1; i <= b && player.getBalance() >= 200; i++)
            {
                Drawer.drawCard();
                ischange = 1;
            }
            if (ischange)
                cout << "�鿨�ɹ���";
            if (!ischange)
                cout << "���㣬ֹͣ�鿨��";
            playerManager.saveToFile();
            cout << "��ǰ���:$" << player.getBalance() << endl;
            break;
        case 2:
            Drawer.DisplayDrawnCards();
            break;
        case 0:
            system("cls");
            break;
        default:
            cout << "�����������������" << endl;
            break;
        }
    } while (a);
}

void Game::PremiumPlayerSystem()
{
on3:
    Player *selectedPlayer = chosePlayer();
    if (selectedPlayer == nullptr)
    {
        cout << "��ѡ����ȷ�Ľ�ɫID�ٴ��̵ꡣ" << endl;
        goto on3;
    }
    PremiumPlayer PremiumPlayer(*selectedPlayer, playerManager);
    if (PremiumPlayer.getBalance() > 300)
    {
        int a;
        do
        {
            std::cout << YELLOW << BOLD << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << RESET << std::endl;
            std::cout << YELLOW << BOLD << "�U    ��ӭ�����߼����ϵͳ          �U" << RESET << std::endl;
            std::cout << YELLOW << BOLD << "�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g" << RESET << std::endl;
            std::cout << YELLOW << BOLD << "�U 1. �ṩ�߼������Ȩ              �U" << std::endl
                      << "�U 2. ������Ϸ�̵�                  �U" << std::endl
                      << "�U 0. �˳�                          �U" << RESET << std::endl;
            std::cout << YELLOW << BOLD << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << RESET << std::endl;

            cin >> a;
            switch (a)
            {
            case 1:
                PremiumPlayer.addPremiumBenefits();
                break;
            case 2:
                system("cls");
                PremiumPlayer.accessGameStore();
                break;
            case 0:
                system("cls");
                break;
            default:
                cout << "�������" << endl;
                break;
            }
        } while (a);
    }
    else
    {
        cout << "������VIP" << endl;
    }
}
void Game::chargeSystem()
{
    Player *selectedPlayer = chosePlayer();
    if (selectedPlayer == nullptr)
    {
        cout << "��ѡ����ȷ�Ľ�ɫID�ٴ��̵ꡣ" << endl;
        return;
    }
    Store store(*selectedPlayer, playerManager);
    double amount;
    cout << "�������ֵ��" << endl;
    cin >> amount;
    store.deposit(amount);
    playerManager.saveToFile();
}
void Game::playerSystem()
{
    int a = 1;
    do
    {
        std::cout << BLUE << BOLD << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << RESET << std::endl;
        std::cout << BLUE << BOLD << "�U     ������Ϸ��ɫ�˵�:            �U" << RESET << std::endl;
        std::cout << BLUE << BOLD << "�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g" << RESET << std::endl;
        std::cout << YELLOW << BOLD << "�U [1]����һ����ɫ                  �U" << std::endl
                  << "�U [2]ɾ����ɫ                      �U" << std::endl
                  << "�U [3]��ʾ���н�ɫ                  �U" << std::endl
                  << "�U [4]����ʥ�������˵�            �U" << std::endl
                  << "�U [5]����VIPϵͳ                   �U" << std::endl
                  << "�U [6]�����̵����г�ֵ            �U" << std::endl
                  << "�U [7]����鿨ϵͳ                  �U" << std::endl
                  << "�U [8]����ǿ�������̵�              �U" << std::endl
                  << "�U [0]�˳�                          �U" << RESET << std::endl;
        std::cout << BLUE << BOLD << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << RESET << std::endl;

        cin >> a;
        switch (a)
        {
        case 1:
            createPlayer();
            break;
        case 2:
            deletePlayer();
            break;
        case 3:
            system("cls");
            cout << "ȫ�������Ϣ���£�" << endl;
            playerManager.displayAllPlayers();
            break;
        case 4:
        {
            system("cls");
        on1:
            Player *chosedPlayer = chosePlayer();
            if (chosedPlayer != nullptr)
            {
                equipmentSystem(chosedPlayer);
                break;
            }
            else
            {
                cout << "��������ȷ��ID" << endl;
                goto on1;
            }
        }
        case 5:
            system("cls");
            cout << "     VIPϵͳ" << endl;
            PremiumPlayerSystem();
            break;
        case 6:
        {
            system("cls");
            cout << "     �̵�" << endl;
        on2:
            Player *selectedPlayer = chosePlayer();
            if (selectedPlayer == nullptr)
            {
                cout << "��ѡ����ȷ�Ľ�ɫID�ٴ��̵ꡣ" << endl;
                goto on2;
            }
            openStore(*selectedPlayer, playerManager);
            break;
        }
        case 7:
        {
            system("cls");
            cout << "     �鿨�̵�" << endl;
        on4:
            Player *selectedPlayer = chosePlayer();
            if (selectedPlayer == nullptr)
            {
                cout << "��ѡ����ȷ�Ľ�ɫID�ٴ��̵ꡣ" << endl;
                goto on4;
            }
            CardDrawSystem(*selectedPlayer);
            break;
        }
        case 8:
        {
            system("cls");
            cout << "     ǿ���̵�" << endl;
        on5:
            Player *selectedPlayer = chosePlayer();
            if (selectedPlayer == nullptr)
            {
                cout << "��ѡ����ȷ�Ľ�ɫID�ٴ��̵ꡣ" << endl;
                goto on5;
            }
            enhanceAttributesSystem(selectedPlayer);
            break;
        }
        case 0:
            break;
        default:
            cout << "�������" << endl;
            break;
        }
    } while (a);
}
void Game::startGame()
{

    PlayerManager playerManager;
    PlayerFactory playerFactory = PlayerFactory::getInstance();

    playerSystem();
}

void Game::openStore(Player &player, PlayerManager &playerManager)
{
    Store store(player, playerManager);
    store.openStore();
}
