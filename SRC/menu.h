#pragma once

#ifndef MENU_H
#define MENU_H
#include<iostream>
using namespace std;

class Menu
{
public:
	virtual void display()=0;
	virtual string getinput() = 0;
private:
	
};

#endif
