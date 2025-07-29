#include<iostream>
#include<string>
#include"battlemenu.h"

using namespace std;

void BattleMenu::display()
{
	cout << "(a) normal attack" << endl;
	cout << "(b) special skill" << endl;
	cout << "(c) use props" << endl;
	cout << "(d) run away" << endl;
}
string BattleMenu::getinput()
{
	string a;
	cin >> a;
	cin.clear();
	while (a.size() > 1 || (a[0] != 'a'&&a[0] != 'b'&&a[0] != 'c'&&a[0] != 'd'))
	{
		cout << "wrong operation" << endl;
		cin >> a;
		cin.clear();
	}
	return a;
}
