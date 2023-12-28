#pragma once
#ifndef FLOWEROFLIFE_H
#define FLOWEROFLIFE_H
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Equipment.h"
#include "Stats.h"

class FlowerofLife : public Equipment
{
public:
    FlowerofLife();
    ~FlowerofLife();
    void strengthen();      //强化生之花
    void initialElements(); //初始化生之花
};

#endif
