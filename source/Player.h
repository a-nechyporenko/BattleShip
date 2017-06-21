#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H
#include"Enum.h"
class Player {
	
public:
	//const int s = 22, c = 61;
	//char map[22][61];
	//char numbers[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	//char lete[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

	bool defeat_flag;
	int hits[10][10];
	int ships[10][10];
	void ships_init();	//Placing in the map array information about the player's ships
	Player();
	~Player();
private:
	/*void in_mass_net(void);
	void str_net(int k, int y);
	void num_str(int j, int k, int y);
	void kanji_str(int x, int y);
	void space_input(int x, int y, int n);*/
	void set(int deck); // размещает на поле один корабль / deck - количество палуб
	bool place_ship(int x, int y, direction dir, int deck); // проверяет, касается ли размещаемый корабль других
};

#endif