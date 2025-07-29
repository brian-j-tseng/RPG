#pragma once

#ifndef ITEM_H
#define ITEM_H
#include<iostream>
using namespace std;

class Item 
{
	friend ostream& operator<<(ostream& os, const Item &item) {
		os << "name:           " << item.name << endl;
		os << "level required: " << item.level_required << endl;
		os << "weight:         " << item.weight << endl;
		os << "effects:        " << item.effects << endl;
		os << "description:    " << item.description << endl;
		return os;
	}
public:
		int level_required; // level limit of equip/use this item
		string name; // the name of this item E.g., ¡§JW¡¦s Hand¡¨
		string effects; // a short description of its effect E.g., ¡§Attack + 100, 20 % of probability making opponents cannot act at the next turn¡¨
		string description; // a short description of this item E.g., ¡§A silver - made hand - shaped weapon.There¡¦s a folklore said that once upon a time, a blacksmith encountered and was beaten by the JWMaster.While fighting with JWM, he found that the shape of JWM¡¦s hand is so beautiful.So he made a weapon that mimics the shape of JWM¡¦s hand for increasing his ability in self - defense.¡¨
		int weight; // the weight of the item
		char type;//Type of this item, ¡§w¡¨ for weapons, ¡§a¡¨ for armors, ¡§c¡¨ for consumables

		virtual bool use()=0;
	private:
	
};
#endif


