#pragma once

#ifndef NOVICEPLAYER_H
#define NOVICEPLAYER_H

#include<string>
#include"item.h"
#include"weaponitem.h"
#include"Armoritem.h"
#include"consumableitem.h"
using namespace std;

class NovicePlayer
{
	friend ostream& operator<<(ostream&, const NovicePlayer&);
public:
	NovicePlayer();
	NovicePlayer(int);
	NovicePlayer(int,string);
	NovicePlayer(const NovicePlayer&);
	//player data
	void setname(string);
	string getname()const;
	virtual void setlevel(int);
	int getlevel()const;
	void sethp(int);
	int gethp()const;
	void setmp(int);
	int getmp()const;
	void setexp(int);
	int getexp()const;
	void setmoney(int);
	int getmoney()const;
	int getAttack(void) const;
	int getDefense(void) const;
	int getMaxHP(void) const;
	int getMaxMP(void) const;
	int getLvupExp(void) const;
	//items and backpack
	string getweapon()const;
	string getarmor()const;
	void setbackpack(int);
	int getbackpack_weight(); //每次使用都重新計算一次背包重量
	int getbackpack_weight_limit()const; 
	int getbackpack_slot_limit()const;
	int getoccupied_slot();
	void setbackpack_weight_limit(int);
	void setbackpack_slot_limit(int);
	bool putitem(Item*);
	Item* takeitem(int);
	void useConsumable(ConsumableItem*,int);
	bool equipWeapon(WeaponItem*, int);
	bool equipArmor(ArmorItem*, int);
	void viewbackpack();
	Item*  getitem(int);// 所選item的pointer

	virtual void specialSkill();
	virtual	string serialize();
    virtual NovicePlayer* unserialize(string);
	virtual string returntype();
private:
	Item** backpack; // the “inventory” in many other games
	WeaponItem* weapon=NULL; // weapon item
	ArmorItem* armor = NULL; // armor item
	int backpack_weight; // current weight of player’s backpack
	int backpack_weight_limit; // limit on weight of backpack
	int backpack_slot_limit; // limit on number of backpack’s slots

	string name;
	int hp;
	int mp;
	int exp;
protected:
	int money;
	int level;
	int attack;
	int defense;
	int max_hp;
	int max_mp;
	int lvup_exp;
};


#endif

