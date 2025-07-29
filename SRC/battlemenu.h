#pragma once

#ifndef BATTLEMENU_H
#define BATTLEMENU_H
#include<iostream>
#include"menu.h"
using namespace std;

class BattleMenu :public Menu
{
public:
	virtual void display();
	virtual string getinput();
private:

};

#endif
