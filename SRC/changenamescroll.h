#pragma once

#ifndef CHANGENAMESCROLL_H
#define CHANGENAMESCROLL_H
#include<iostream>
#include"noviceplayer.h"
#include"ConsumableItem.h"

using namespace std;

class ChangenameScroll :public ConsumableItem
{
public:
	ChangenameScroll()
	{
		level_required = 1;
		name = "ChangenameScroll";
		effects = "Change name.";
		description = "you will get a chance to reset your name!";
		weight = 1;
		type = 'c';
	}
	void use(NovicePlayer* player)
	{
		string a;
		cin >> a;
		player->setname(a);
	}
private:

};
#endif
