#include<iostream>
#include<string>
#include<math.h>
#include<sstream>
#include"noviceplayer.h"
#include"item.h"
#include"weaponitem.h"
#include"armoritem.h"
#include"consumableitem.h"

using namespace std;

ostream& operator<<(ostream& os, const NovicePlayer& player) {
	os << "name:    " << player.getname() << endl;
	os << "level:   " << player.getlevel() << endl;
	os << "attack:  " << player.getAttack() << endl;
	os << "defense: " << player.getDefense() << endl;
	os << "hp:      " << player.gethp() << " / " << player.getMaxHP() << endl;
	os << "mp:      " << player.getmp() << " / " << player.getMaxMP() << endl;
	os << "exp:     " << player.getexp() << " / " << player.getLvupExp() << endl;
	os << "money:   " << player.getmoney() << endl;
	os << "weapon:  " << player.getweapon() << endl;
	os << "armor:   " << player.getarmor() << endl;

	return os;
}

NovicePlayer::NovicePlayer() 
{
	setlevel(1);
	setname("anonymous");//?
	setmoney(100);
}
NovicePlayer::NovicePlayer(int a)
{
	setlevel(a);
	setname("anonymous");//?
	setmoney(100);
}
NovicePlayer::NovicePlayer(int a, string b)
{
	setlevel(a);
	setname(b);
	setmoney(100);
}
NovicePlayer::NovicePlayer(const NovicePlayer& c)
{
	setlevel(c.getlevel());
	setname(c.getname());
	setmoney(c.getmoney());
	sethp(c.gethp());
	setmp(c.getmp());
}

void NovicePlayer::setname(string a)
{
	if (size(a)>20||empty(a))
	{
		cout<<"wrong name";
	}
	else
	{
		name = a;
	}
}
string NovicePlayer :: getname()const
{
	return name;
}
void NovicePlayer::setlevel(int a)
{
	if (a >= 0)
	{
		level = a;
		attack = (20 + 5 * a);
		defense = (20 + 5 * a);
		max_hp = (100 + 10 * a);
		hp= (100 + 10 * a);
		max_mp = (40 + 5 * a);
		mp = (40 + 5 * a);
		lvup_exp = 10 * pow(2, a);
		exp = 10 * pow(2, a - 1);
		setbackpack(a);
	}
	else
	{
		cout << "wrong level value";
	}
}
int NovicePlayer::getlevel()const
{
	return level;
}
void NovicePlayer::sethp(int a)
{
	if (a <= max_hp&& a >= 0)
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
int NovicePlayer::gethp()const
{
	return hp;
}
void NovicePlayer::setmp(int a)
{
	if (a <= max_mp && a >= 0)
	{
		mp = a;
	}
	else if (a > max_mp)
	{
		hp = max_mp;
	}
	else if (a < 0)
	{
		mp = 0;
	}
}
int NovicePlayer::getmp()const
{
	return mp;
}
void NovicePlayer::setexp(int a)
{
	if ( a >= 0)
	{
		exp = a;
	}
	if (exp >= lvup_exp)
	{
		setlevel((getlevel() + 1));
	}
}
int NovicePlayer::getexp()const
{
	return exp;
}
void NovicePlayer::setmoney(int a)
{
	if (a >= 0)
	{
		money = a;
	}
	else
	{
		cout << "wrong mp value";
	}
}
int NovicePlayer::getmoney()const
{
	return money;
}
int NovicePlayer::getAttack(void) const
{
	return attack;
}
int NovicePlayer::getDefense(void) const
{
	return defense;
}
int NovicePlayer::getMaxHP(void) const
{
	return max_hp;
}
int NovicePlayer::getMaxMP(void) const
{
	return max_mp;
}
int NovicePlayer::getLvupExp(void) const
{
	return lvup_exp;
}
void NovicePlayer::specialSkill()
{
	cout << "not happen anything." << endl;
}
string NovicePlayer::serialize()
{
	string a = "$NovicePlayer$a";
	a = a + getname();
	a = a + "$b";
	stringstream s;
	s << getlevel();
	string temp;
	s >> temp;
	a = a + temp;
	a = a + "$c";
	s.str("");
	s.clear();
	s << getexp();
	s >> temp;
	a = a + temp;
	a = a + "$d";
	s.str("");
	s.clear();
	s << gethp();
	s >> temp;
	a = a + temp;
	a = a + "$e";
	s.str("");
	s.clear();
	s << getmp();
	s >> temp;
	a = a + temp;
	a = a + "$f";
	s.str("");
	s.clear();
	s << getmoney();
	s >> temp;
	a = a + temp;
	a = a + "$";
	s.str("");
	s.clear();
	return a;
}
NovicePlayer returnunserialize;
NovicePlayer* NovicePlayer::unserialize(string serial)
{
	stringstream s;
	int tem = 0;
	string temp;
	for (int i = 2; i < serial.size(); i++)
	{
		if (serial[i] == '$')
		{
			for (int j = (i+2); j < serial.size(); j++)
			{
				if (serial[j] == '$')
				{
					break;
				}
				temp = temp + serial[j];
			}
			switch (serial[i+1])
			{
			case 'a'://name
				returnunserialize.setname(temp);
				break;
			case 'b'://level
				s << temp;
				s >> tem;
				returnunserialize.setlevel(tem);
				s.str("");
				s.clear();
				break;
			case 'c'://exp
				s << temp;
				s >> tem;
				returnunserialize.setexp(tem);
				s.str("");
				s.clear();
				break;
			case 'd'://hp
				s << temp;
				s >> tem;
				returnunserialize.sethp(tem);
				s.str("");
				s.clear();
				break;
			case 'e'://mp
				s << temp;
				s >> tem;
				returnunserialize.setmp(tem);
				s.str("");
				s.clear();
				break;
			case 'f'://money
				s << temp;
				s >> tem;
				returnunserialize.setmoney(tem);
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

//items&backpck
string NovicePlayer::getweapon()const
{
	if (weapon == NULL)
	{
		return " ";
	}
	return weapon->name;
}
string NovicePlayer::getarmor()const
{
	if (armor == NULL)
	{
		return " ";
	}
	return armor->name;
}
int NovicePlayer::getbackpack_weight()
{
	backpack_weight = 0;
	for (int i = 0; i < getbackpack_slot_limit(); i++)
	{
		if (backpack[i] == NULL)
		{
			continue;
		}
		backpack_weight += backpack[i]->weight;
	}
	return backpack_weight;
}
int NovicePlayer::getbackpack_weight_limit()const
{
	return backpack_weight_limit;
}
int NovicePlayer::getbackpack_slot_limit()const
{
	return backpack_slot_limit;
}
int NovicePlayer::getoccupied_slot()//1
{
	int occupied_slot = 0;
	for (int i = 0; i < getbackpack_slot_limit(); i++)
	{
		if (backpack[i] != NULL) {
			occupied_slot++;
		}
	}
	return occupied_slot;
}
void NovicePlayer::setbackpack_weight_limit(int a)//1
{
	backpack_weight_limit = a;
}
void NovicePlayer::setbackpack_slot_limit(int a)//1
{
	backpack_slot_limit = a;
}
void NovicePlayer::setbackpack(int a)//a值為等級
{
	int b = getbackpack_slot_limit();//暫時除存原本的空間大小
	if (a <= 5)
	{
		if (a <= 5)//背包的相關重量以及存放物品空間//會在等級改變時跟著改變
		{
			setbackpack_slot_limit(10);
			setbackpack_weight_limit(30);
		}
		else
		{
			setbackpack_slot_limit(a*2);
			setbackpack_weight_limit(6 * a);
		}
	}
	Item**backpack2;
	backpack2 = new Item*[getbackpack_slot_limit()];
	for (int i = 0; i < backpack_slot_limit; i++) 
	{
		backpack2[i] = NULL; 
	}
	for (int i = 0; i < b; i++)
	{
		backpack2[i] = backpack[i];
	}
	backpack = backpack2;
}
bool NovicePlayer::putitem(Item* a)//
{
	if ((getbackpack_slot_limit() < getoccupied_slot() + 1)||((getbackpack_weight()+a->weight)>getbackpack_weight_limit()))
	{
		cout << "backpack is full" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < getbackpack_slot_limit(); i++)
		{
			if (backpack[i] == NULL)
			{
				backpack[i] = a;
				break;
			}
		}
		cout << "put " << a->name << " into backpack!" << endl;
		return 1;
	}
	return 0;
}
Item* NovicePlayer::takeitem(int index)
{
	if (backpack[index] == NULL)
	{
		cout << "noting to throw" << endl;
		return NULL;
	}
	else
	{
		Item* tmpitem;
		tmpitem = backpack[index];
		backpack[index] = NULL;
		return tmpitem;
	}
	return  NULL;
}
bool NovicePlayer::equipWeapon(WeaponItem* weapon2,int b)//b for index in backpack
{
	if (weapon == NULL)//判斷原本是否有穿裝備
	{
		if (weapon2->level_required > getlevel())
		{
			cout << "your level is not enough!" << endl;
			return 0;
		}
		weapon = weapon2;
		attack += weapon->attack_increment;
		backpack[b] = NULL;
		cout << "equip " << weapon->name << " !" << endl;
		return 1;
	}
	if (weapon != NULL)
	{
		if ((getbackpack_weight() - (weapon2->weight) + (weapon->weight)) > getbackpack_weight_limit())
		{
			cout << "the weight of baclpack is too large to change the weapon!" << endl;
			return 0;
		}
		else
		{
			if (weapon2->level_required > getlevel())
			{
				cout << "your level is not enough!" << endl;
				return 0;
			}
			backpack[b] = NULL;
			putitem(weapon);
			attack = attack - (weapon->attack_increment);
			weapon = weapon2;
			attack += weapon->attack_increment;
			cout << "equip " << weapon->name << " !" << endl;
			return 1;
		}
	}
	
}
bool NovicePlayer::equipArmor(ArmorItem* armor2,int b)//b for index in backpack
{
	if (armor == NULL)//判斷原本是否有穿裝備
	{
		if (armor2->level_required > getlevel())
		{
			cout << "your level is not enough!" << endl;
			return 0;
		}
		backpack[b] = NULL;
		armor = armor2;
		defense += armor->defense_increment;
		cout << "equip " << armor->name << " !" << endl;
		return 1;
	}
	if (armor != NULL)
	{
		if ((getbackpack_weight() - (armor2->weight) + (armor->weight)) > getbackpack_weight_limit())
		{
			cout << "the weight of baclpack is too large to change the armor!" << endl;
			return 0;
		}
		else
		{
			if (armor2->level_required > getlevel())
			{
				cout << "your level is not enough!" << endl;
				return 0;
			}
			backpack[b] = NULL;
			putitem(armor);
			defense = defense - (armor->defense_increment);
			armor = armor2;
			defense += armor->defense_increment;
			cout << "equip " << armor->name << " !" << endl;
			return 1;
		}
	}

}
void NovicePlayer::useConsumable(ConsumableItem* a, int b)//b for the index in backpack
{
	a->use(this);
	backpack[b] = NULL;
	cout << "use " << a->name << " !" << endl;
}
void NovicePlayer::viewbackpack()
{
	cout << "backpack weight: " << getbackpack_weight() << "/" << getbackpack_weight_limit()<<endl;
	cout << "backpack slot: " << getoccupied_slot() << "/" << getbackpack_slot_limit() << endl;
	if (getoccupied_slot() == 0)
	{
		cout << "your backpack is empty!" << endl;
	}
	for (int i = 0; i < getbackpack_slot_limit(); i++)
	{
		if (backpack[i] == NULL)
		{
			continue;
		}
		if (backpack[i] != NULL)
		{
			cout << "(" << i << "):" << backpack[i]->name << endl;
		}
	}
}
Item* NovicePlayer::getitem(int a)
{
	return backpack[a];
}
string NovicePlayer::returntype()
{
	return "n";
}

