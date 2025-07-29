#include<iostream>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<vector>
#include"field.h"

using namespace std;

Field::Field(int** data, int x, int y ,int w, int h)
//The first parameter is the map data
//The second and third parameter are the current place(x, y) of player
//The forth and fifth parameter are the(width, height) of vision
{
	map_data = data;
	setPosition(x, y);
	setVisionSize(w, h);
}

Field::Field(string name, int x, int y, int w, int h)
//Similar to first one, but the first parameter is name of file that stores map data
{
	map_name = name;
	setPosition(x, y);
	setVisionSize(w, h);
	string line;
	ifstream openthefile(name, ios::in);
	stringstream s;
	int symbo,row;
	int column;
	getline(openthefile, line);
	s << line;
	s >> column;
	if (s.peek() == ',')
	{
		s.ignore();
	}
	s >> row;
	s.clear();
	cin.clear();
	vector<vector<int>> map(row,vector<int>(column));
	for(int i = 0; i < row; i++)
	{
		getline(openthefile, line);
		s << line;
		for (int j = 0; j < column; j++)
		{
			if (s.peek() == ',')
			{
				s.ignore();
			}
			s >> symbo;
			s.clear();
			map[i][j]= symbo;
		}
		cin.clear();
		if (openthefile.eof())
		{
			break;
		}
	}
	map_data = new int*[row];
	for (int i = 0; i < row; i++)
	{
		map_data[i] = new int[column];//地圖必須是四方形
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			setMapSymbol(map[i][j], i, j);
		}
		cout << endl;
	}
	map_height = row;
	map_width = column;
}

Field::~Field()
{
	delete[] map_data;
}

bool Field::move(char m)
//Move player to next position, the parameter is the direction
//The return value indicates whether this move is legal or not
{
	if (m == 'W' || m == 'w')
	{
		return moveUp();
	}
	if (m == 'A' || m == 'a')
	{
		return moveLeft();
	}
	if (m == 'S' || m == 's')
	{
		return moveDown();
	}
	if (m == 'D'|| m == 'd')
	{
		return moveRight();
	}
}
bool Field::moveUp(void)
{
	if (getMapSymbol(getCurrentPositionX(), getCurrentPositionY() - 1) == 0 || getMapSymbol(getCurrentPositionX(), getCurrentPositionY() - 1) == 2 || getMapSymbol(getCurrentPositionX(), getCurrentPositionY() - 1) == 201|| getMapSymbol(getCurrentPositionX(), getCurrentPositionY() - 1) == 203)
	{
		setPosition(getCurrentPositionX(), getCurrentPositionY() - 1);
		return 1;
	}
	else
	{
		cout << "invalied move" << endl;
		return 0;
	}
	return 0;
}
bool Field::moveDown(void)
{
	if (getMapSymbol(getCurrentPositionX(), getCurrentPositionY() + 1) == 0 || getMapSymbol(getCurrentPositionX(), getCurrentPositionY() + 1) == 2|| getMapSymbol(getCurrentPositionX(), getCurrentPositionY() + 1) == 201|| getMapSymbol(getCurrentPositionX(), getCurrentPositionY() + 1) == 203)
	{
		setPosition(getCurrentPositionX(), getCurrentPositionY() + 1);
		return 1;
	}
	else
	{
		cout << "invalied move" << endl;
		return 0;
	}
	return 0;
}
bool Field::moveLeft(void)
{
	if (getMapSymbol(getCurrentPositionX() - 1, getCurrentPositionY()) == 0 || getMapSymbol(getCurrentPositionX() - 1, getCurrentPositionY()) == 2 || getMapSymbol(getCurrentPositionX() - 1, getCurrentPositionY()) == 201 || getMapSymbol(getCurrentPositionX() - 1, getCurrentPositionY()) == 203)
	{
		setPosition(getCurrentPositionX() - 1, getCurrentPositionY());
		return 1;
	}
	else
	{
		cout << "invalied move" << endl;
		return 0;
	}
	return 0;
	
}
bool Field::moveRight(void)
{
	if (getMapSymbol(getCurrentPositionX()+1, getCurrentPositionY()) == 0 || getMapSymbol(getCurrentPositionX()+1, getCurrentPositionY()) == 2|| getMapSymbol(getCurrentPositionX() + 1, getCurrentPositionY()) == 201 || getMapSymbol(getCurrentPositionX() + 1, getCurrentPositionY()) == 203)
	{
		setPosition(getCurrentPositionX() + 1, getCurrentPositionY());
		return 1;
	}
	else
	{
		cout << "invalied move" << endl;
		return 0;
	}
	return 0;

}
	
//The same as move(char), move player to next position
//But the direction is determined
//These methods get the information of the map
int Field::getCurrentPositionX(void) const
{
	return current_position_x;
}
int Field::getCurrentPositionY(void) const
{
	return current_position_y;
}
int Field::getVisionWidth(void) const
{
	return vision_width;
}
int Field::getVisionHeight(void) const
{
	return vision_height;
}
string Field::getMapName(void) const
{
	return map_name;
}
int Field::getMapSymbol(int x, int y)const//?
{
	return (map_data[x][y]);
}
//Parameter is the position(x, y)
void Field::setPosition(int x, int y)
{
	current_position_x = x;
	current_position_y = y;
}
//Set the position of player, prameters are position(x, y)
void Field::setMapSymbol(int sym, int x, int y)
//Set the symbol on a specific position
//The first parameter is symbol, the rest are position(x, y)
{
	map_data[x][y] = sym;
}
void Field::setVisionSize(int w, int h)
{
	vision_width = w;
	vision_height = h;
}
//Set the size of vision, parameters are(width, height)
void Field::display(void) const
//Displaying the map
{
	char c[3];
	c[0] = -94;
	c[1] = 112;
	c[2] = 0;

	if (getCurrentPositionY() < getVisionHeight() && getCurrentPositionX() < getVisionWidth())
	{
		for (int i = 0; i <= getCurrentPositionY() + getVisionHeight(); i++)
		{
			for (int j = 0; j <= (getCurrentPositionX() + getVisionWidth()); j++)
			{
				if (i == getCurrentPositionY() && j == getCurrentPositionX())
				{
					cout << setw(2) << "\033[41m　\033[40m";
					continue;
				}
				if (getMapSymbol(j, i) == 1)
				{
					cout << setw(2) << c << " ";
					continue;
				}
				if (getMapSymbol(j, i) == 201 && getMapSymbol(getCurrentPositionX(), getCurrentPositionY()) != 201)//?
				{
					cout << setw(2) << "起";
					continue;
				}
				if (getMapSymbol(j, i) == 2)
				{
					cout << setw(2) << "怪";
					continue;
				}
				if (getMapSymbol(j, i) == 0)
				{
					cout << setw(2) << "　";
					continue;
				}
				if (getMapSymbol(j, i) == 203)
				{
					cout << setw(2)<< "終";
					continue;
				}
			}
			cout << endl;
		}
	}
	if (getCurrentPositionY() >= getVisionHeight() && getCurrentPositionX() < getVisionWidth())
	{
		for (int i = (getCurrentPositionY() - getVisionHeight()); i <= (getCurrentPositionY() + getVisionHeight()); i++)
		{
			for (int j = 0; j <= (getCurrentPositionX() + getVisionWidth()); j++)
			{
				if (i>=map_height)
				{
					continue;
				}
				if (i == getCurrentPositionY() && j == getCurrentPositionX())
				{
					cout << setw(2) << "\033[41m　\033[40m";
					continue;
				}
				if (getMapSymbol(j, i) == 1)
				{
					cout << setw(2) << c << " ";
					continue;
				}
				if (getMapSymbol(j, i) == 201 && getMapSymbol(getCurrentPositionX(), getCurrentPositionY()) != 201)//?
				{
					cout << setw(2) << "起";
					continue;
				}
				if (getMapSymbol(j, i) == 2)
				{
					cout << setw(2) << "怪";
					continue;
				}
				if (getMapSymbol(j, i) == 0)
				{
					cout << setw(2) << "　";
					continue;
				}
				if (getMapSymbol(j, i) == 203)
				{
					cout << setw(2)<< "終";
					continue;
				}
			}
			cout << endl;
		}
	}
	if (getCurrentPositionY() < getVisionHeight() && getCurrentPositionX() >= getVisionWidth())
	{
		for (int i = 0; i <= getCurrentPositionY() + getVisionHeight(); i++)
		{
			for (int j = (getCurrentPositionX() - getVisionWidth()); j <= (getCurrentPositionX() + getVisionWidth()); j++)
			{
				if (j >= map_width)
				{
					continue;
				}
				if (i == getCurrentPositionY() && j == getCurrentPositionX())
				{
					cout << setw(2) << "\033[41m　\033[40m";
					continue;
				}
				if (getMapSymbol(j, i) == 1)
				{
					cout << setw(2) << c << " ";
					continue;
				}
				if (getMapSymbol(j, i) == 201 && getMapSymbol(getCurrentPositionX(), getCurrentPositionY()) != 201)//?
				{
					cout << setw(2) << "起";
					continue;
				}
				if (getMapSymbol(j, i) == 2)
				{
					cout << setw(2) << "怪";
					continue;
				}
				if (getMapSymbol(j, i) == 0)
				{
					cout << setw(2) << "　";
					continue;
				}
				if (getMapSymbol(j, i) == 203)
				{
					cout << setw(2)<< "終";
					continue;
				}
			}
			cout << endl;
		}
	}
	if (getCurrentPositionY() >= getVisionHeight() && getCurrentPositionX() >= getVisionWidth())
	{
		for (int i = (getCurrentPositionY()- getVisionHeight()); i <= (getCurrentPositionY() + getVisionHeight()); i++)
		{
			for (int j = (getCurrentPositionX()- getVisionWidth()); j <= (getCurrentPositionX() + getVisionWidth()); j++)
			{
				if ( j>= map_width|| i>=map_height)
				{
					continue;
				}
				if (i == getCurrentPositionY() && j == getCurrentPositionX())
				{
					cout << setw(2) << "\033[41m　\033[40m";
					continue;
				}
				if (getMapSymbol(j, i) == 1)
				{
					cout << setw(2) << c<<" ";
					continue;
				}
				if (getMapSymbol(j, i) == 201 && getMapSymbol(getCurrentPositionX(), getCurrentPositionY()) != 201)//?
				{
					cout << setw(2) << "起";
					continue;
				}
				if (getMapSymbol(j, i) == 2)
				{
					cout << setw(2) << "怪";
					continue;
				}
				if (getMapSymbol(j, i) == 0)
				{
					cout << setw(2) << "　";
					continue;
				}
				if (getMapSymbol(j, i) == 203)
				{
					cout << setw(2) << "終";
					continue;
				}
			}
			cout << endl;
		}
	}
	cout << endl;
}
/*==============================================

Please add more methods according to your own features

==============================================*/
