#pragma once

#ifndef GOLDENSWORD_H
#define GOLDENSWORD_H
#include<iostream>
#include"WeaponItem.h"

using namespace std;

class GoldenSword :public WeaponItem
{
public:
	GoldenSword() :WeaponItem(60)
	{
		level_required = 10;
		name = "goldensword";
		effects = "increase attack 60 points.";
		description = "a aword made dy gold ,have very very sharp edge,can get by store or defeat zombie monster.";
		weight = 20;
		type = 'w';
	}
private:

};
#endif
