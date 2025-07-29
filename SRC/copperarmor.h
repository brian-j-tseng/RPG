#pragma once

#ifndef COPPERARMOR_H
#define COPPERARMOR_H
#include<iostream>
#include"ArmorItem.h"

using namespace std;

class CopperArmor :public ArmorItem
{
public:
	CopperArmor() :ArmorItem(25)
	{
		level_required = 5;
		name = "CopperArmor";
		effects = "increase defense 25 points.";
		description = "a armor made with copper,have very strong body protect function,can get by store or defeat monster.";
		weight = 15;
		type = 'a';
	}
private:

};
#endif
