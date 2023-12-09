// Game.cpp
#include "Game.h"

Game::Game() {
    // Constructor implementation, if needed
    cout << "原神启动！！" << endl;
}

Game::~Game() {
    // Destructor implementation, if needed
    cout << "前面区域以后再来探索吧！！" << endl;
}

Player* Game::createPlayer()
{
    string name;
    int level = 0;
    cout << "请输入角色名：" << endl;
    cin >> name;
    Player* player = playerFactory.createPlayer(name, level);
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
        if (idType != typeid(int)) {
            cout << "请输入正确的ID" << endl;
            return nullptr;
        }
        Player* player = playerManager.getPlayerById(id);
        if (player == nullptr) {
            cout << "请输入正确的ID" << endl;
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

    do {
        cout << "这是圣遗物管理菜单:" << endl;
        cout << "拆卸圣遗物请输入1，装备圣遗物请输入2，强化圣遗物请输入3，展示圣遗物请输入4，退出请输入0" << '\n';
        cin >> a;
        switch (a) {
        case 1:M.removeEquipment(); break;
        case 2:M.addEquipment(); break;
        case 3:if (M.FlowerofLife::getcount() == 0 && M.PlumeofDeath::getcount() == 0 && M.SandsofEon::getcount() == 0 && M.GobletofEonothem::getcount() == 0 && M.CircletofLogos::getcount() == 0) {
            system("cls");
            M.displayEquipment(); break;
        }
              else
            M.strengthenAll(); M.displayEquipment(); break;
        case  4:system("cls"); M.displayEquipment(); break;
        case 0:break;
        default:cout << "输入错误" << endl; break;
        }
    } while (a);
}
void Game::playerSystem() {
    int a = 1;
    do {
        cout << "这是游戏角色菜单:" << endl;
        cout << "创建一个角色请输入1，删除角色请输入2，显示所有角色请输入3，选择角色请输入4，退出请输入0" << '\n';
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

        case 0:break;
        default:cout << "输入错误" << endl; break;
        }
    } while (a);
}
void Game::startGame() {

    PlayerManager playerManager;
    PlayerFactory playerFactory = PlayerFactory::getInstance();

    cout << "欢迎来到圣遗物管理系统：" << endl;
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


