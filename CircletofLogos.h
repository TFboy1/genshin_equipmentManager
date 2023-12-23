// CircletofLogos.h
#pragma once
#ifndef CIRCLETOFLOGOS_H
#define CIRCLETOFLOGOS_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Equipment.h"
#include "Stats.h"

class CircletofLogos : public Equipment {
public:
    CircletofLogos();
    ~CircletofLogos();
    //void showElements();
    void strengthen();
    void initialElements();

private:
    
};

#endif
