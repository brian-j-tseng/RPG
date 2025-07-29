#pragma once

#ifndef MAGICBOOKPRO_H
#define MAGICBOOKPRO_H
#include<iostream>
#include"WeaponItem.h"

using namespace std;

class MagicBookPro :public WeaponItem
{
public:
	MagicBookPro() :WeaponItem(75)
	{
		level_required = 12;
		name = "magicbookpro";
		effects = "increase attack 75 points.";
		description = "a old magic textbook lost by the most powerful magician ,which can iprove your magic skill,can get by store or defeat zombie monster.";
		weight = 20;
		type = 'w';
	}
private:
};
#endif
