#include"BattleShips.h"
#include<iostream>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	BattleShips bs;
	while (bs.gameOver())
	{
		bs.gameUpdate();
	}
	bs.win();
	system("pause");
	return 0;
}
