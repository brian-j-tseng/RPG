#pragma once

#ifndef WEAPONITEM_H
#define WEAPONITEM_H
#include<iostream>
#include"item.h"

using namespace std;

class WeaponItem :public Item
{
public:
	WeaponItem(int a):attack_increment(a)
	{
	}
	const int attack_increment;
	
	bool use()
	{
		return 1;
	}
private:

};
#endif
