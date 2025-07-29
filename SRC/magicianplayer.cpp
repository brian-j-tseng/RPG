#include<iostream>
#include<sstream>
#include"magicianplayer.h"

using namespace std;

MagicianPlayer::MagicianPlayer()
{
	setlevel(1);
	setname("anonymous");
}
MagicianPlayer::MagicianPlayer(int a)
{
	setlevel(a);
	setname("anonymous");//?
}
MagicianPlayer::MagicianPlayer(int a, string b)
{
	setlevel(a);
	setname(b);
}
MagicianPlayer::MagicianPlayer(const MagicianPlayer& c)
{
	setlevel(c.getlevel());
	setname(c.getname());
}

void MagicianPlayer::setlevel(int a)
{
	if (a >= 0)
	{
		level = a;
		attack = 30 + 8 * a;
		defense = 20 + 7 * a;
		max_hp = 120 + 15 * a;
		max_mp = 100 + 15 * a;
		lvup_exp = 10 * pow(2, a);
	}
	else
	{
		cout << "wrong level value";
	}
}
void MagicianPlayer::specialSkill()
{
	sethp((getmp() + 10 * getlevel()));
	setmp((gethp() - 5 * getlevel()));
	cout << "mp + "<< 10 * getlevel() <<" point"<< endl;
	cout << "hp - " << 5 * getlevel() << " point" << endl;
}
string MagicianPlayer::serialize()
{
	string a = "MagicianPlayer$";
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
MagicianPlayer returnunserialize;
MagicianPlayer* MagicianPlayer::unserialize(string serial)
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
string MagicianPlayer::returntype()
{
	return "m";
}