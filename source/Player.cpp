//#include "Player.h"
//#include <iostream>
//
//
//Player::Player(){
//	defeat_flag = 0;
//}
//
//int input(int& character, int& digit){
//	character = -1, digit = -1;
//	int massage = 0;
//	char ch, d;
//	std::cout << "—трел€йте!\n";
//	std::cout << "¬ведите английскую строчную букву от A до J:";
//	std::cin >> ch;
//	for (int i = 0; i<10; i++)
//	{
//		if (ch == lete[i]) { character = i; }
//	}
//	if (character == -1) { massage = 1; return massage; }
//	std::cout << "¬ведите цифру от 0 до 9:";
//	std::cin >> d;
//	for (int i = 0; i<10; i++)
//	{
//		if (d == numbers[i]) { digit = i; }
//	}
//	if (digit == -1) { massage = 1; return massage; }
//	return massage;
//}
//
//void Player::ships_init() {
//	for (int i = 0; i<10; i++)
//		for (int j = 0; j<10; j++)
//		{
//			ships[i][j] = 1;
//			hits[i][j] = 0;
//		}
//	set(4);
//	set(3); set(3);
//	set(2); set(2); set(2);
//	set(1); set(1); set(1); set(1);
//}
//
//void Player::set(int deck) {
//	int my = deck - 1;
//	bool coor, isset = 0;
//	direction dir;
//	int x, y, r;
//	while (isset == 0)
//	{
//		coor = 0;
//		r = rand() % 2;
//		if (r == 0) dir = horisontal;
//		else dir = vertical;
//		while (coor == 0)
//		{
//			x = rand() % 10;
//			y = rand() % 10;
//			if (ships[x][y] == 1) coor = 1;
//		}
//		int e = 0;
//		switch (dir)
//		{
//		case horisontal:
//			if (ships[x][y + my] == 1)
//			{
//				if ((y + my) >= 10) break;
//				e = place_ship(x, y, dir, deck); // check near positions
//				if (e == 0)
//				{
//					for (int i = 0; i<deck; i++)
//						ships[x][y + i] = 2;
//					isset = 1;
//				}
//			}
//			break;
//
//		case vertical:
//			if (ships[x + my][y] == 1)
//			{
//				e = place_ship(x, y, dir, deck);
//				if (e == 0)
//				{
//					for (int i = 0; i<deck; i++)
//						ships[x + i][y] = 2;
//					isset = 1;
//				}
//			}
//			break;
//		}
//	}
//}
//
//bool Player::place_ship(int x, int y, direction dir, int deck)
//{
//	bool e = 0;
//	switch (dir)
//	{
//	case horisontal:
//		if (y == 0)
//			if (x == 0)
//			{
//				for (int i = 0; i <= deck; i++)
//					if (ships[x + 1][y + i] != 1) { e = 1; break; }
//				if (ships[x][y + deck] != 1) { e = 1; }
//				break;
//			}
//			else if (x == 9)
//			{
//				for (int i = 0; i <= deck; i++)
//					if (ships[x - 1][y + i] != 1) { e = 1; break; }
//				if (ships[x][y + deck] != 1) { e = 1; }
//				break;
//			}
//			else
//			{
//				for (int i = 0; i <= deck; i++)
//				{
//					if (ships[x + 1][y + i] != 1) { e = 1; break; }
//					if (ships[x - 1][y + i] != 1) { e = 1; break; }
//				}
//				if (ships[x][y + deck] != 1) { e = 1; }
//				break;
//			}
//		else if (y == (10 - deck))
//			if (x == 0)
//			{
//				for (int i = -1; i<deck; i++)
//					if (ships[x + 1][y + i] != 1) { e = 1; break; }
//				if (ships[x][y - 1] != 1) { e = 1; }
//				break;
//			}
//			else if (x == 9)
//			{
//				for (int i = -1; i<deck; i++)
//					if (ships[x - 1][y + i] != 1) { e = 1; break; }
//				if (ships[x][y - 1] != 1) { e = 1; }
//				break;
//			}
//			else
//			{
//				for (int i = -1; i<deck; i++)
//				{
//					if (ships[x + 1][y + i] != 1) { e = 1; break; }
//					if (ships[x - 1][y + i] != 1) { e = 1; break; }
//				}
//				if (ships[x][y - 1] != 1) { e = 1; }
//				break;
//			}
//		else
//			if (x == 0)
//			{
//				for (int i = -1; i <= deck; i++)
//					if (ships[x + 1][y + i] != 1) { e = 1; break; }
//				if (ships[x][y - 1] != 1) { e = 1; break; }
//				if (ships[x][y + deck] != 1) { e = 1; }
//				break;
//			}
//			else if (x == 9)
//			{
//				for (int i = -1; i <= deck; i++)
//					if (ships[x - 1][y + i] != 1) { e = 1; break; }
//				if (ships[x][y - 1] != 1) { e = 1; break; }
//				if (ships[x][y + deck] != 1) { e = 1; }
//				break;
//			}
//			else
//			{
//				for (int i = -1; i <= deck; i++)
//				{
//					if (ships[x + 1][y + i] != 1) { e = 1; break; }
//					if (ships[x - 1][y + i] != 1) { e = 1; break; }
//				}
//				if (ships[x][y - 1] != 1) { e = 1; break; }
//				if (ships[x][y + deck] != 1) { e = 1; }
//				break;
//			}
//
//	case vertical:
//		if (x == 0)
//			if (y == 0)
//			{
//				for (int i = 0; i <= deck; i++)
//					if (ships[x + i][y + 1] != 1) { e = 1; break; }
//				if (ships[x + deck][y] != 1) { e = 1; }
//				break;
//			}
//			else if (y == 9)
//			{
//				for (int i = 0; i <= deck; i++)
//					if (ships[x + i][y - 1] != 1) { e = 1; break; }
//				if (ships[x + deck][y] != 1) { e = 1; }
//				break;
//			}
//			else
//			{
//				for (int i = 0; i <= deck; i++)
//				{
//					if (ships[x + i][y + 1] != 1) { e = 1; break; }
//					if (ships[x + i][y - 1] != 1) { e = 1; break; }
//				}
//				if (ships[x + deck][y] != 1) { e = 1; }
//				break;
//			}
//		else if (x == (10 - deck))
//			if (y == 0)
//			{
//				for (int i = -1; i<deck; i++)
//					if (ships[x + i][y + 1] != 1) { e = 1; break; }
//				if (ships[x - 1][y] != 1) { e = 1; }
//				break;
//			}
//			else if (y == 9)
//			{
//				for (int i = -1; i<deck; i++)
//					if (ships[x + i][y - 1] != 1) { e = 1; break; }
//				if (ships[x - 1][y] != 1) { e = 1; }
//				break;
//			}
//			else
//			{
//				for (int i = -1; i<deck; i++)
//				{
//					if (ships[x + i][y + 1] != 1) { e = 1; break; }
//					if (ships[x + i][y - 1] != 1) { e = 1; break; }
//				}
//				if (ships[x - 1][y] != 1) { e = 1; }
//				break;
//			}
//		else
//			if (y == 0)
//			{
//				for (int i = -1; i <= deck; i++)
//					if (ships[x + i][y + 1] != 1) { e = 1; break; }
//				if (ships[x - 1][y] != 1) { e = 1; break; }
//				if (ships[x + deck][y] != 1) { e = 1; }
//				break;
//			}
//			else if (y == 9)
//			{
//				for (int i = -1; i <= deck; i++)
//					if (ships[x + i][y - 1] != 1) { e = 1; break; }
//				if (ships[x - 1][y] != 1) { e = 1; break; }
//				if (ships[x + deck][y] != 1) { e = 1; }
//				break;
//			}
//			else
//			{
//				for (int i = -1; i <= deck; i++)
//				{
//					if (ships[x + i][y + 1] != 1) { e = 1; break; }
//					if (ships[x + i][y - 1] != 1) { e = 1; break; }
//				}
//				if (ships[x - 1][y] != 1) { e = 1; break; }
//				if (ships[x + deck][y] != 1) { e = 1; }
//				break;
//			}
//		/////////////////////////////////////////////
//	}
//	return e;
//}
//
////void in_mass_net(void)
////{
////	int k = 1;
////	space_input(0, 0, 4);
////	kanji_str(0, 4);
////	space_input(0, 24, 16);
////	kanji_str(0, 40);
////	space_input(0, 60, 1);
////	for (char j = '0'; j<':'; j++)
////	{
////		space_input(k, 0, 4);
////		str_net(k, 4);
////		space_input(k, 24, 16);
////		str_net(k, 40);
////		k++;
////		space_input(k, 0, 2);
////		num_str(j, k, 2);
////		space_input(k, 24, 14);
////		num_str(j, k, 38);
////		k++;
////	}
////	space_input(k, 0, 4);
////	str_net(k, 4);
////	space_input(k, 24, 16);
////	str_net(k, 40);
////}
////
////void str_net(int k, int y)
////{
////	for (int i = 0; i<10; i++)
////	{
////		map[k][y + i] = '#';
////		y++;
////		map[k][y + i] = '-';
////	}
////	map[k][24] = '#';
////	map[k][60] = '#';
////}
////
////void num_str(int j, int k, int y)
////{
////	map[k][y] = j;
////	y++;
////	map[k][y] = ' ';
////	y++;
////	for (int i = 0; i<10; i++)
////	{
////		map[k][y + i] = '|';
////		y++;
////		map[k][y + i] = ' ';
////	}
////	map[k][24] = '|';
////	map[k][60] = '|';
////}
////
////void kanji_str(int x, int y)
////{
////	char ch = 'A';
////	for (int i = 0; i<10; i++)
////	{
////		map[x][y] = ' ';
////		y++;
////		map[x][y] = ch;
////		ch++;
////		y++;
////	}
////}
////
////void space_input(int x, int y, int n)
////{
////	for (int i = 0; i<n; i++)
////	{
////		map[x][y] = ' ';
////		y++;
////	}
////
////}
//Player::~Player(){
//}
