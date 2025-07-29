#pragma once

#ifndef GOBLINMONSTER_H
#define GOBLINMONSTER_H

#include<string>
#include"basemonster.h"
using namespace std;

class GoblinMonster:public BaseMonster
{
public:
	GoblinMonster();
	~GoblinMonster();

	virtual Item* fallingitems();
	virtual string serialize();
	virtual GoblinMonster* unserialize(string);
	Item* falling;
};

#endif
