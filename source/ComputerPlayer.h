#pragma once
#ifndef _COMPUTERPLAYER_H
#define _COMPUTERPLAYER_H
#include "Player.h"
#include "HumanPlayer.h"
class ComputerPlayer :public Player
{
public:
	ComputerPlayer();
	~ComputerPlayer();
};

#endif