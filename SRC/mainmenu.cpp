#include<iostream>
#include<string>
#include"mainmenu.h"

using namespace std;

void MainMenu::display()
{
	if (!continuofgame)
	{
		cout<< "welcome to this game" << endl;
		cout << "(1) start a new game" << endl;
		cout << "(2) open your play record" << endl;
	}
	if (continuofgame)
	{
		cout << "(1) start a new game" << endl;
		cout << "(2) open your play record" << endl;
		cout << "(3) exit the game" << endl;
		cout << "(4) save your record" << endl;
		cout << "(5) back to your game(continue)" << endl;
	}
}
string MainMenu::getinput()
{
	string a;
	if (!continuofgame)
	{
		cin >> a;
		while (a.size() > 1 || (a[0] != '1' && a[0] != '2'))//¨¾§b
		{
			cout << "wrong operation" << endl;
			cin.clear();
			cin >> a;
		}
		continuofgame = 1;
		return a;
	}
	if (continuofgame)
	{
		cin >> a;
		cin.clear();
		while (a.size() > 1 || (a[0] != '1' && a[0] != '2' && a[0] != '3' && a[0] != '4' && a[0] != '5'))//¨¾§b
		{
			cout << "wrong operation" << endl;
			cin >> a;
			cin.clear();
		}
		return a;
	}
}