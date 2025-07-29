#pragma once

#ifndef ARMORITEM_H
#define ARMORITEM_H
#include<iostream>
#include"item.h"

using namespace std;

class ArmorItem :public Item
{
public:
	ArmorItem(int a) : defense_increment(a)
	{
	}
	const int defense_increment;
	bool use()
	{
		return 1;
	}
private:

};
#endif
