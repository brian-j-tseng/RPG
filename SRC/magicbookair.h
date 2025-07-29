#pragma once

#ifndef MAGICBOOKAIR_H
#define MAGICBOOKAIR_H
#include<iostream>
#include"WeaponItem.h"

using namespace std;

class MagicBookAir :public WeaponItem
{
public:
	MagicBookAir() :WeaponItem(35)
	{
		level_required = 6;
		name = "magicbookair";
		effects = "increase attack 35 points.";
		description = "a old magic textbook lost by a powerful magician ,which can iprove your magic skill,can get by store or defeat zombie monster.";
		weight = 10;
		type = 'w';
	}
private:

};
#endif
