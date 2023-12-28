#include "Game.h"
extern int s[4];
extern int s0[4];
Game::Game()
{
    std::cout << RED << BOLD << "╔══════════════════════════════╗" << RESET << std::endl;
    std::cout << RED << BOLD << "║ " << RESET << "原神" << RED << "启动" << RESET << "！！                " << RED << BOLD << " ║" << RESET << std::endl;
    std::cout << RED << BOLD << "╚══════════════════════════════╝" << RESET << std::endl;
    std::cout << "欢迎来到" << BLUE << BOLD << " 模拟原神系统：" << RESET << std::endl;
}

Game::~Game()
{
    std::cout << BLUE << BOLD << "╔══════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BLUE << BOLD << "║ " << RESET << ITALIC << "前面区域以后再来探索吧！！" << RESET << BLUE << BOLD << "               ║" << RESET << std::endl;
    std::cout << BLUE << BOLD << "╚══════════════════════════════════════════╝" << RESET << std::endl;
}

Player *Game::createPlayer()
{
    string name;
    int level = 0;
    double balance = 0;
    int health = 10, attack = 2, defense = 2;
    cout << "请输入角色名：" << endl;
    cin >> name;
    Player *player = playerFactory.createPlayer(name, level, balance, health, attack, defense);
    playerManager.addPlayer(player);
    cout << "显示此时所有玩家" << endl;
    playerManager.displayAllPlayers();
    return player;
}
void Game::deletePlayer()
{
    int id;
    cout << "请输入要删除的角色id" << endl;
    cin >> id;
    Player *player = playerManager.getPlayerById(id);
    playerManager.removePlayer(player);
    cout << "删除成功" << endl;
}
Player *Game::chosePlayer()
{
    int id;
    while (true)
    {
        cout << "请输入要选择的角色id:" << endl;
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
        std::cout << BLUE << BOLD << "╔══════════════════════════════════╗" << RESET << std::endl;
        std::cout << BLUE << BOLD << "║     这是圣遗物管理菜单:          ║" << RESET << std::endl;
        std::cout << BLUE << BOLD << "╠══════════════════════════════════╣" << RESET << std::endl;
        std::cout << BLUE << BOLD << "║ 1. 拆卸圣遗物                    ║" << std::endl
                  << "║ 2. 装备圣遗物                    ║" << std::endl
                  << "║ 3. 强化圣遗物                    ║" << std::endl
                  << "║ 4. 展示圣遗物                    ║" << std::endl
                  << "║ 0. 退出                          ║" << RESET << std::endl;
        std::cout << BLUE << BOLD << "╚══════════════════════════════════╝" << RESET << std::endl;

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
                cout << "强化成功，花费$200,当前余额：$" << player->getBalance() << endl;
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
            cout << "输入错误" << endl;
            break;
        }
    } while (a);
}
void Game::enhanceAttributesSystem(Player *player)
{
    int choice;
    do
    {
        std::cout << YELLOW << BOLD << "╔══════════════════════════════════╗" << RESET << std::endl;
        std::cout << YELLOW << BOLD << "║       强化属性商店               ║" << RESET << std::endl;
        std::cout << YELLOW << BOLD << "╠══════════════════════════════════╣" << RESET << std::endl;
        std::cout << YELLOW << BOLD << "║ 1. 提升2点生命值($150)           ║" << std::endl
                  << "║ 2. 提升1点攻击力($100)           ║" << std::endl
                  << "║ 3. 提升1点防御力($100)           ║" << std::endl
                  << "║ 0. 返回上级菜单                  ║" << RESET << std::endl;
        std::cout << YELLOW << BOLD << "╚══════════════════════════════════╝" << RESET << std::endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            if (player->getBalance() >= 150)
            {
                player->increaseHealth();
                player->setBalance(player->getBalance() - 150);
                cout << "当前余额：$" << player->getBalance() << endl;
            }
            else
                cout << "余额不足" << endl;
            break;
        case 2:
            system("cls");
            if (player->getBalance() >= 100)
            {
                player->increaseAttack();
                player->setBalance(player->getBalance() - 100);
                cout << "当前余额：$" << player->getBalance() << endl;
            }
            else
                cout << "余额不足" << endl;
            break;
        case 3:
            system("cls");
            if (player->getBalance() >= 100)
            {
                player->increaseDefense();
                player->setBalance(player->getBalance() - 100);
                cout << "当前余额：$" << player->getBalance() << endl;
            }
            else
                cout << "余额不足" << endl;
            break;
        case 0:
            system("cls");
            break;
        default:
            cout << "输入错误，请重新输入" << endl;
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

    std::cout << MAGENTA << BOLD << "欢迎来到原神角色卡池抽卡环节" << RESET << std::endl;
    do
    {
        std::cout << CYAN << BOLD << "╔══════════════════════════════════╗" << RESET << std::endl;
        std::cout << CYAN << BOLD << "║           抽卡系统               ║" << RESET << std::endl;
        std::cout << CYAN << BOLD << "╠══════════════════════════════════╣" << RESET << std::endl;
        std::cout << CYAN << BOLD << "║ 1. 抽取角色                      ║" << std::endl
                  << "║ 2. 展示角色抽取历史记录          ║" << std::endl
                  << "║ 0. 退出                          ║" << RESET << std::endl;
        std::cout << CYAN << BOLD << "╚══════════════════════════════════╝" << RESET << std::endl;
        cin >> a;
        int ischange = 0;
        switch (a)
        {
        case 1:
            system("cls");
            cout << "请输入想抽取的次数(每次花费$200)" << endl;
            cin >> b;
            for (int i = 1; i <= b && player.getBalance() >= 200; i++)
            {
                Drawer.drawCard();
                ischange = 1;
            }
            if (ischange)
                cout << "抽卡成功！";
            if (!ischange)
                cout << "余额不足，停止抽卡！";
            playerManager.saveToFile();
            cout << "当前余额:$" << player.getBalance() << endl;
            break;
        case 2:
            Drawer.DisplayDrawnCards();
            break;
        case 0:
            system("cls");
            break;
        default:
            cout << "输入错误，请重新输入" << endl;
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
        cout << "请选择正确的角色ID再打开商店。" << endl;
        goto on3;
    }
    PremiumPlayer PremiumPlayer(*selectedPlayer, playerManager);
    if (PremiumPlayer.getBalance() > 300)
    {
        int a;
        do
        {
            std::cout << YELLOW << BOLD << "╔══════════════════════════════════╗" << RESET << std::endl;
            std::cout << YELLOW << BOLD << "║    欢迎来到高级玩家系统          ║" << RESET << std::endl;
            std::cout << YELLOW << BOLD << "╠══════════════════════════════════╣" << RESET << std::endl;
            std::cout << YELLOW << BOLD << "║ 1. 提供高级玩家特权              ║" << std::endl
                      << "║ 2. 访问游戏商店                  ║" << std::endl
                      << "║ 0. 退出                          ║" << RESET << std::endl;
            std::cout << YELLOW << BOLD << "╚══════════════════════════════════╝" << RESET << std::endl;

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
                cout << "输入错误" << endl;
                break;
            }
        } while (a);
    }
    else
    {
        cout << "您不是VIP" << endl;
    }
}
void Game::chargeSystem()
{
    Player *selectedPlayer = chosePlayer();
    if (selectedPlayer == nullptr)
    {
        cout << "请选择正确的角色ID再打开商店。" << endl;
        return;
    }
    Store store(*selectedPlayer, playerManager);
    double amount;
    cout << "请输入充值金额：" << endl;
    cin >> amount;
    store.deposit(amount);
    playerManager.saveToFile();
}
void Game::playerSystem()
{
    int a = 1;
    do
    {
        std::cout << BLUE << BOLD << "╔══════════════════════════════════╗" << RESET << std::endl;
        std::cout << BLUE << BOLD << "║     这是游戏角色菜单:            ║" << RESET << std::endl;
        std::cout << BLUE << BOLD << "╠══════════════════════════════════╣" << RESET << std::endl;
        std::cout << YELLOW << BOLD << "║ [1]创建一个角色                  ║" << std::endl
                  << "║ [2]删除角色                      ║" << std::endl
                  << "║ [3]显示所有角色                  ║" << std::endl
                  << "║ [4]进入圣遗物管理菜单            ║" << std::endl
                  << "║ [5]进入VIP系统                   ║" << std::endl
                  << "║ [6]进入商店或进行充值            ║" << std::endl
                  << "║ [7]进入抽卡系统                  ║" << std::endl
                  << "║ [8]进入强化属性商店              ║" << std::endl
                  << "║ [0]退出                          ║" << RESET << std::endl;
        std::cout << BLUE << BOLD << "╚══════════════════════════════════╝" << RESET << std::endl;

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
            cout << "全体玩家信息如下：" << endl;
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
                cout << "请输入正确的ID" << endl;
                goto on1;
            }
        }
        case 5:
            system("cls");
            cout << "     VIP系统" << endl;
            PremiumPlayerSystem();
            break;
        case 6:
        {
            system("cls");
            cout << "     商店" << endl;
        on2:
            Player *selectedPlayer = chosePlayer();
            if (selectedPlayer == nullptr)
            {
                cout << "请选择正确的角色ID再打开商店。" << endl;
                goto on2;
            }
            openStore(*selectedPlayer, playerManager);
            break;
        }
        case 7:
        {
            system("cls");
            cout << "     抽卡商店" << endl;
        on4:
            Player *selectedPlayer = chosePlayer();
            if (selectedPlayer == nullptr)
            {
                cout << "请选择正确的角色ID再打开商店。" << endl;
                goto on4;
            }
            CardDrawSystem(*selectedPlayer);
            break;
        }
        case 8:
        {
            system("cls");
            cout << "     强化商店" << endl;
        on5:
            Player *selectedPlayer = chosePlayer();
            if (selectedPlayer == nullptr)
            {
                cout << "请选择正确的角色ID再打开商店。" << endl;
                goto on5;
            }
            enhanceAttributesSystem(selectedPlayer);
            break;
        }
        case 0:
            break;
        default:
            cout << "输入错误" << endl;
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
