// FlowerofLife.h
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

class FlowerofLife : public Equipment {
public:
    FlowerofLife();
    ~FlowerofLife();
    //void showElements();
    void strengthen();
    void initialElements();

private:
    
};

#endif
