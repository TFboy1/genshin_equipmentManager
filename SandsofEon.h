// SandsofEon.h
#pragma once
#ifndef SANDSOFEON_H
#define SANDSOFEON_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Equipment.h"
#include "Stats.h"

class SandsofEon : public Equipment {
public:
    SandsofEon();
    ~SandsofEon();
    void showElements();
    void strengthen();
    void initialElements();

private:
    std::vector<Stats> attributess;
};

#endif
