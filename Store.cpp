#include "store.h"

Store::Store(Player &player, PlayerManager &playerManager) : player(player), playerManager(playerManager)
{
    loadProductsFromFile();
    player.loadInventoryFromFile();
}

Store::~Store() {}
void Store::showPurchaed()
{
    cout << "�ѹ������Ʒ��" << endl;
    for (const auto purchased : player.getInventory())
        for (const auto &product : products)
        {
            {
                if (product.id == purchased)
                {
                    cout << "ID��" << product.id << "�����ƣ�" << product.name << "���۸�$" << product.price << endl;
                }
            }
        }
}
void Store::openStore()
{
    int choice = 1;
    do
    {
        cout << "�̵�˵�:" << endl;
        cout << "�鿴���ڳ��۵���Ʒ������1����ֵ������2��������Ʒ������3���鿴�Ѿ��������Ʒ�밴4���˳�������0" << '\n';
        cin >> choice;
        switch (choice)
        {
        case 1:
            displayProducts();
            break;
        case 2:
        {
            double amount;
            cout << "�������ֵ��" << endl;
            cin >> amount;
            deposit(amount);
            playerManager.saveToFile();
            break;
        }
        case 3:
        {
            int productId;
            cout << "������Ҫ�������ƷID��" << endl;
            cin >> productId;
            purchaseProduct(productId);
            playerManager.saveToFile();
            break;
        }
        case 4:
            showPurchaed();
            break;
        case 0:
            break;
        default:
            cout << "�������" << endl;
            break;
        }
    } while (choice);
}
void Store::addProduct(int id, const string &name, double price)
{
    Product newProduct = {id, name, price}; // �޸Ĵ���Product�ķ�ʽ�������Ʒ����
    products.push_back(newProduct);
    saveProductsToFile();
    cout << "��Ʒ����ӣ�ID " << id << "������ " << name << "���۸� $" << price << endl;
}
void Store::discount()
{
    for (auto &product : products)
    {
        product.price *= 0.8;
    }
    cout << "�̳���Ʒ�Ѵ���ۡ�" << endl;
}
void Store::rediscount()
{
    for (auto& product : products)
    {
        product.price *= 1.25;
    }
    cout << "�̳���Ʒ�Ѵ���ۡ�" << endl;
}
void Store::removeProduct(int id)
{
    auto it = find_if(products.begin(), products.end(), [id](const Product &p)
                      { return p.id == id; });

    if (it != products.end())
    {
        products.erase(it);
        cout << "��Ʒ���Ƴ���ID " << id << endl;
        saveProductsToFile();
    }
    else
    {
        cout << "δ�ҵ�IDΪ " << id << " ����Ʒ��" << endl;
    }
}

double Store::getPlayerBalance() const
{
    return player.getBalance();
}

void Store::deposit(double amount)
{
    player.setBalance(player.getBalance() + amount);
    cout << "��ֵ�ɹ�����ǰ��$" << player.getBalance() << endl;
}

void Store::displayProducts() const
{
    cout << "�̵��е���Ʒ��" << endl;
    for (const auto &product : products)
    {
        cout << "ID��" << product.id << "�����ƣ�" << product.name << "���۸�$" << product.price << endl;
    }
}

bool Store::withdraw(double amount)
{
    double playerBalance = player.getBalance();
    if (playerBalance >= amount)
    {
        player.setBalance(playerBalance - amount);
        cout << "����ɹ�����ǰ��$" << player.getBalance() << endl;
        return true;
    }
    else
    {
        cout << "���㡣����ʧ�ܡ�" << endl;
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
            player.addToInventory(productId);
            cout << "����ɹ����Ѵ���������п۳� $" << productPrice << endl;
            return true;
        }
        else
        {
            cout << "����ʧ�ܡ�" << endl;
            return false;
        }
    }
    else
    {
        cout << "δ�ҵ�IDΪ " << productId << " ����Ʒ��" << endl;
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
        cout << "��Ʒ��Ϣ�ѱ��浽�ļ���" << endl;
    }
    else
    {
        cout << "�޷����ļ����б��档" << endl;
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
        cout << "�޷����ļ����м��ء�" << endl;
    }
}