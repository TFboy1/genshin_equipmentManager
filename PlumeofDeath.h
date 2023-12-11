#pragma once
#ifndef PLUMEOFDEATH_H
#define PLUMEOFDEATH_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Equipment.h"
#include "Stats.h"

class PlumeofDeath : public Equipment {
public:
    PlumeofDeath();
    ~PlumeofDeath();
   void showElements();
    void strengthen();
    void initialElements();
private:
   
};

#endif
