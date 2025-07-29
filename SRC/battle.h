#ifndef BATTLE_H
#define BATTLE_H
#include<iostream>
#include<vector>
#include"noviceplayer.h"
#include"basemonster.h"
#include"jwmonster.h"
#include"goblinmonster.h"
#include"zombiemonster.h"
using namespace std;

struct Character
{
	char type; // monster or player?
	bool alive; // alive or dead?
	void *instance; // pointer to instance
};
class Battle
{
public:
	Battle(int, int);
	~Battle();
	
	void setplayer(NovicePlayer*,int);
	void setmonster(BaseMonster*,int);
	GoblinMonster producegoblinmonster();
	ZombieMonster producezombiemonster();
	JWMonster producejwmonster();
	bool battle();

	NovicePlayer *tmp_player;
	BaseMonster *tmp_monster;
private:
	int nofplayer;
	int nofmonster;
	Character *actionlist;

	//generate monster
	GoblinMonster goblin1;
	GoblinMonster goblin2;
	GoblinMonster goblin3;

	ZombieMonster zombie1;
	ZombieMonster zombie2;
	ZombieMonster zombie3;
	
	JWMonster jw1;
	JWMonster jw2;
	JWMonster jw3;
	//----------------------
	int nturn=1;
};
#endif

