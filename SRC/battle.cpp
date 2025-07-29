#include<iostream>
#include<string>
#include<sstream>
#include<typeinfo>
#include<stdlib.h>
#include<time.h>
#include"noviceplayer.h"
#include"basemonster.h"
#include"jwmonster.h"
#include"goblinmonster.h"
#include"zombiemonster.h"
#include"battle.h"
#include"battlemenu.h"

using namespace std;

Battle :: Battle(int nplayer, int nmonster)//最多三打三
{
	nofplayer = nplayer;
	nofmonster = nmonster;
	if(nplayer <= 3 && nmonster <= 3)
	{
		int total;
		total = nplayer + nmonster;
		actionlist = new Character[(total+1)];
	}
	else
	{
		cout << "error:wrong number of Battle!" << endl;
	}
}
Battle :: ~Battle()
{
}
void Battle::setplayer(NovicePlayer *player,int numberplayer)
{
	actionlist[numberplayer].type = 'p';
	if (player->gethp() > 0)
	{
		actionlist[numberplayer].alive = 1;
	}
	else
	{
		actionlist[numberplayer].alive = 0;
	}
	actionlist[numberplayer].instance = player;
}
void Battle::setmonster(BaseMonster *monster , int numbermonster)
{
	actionlist[(nofplayer + numbermonster)].type = 'm';
	if (monster->getHP() > 0)
	{
		actionlist[(nofplayer + numbermonster)].alive = 1;
	}
	else
	{
		actionlist[(nofplayer + numbermonster)].alive = 0;
	}
	actionlist[(nofplayer+ numbermonster)].instance = monster;
}
GoblinMonster Battle::producegoblinmonster()
{
	GoblinMonster goblin;
	return goblin;
}
ZombieMonster Battle::producezombiemonster()
{
	ZombieMonster zombie;
	return zombie;
}
JWMonster Battle::producejwmonster()
{
	JWMonster jw;
	return jw;
}
bool Battle::battle()
{
	system("cls");
	int countlevel=0;
	for (int i = 1; i <= nofplayer; i++)
	{
		if (actionlist[i].instance == NULL)
		{
			tmp_player = static_cast<NovicePlayer*>(actionlist[i].instance);
			countlevel += tmp_player->getlevel();
		}
	}
	//根據等級來產生相對應的怪物
	if (countlevel < 5)
	{
		for (int i = 0; i < nofmonster; i++)
		{
			if (i == 0)
			{
				setmonster(&goblin1, 1);
			}
			if (i == 1)
			{
				setmonster(&goblin2, 2);
			}
			if (i == 2)
			{
				setmonster(&goblin3, 3);
			}
		}
	}
	if (countlevel < 10&& countlevel >= 5)
	{
		for (int i = 0; i < nofmonster; i++)
		{
			if (i == 0)
			{
				srand(time(NULL));
				int a = 0;
				a = (rand() % 2);
				if (a == 0)
				{
					setmonster(&goblin1, 1);
				}
				if (a == 1)
				{
					setmonster(&zombie1, 1);
				}
			}
			if (i == 1)
			{
				srand(time(NULL));
				int a = 0;
				a = (rand() % 2);
				if (a == 0)
				{
					setmonster(&goblin2, 2);
				}
				if (a == 1)
				{
					setmonster(&zombie2, 2);
				}
			}
			if (i == 2)
			{
				srand(time(NULL));
				int a = 0;
				a = (rand() % 2);
				if (a == 0)
				{
					setmonster(&goblin3, 3);
				}
				if (a == 1)
				{
					setmonster(&zombie3, 3);
				}
			}
		}
	}
	if (countlevel > 10)
	{
		for (int i = 0; i < nofmonster; i++)
		{
			if (i == 0)
			{
				srand(time(NULL));
				int a;
				a = (rand() % 6);
				if (a >= 0 && a <= 2)
				{
					setmonster(&goblin1, 1);
				}
				if (a == 3 || a == 4)
				{
					setmonster(&zombie1, 1);
				}
				if (a == 5)
				{
					setmonster(&jw1, 1);
				}
			}
			if (i == 1)
			{
				srand(time(NULL));
				int a;
				a = (rand() % 6);
				if (a >= 0 && a <= 2)
				{
					setmonster(&goblin2, 2);
				}
				if (a == 3 || a == 4)
				{
					setmonster(&zombie2, 2);
				}
				if (a == 5)
				{
					setmonster(&jw2, 2);
				}
			}
			if (i == 2)
			{
				srand(time(NULL));
				int a;
				a = (rand() % 6);
				if (a >= 0 && a <= 2)
				{
					setmonster(&goblin3, 3);
				}
				if (a == 3 || a == 4)
				{
					setmonster(&zombie3, 3);
				}
				if (a == 5)
				{
					setmonster(&jw3, 3);
				}
			}
		}
	}
	
	int aliveplayer=nofplayer;//遇到玩家生命值=0時剪一
	int alivemonster = nofmonster;//遇到怪物生命值=0時剪一
	BattleMenu battlemenu;
	string a;
	stringstream s;
	int c;
	for (nturn; nturn < 200; nturn++)//只要有玩家或怪物死亡就檢查一次是否結束戰鬥
	{
		cout << "turn " << nturn << ": " << endl;
		for (int i = 1; i <= (nofplayer + nofmonster); i++)
		{
			if (actionlist[i].alive == 1)
			{
				if (actionlist[i].type == 'p')
				{ 
					tmp_player = static_cast<NovicePlayer*>(actionlist[i].instance);
					cout << *tmp_player << endl;
					cout << "waht do you want " << tmp_player->getname() << " do?" << endl;
					battlemenu.display();
					a = battlemenu.getinput();
					switch (a[0])
					{
					case'a':
						for (int j = 1; j <= nofmonster; j++)
						{
							if (actionlist[(j + nofplayer)].alive == 1)
							{
								tmp_monster = static_cast<BaseMonster*>(actionlist[(j + nofplayer)].instance);
								cout << tmp_player->getname() << " attack " << tmp_monster->name << endl;
								if ((tmp_player->getAttack() - tmp_monster->defense) > 0)//攻擊力大過防禦力才可攻擊
								{
									tmp_monster->setHP(tmp_monster->getHP() - (tmp_player->getAttack() - tmp_monster->defense));
								}
								else
								{
									cout << "invalid attack!" << endl;
								}
								if (tmp_monster->getHP() == 0)
								{
									cout << tmp_monster->name << "died" << endl;
									alivemonster--;
									tmp_player->setexp(tmp_player->getexp() + tmp_monster->exp);
									tmp_player->setmoney(tmp_player->getmoney() + tmp_monster->money);
									tmp_player->putitem(tmp_monster->fallingitems());
								}
								break;
							}
						}
						break;
					case'b':
						cout << tmp_player->getname() << "use special skill!" << endl;
						tmp_player->specialSkill();
						break;
					case'c':
						tmp_player->viewbackpack();
						cout << "which item do you want to use?" << endl;
						cin.clear();
						cin >> a;
						cin.clear();
						while (1)//防呆
						{
							if (a.size() > 2 || a.size() == 0)//?
							{
								cout << "wrong operation" << endl;
								cin >> a;
								cin.clear();
								continue;
							}
							if (a.size() == 1)
							{
								if (a[0] >= 48 && a[0] <= 57)
								{
									s << a;
									s >> c;
									s.clear();
									if (c >= tmp_player->getbackpack_slot_limit())
									{
										cout << "wrong operation" << endl;
										cin >> a;
										cin.clear();
										continue;
									}
									break;
								}
								else
								{
									cout << "wrong operation" << endl;
									cin >> a;
									cin.clear();
									continue;
								}
							}
							if (a.size() == 2)
							{
								if (a[0] >= 48 && a[0] <= 57 && a[1] >= 48 && a[1] <= 57)
								{
									s << a;
									s >> c;
									s.clear();
									if (c >= tmp_player->getbackpack_slot_limit())
									{
										cout << "wrong operation" << endl;
										cin >> a;
										cin.clear();
										continue;
									}
									break;
								}
								else
								{
									cout << "wrong operation" << endl;
									cin >> a;
									cin.clear();
									continue;
								}
							}
						}
						if (tmp_player->getitem(c) == NULL)
						{
							cout << "noting to use" << endl;
							break;
						}
						switch (tmp_player->getitem(c)->type)
						{
						case'w':
							WeaponItem* myweapon;
							myweapon = dynamic_cast<WeaponItem*>(tmp_player->takeitem(c));
							tmp_player->equipWeapon(myweapon, c);
							cout << &tmp_player << endl;
							break;
						case'a':
							ArmorItem* myarmor;
							myarmor = dynamic_cast<ArmorItem*>(tmp_player->takeitem(c));
							tmp_player->equipArmor(myarmor, c);
							cout << &tmp_player << endl;
							break;
						case'c':
							ConsumableItem* myprops;
							myprops = dynamic_cast<ConsumableItem*>(tmp_player->takeitem(c));
							tmp_player->useConsumable(myprops, c);
							cout << &tmp_player << endl;
							break;
						default:
							break;
						};
						break;
					case'd':
						cout << "you run away" << endl;
						return 1;
						break;
					default:
						break;
					};
					system("cls");
				}
				else if (actionlist[i].type == 'm')
				{
					tmp_monster = static_cast<BaseMonster*>(actionlist[i].instance);
					for (int j = 1; j <= nofplayer; j++)
					{
						if (actionlist[j].alive == 1)
						{
							tmp_player = static_cast<NovicePlayer*>(actionlist[j].instance);
							cout << tmp_monster->name << " attack " << tmp_player->getname() << endl;
							if ((tmp_monster->attack - tmp_player->getDefense()) > 0)//攻擊力大過防禦力才可攻擊
							{
								tmp_player->sethp(tmp_player->gethp() - (tmp_monster->attack - tmp_player->getDefense()));
							}
							else
							{
								cout << "invalid" << endl;
							}
							if (tmp_player->gethp() == 0)
							{
								cout << tmp_player->getname()<< "died" << endl;
								aliveplayer--;
							}
						}
					}
				}
			}
			if (aliveplayer == 0 || alivemonster == 0)
			{
				break;
			}
		}
		if (aliveplayer == 0 || alivemonster == 0)
		{
			break;
		}
	}
	if (aliveplayer == 0)
	{
		cout << "monster win" << endl;
		cout << "turn:" <<nturn<< endl;
		return 0;
	}
	if (alivemonster == 0)
	{
		cout << "player win" << endl;
		cout << "turn:" << nturn << endl;
		return 1;
	}
	return 0;
}

















