#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H
#include"Enum.h"
class Player {
	
public:
	bool defeat_flag;
	int hits[10][10];
	int ships[10][10];
	char numbers[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	char lete[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	void ships_init();	//Placing in the map array information about the player's ships
	Player();
	~Player();
private:
	void set(int deck); // размещает на поле один корабль / deck - количество палуб
	bool place_ship(int x, int y, direction dir, int deck); // проверяет, касается ли размещаемый корабль других
};

#endif