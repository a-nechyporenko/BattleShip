#include "HumanPlayer.h"
#include"Player.h"
#include<iostream>


HumanPlayer::HumanPlayer(){
}

int input(int& character, int& digit)
{
	character = -1, digit = -1;
	int massage = 0;
	char ch, d;
	std::cout << "���������!\n";
	std::cout << "������� ���������� �������� ����� �� A �� J:";
	std::cin >> ch;
	for (int i = 0; i<10; i++)
	{
		if (ch == lete[i]) { character = i; }
	}
	if (character == -1) { massage = 1; return massage; }
	std::cout << "������� ����� �� 0 �� 9:";
	std::cin >> d;
	for (int i = 0; i<10; i++)
	{
		if (d == numbers[i]) { digit = i; }
	}
	if (digit == -1) { massage = 1; return massage; }
	return massage;
}
HumanPlayer::~HumanPlayer(){
}
