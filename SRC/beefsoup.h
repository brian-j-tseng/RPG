#pragma once

#ifndef BEEFSOUP_H
#define BEEFSOUP_H
#include<iostream>
#include"noviceplayer.h"
#include"ConsumableItem.h"

using namespace std;

class BeefSoup :public ConsumableItem
{
public:
	BeefSoup()
	{
		level_required = 1;
		name = "BeefSoup";
		effects = "increase hp by 10 points.";
		description = "a delicious beefsoup seems to restore power!";
		weight = 3;
		type = 'c';
	}
	virtual void use(NovicePlayer*player)
	{
		player->sethp(player->gethp() + 10);
	}
private:
};
#endif
