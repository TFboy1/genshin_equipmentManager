#include "Game.h"

Game::Game()
{
    cout << RED << "ԭ��" << RESET << "����"
         << "����" << RESET << std::endl;
}

Game::~Game()
{
    cout << "ǰ�������Ժ�����̽���ɣ���" << endl;
}

Player *Game::createPlayer()
{
    string name;
    int level = 0;
    double balance = 0;
    cout << "�������ɫ����" << endl;
    cin >> name;
    Player *player = playerFactory.createPlayer(name, level, balance);
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
        cout << "����ʥ�������˵�:" << endl;
        cout << "��жʥ����������1" << '\n'
             << "װ��ʥ����������2" << '\n'
             << "ǿ��ʥ����������3" << '\n'
             << "չʾʥ����������4" << '\n'
             << "�˳�������0" << '\n';

        cin >> a;
        switch (a)
        {
        case 1:
        {
            M.removeEquipment();
            break;
        }
        case 2:
            M.addEquipment();
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
    M.saveEquipment();
}

void Game::CardDrawSystem(Player &player)
{
    int a;
    int b;

    CardDraw Drawer(player);
    cout << "��ӭ����ԭ���ɫ���س鿨����" << endl;
    do
    {
        cout << "��ȡ��ɫ�밴1" << '\n'
             << "չʾ��ɫ��ȡ��ʷ��¼�밴2���˳��밴0" << endl;

        cin >> a;
        switch (a)
        {
        case 1:
            cout << "���������ȡ�Ĵ���" << endl;
            cin >> b;
            for (int i = 1; i <= b; i++)
                Drawer.drawCard();
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
 on3:   Player *selectedPlayer = chosePlayer();
    if (selectedPlayer == nullptr)
    {
        cout << "��ѡ����ȷ�Ľ�ɫID�ٴ��̵ꡣ" << endl;
        goto on3;
    }
    PremiumPlayer PremiumPlayer(*selectedPlayer, playerManager);
    if (PremiumPlayer.getBalance() > 30)
    {
        int a;
        do
        {
            cout << "��ӭ�����߼����ϵͳ:" << endl;
            cout << "�ṩ�߼������Ȩ������1" << '\n'
                 << "������Ϸ�̵�������2���˳�������0" << '\n';

            cin >> a;
            switch (a)
            {
            case 1:
                PremiumPlayer.addPremiumBenefits();
                break;
            case 2:
                PremiumPlayer.accessGameStore();
                break;
            case 0:
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
        cout << "������Ϸ��ɫ�˵�:" << endl;
        cout << "����һ����ɫ������1" << '\n'
             << "ɾ����ɫ������2" << '\n'
             << "��ʾ���н�ɫ������3" << '\n'
             << "����ʥ�������˵�������4" << '\n'
             << "����VIPϵͳ������5" << '\n'
             << "�����̵����г�ֵ�밴6" << '\n'
             << "����鿨ϵͳ�밴7" << '\n'
             << "�˳�������0" << '\n';

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
            playerManager.displayAllPlayers();
            break;
        case 4:
        {
         on1:   Player *chosedPlayer = chosePlayer();
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
            PremiumPlayerSystem();
            break;
        case 6:
        {
         on2:   Player *selectedPlayer = chosePlayer();
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
         on4:   Player *selectedPlayer = chosePlayer();
            if (selectedPlayer == nullptr)
            {
                cout << "��ѡ����ȷ�Ľ�ɫID�ٴ��̵ꡣ" << endl;
                goto on4;
            }
            CardDrawSystem(*selectedPlayer);
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
    cout << "��ӭ����" << BLUE << "ģ��ԭ��ϵͳ��" << RESET << endl;
    playerSystem();
}

void Game::openStore(Player &player, PlayerManager &playerManager)
{
    Store store(player, playerManager);
    store.openStore();
}
