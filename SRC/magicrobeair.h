#pragma once

#ifndef MAGICROBEAIR_H
#define  MAGICROBEAIR_H
#include<iostream>
#include"ArmorItem.h"

using namespace std;

class MagicRobeAir : public ArmorItem
{
public:
	MagicRobeAir() :ArmorItem(15)
	{
		level_required = 3;
		name = "MagicRobeAir";
		effects = "increase defense 15 points.";
		description = "a MagicRobe made by the oldest magicin in canada,have body protect function,can get by store or defeat monster.";
		weight = 10;
		type = 'a';
	}
private:

};
#endif
