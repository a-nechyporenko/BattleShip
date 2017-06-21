#pragma once
#include"Player.h"

class HumanPlayer :public Player {
public:
	HumanPlayer();
	void map_init(); //Placing in the map array information about the player's ships
	void show();
	int input(int&, int&);//User input
	bool turn(int character, int digit); // Player progress
	~HumanPlayer();
};