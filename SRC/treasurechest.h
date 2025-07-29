#pragma once

#ifndef TREASURECHEST_H
#define TREASURECHEST_H
#include<iostream>
#include"noviceplayer.h"
#include"ConsumableItem.h"

using namespace std;

class Treasurechest :public ConsumableItem
{
public:
	Treasurechest()
	{
		level_required = 1;
		name = "Treasurechest";
		effects = "increase money 100$.";
		description = "a chest lost by a Pirate Captain,seems to have a lot of money!";
		weight = 3;
		type = 'c';
	}
	void use(NovicePlayer* player)
	{
		player->setmoney(player->getmoney() + 10);
	}
private:

};
#endif
