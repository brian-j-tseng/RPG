#pragma once

#ifndef BASEMONSTER_H
#define BASEMONSTER_H

#include<string>
#include"item.h"
using namespace std;

class BaseMonster
{
	friend ostream& operator<<(ostream&, const BaseMonster &);
public:
	BaseMonster(string, int, int, int, int, int, int) ;
    ~BaseMonster();


	void setHP(int);
	int getHP() const;
	void setMP(int);
	int getMP() const;
	static int getInstanceCount(void);



	const string name; // Name of the monster
	const int attack; // Attack of the monster
	const int defense; // Defense of the monster 
	const int exp; // Experience earned by players after beating this monster
	const int money; // Amount of money dropped after beating this monster
	const int max_hp ; // The monster¡¦s maximum HP
	const int max_mp ; // The monster¡¦s maximum MP

	virtual string serialize() = 0;
	virtual Item* fallingitems() =0;
	//virtual BaseMonster* unserialize(string)=0;
private:
	int hp;
	int mp;
	static int count;
protected:
};


#endif

