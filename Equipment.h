#pragma once
#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include"FlowerofLife.h"
#include"PlumeofDeath.h"
#include"SandsofEon.h"
#include"GobletofEonothem.h"
#include"CircletofLogos.h"
using namespace std;
class Equipment :public FlowerofLife, public PlumeofDeath, public SandsofEon, public GobletofEonothem, public CircletofLogos {
public:
	Equipment() {}
	~Equipment() {}

};
#endif