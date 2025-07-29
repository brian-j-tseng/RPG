#pragma once

#ifndef ORCPLAYER_H
#define ORCPLAYER_H

#include "noviceplayer.h"
using namespace std;

class OrcPlayer : public NovicePlayer
{
public:
	OrcPlayer();
	OrcPlayer(int);
	OrcPlayer(int, string);
	OrcPlayer(const OrcPlayer&);

	virtual void setlevel(int);
	virtual void specialSkill();
	virtual	string serialize();
	virtual	OrcPlayer* unserialize(string);
	virtual string returntype();
};

#endif

