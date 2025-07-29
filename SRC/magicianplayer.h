#pragma once

#ifndef MAGICIANPLAYER_H
#define MAGICIANPLAYER_H

#include "noviceplayer.h"
using namespace std;

class MagicianPlayer : public NovicePlayer
{
public:
	MagicianPlayer();
	MagicianPlayer(int);
	MagicianPlayer(int, string);
	MagicianPlayer(const MagicianPlayer&);

	virtual void setlevel(int);
	virtual void specialSkill();
	virtual	string serialize();
	virtual	MagicianPlayer* unserialize(string);
	virtual string returntype();
};

#endif

