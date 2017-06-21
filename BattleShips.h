#pragma once
#include"Enum.h"
class BattleShips {
public:
	BattleShips();
	void start();
	void stop();
	~BattleShips();
private:
	bool gameOver();
	void gameUpdate();
	int checkEnd();
	void controlState();
	void Draw();
	machinstate m_State;
	StepState m_StepState;
};
