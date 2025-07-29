#include<iostream>
#include<string>
#include<time.h>
#include"basemonster.h"
#include"item.h"

using namespace std;

int BaseMonster::count = 0;

ostream& operator<<(ostream& os, const BaseMonster &monster) {
	os << "name:    " << monster.name << endl;
	os << "attack:  " << monster.attack << endl;
	os << "defense: " << monster.defense << endl;
	os << "money:   " << monster.money << endl;
	os << "hp:      " << monster.getHP() << " / " << monster.max_hp << endl;
	os << "mp:      " << monster.getMP() << " / " << monster.max_mp << endl;
	return os;
}

BaseMonster::BaseMonster(string a, int b, int c, int d, int e, int f, int g)
	:name(a),attack(b),defense(c),exp(d),money(e),max_hp(f),max_mp(g)
{
	setHP(f);
	setMP(g);
	count++;
}
BaseMonster::~BaseMonster()
{
	count--;
}


void BaseMonster::setHP(int a)
{
	if (a <= max_hp&&a>=0)
	{
		hp = a;
	}
	else if (a > max_hp)
	{
		hp = max_hp;
	}
	else if (a < 0)
	{
		hp = 0;
	}
}
int BaseMonster::getHP() const
{
	return hp;
}
void BaseMonster::setMP(int a)
{
	if (a <= max_mp)
	{
		mp = a;
	}
}
int BaseMonster::getMP() const
{
	return mp;
}
int BaseMonster::getInstanceCount(void)
{
	return count;
}
