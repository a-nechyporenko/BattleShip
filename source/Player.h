#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H
#include"Enum.h"
class Player {
public:
	Player();
	bool defeat_flag;
	int hits[10][10];
	int ships[10][10];
	int countShots;
	int scoreCounter;
	void shipsInit();	//Placing in the map array information about the player'LINES ships
	~Player();

private:
	void set(int deck); // places one ship on the field / deck - number of decks
	bool checkFreePlaceNearShip(int x, int y, Direction dir, int deck); // checks if the ship being placed is related to other
};

#endif