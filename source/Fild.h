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
private:
	const int s = 22, c = 61;
	char map[22][61];
	void show(int s, int c);
	void str_net(int k, int y);
	void num_str(int j, int k, int y);
	void kanji_str(int x, int y);
	void space_input(int x, int y, int n);
};

#endif