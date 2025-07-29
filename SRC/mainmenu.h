#pragma once

#ifndef MAINMENU_H
#define MAINMENU_H
#include<iostream>
#include"menu.h"
using namespace std;

class MainMenu:public Menu
{
public:
	virtual void display();
	virtual string getinput();
private:
	bool continuofgame=0;
};

#endif
