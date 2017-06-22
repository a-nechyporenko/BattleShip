#include "Player.h"
#include"Enum.h"


Player::Player(){
	Player::defeat_flag = 0;
	Player::scoreCounter = 0;
	Player::countShots = 0;
	Player::shipsInit();
}

void Player::shipsInit() {
	for (int i = 0; i<10; i++)
		for (int j = 0; j<10; j++)
		{
			ships[i][j] = 1;
			hits[i][j] = 0;
		}
	set(4);
	set(3); set(3);
	set(2); set(2); set(2);
	set(1); set(1); set(1); set(1);
}

void Player::set(int deck) {
	int my = deck - 1;
	bool coor, isset = 0;
	Direction dir;
	int x, y, r;
	while (isset == 0)
	{
		coor = 0;
		r = rand() % 2;
		if (r == 0) dir = horisontal;
		else dir = vertical;
		while (coor == 0)
		{
			x = rand() % 10;
			y = rand() % 10;
			if (ships[x][y] == 1) coor = 1;
		}
		int e = 0;
		switch (dir)
		{
		case horisontal:
			if (ships[x][y + my] == 1)
			{
				if ((y + my) >= 10) break;
				e = checkFreePlaceNearShip(x, y, dir, deck); // check near positions
				if (e == 0)
				{
					for (int i = 0; i<deck; i++)
						ships[x][y + i] = 2;
					isset = 1;
				}
			}
			break;

		case vertical:
			if (ships[x + my][y] == 1)
			{
				e = checkFreePlaceNearShip(x, y, dir, deck);
				if (e == 0)
				{
					for (int i = 0; i<deck; i++)
						ships[x + i][y] = 2;
					isset = 1;
				}
			}
			break;
		}
	}
}

bool Player::checkFreePlaceNearShip(int x, int y, Direction dir, int deck)
{
	bool e = 0;
	switch (dir)
	{
	case horisontal:
		if (y == 0)
			if (x == 0)
			{
				for (int i = 0; i <= deck; i++)
					if (ships[x + 1][y + i] != 1) { e = 1; break; }
				if (ships[x][y + deck] != 1) { e = 1; }
				break;
			}
			else if (x == 9)
			{
				for (int i = 0; i <= deck; i++)
					if (ships[x - 1][y + i] != 1) { e = 1; break; }
				if (ships[x][y + deck] != 1) { e = 1; }
				break;
			}
			else
			{
				for (int i = 0; i <= deck; i++)
				{
					if (ships[x + 1][y + i] != 1) { e = 1; break; }
					if (ships[x - 1][y + i] != 1) { e = 1; break; }
				}
				if (ships[x][y + deck] != 1) { e = 1; }
				break;
			}
		else if (y == (10 - deck))
			if (x == 0)
			{
				for (int i = -1; i<deck; i++)
					if (ships[x + 1][y + i] != 1) { e = 1; break; }
				if (ships[x][y - 1] != 1) { e = 1; }
				break;
			}
			else if (x == 9)
			{
				for (int i = -1; i<deck; i++)
					if (ships[x - 1][y + i] != 1) { e = 1; break; }
				if (ships[x][y - 1] != 1) { e = 1; }
				break;
			}
			else
			{
				for (int i = -1; i<deck; i++)
				{
					if (ships[x + 1][y + i] != 1) { e = 1; break; }
					if (ships[x - 1][y + i] != 1) { e = 1; break; }
				}
				if (ships[x][y - 1] != 1) { e = 1; }
				break;
			}
		else
			if (x == 0)
			{
				for (int i = -1; i <= deck; i++)
					if (ships[x + 1][y + i] != 1) { e = 1; break; }
				if (ships[x][y - 1] != 1) { e = 1; break; }
				if (ships[x][y + deck] != 1) { e = 1; }
				break;
			}
			else if (x == 9)
			{
				for (int i = -1; i <= deck; i++)
					if (ships[x - 1][y + i] != 1) { e = 1; break; }
				if (ships[x][y - 1] != 1) { e = 1; break; }
				if (ships[x][y + deck] != 1) { e = 1; }
				break;
			}
			else
			{
				for (int i = -1; i <= deck; i++)
				{
					if (ships[x + 1][y + i] != 1) { e = 1; break; }
					if (ships[x - 1][y + i] != 1) { e = 1; break; }
				}
				if (ships[x][y - 1] != 1) { e = 1; break; }
				if (ships[x][y + deck] != 1) { e = 1; }
				break;
			}

	case vertical:
		if (x == 0)
			if (y == 0)
			{
				for (int i = 0; i <= deck; i++)
					if (ships[x + i][y + 1] != 1) { e = 1; break; }
				if (ships[x + deck][y] != 1) { e = 1; }
				break;
			}
			else if (y == 9)
			{
				for (int i = 0; i <= deck; i++)
					if (ships[x + i][y - 1] != 1) { e = 1; break; }
				if (ships[x + deck][y] != 1) { e = 1; }
				break;
			}
			else
			{
				for (int i = 0; i <= deck; i++)
				{
					if (ships[x + i][y + 1] != 1) { e = 1; break; }
					if (ships[x + i][y - 1] != 1) { e = 1; break; }
				}
				if (ships[x + deck][y] != 1) { e = 1; }
				break;
			}
		else if (x == (10 - deck))
			if (y == 0)
			{
				for (int i = -1; i<deck; i++)
					if (ships[x + i][y + 1] != 1) { e = 1; break; }
				if (ships[x - 1][y] != 1) { e = 1; }
				break;
			}
			else if (y == 9)
			{
				for (int i = -1; i<deck; i++)
					if (ships[x + i][y - 1] != 1) { e = 1; break; }
				if (ships[x - 1][y] != 1) { e = 1; }
				break;
			}
			else
			{
				for (int i = -1; i<deck; i++)
				{
					if (ships[x + i][y + 1] != 1) { e = 1; break; }
					if (ships[x + i][y - 1] != 1) { e = 1; break; }
				}
				if (ships[x - 1][y] != 1) { e = 1; }
				break;
			}
		else
			if (y == 0)
			{
				for (int i = -1; i <= deck; i++)
					if (ships[x + i][y + 1] != 1) { e = 1; break; }
				if (ships[x - 1][y] != 1) { e = 1; break; }
				if (ships[x + deck][y] != 1) { e = 1; }
				break;
			}
			else if (y == 9)
			{
				for (int i = -1; i <= deck; i++)
					if (ships[x + i][y - 1] != 1) { e = 1; break; }
				if (ships[x - 1][y] != 1) { e = 1; break; }
				if (ships[x + deck][y] != 1) { e = 1; }
				break;
			}
			else
			{
				for (int i = -1; i <= deck; i++)
				{
					if (ships[x + i][y + 1] != 1) { e = 1; break; }
					if (ships[x + i][y - 1] != 1) { e = 1; break; }
				}
				if (ships[x - 1][y] != 1) { e = 1; break; }
				if (ships[x + deck][y] != 1) { e = 1; }
				break;
			}
		/////////////////////////////////////////////
	}
	return e;
}

Player::~Player(){
}
