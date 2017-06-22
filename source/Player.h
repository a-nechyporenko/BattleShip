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
	int score;
	void ships_init();	//Placing in the map array information about the player's ships
	~Player();

private:
	void set(int deck); // размещает на поле один корабль / deck - количество палуб
	bool place_ship(int x, int y, direction dir, int deck); // проверяет, касается ли размещаемый корабль других
};

#endif