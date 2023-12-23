// Game.cpp
#include "Game.h"

Game::Game() {
    // Constructor implementation, if needed
    cout << RED << "原神" << RESET << "启动" <<  "！！" << RESET << std::endl;
}

Game::~Game() {
    // Destructor implementation, if needed
    cout << "前面区域以后再来探索吧！！" << endl;
}

Player* Game::createPlayer()
{
    string name;
    int level = 0;
    double balance = 0;
    cout << "请输入角色名：" << endl;
    cin >> name;
    Player* player = playerFactory.createPlayer(name, level,balance);
    playerManager.addPlayer(player);
    PlayerObserver playerObserve(player->Getid());
    subject.attach(&playerObserve);

    cout << "显示此时所有玩家" << endl;
    playerManager.displayAllPlayers();
    return player;
}
void Game::deletePlayer() {
    int id;
    cout << "请输入要删除的角色id" << endl;
    cin >> id;
    Player* player = playerManager.getPlayerById(id);
    playerManager.removePlayer(player);
    cout << "删除成功" << endl;
}
Player* Game::chosePlayer() {
    int id;
    while (true) {
        cout << "请输入要选择的角色id:" << endl;
        cin >> id;
        const std::type_info& idType = typeid(id);
        
        Player* player = playerManager.getPlayerById(id);
        if (player == nullptr) {
            
            return nullptr;
        }
        else {
            break;
        }
    }
    /*cout << "请输入要选择的角色id:" << endl;
    cin >> id;
    const std::type_info& idType = typeid(id);
    if (idType != typeid(int)) {
        cout << "请输入正确的ID" << endl;
        return nullptr;
    }*/
    Player* player = playerManager.getPlayerById(id);

    return player;
}
void Game::equipmentSystem(Player* player) {
    int a = 1;
    EquipmentManager M = player->getEquipmentManager();
    M.setPlayerName(player->Getname());
    M.setPlayerId(player->Getid());
    //
    // M.loud();
    M.readEquipment();
    do {
        cout << "这是圣遗物管理菜单:" << endl;
        //cout << "展示圣遗物请输入1，强化圣遗物请输入2，退出请输入0" << '\n';
        cout << "拆卸圣遗物请输入1"<<'\n'<<"装备圣遗物请输入2"<<'\n'<<"强化圣遗物请输入3"<<'\n'<<"展示圣遗物请输入4"<<'\n'<<"退出请输入0" << '\n';
            
        cin >> a;
        switch (a) {
        case 1: {
          
        M.removeEquipment(); break;
        }
        case 2:M.addEquipment(); break;
        case 3:if (M.getEquipments().empty()) {
            system("cls");
            M.displayEquipment(); break;
        }
              else {
            system("cls");
            M.strengthenAll(); break;
        }
        case  4:system("cls"); M.displayEquipment(); break;
        case 0:system("cls"); break;
        //case 5:system("cls"); M.devastateEquipment(); break;
        default:cout << "输入错误" << endl; break;
        }
    } while (a);
    M.saveEquipment();
}

void Game::CardDrawSystem(Player& player)
{
    int a;
    int b;
   
    CardDraw Drawer(player);
        cout << "欢迎来到原神角色卡池抽卡环节" << endl;
   do{
        cout << "抽取角色请按1"<<'\n'<<"展示角色抽取历史记录请按2，退出请按0" << endl;
    
        cin >> a;
        switch (a) {
        case 1:
            cout << "请输入想抽取的次数" << endl;
            cin >> b;
            for (int i = 1; i <= b; i++)
                Drawer.drawCard(); break;
        case 2:
            Drawer.DisplayDrawnCards();
            break;
        case 0:
            system("cls");
            break;
        default:cout << "输入错误，请重新输入" << endl; break;
        }
    } while (a);
}






void Game::PremiumPlayerSystem()
{
    Player* selectedPlayer = chosePlayer();
    if (selectedPlayer == nullptr) {
        cout << "请选择正确的角色ID再打开商店。" << endl;
        return;
    }
    PremiumPlayer  PremiumPlayer(*selectedPlayer,playerManager);
    if (PremiumPlayer.getBalance() > 30) {
        int a;
        do {
            cout << "欢迎来到高级玩家系统:" << endl;
            cout << "提供高级玩家特权请输入1" << '\n' << "访问游戏商店请输入2，退出请输入0" << '\n';
                
            cin >> a;
            switch (a) {
            case 1:PremiumPlayer.addPremiumBenefits(); break;
            case 2:PremiumPlayer.accessGameStore(); break;
            case 0:break;
            default:cout << "输入错误" << endl; break;
            }
        } while (a);
    }
    else {
        cout << "您不是VIP" << endl;
    }
    
}
void Game::chargeSystem()
{
    // 检查是否选择了角色
    Player* selectedPlayer = chosePlayer();
    if (selectedPlayer == nullptr) {
        cout << "请选择正确的角色ID再打开商店。" << endl;
        return;
    }

    // 创建一个带有所选角色的商店实例
    Store store(*selectedPlayer,playerManager);
    double amount;
    cout << "请输入充值金额：" << endl;
    cin >> amount;
    store.deposit(amount);
    playerManager.saveToFile();
   
}
void Game::playerSystem() {
    int a = 1;
    do {
        cout << "这是游戏角色菜单:" << endl;
        cout << "创建一个角色请输入1"<<'\n'<<"删除角色请输入2"<<'\n'<<"显示所有角色请输入3"<<'\n'<<"进入圣遗物管理菜单请输入4"<<'\n'<<"进入VIP系统请输入5"<<'\n'<<"进入商店或进行充值请按6"<<'\n'<<"进入抽卡系统请按7"<<'\n'<<"退出请输入0" << '\n';
           
        cin >> a;
        switch (a) {
        case 1:createPlayer(); break;
        case 2:deletePlayer(); break;
        case 3:playerManager.displayAllPlayers(); break;
        case 4: {
            Player* chosedPlayer = chosePlayer();
            if (chosedPlayer != nullptr) {
                equipmentSystem(chosedPlayer); break;
            }
            else
            {
                cout << "请输入正确的ID" << endl;
            }
        }
        /*case 5: openStore(); break;*/
        case 5: PremiumPlayerSystem(); break;
        case 6: {
            // 检查是否选择了角色
       Player* selectedPlayer = chosePlayer();
       if (selectedPlayer == nullptr) {
           cout << "请选择正确的角色ID再打开商店。" << endl;
           return;
       }
       openStore(*selectedPlayer,playerManager); break;
        }
        case 7: {
            Player* selectedPlayer = chosePlayer();
            if (selectedPlayer == nullptr) {
                cout << "请选择正确的角色ID再打开商店。" << endl;
                return;
            }
            CardDrawSystem(*selectedPlayer); break;
        }
        case 0:break;
        default:cout << "输入错误" << endl; break;
        }
    } while (a);
}
void Game::startGame() {

    PlayerManager playerManager;
    PlayerFactory playerFactory = PlayerFactory::getInstance();

    cout << "欢迎来到"<<BLUE<<"模拟原神系统：" <<RESET<< endl;
    /*cout << "开始游戏请按1" << endl;
    int choice = 0;
    cin>> choice;
    while (true) {
        if (choice == 1 || choice == 0) {
            break;
        }
        else {
            cout << "输入错误，请重新输入" << endl;
            cin >> choice;
        }
    }  */
    playerSystem();



    /*cout<<"是否创建一个角色"<<endl;
    cout<<"1.是"<<endl;
    cout<<"2.否"<<endl;

    int choice;
    cin>>choice;
    if (choice == 1) {

        Player* player=createPlayer();
        playerSystem();
    }
    else if(choice==2){
        cout<<"请先创建一个角色再开始游戏："<<endl;
        cout<<"结束游戏或者继续创建一个角色？"<<endl;
        cout<<"1.结束游戏"<<endl;
        cout<<"2.继续创建一个角色"<<endl;
        int choice1;
        cin>>choice1;
        if (choice1 == 1) {
            cout<<"游戏结束"<<endl;
        }
        else if(choice1==2){

            createPlayer();
            playerSystem();
        }
        else {
            cout<<"输入错误"<<endl;

        }
    }
    else {
            cout<<"输入错误"<<endl;
    }*/


}

void Game::openStore(Player& player,PlayerManager &playerManager)
{
    Store store(player, playerManager);
    store.openStore();
}


