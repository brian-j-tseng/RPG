#include<iostream>
#include<sstream>
#include"knightplayer.h"

using namespace std;

KnightPlayer :: KnightPlayer()
{
	setlevel(1);
	setname("anonymous");
}
KnightPlayer::KnightPlayer(int a)
{
	setlevel(a);
	setname("anonymous");//?
}
KnightPlayer::KnightPlayer(int a, string b)
{
	setlevel(a);
	setname(b);
}
KnightPlayer::KnightPlayer(const KnightPlayer& c)
{
	setlevel(c.getlevel());
	setname(c.getname());
}

void KnightPlayer::setlevel(int a)
{
	if (a >= 0)
	{
		level = a;
		attack = 40 + 10* a;
		defense = 20 + 12 * a;
		max_hp = 150 + 25 * a;
		max_mp = 70 + 10 * a;
		lvup_exp = 10 * pow(2, a);
	}
	else
	{
		cout << "wrong level value";
	}
}
void KnightPlayer::specialSkill()
{
	sethp((gethp() + 10*getlevel()));
	setmp((getmp() - 5*getlevel()));
	cout << "hp + " << 10 * getlevel() << " point" << endl;
	cout << "mp - " << 5 * getlevel() << " point" << endl;
}
string KnightPlayer::serialize()
{
	string a = "$KnightPlayer$";
	a = a + getname();
	a = a + "$";
	stringstream s;
	s << getlevel();
	string temp;
	s >> temp;
	a = a + temp;
	a = a + "$";
	s.str("");
	s.clear();
	s << getexp();
	s >> temp;
	a = a + temp;
	a = a + "$";
	s.str("");
	s.clear();
	s << gethp();
	s >> temp;
	a = a + temp;
	a = a + "$";
	s.str("");
	s.clear();
	s << getmp();
	s >> temp;
	a = a + temp;
	a = a + "$";
	s.str("");
	s.clear();
	s << getmoney();
	s >> temp;
	a = a + temp;
	a = a + "$";
	s.str("");
	s.clear();
	s << getAttack();
	s >> temp;
	a = a + temp;
	a = a + "$";
	s.str("");
	s.clear();
	s << getDefense();
	s >> temp;
	a = a + temp;
	a = a + "$";
	s.str("");
	s.clear();
	s << getMaxHP();
	s >> temp;
	a = a + temp;
	a = a + "$";
	s.str("");
	s.clear();
	s << getMaxMP();
	s >> temp;
	a = a + temp;
	a = a + "$";
	s.str("");
	s.clear();
	s << getLvupExp();
	s >> temp;
	a = a + temp;
	return a;
}
KnightPlayer returnunserialize;
KnightPlayer* KnightPlayer::unserialize(string serial)
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
string KnightPlayer::returntype()
{
	return "k";
}