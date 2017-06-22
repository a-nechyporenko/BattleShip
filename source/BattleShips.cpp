#include "BattleShips.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include"Enum.h"
#include<thread>


void BattleShips::start(){
	if (m_State != machinstate::start) {
		m_State = machinstate::start;
		std::thread thr(&BattleShips::m_StepState, this);
		thr.detach();
	}
}

void BattleShips::stop(){
	m_State = machinstate::stop;
}

//constructor 

BattleShips::BattleShips() 
					: m_StepState(StepState::Human)
					, m_State(machinstate::undefined)
{
	BattleShips::start();
}

bool BattleShips::turnHuman(int character, int digit)
{
	setlocale(LC_CTYPE, "Russian");
	bool e = 0;
	if ((human.hits[digit][character] == 1) || (human.hits[digit][character] == 2))
	{
		std::cout << "Вы сюда уже стреляли! Давайте еще раз...";
		_getch();
		e = 1;
	}
	else
	{
		if (computer.ships[digit][character] == 1)
		{
			human.hits[digit][character] = 1;
			std::cout << "Промазали!)))";
			_getch();
		}
		else if (computer.ships[digit][character] == 2)
		{
			human.hits[digit][character] = 2;
			computer.ships[digit][character] = 3;
			std::cout << "Попали!((( Ходите еще раз...";
			e = 1;
			_getch();
		}
	}
	return e;
}

bool BattleShips::turnComputer()
{
	bool e = 0;
	while (e == 0)
	{
		int digit = rand() % 10;
		int character = rand() % 10;
		if (computer.hits[digit][character] == 1) e = 0;
		else
		{
			if (human.ships[digit][character] == 1)
			{
				computer.hits[digit][character] = 1;
				human.ships[digit][character] = 3;
				e = 1;
			}
			else if (human.ships[digit][character] == 2)
			{
				computer.hits[digit][character] = 1;
				human.ships[digit][character] = 4;
				continue;
			}
		}
	}
	return 0;
}

int BattleShips::checkEnd(){
	bool k1 = 0, k2 = 0;
	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<10; j++)
		{
			if (human.ships[i][j] == 2) { k1 = 1; }
			if (computer.ships[i][j] == 2) { k2 = 1; }
		}
	}
	if (k1 == 0) { human.defeat_flag = 1; return 2; }
	if (k2 == 0) { computer.defeat_flag = 1; return 2; }
	return 0;
}
//destructor

BattleShips::~BattleShips() {
	BattleShips::stop();
}

void BattleShips::controlState() {
	static int i = 0;		//count steps
	while (m_State == machinstate::start) {
		switch (m_StepState) {				//change color
		case StepState::Human:

			m_StepState = StepState::Computer;
			break;
		case StepState::Computer:

			m_StepState = StepState::Human;
			break;

		}
	}
}
