#pragma once

#ifndef WOODENARMOR_H
#define WOODENARMOR_H
#include<iostream>
#include"ArmorItem.h"

using namespace std;

class WoodenArmor : public ArmorItem
{
public:
	WoodenArmor() :ArmorItem(10)
	{
		level_required = 1;
		name = "WoodenArmor";
		effects = "increase defense 10 points.";
		description = "a armor made by Lu ban,have strong body protect function,can get by store or defeat monster.";
		weight = 10;
		type = 'a';
	}
private:

};
#endif

