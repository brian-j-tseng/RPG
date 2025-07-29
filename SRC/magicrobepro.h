#pragma once

#ifndef MAGICROBEPRO_H
#define MAGICROBEPRO_H
#include<iostream>
#include"ArmorItem.h"

using namespace std;

class MagicRobePro :public ArmorItem
{
public:
	MagicRobePro() :ArmorItem(50)
	{
		level_required = 10;
		name = "MagicRobePro";
		effects = "increase defense 50 points.";
		description = "a MagicRobe made by the most powerful magicin in medieval,have body protect function,can get by store or defeat monster.";
		weight = 20;
		type = 'a';
	}
private:

};
#endif
