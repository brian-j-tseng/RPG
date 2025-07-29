#pragma once

#ifndef GAME_H
#define GAME_H

#include "noviceplayer.h"
#include"mainmenu.h"
#include"fieldmenu.h"
#include"field.h"
using namespace std;

class Game
{
public:
	void run();
	bool save();
	void loadrecord();
	void setnewgame();
	void gamestart();
private:
	bool exit = 0;
	MainMenu mainmenu;
	FieldMenu fieldmenu;
	NovicePlayer** player_list;
	int playernumber=0;
	Field* map;
	int mapnumber;
	/*Storyline progress
	Files loaded
	Statistics(optional, e.g., # of monster killed)
	*/
};

#endif

