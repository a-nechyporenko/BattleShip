#pragma once
#ifndef _BATTLESHIPS_H
#define _BATTLESHIPS_H
#include"HumanPlayer.h"
#include"ComputerPlayer.h"
#include"Fild.h"
#include"Enum.h"
class BattleShips:public Fild {
public:
	BattleShips();
	bool gameOver();
	void gameUpdate();
	void start();
	void stop();
	void Win();
	~BattleShips();
	
private:
	ComputerPlayer computer;
	HumanPlayer human;
	bool e;
	void map_init();
	int checkEnd();
	void controlState();
	void score();
	bool turnHuman(int character, int digit);	// for human player
	bool turnComputer();						//for computer player
	machinstate m_State;
	StepState m_StepState;
};
#endif