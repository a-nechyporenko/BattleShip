#pragma once
#ifndef _HUMANPLAYER_H
#define _HUMANPLAYER_H
#include"Player.h"
#include"Fild.h"

class HumanPlayer :public Player, public Fild {
public:
	HumanPlayer();
	char numbers[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	char lete[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	int message;	// The variable stores the message codes (0 - everything is fine, 1 - the user pressed the wrong key, 2 - the game is over)
	int input(int&, int&, int massage);					//User input
	~HumanPlayer();	
};

#endif