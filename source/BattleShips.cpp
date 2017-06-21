#include "BattleShips.h"
#include<thread>


BattleShips::BattleShips()
{
}
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
	start();
}

//destructor

BattleShips::~BattleShips() {
	stop();
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

BattleShips::~BattleShips()
{
}
