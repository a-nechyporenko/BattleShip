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
	void start();
	void stop();
	~BattleShips();
	
private:
	ComputerPlayer computer;
	HumanPlayer human;
	bool gameOver();
	void gameUpdate();
	int checkEnd();
	void controlState();
	bool turnHuman(int character, int digit);	// for human player
	bool turnComputer();						//for computer player
	void Draw();
	machinstate m_State;
	StepState m_StepState;
};
#endif