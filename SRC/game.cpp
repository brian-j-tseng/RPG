#include"game.h"
#include"field.h"
#include"battle.h"
#include"knightplayer.h"
#include"magicianplayer.h"
#include"noviceplayer.h"
#include"orcplayer.h"
#include"copperarmor.h"
#include"diamonarmor.h"
#include"magicrobeair.h"
#include"magicrobepro.h"
#include"woodenarmor.h"
#include"beefsoup.h"
#include"candy.h"
#include"changenamescroll.h"
#include"spinach.h"
#include"strangesoup.h"
#include"treasurechest.h"
#include"ironsword.h"
#include"magicbookair.h"
#include"magicbookpro.h"
#include"sliversword.h"
#include"goldensword.h"
#include<string>
#include<sstream>
#include<time.h>
#include<fstream>

using namespace std;

void Game::run()
{
	while (exit == 0)
	{
		system("cls");
		mainmenu.display();
		string a;
		a=mainmenu.getinput();
		switch (a[0])
		{
		case'1':
			setnewgame();
			gamestart();
			break;
		case'2':
			loadrecord();
			gamestart();
			break;
		case'3':
			if (save() == 1)
			{
				cout << "save success!"<<endl;
			}
			exit = 1;
			break;
		case'4':
			if (save() == 1)
			{
				cout << "save success!" << endl;
			}
		case'5':
			gamestart();
			break;
		default:
			break;
		}
		if (mapnumber = 3 && map->getMapSymbol(map->getCurrentPositionX(), map->getCurrentPositionY()) == 203)
		{
			break;
		}
	}
}
void Game::setnewgame()
{
	string player1_name;
	cout << "What is your name:" << endl;
	cin.clear();
	cin >> player1_name;
	cin.clear();
	while (player1_name.size() > 15)
	{
		cout << "too long" << endl;
		cin>> player1_name;
		cin.clear();
	}
	player_list = new NovicePlayer*[3];
	player_list[0] = new NovicePlayer(1, player1_name);
	player_list[1] = NULL;
	player_list[2] = NULL;
	map = new Field("map1.txt",1,1,5,5);
	mapnumber = 1;
	playernumber = 1;
}
void Game::loadrecord()
{
	ifstream loadgame("gamerecord.txt", ios::in);
	string line;
	string tmp1,tmp2;
	stringstream s;
	int a,b;
	int x, y;
	string mapname;
	do
	{
		getline(loadgame, line);
		if (line[0] == '$')
		{
			int itemcount = 0;
			do
			{
				getline(loadgame, line);
				for (int i = 1; i < line.size(); i++)
				{
					if (line[i] == ':')
					{
						a = 1;
						break;
					}
					tmp1 += line[i];
				}
				for (int i = a; i < line.size(); i++)
				{
					tmp2 += line[i];
				}
				if (tmp1 == "type")
				{
					if (tmp2 == "k")
					{
						player_list[playernumber] = new KnightPlayer;
						playernumber++;
					}
					if (tmp2 == "m")
					{
						player_list[playernumber] = new MagicianPlayer;
						playernumber++;
					}
					if (tmp2 == "n")
					{
						player_list[playernumber] = new NovicePlayer;
						playernumber++;
					}
					if (tmp2 == "o")
					{
						player_list[playernumber] = new OrcPlayer;
						playernumber++;
					}
					if (tmp2 == "map")
					{
						map = new Field("map1.txt", 1, 1, 5, 5);
					}
				}
				if (tmp1 == "name")
				{
					player_list[playernumber]->setname(tmp2);
				}
				if (tmp1 == "level")
				{
					s << tmp2;
					s >> b;
					player_list[playernumber]->setlevel(b);
				}
				if (tmp1 == "hp")
				{
					s << tmp2;
					s >> b;
					player_list[playernumber]->sethp(b);
				}
				if (tmp1 == "mp")
				{
					s << tmp2;
					s >> b;
					player_list[playernumber]->setmp(b);
				}
				if (tmp1 == "exp")
				{
					s << tmp2;
					s >> b;
					player_list[playernumber]->setexp(b);
				}
				if (tmp1 == "money")
				{
					s << tmp2;
					s >> b;
					player_list[playernumber]->setmoney(b);
				}
				if (tmp1 == "weapon")
				{
					if (tmp2 == "goldensword")
					{
						player_list[playernumber]->equipWeapon(new GoldenSword,0);
					}
					if (tmp2 == "sliversword")
					{
						player_list[playernumber]->equipWeapon(new SliverSword,0);
					}
					if (tmp2 == "ironsword")
					{
						player_list[playernumber]->equipWeapon(new IronSword,0);
					}
					if (tmp2 == "magicbookair")
					{
						player_list[playernumber]->equipWeapon(new MagicBookAir,0);
					}
					if (tmp2 == "magicbookpro")
					{
						player_list[playernumber]->equipWeapon(new MagicBookPro,0);
					}
				}
				if (tmp1 == "armor")
				{
					if (tmp2 == "copperarmor")
					{
						player_list[playernumber]->equipArmor(new CopperArmor, 0);
					}
					if (tmp2 == "diamondarmor")
					{
						player_list[playernumber]->equipArmor(new DiamondArmor, 0);
					}
					if (tmp2 == "woodenarmor")
					{
						player_list[playernumber]->equipArmor(new WoodenArmor, 0);
					}
					if (tmp2 == "magicrobeair")
					{
						player_list[playernumber]->equipArmor(new MagicRobeAir, 0);
					}
					if (tmp2 == "magicrobepro")
					{
						player_list[playernumber]->equipArmor(new MagicRobePro, 0);
					}
				}
				if (tmp1 == "itemname")
				{
					if (tmp2 == "goldensword")
					{
						player_list[playernumber]->putitem(new GoldenSword);
					}
					if (tmp2 == "sliversword")
					{
						player_list[playernumber]->putitem(new SliverSword);
					}
					if (tmp2 == "ironsword")
					{
						player_list[playernumber]->putitem(new IronSword);
					}
					if (tmp2 == "magicbookair")
					{
						player_list[playernumber]->putitem(new MagicBookAir);
					}
					if (tmp2 == "magicbookpro")
					{
						player_list[playernumber]->putitem(new MagicBookPro);
					}
					if (tmp2 == "copperarmor")
					{
						player_list[playernumber]->putitem(new CopperArmor);
					}
					if (tmp2 == "diamondarmor")
					{
						player_list[playernumber]->putitem(new DiamondArmor);
					}
					if (tmp2 == "woodenarmor")
					{
						player_list[playernumber]->putitem(new WoodenArmor);
					}
					if (tmp2 == "magicrobeair")
					{
						player_list[playernumber]->putitem(new MagicRobeAir);
					}
					if (tmp2 == "magicrobepro")
					{
						player_list[playernumber]->putitem(new MagicRobePro);
					}
					if (tmp2 == "beefsoup")
					{
						player_list[playernumber]->putitem(new BeefSoup);
					}
					if (tmp2 == "candy")
					{
						player_list[playernumber]->putitem(new Candy);
					}
					if (tmp2 == "changenamescroll")
					{
						player_list[playernumber]->putitem(new ChangenameScroll);
					}
					if (tmp2 == "spinach")
					{
						player_list[playernumber]->putitem(new Spinach);
					}
					if (tmp2 == "strangesoup")
					{
						player_list[playernumber]->putitem(new StrangeSoup);
					}
					if (tmp2 == "treasurechest")
					{
						player_list[playernumber]->putitem(new Treasurechest);
					}
				}
				if (tmp1 == "mapname")
				{
				}
				if (tmp1 == "position_x")
				{
					s << tmp2;
					s >> x;
				}
				if (tmp1 == "position_y")
				{
					s << tmp2;
					s >> y;
				}
			} while (line[0]=='?');
		}
		map = new Field("map1.txt", 1,1, 5, 5);
	} while (line[0]!='?');
	cout << "load over!" << endl;
}
bool Game::save()
{
	ofstream savegame("gamerecord.txt", ios::out);
	//存玩家資訊
	for (int i = 0; i < playernumber; i++)
	{
		savegame << "$"<< "\n";
		savegame << "type:"<< player_list[i]->returntype()<<"\n";
		savegame << "name:" << player_list[i]->getname() << "\n";
		savegame << "level:" << player_list[i]->getlevel() << "\n";
		savegame << "hp:" << player_list[i]->gethp() << "\n";
		savegame << "mp:" << player_list[i]->getmp() << "\n";
		savegame << "exp:" << player_list[i]->getexp() << "\n";
		savegame << "money:" << player_list[i]->getmoney() << "\n";
		savegame << "weapon:" << player_list[i]->getweapon() << "\n";
		savegame << "armor:" << player_list[i]->getarmor() << "\n";
		for (int j = 0; j < player_list[i]->getbackpack_slot_limit(); j++)
		{
			if (player_list[i]->getitem(j) != NULL)
			{
				savegame << "itemname:" << player_list[i]->getitem(j)->name << "\n";
			}
		}
		savegame << "!" << "\n";
	}
	//存地圖資訊寫load時記得要加上大小
	savegame << "$" << "type:" << "map" << "\n";
	savegame << "mapname:" << map->getMapName() << "\n";
	savegame << "position_x:" << map->getCurrentPositionX() << "\n";
	savegame << "position_y:" << map->getCurrentPositionY() << "\n";
	savegame << "mapvalue:" << "\n";
	for (int i = 0; i < 12; i++)
	{
		for (int j= 0; j < 12; j++)
		{
			savegame << map->getMapSymbol(i, j) << ",";
		}
		savegame << "\n";
	}
	savegame << "!\n";
	savegame << "?";
	return 1;
}
void Game::gamestart()
{
	bool exitgamestart = 0;
	while (!exitgamestart)//未完成
	{
		system("cls");
		map->display();
		fieldmenu.display();
		string a = "0";
		a = fieldmenu.getinput()[0];
		int b = 0, c = 0;
		stringstream s;
		switch (a[0])
		{
		case'w':
		case's':
		case'a':
		case'd':
			map->move(a[0]);
			break;
		case'q':
			cout << "Which player do you want to choose" << endl;
			for (int i = 0; i < 3; i++)
			{
				if (player_list[i] != NULL)
				{
					cout << "(" << i << ")" ;
					cout << player_list[i]->getname()<<endl;
				}
			}
			cin >> a;
			cin.clear();
			while (a.size() > 1||(a!="0"&&a!="1"&&a!="2"))
			{
				cout << "wrong operation!" << endl;
				cin >> a;
				cin.clear();
			}
			s << a;
			s >> b;
			s.clear();
			if (player_list[b] == NULL)
			{
				break;
			}
			player_list[b]->viewbackpack();
			cout << endl;
			cout << "what do you want to do ?"<<endl;
			cout << "(a)throw out item" << endl;
			cout << "(b)use item" << endl;
			cin >> a;
			cin.clear();
			while (a.size() > 1 || (a != "a"&&a != "b"))
			{
				cout << "wrong operation!" << endl;
				cin >> a;
				cin.clear();
			}
			switch (a[0])
			{
			case 'a'://throw out item
				cout << "which item do you want to throw out?" << endl;
				player_list[b]->viewbackpack();
				cout << "(n) back" << endl;
				cin >> a;
				cin.clear();
				while (1)//防呆
				{
					if (a[0] == 'n')
					{
						break;
					}
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
							if (c >= player_list[b]->getbackpack_slot_limit())
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
							if (c >= player_list[b]->getbackpack_slot_limit())
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
				if (a[0] == 'n')
				{
					break;
				}
				if (player_list[b]->getitem(c) == NULL)
				{
					cout << "nothing to throw" << endl;
					break;
				}
				cout << player_list[b]->getname() << "throw out " << player_list[b]->takeitem(c)->name << endl;
				break;

			case 'b'://use
				cout << "which item do you want to use?" << endl;
				cin.clear();
				cin >> a;
				cin.clear();
				while (1)//防呆
				{
					if (a[0] == 'n')
					{
						break;
					}
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
							if (c >= player_list[b]->getbackpack_slot_limit())
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
							if (c >= player_list[b]->getbackpack_slot_limit())
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
				if (a[0] == 'n')
				{
					break;;
				}
				if (player_list[b]->getitem(c) == NULL)
				{
					cout << "noting to use" << endl;
					break;
				}
				switch (player_list[b]->getitem(c)->type)
				{
				case'w':
					WeaponItem* myweapon;
					myweapon = dynamic_cast<WeaponItem*>(player_list[b]->takeitem(c));
					player_list[b]->equipWeapon(myweapon, c);
					cout << &player_list[b] << endl;
					break;
				case'a':
					ArmorItem* myarmor;
					myarmor = dynamic_cast<ArmorItem*>(player_list[b]->takeitem(c));
					player_list[b]->equipArmor(myarmor, c);
					cout << &player_list[b] << endl;
					break;
				case'c':
					ConsumableItem* myprops;
					myprops = dynamic_cast<ConsumableItem*>(player_list[b]->takeitem(c));
					player_list[b]->useConsumable(myprops, c);
					cout << &player_list[b] << endl;
					break;
				default:
					break;
				};
				break;
			default:
				cout << "wrong operation!" << endl;
				break;
			};
			break;
		case'f':
			for (int i = 0; i < 3; i++)
			{
				if (player_list[i] != NULL)
				{
					cout << &player_list[i] << endl;
				}
			}
			break;
		case'g':
			exitgamestart = 1;
			break;
		default:
			cout << "wrong operation!" << endl;
			break;
		}
		//打怪
		if (map->getMapSymbol(map->getCurrentPositionX(), map->getCurrentPositionY()) == 2)
		{
			map->setMapSymbol(0, map->getCurrentPositionX(), map->getCurrentPositionY());
			playernumber = 0;
			for (int i = 0; i < 3; i++)
			{
				if (player_list[i] != NULL)
				{
					playernumber++;
				}
			}
			srand(time(NULL));
			int d = rand() % 3;
			Battle encounter(playernumber, d+1);
			for (int i = 0; i < playernumber; i++)
			{
				if(player_list[i]!=NULL)
				{
					encounter.setplayer(player_list[i], i + 1);
				}
			}
			if (!encounter.battle())
			{
				cout << "game over";
				break;
			}
		}
		if(mapnumber==1&&map->getMapSymbol(map->getCurrentPositionX(), map->getCurrentPositionY()) == 203)
		{
			map = new Field("map2.txt", 1, 1, 3, 3);
			mapnumber = 2;
		}
		if (mapnumber == 2 && map->getMapSymbol(map->getCurrentPositionX(), map->getCurrentPositionY()) == 203)
		{
			map = new Field("map3.txt", 1, 1, 3, 3);
			mapnumber = 3;
		}
		if (mapnumber == 3 && map->getMapSymbol(map->getCurrentPositionX(), map->getCurrentPositionY()) == 203)
		{
			cout << "congratulations!" << endl;
			cout << "you have alreay arrived the destination" << endl;
			break;
		}
		cin.clear();
	}
}

