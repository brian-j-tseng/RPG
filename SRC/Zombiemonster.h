#pragma once

#ifndef ZOMBIEMONSTER_H
#define ZOMBIEMONSTER_H

#include<string>
#include"basemonster.h"
using namespace std;

class ZombieMonster :public BaseMonster
{
public:
	ZombieMonster();
	~ZombieMonster();

	virtual Item* fallingitems() ;
	virtual string serialize();
	virtual ZombieMonster* unserialize(string);

	Item* falling;
};

#endif
