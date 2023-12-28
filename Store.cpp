#include "store.h"

Store::Store(Player &player, PlayerManager &playerManager) : player(player), playerManager(playerManager)
{
    loadProductsFromFile();
    player.loadInventoryFromFile();
}

Store::~Store() {}
void Store::showPurchaed()
{
    cout << "已购买的商品：" << endl;
    for (const auto purchased : player.getInventory())
        for (const auto &product : products)
        {
            {
                if (product.id == purchased)
                {
                    cout << "ID：" << product.id << "，名称：" << product.name << "，价格：$" << product.price << endl;
                }
            }
        }
}
void Store::openStore()
{
    int choice = 1;
    do
    {
        std::cout << GREEN << BOLD << "╔══════════════════════════════════╗" << RESET << std::endl;
        std::cout << GREEN << BOLD << "║             商店菜单             ║" << RESET << std::endl;
        std::cout << GREEN << BOLD << "╠══════════════════════════════════╣" << RESET << std::endl;
        std::cout << GREEN << BOLD << "║ 1. 查看正在出售的商品            ║" << std::endl
                  << "║ 2. 充值                          ║" << std::endl
                  << "║ 3. 购买商品                      ║" << std::endl
                  << "║ 4. 查看已经购买的商品            ║" << std::endl
                  << "║ 0. 退出                          ║" << RESET << std::endl;
        std::cout << GREEN << BOLD << "╚══════════════════════════════════╝" << RESET << std::endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            displayProducts();
            break;
        case 2:
        {
            double amount;
            cout << "请输入充值金额：" << endl;
            cin >> amount;
            system("cls");
            deposit(amount);
            playerManager.saveToFile();
            break;
        }
        case 3:
        {
            int productId;
            cout << "请输入要购买的商品ID：" << endl;
            cin >> productId;
            system("cls");
            purchaseProduct(productId);
            playerManager.saveToFile();
            break;
        }
        case 4:
            system("cls");
            showPurchaed();
            break;
        case 0:
            system("cls");
            break;
        default:
            cout << "输入错误" << endl;
            break;
        }
    } while (choice);
}
void Store::addProduct(int id, const string &name, double price)
{
    Product newProduct = {id, name, price}; // 修改创建Product的方式，添加商品名称
    products.push_back(newProduct);
    saveProductsToFile();
    cout << "商品已添加：ID " << id << "，名称 " << name << "，价格 $" << price << endl;
}
void Store::discount()
{
    for (auto &product : products)
    {
        product.price *= 0.8;
    }
    cout << "商城商品已打八折。" << endl;
}
void Store::rediscount()
{
    for (auto &product : products)
    {
        product.price *= 1.25;
    }
    cout << "商城商品已打八折。" << endl;
}
void Store::removeProduct(int id)
{
    auto it = find_if(products.begin(), products.end(), [id](const Product &p)
                      { return p.id == id; });

    if (it != products.end())
    {
        products.erase(it);
        cout << "商品已移除：ID " << id << endl;
        saveProductsToFile();
    }
    else
    {
        cout << "未找到ID为 " << id << " 的商品。" << endl;
    }
}

double Store::getPlayerBalance() const
{
    return player.getBalance();
}

void Store::deposit(double amount)
{
    player.setBalance(player.getBalance() + amount);
    cout << "充值成功。当前余额：$" << player.getBalance() << endl;
}

void Store::displayProducts() const
{
    cout << "商店中的商品：" << endl;
    for (const auto &product : products)
    {
        cout << "ID：" << product.id << "，名称：" << product.name << "，价格：$" << product.price << endl;
    }
}

bool Store::withdraw(double amount)
{
    double playerBalance = player.getBalance();
    if (playerBalance >= amount)
    {
        player.setBalance(playerBalance - amount);
        cout << "购买成功。当前余额：$" << player.getBalance() << endl;
        return true;
    }
    else
    {
        cout << "余额不足。购买失败。" << endl;
        return false;
    }
}

bool Store::purchaseProduct(int productId)
{
    auto it = find_if(products.begin(), products.end(), [productId](const Product &p)
                      { return p.id == productId; });

    if (it != products.end())
    {
        double productPrice = it->price;
        if (withdraw(productPrice))
        {
            cout << "已从您的余额中扣除 $" << productPrice << endl;
            player.addToInventory(productId);
            return true;
        }
        else
        {
            cout << "购买失败。" << endl;
            return false;
        }
    }
    else
    {
        cout << "未找到ID为 " << productId << " 的商品。" << endl;
        return false;
    }
}

void Store::saveProductsToFile()
{
    ofstream file("store.txt");
    if (file.is_open())
    {
        for (const auto &product : products)
        {
            file << product.id << " " << product.name << " " << product.price << endl;
        }

        file.close();
        cout << "商品信息已保存到文件。" << endl;
    }
    else
    {
        cout << "无法打开文件进行保存。" << endl;
    }
}

void Store::loadProductsFromFile()
{
    ifstream file("store.txt");
    if (file.is_open())
    {
        products.clear();

        Product tempProduct;

        while (file >> tempProduct.id >> tempProduct.name >> tempProduct.price)
        {
            products.push_back(tempProduct);
        }

        file.close();
    }
    else
    {
        cout << "无法打开文件进行加载。" << endl;
    }
}