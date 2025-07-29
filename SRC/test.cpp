#include "noviceplayer.h"
#include "orcplayer.h"
#include "knightplayer.h"
#include "magicianplayer.h"
#include "basemonster.h"
#include "goblinmonster.h"
#include "jwmonster.h"
#include "zombiemonster.h"
#include "battle.h"
#include <iostream>
#include <string>
using namespace std;

//Operator overloading
ostream& operator<<(ostream& os, const NovicePlayer& player) {
	os << "name:    " << player.getname() << endl;
	os << "level:   " << player.getlevel() << endl;
	os << "attack:  " << player.getAttack() << endl;
	os << "defense: " << player.getDefense() << endl;
	os << "hp:      " << player.gethp() << " / " << player.getMaxHP() << endl;
	os << "mp:      " << player.getmp() << " / " << player.getMaxMP() << endl;
	os << "exp:     " << player.getexp() << " / " << player.getLvupExp() << endl;
	os << "money:   " << player.getmoney() << endl;

	return os;
}
ostream& operator<<(ostream& os, const BaseMonster &monster) {
	os << "name:    " << monster.name << endl;
	os << "attack:  " << monster.attack << endl;
	os << "defense: " << monster.defense << endl;
	os << "money: " << monster.money << endl;
	os << "hp:      " << monster.getHP() << " / " << monster.max_hp << endl;
	os << "mp:      " << monster.getMP() << " / " << monster.max_mp << endl;
	return os;
}

int main() {
	MagicianPlayer player1;
	NovicePlayer player2;
	NovicePlayer player3;
	Battle battle1(3,1);
	battle1.setplayer(&player1, 1);
	battle1.setplayer(&player2, 2);
	battle1.setplayer(&player3, 3);
	ZombieMonster monster1;
	GoblinMonster monster2;
	battle1.setmonster(&monster1,1);
	battle1.setmonster(&monster2, 2);
	
	cout << player1 << endl;
	cout << player2 << endl;
	cout << player3 << endl;
	cout << monster1 << endl;
	cout << monster2 << endl;
	battle1.battle();
	cout << player1 << endl;
	cout << player2 << endl;
	cout << player3 << endl;
	cout << monster1 << endl;
	cout << monster2 << endl;
	system("PAUSE");
	return 0;
}