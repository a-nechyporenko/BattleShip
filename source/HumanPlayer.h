#pragma once
#ifndef _HUMANPLAYER_H
#define _HUMANPLAYER_H
#include"Player.h"

class HumanPlayer :public Player {
public:
					
	void show();
	int input(int&, int&);					//User input
	bool turn(int character, int digit);	// Player progress
	
private:
	HumanPlayer();
	~HumanPlayer();
};

#endif