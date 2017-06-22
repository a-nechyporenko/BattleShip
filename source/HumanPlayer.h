#pragma once
#ifndef _HUMANPLAYER_H
#define _HUMANPLAYER_H
#include"Player.h"
#include"Fild.h"

class HumanPlayer :public Player, public Fild {
public:
	HumanPlayer();
	~HumanPlayer();
private:
	int input(int&, int&);					//User input
};

#endif