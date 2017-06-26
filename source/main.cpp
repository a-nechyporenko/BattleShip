#include"BattleShips.h"
#include<iostream>

int main()
{
	BattleShips bs;
	while (bs.gameOver())
	{
		bs.gameUpdate();
	}
	bs.win();
	system("pause");
	return 0;
}
