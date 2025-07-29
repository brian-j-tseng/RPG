#include<iostream>
#include<string>
#include<sstream>
#include<time.h>
#include"goblinmonster.h"
#include"ArmorItem.h"
#include"copperarmor.h"
#include"diamonarmor.h"
#include"magicrobeair.h"
#include"magicrobepro.h"
#include"woodenarmor.h"
#include"beefsoup.h"
#include"candy.h"
#include"changenamescroll.h"
#include"consumableItem.h"
#include"spinach.h"
#include"strangesoup.h"
#include"treasurechest.h"
#include"ironsword.h"
#include"magicbookair.h"
#include"magicbookpro.h"
#include"sliversword.h"
#include"weaponItem.h"
#include"goldensword.h"

using namespace std;

GoblinMonster::GoblinMonster()
	:BaseMonster("Goblin", 10, 0, 12, 30, 100, 50)
{
}
GoblinMonster::~GoblinMonster()
{
	BaseMonster:: ~BaseMonster();
}
Item* GoblinMonster::fallingitems()
{
	srand(time(NULL));
	int a = rand() % 3;
	int b = rand() % 50;
	//weaponitem
	if (a == 0)
	{
		if (b >= 0 && b < 20)
		{
			falling=new IronSword;
			return falling;
		}
		if (b >= 20 && b < 30)
		{
			falling = new SliverSword;
			return falling;
		}
		if (b >= 30 && b < 32)
		{
			falling = new GoldenSword;
			return falling;
		}
		if (b >= 32 && b < 48)
		{
			falling = new MagicBookAir;
			return falling;
		}
		if (b >= 48 && b < 49)
		{
			falling = new MagicBookPro;
			return falling;
		}
	}
	//armoritem
	if (a == 1)
	{
		if (b >= 0 && b < 20)
		{
			falling = new WoodenArmor;
			return falling;
		}
		if (b >= 20 && b < 30)
		{
			falling = new CopperArmor;
			return falling;
		}
		if (b >= 30 && b < 32)
		{
			falling = new DiamondArmor;
			return falling;
		}
		if (b >= 32 && b < 48)
		{
			falling = new MagicRobeAir;
			return falling;
		}
		if (b >= 48 && b < 49)
		{
			falling = new MagicRobePro;
			return falling;
		}
	}
	//comsumableitem
	if (a == 2)
	{
		if (b >= 0 && b < 20)
		{
			falling = new BeefSoup;
			return falling;
		}
		if (b >= 20 && b < 35)
		{
			falling = new Spinach;
			return falling;
		}
		if (b >= 35 && b < 39)
		{
			falling = new Treasurechest;
			return falling;
		}
		if (b >= 39 && b < 40)//1/50
		{
			falling = new ChangenameScroll;
			return falling;
		}
		if (b >= 40 && b < 45)
		{
			falling = new StrangeSoup;
			return falling;
		}
		if (b >= 45 && b < 49)
		{
			falling = new Candy;
			return falling;
		}
	}
}
string GoblinMonster::serialize()
{
	string a = "$GoblinMonster$a";
	stringstream s;
	s << exp;
	string temp;
	s >> temp;
	a = a + temp;
	a = a + "$b";
	s.str("");
	s.clear();
	s << attack;
	s >> temp;
	a = a + temp;
	a = a + "$c";
	s.str("");
	s.clear();
	s << defense;
	s >> temp;
	a = a + temp;
	a = a + "$d";
	s.str("");
	s.clear();
	s << money;
	s >> temp;
	a = a + temp;
	a = a + "$e";
	s.str("");
	s.clear();
	s << getHP();
	s >> temp;
	a = a + temp;
	a = a + "$f";
	s.str("");
	s.clear();
	s << getMP();
	s >> temp;
	a = a + temp;
	a = a + "$";
	return a;
}
GoblinMonster returnunserialize;
GoblinMonster* GoblinMonster::unserialize(string serial)
{
	stringstream s;
	int tem = 0;
	string temp;
	for (int i = 2; i < serial.size(); i++)
	{
		if (serial[i] == '$')
		{
			for (int j = (i + 2); j < serial.size(); j++)
			{
				if (serial[j] == '$')
				{
					break;
				}
				temp = temp + serial[j];
			}
			switch (serial[i + 1])
			{
			case 'a'://exp
				break;
			case 'b'://
				break;
			case 'c'://
				break;
			case 'd'://
				break;
			case 'e'://mp
				s << temp;
				s >> tem;
				returnunserialize.setHP(tem);
				s.str("");
				s.clear();
				break;
			case 'f'://money
				s << temp;
				s >> tem;
				returnunserialize.setMP(tem);
				s.str("");
				s.clear();
				break;
			default:
				break;
			};
			temp.clear();
		}

	}
	return (&returnunserialize);
}
