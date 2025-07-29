#pragma once

#ifndef FIELDMENU_H
#define FIELDMENU_H
#include<iostream>
#include"menu.h"
using namespace std;

class FieldMenu :public Menu
{
public:
	virtual void display();
	virtual string getinput();
private:
	
};

#endif
