#pragma once

#ifndef IRONSWORD_H
#define IRONSWORD_H
#include<iostream>
#include"WeaponItem.h"

using namespace std;

class IronSword :public WeaponItem
{
public:
	IronSword() :WeaponItem(10)
	{
		level_required = 1;
		name = "ironsword";
		effects = "increase attack 10 points.";
		description = "a aword made dy iron ,have sharp edge,can get by store or defeat monster.";
		weight = 10;
		type = 'w';
	}
private:

};
#endif
