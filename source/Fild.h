#pragma once
#ifndef _Fild_H
#define _Fild_H
class Fild
{
public:
	Fild();
	
	char numbers[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	char lete[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	void showMas();
	void in_mass_net();
	~Fild();
protected:
	const int LINES = 22, COLUMN = 61;
	char map[22][61];
private:
	void show(int LINES, int COLUMN);
	void strNet(int k, int y);
	void numStr(int j, int k, int y);
	void kanjiStr(int x, int y);
	void spaceInput(int x, int y, int n);
};

#endif