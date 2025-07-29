#pragma once

#ifndef STRANGESOUP_H
#define STRANGESOUP_H
#include<iostream>
#include"noviceplayer.h"
#include"ConsumableItem.h"

using namespace std;

class StrangeSoup :public ConsumableItem
{
public:
	StrangeSoup()
	{
		level_required = 1;
		name = " StrangeSoup";
		effects = "unknown.";
		description = "a strange soup with stinky smelling";
		weight = 1;
		type = 'c';
	}
	void use(NovicePlayer* player)
	{
		player->setmp(player->getmp() + 20);
	}
private:

};

#endif
