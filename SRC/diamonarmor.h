#pragma once

#ifndef DIAMONDARMOR_H
#define DIAMONDARMOR_H
#include<iostream>
#include"ArmorItem.h"

using namespace std;

class DiamondArmor :public ArmorItem
{
public:
	DiamondArmor() :ArmorItem(75)
	{
		level_required = 15;
		name = "DiamondArmor";
		effects = "increase defense 75 points.";
		description = "a armor made by diamond ,have the strongest body protect function,can get only by defeat jwmonster.";
		weight = 30;
		type = 'a';
	}
private:

};
#endif
