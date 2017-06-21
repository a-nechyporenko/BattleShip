#include "Fild.h"
#include<iostream>

Fild::Fild()
{
	in_mass_net();
}

void Fild::str_net(int k, int y)
{
	for (int i = 0; i<10; i++)
	{
		Fild::map[k][y + i] = '#';
		y++;
		Fild::map[k][y + i] = '-';
	}
	Fild::map[k][24] = '#';
	Fild::map[k][60] = '#';
}

void Fild::num_str(int j, int k, int y)
{
	Fild::map[k][y] = j;
	y++;
	Fild::map[k][y] = ' ';
	y++;
	for (int i = 0; i<10; i++)
	{
		Fild::map[k][y + i] = '|';
		y++;
		Fild::map[k][y + i] = ' ';
	}
	Fild::map[k][24] = '|';
	Fild::map[k][60] = '|';
}

void Fild::kanji_str(int x, int y)
{
	char ch = 'A';
	for (int i = 0; i<10; i++)
	{
		Fild::map[x][y] = ' ';
		y++;
		Fild::map[x][y] = ch;
		ch++;
		y++;
	}
}

void Fild::space_input(int x, int y, int n)
{
	for (int i = 0; i<n; i++)
	{
		Fild::map[x][y] = ' ';
		y++;
	}

}

void Fild::showMas() {
	show(22, 61);
}
void Fild::in_mass_net()
{
	int k = 1;
	Fild::space_input(0, 0, 4);
	Fild::kanji_str(0, 4);
	Fild::space_input(0, 24, 16);
	Fild::kanji_str(0, 40);
	Fild::space_input(0, 60, 1);
	for (char j = '0'; j<':'; j++)
	{
		Fild::space_input(k, 0, 4);
		Fild::str_net(k, 4);
		Fild::space_input(k, 24, 16);
		Fild::str_net(k, 40);
		k++;
		Fild::space_input(k, 0, 2);
		Fild::num_str(j, k, 2);
		Fild::space_input(k, 24, 14);
		Fild::num_str(j, k, 38);
		k++;
	}
	Fild::space_input(k, 0, 4);
	Fild::str_net(k, 4);
	Fild::space_input(k, 24, 16);
	Fild::str_net(k, 40);
}
void Fild::show(int s, int c)
{
	for (int i = 0; i<s; i++)
	{
		for (int j = 0; j < c; j++)
		{
			std::cout <<Fild::map[i][j];
		}
		std::cout << "\n";
	}
}


Fild::~Fild()
{
}
