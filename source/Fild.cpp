#include "Fild.h"
#include<iostream>

Fild::Fild()
{
	in_mass_net();
}

void Fild::strNet(int k, int y)
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

void Fild::numStr(int j, int k, int y)
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

void Fild::kanjiStr(int x, int y)
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

void Fild::spaceInput(int x, int y, int n)
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
	Fild::spaceInput(0, 0, 4);
	Fild::kanjiStr(0, 4);
	Fild::spaceInput(0, 24, 16);
	Fild::kanjiStr(0, 40);
	Fild::spaceInput(0, 60, 1);
	for (char j = '0'; j<':'; j++)
	{
		Fild::spaceInput(k, 0, 4);
		Fild::strNet(k, 4);
		Fild::spaceInput(k, 24, 16);
		Fild::strNet(k, 40);
		k++;
		Fild::spaceInput(k, 0, 2);
		Fild::numStr(j, k, 2);
		Fild::spaceInput(k, 24, 14);
		Fild::numStr(j, k, 38);
		k++;
	}
	Fild::spaceInput(k, 0, 4);
	Fild::strNet(k, 4);
	Fild::spaceInput(k, 24, 16);
	Fild::strNet(k, 40);
}
void Fild::show(int LINES, int COLUMN)
{
	for (int i = 0; i<LINES; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			std::cout <<Fild::map[i][j];
		}
		std::cout << "\n";
	}
}


Fild::~Fild()
{
}
