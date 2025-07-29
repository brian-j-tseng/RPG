#pragma once

#ifndef CANDY_H
#define CANDY_H
#include<iostream>
#include"noviceplayer.h"
#include"ConsumableItem.h"
using namespace std;

class Candy :public ConsumableItem
{
public:
	Candy()
	{
		level_required = 1;
		name = " Candy";
		effects = "level up.";
		description = "a mysterious candy can bring you to next level!";
		weight = 1;
		type = 'c';
	}
	void use(NovicePlayer* player)
	{
		player->setlevel(player->getlevel() + 1);
	}
private:

};
#endif
