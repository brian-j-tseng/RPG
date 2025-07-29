#pragma once

#ifndef SPINACH_H
#define SPINACH_H
#include<iostream>
#include"noviceplayer.h"
#include"ConsumableItem.h"

using namespace std;

class Spinach :public ConsumableItem
{
public:
	Spinach()
	{
		level_required = 1;
		name = "Spinach";
		effects = "increase exp 10 points.";
		description = "healthful and delicious !";
		weight = 1;
		type = 'c';
	}
	void use(NovicePlayer* player)
	{
		player->setexp(player->getexp() + 10);
	}
private:

};
#endif
