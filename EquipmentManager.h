#pragma once
#ifndef EQUIPMENTMANAGER_H
#define EQUIPMENTMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include "Equipment.h"
#include "FlowerofLife.h"
#include <functional>
#include <random>
#include <sstream>
#include "Player.h"

using namespace std;

class EquipmentManager
{
public:
    EquipmentManager() {}

    //�������ID
    void setPlayerId(int id)
    {
        this->playerId = id;
    }

    //ǿ��ʥ����
    bool strengthenAll()
    {
        int d;
        cout << "��ȷ������ǿ��ʥ����:  �˳�������0" << '\n';
        cout << "ȷ��ǿ����֮����������1" << '\n';
        cin >> d;
        if (d == 0)
        {
            system("cls");
            return false;
        }
        else
        {
            switch (d)
            {
            case 1:
                flowerOfLife.strengthen();
                break;
            }
        }
        Sleep(2000);
        system("cls");

        return true;
    }

    //��жʥ����
    bool removeEquipment()
    {
        system("cls");
        if (flowerOfLife.getequip() != 1)
        {
            cout << "���޿ɲ�ж��ʥ�����ȴ�����" << '\n';
            Sleep(2000);
            system("cls");
            return false;
        }
        int a;
        cout << "��ȷ�������жʥ����:  �˳�������0" << '\n';
        if (flowerOfLife.getequip() == 1)
            cout << "ȷ�ϲ�ж��֮����������1" << '\n';

        cin >> a;
        if (a == 0)
        {
            system("cls");
            return false;
        }
        switch (a)
        {
        case 1:
            flowerOfLife.false_equip();
            equipments.push_back(flowerOfLife);
            equipments[0].setEquipt(0);
            cout << "��ж��֮���ɹ�" << '\n';
            break;
        }
        Sleep(2000);
        system("cls");
        return true;
    }

    //װ��ʥ����
    bool addEquipment()
    {
        system("cls");
        if (flowerOfLife.getequip() != 0)
        {
            cout << "���޿�װ����ʥ�����ȴ�����" << '\n';
            Sleep(2000);
            system("cls");
            return false;
        }
        int b;
        cout << "��ȷ������װ��ʥ����:  �˳�������0" << '\n';
        if (flowerOfLife.getequip() == 0)
            cout << "ȷ��װ����֮����������1" << '\n';

        cin >> b;
        if (b == 0)
        {
            system("cls");
            return false;
        }
        switch (b)
        {
        case 1:
            flowerOfLife.true_equip();
            equipments.push_back(flowerOfLife);
            equipments[0].setEquipt(1);
            cout << "װ����֮���ɹ�" << '\n';
            break;
        }
        Sleep(2000);
        system("cls");
        return true;
    }

    //��жʥ����
    bool displayEquipment()
    {
        if (flowerOfLife.getequip() == 0)
        {
            cout << "ʥ�����Ѿ�����ж����ȴ�����" << '\n';
            Sleep(2000);
            system("cls");
            return false;
        }
        if (flowerOfLife.getequip() == 1)
            flowerOfLife.showElements();
        return true;
    }

    //��ȡװ����Ϣ
    vector<Equipment> getEquipments()
    {
        Equipment temp;
        equipments.push_back(temp);
        return equipments;
    }

    //��ʼ��װ��
    void initEquipments(int id)
    {
        equipments.push_back(flowerOfLife);
        for (Equipment &equipment : equipments)
        {
            equipment.setPlayerId(id);
        }
    }

    //�����������
    void setPlayerName(string playerName)
    {
        this->playerName = playerName;
    }

    //��ȡ�������
    string getPlayerName()
    {
        return playerName;
    }

    //���ļ��ж�ȡװ����Ϣ
    void readEquipment()
    {
        ifstream file("equipment.txt");
        if (file.is_open())
        {

            std::string line;
            while (getline(file, line))
            {
                istringstream ss(line);
                vector<string> words;
                string word;
                while (ss >> word)
                {
                    words.push_back(word);
                }

                if (std::stoi(words[0]) == this->playerId)
                {
                    Equipment temp;
                    temp.setPlayerId(std::stoi(words[0]));
                    temp.setEquipt(std::stoi(words[1]));
                    equipments.push_back(temp);
                    flowerOfLife.setPlayerId(std::stoi(words[0]));
                    flowerOfLife.setEquipt(std::stoi(words[1]));
                }
            }
            file.close();
        }
    }

private:
    FlowerofLife flowerOfLife;
    vector<Equipment> equipments;
    string playerName;
    int playerId;
};

#endif
