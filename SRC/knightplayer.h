#pragma once

#ifndef KNIGHTPLAYER_H
#define KNIGHTPLAYER_H

#include "noviceplayer.h"
using namespace std;

class KnightPlayer : public NovicePlayer
{
public:
	KnightPlayer();
	KnightPlayer(int);
	KnightPlayer(int, string);
	KnightPlayer(const KnightPlayer&);

	virtual void setlevel(int);
	virtual void specialSkill();
	virtual	string serialize();
	virtual	KnightPlayer* unserialize(string);
	virtual string returntype();
};

#endif
