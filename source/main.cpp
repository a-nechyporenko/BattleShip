#include"BattleShips.h"
#include"Enum.h"
#include"Fild.h"
#include<iostream>


int main()
{
	setlocale(LC_CTYPE, "Russian");
	BattleShips bs;

	while (bs.gameOver()) {
		bs.gameUpdate();
	}
	system("pause");
	return 0;
}
