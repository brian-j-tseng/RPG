#pragma once

#ifndef SLIVERSWORD_H
#define SLIVERSWORD_H
#include<iostream>
#include"item.h"
#include"WeaponItem.h"

using namespace std;

class SliverSword :public WeaponItem
{
public:
	SliverSword() :WeaponItem(30)
	{
		level_required = 5;
		name = "sliversword";
		effects = "increase attack 30 points.";
		description = "a aword made dy sliver ,have very sharp edge,can get by store or defeat zombie monster.";
		weight = 15;
		type = 'w';
	}
private:

};

#endif
