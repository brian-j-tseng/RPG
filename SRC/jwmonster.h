#pragma once

#ifndef JWMONSTER_H
#define JWMONSTER_H

#include<string>
#include"basemonster.h"
using namespace std;

class JWMonster :public BaseMonster
{
public:
	JWMonster();
	~JWMonster();

	virtual Item* fallingitems();
	virtual string serialize();
	virtual JWMonster* unserialize(string);

	Item* falling;
};

#endif
