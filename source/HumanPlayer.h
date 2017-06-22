#pragma once
#ifndef _HUMANPLAYER_H
#define _HUMANPLAYER_H
#include"Player.h"
#include"Fild.h"

class HumanPlayer :public Player, public Fild {
public:
						
private:
	HumanPlayer();
	int input(int&, int&);					//User input
	~HumanPlayer();
};

#endif