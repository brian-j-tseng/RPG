#include<iostream>
#include<string>
#include"fieldmenu.h"

using namespace std;

void FieldMenu::display()
{
	cout << "(w) upward" << endl;
	cout << "(a) leftward" << endl;
	cout << "(s) downward" << endl;
	cout << "(d) rightward" << endl;
	cout << "(q) open your backpack" << endl;
	cout << "(f) display your status" << endl;
	cout << "(g) back to main menu" << endl;
}
string FieldMenu::getinput()
{
	string operation;
	cin >> operation;
	cin.clear();
	while (operation.size() > 1 || operation.size() == 0)//¨¾§b
	{
		cout << "wrong operation" << endl;
		cin >> operation;
		cin.clear();
	}
	return operation;
}
