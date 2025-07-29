#pragma once

#ifndef CONSUMABLEITEM_H
#define CONSUMABLEITEM_H
#include<iostream>
#include"item.h"

using namespace std;

class NovicePlayer;

class ConsumableItem :public Item
{
public:
	ConsumableItem()
	{
	}
	virtual void use(NovicePlayer*)=0;
	bool use()
	{
		return 1;
	}
private:
};
#endif
