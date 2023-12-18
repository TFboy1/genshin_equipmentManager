#include "store.h"

Store::Store(Player& player,PlayerManager &playerManager ) : player(player),playerManager(playerManager) {
    // 构造函数
    loadProductsFromFile();
    player.loadInventoryFromFile();
    
}

Store::~Store() {
    // 析构函数
}
void Store::showPurchaed() {
    	cout << "已购买的商品：" << endl;
        for (const auto purchased : player.getInventory())
        for (const auto& product : products) {
            {
             if (product.id == purchased) {
                 cout << "ID：" << product.id << "，名称：" << product.name << "，价格：$" << product.price << endl;
             }
            }
	}

}
void Store::openStore() {
    //// 检查是否选择了角色
    //Player* selectedPlayer = chosePlayer();
    //if (selectedPlayer == nullptr) {
    //    cout << "请选择正确的角色ID再打开商店。" << endl;
    //    return;
    //}

    //// 创建一个带有所选角色的商店实例
    //Store store(*selectedPlayer);

    int choice = 1;
    do {
        cout << "商店菜单:" << endl;
        cout << "查看正在出售的商品请输入1，充值请输入2，购买商品请输入3，查看已经购买的商品请按4，退出请输入0" << '\n';
        cin >> choice;
        switch (choice) {
        case 1:displayProducts(); break;
        case 2: {
            double amount;
            cout << "请输入充值金额：" << endl;
            cin >> amount;
            deposit(amount);
            playerManager.saveToFile();
            break;
        }
        case 3: {
            int productId;
            cout << "请输入要购买的商品ID：" << endl;
            cin >> productId;
            purchaseProduct(productId);
            playerManager.saveToFile();
            break;
        }
        case 4: showPurchaed(); break; // 新增的管理商城功能
        case 0: break;
        default: cout << "输入错误" << endl; break;
        }
    } while (choice);
}
void Store::addProduct(int id, const string& name, double price) {
    Product newProduct = { id, name, price };  // 修改创建Product的方式，添加商品名称
    products.push_back(newProduct);
    saveProductsToFile();
    cout << "商品已添加：ID " << id << "，名称 " << name << "，价格 $" << price << endl;
}
void Store::discount() {
    for (auto& product : products) {
		product.price *= 0.8;
	}
	cout << "商城商品已打八折。" << endl;
	
}
void Store::removeProduct(int id) {
    auto it = find_if(products.begin(), products.end(), [id](const Product& p) {
        return p.id == id;
        });

    if (it != products.end()) {
        products.erase(it);
        cout << "商品已移除：ID " << id << endl;
        saveProductsToFile();
    }
    else {
        cout << "未找到ID为 " << id << " 的商品。" << endl;
    }
}

double Store::getPlayerBalance() const {
    return player.getBalance();
}

void Store::deposit(double amount) {
    player.setBalance(player.getBalance() + amount);
    cout << "充值成功。当前余额：$" << player.getBalance() << endl;

}

void Store::displayProducts() const {
    cout << "商店中的商品：" << endl;
    for (const auto& product : products) {
        cout << "ID：" << product.id << "，名称：" << product.name << "，价格：$" << product.price << endl;
    }
}

bool Store::withdraw(double amount) {
    double playerBalance = player.getBalance();
    if (playerBalance >= amount) {
        player.setBalance(playerBalance - amount);
        cout << "购买成功。当前余额：$" << player.getBalance() << endl;
        return true;
    }
    else {
        cout << "余额不足。购买失败。" << endl;
        return false;
    }
}

bool Store::purchaseProduct(int productId) {
    auto it = find_if(products.begin(), products.end(), [productId](const Product& p) {
        return p.id == productId;
        });

    if (it != products.end()) {
        double productPrice = it->price;
        if (withdraw(productPrice)) {
            // 扣除玩家余额成功，将商品添加到玩家库存
            // 请根据实际情况修改这里的逻辑，例如将商品添加到玩家的库存中
            player.addToInventory(productId);  // 调用添加到库存的函数
            cout << "购买成功！已从您的余额中扣除 $" << productPrice << endl;
            return true;
        }
        else {
			cout << "购买失败。" << endl;
			return false;
		}
    }
    else {
        cout << "未找到ID为 " << productId << " 的商品。" << endl;
        return false;
    }
}

void Store::manageStore() {
    int choice = 1;
    do {
        cout << "增加商品请输入1，删除商品请输入2，查看商品请输入3，退出请输入0" << '\n';
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string name;
            double price;
            cout << "请输入商品ID：" << endl;
            cin >> id;
            cout << "请输入商品名称：" << endl;
            cin >> name;
            cout << "请输入商品价格：" << endl;
            cin >> price;
            addProduct(id, name, price);
            break;
        }
        case 2: {
            int id;
            cout << "请输入要删除的商品ID：" << endl;
            cin >> id;
            removeProduct(id);
            break;
        }
        case 3: displayProducts(); break;
        case 0: break;
        default: cout << "输入错误" << endl; break;
        }
    } while (choice);
}

void Store::saveProductsToFile() {
    ofstream file("store.txt");
    if (file.is_open()) {
        for (const auto& product : products) {
            file << product.id << " " << product.name << " " << product.price << endl;
        }

        file.close();
        cout << "商品信息已保存到文件。" << endl;
    }
    else {
        cout << "无法打开文件进行保存。" << endl;
    }
}

void Store::loadProductsFromFile() {
    ifstream file("store.txt");
    if (file.is_open()) {
        products.clear(); // 清空当前商品列表

        Product tempProduct; // 临时存储每个商品的变量

        while (file >> tempProduct.id >> tempProduct.name >> tempProduct.price) {
            products.push_back(tempProduct);
        }

        file.close();
        /*cout << "商品信息已从文件加载。" << endl;*/
    }
    else {
        cout << "无法打开文件进行加载。" << endl;
    }
}