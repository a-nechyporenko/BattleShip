#include <iostream>
#include <conio.h>
#include <thread>
#include <Windows.h>
#include <ctime>
#include <stdlib.h>
#include <clocale>
enum StepState { Human, Computer };
using namespace std;
//--------------Logic of the game -------------
class Player {
	
public:
	bool defeat_flag;
	int hits[10][10];
	int ships[10][10];

private:
	Player(){ defeat_flag = 0; }
	void ships_init(); //помещение в массив ships кораблей
	void set(int deck); // размещает на поле один корабль / deck - количество палуб
	int place_ship(int x, int y, StepState m_StepState, int deck); // проверяет, касается ли размещаемый корабль других
};

class HumanPlayer {
public:
	void map_init(); //Placing in the map array information about the player's ships
	void show();
	int input(int&, int&);//User input
	bool turn(int character, int digit); // Player progress
};

class ComputerPlayer {
public:
	bool turn(); // Computer progress
};
//-------Graphical composition of the game -----
class ConsolDisplays{

};

class Board{
};

class Menu{
};
//------------ Game constructor -----
class BattleShips {
	enum machinstate { undefined, start, stop };
public:
	BattleShips();
	void start();
	void stop();
	bool gameOver();
	void gameUpdate();
	int checkEnd();
	~BattleShips();
private:
	void controlState();
	void Draw();				
	machinstate m_State;
	StepState m_StepState;
};

void BattleShips::start() {
	if (m_State != machinstate::start) {
		m_State = machinstate::start;
		std::thread thr(&BattleShips::m_StepState, this);
		thr.detach();
	}
}

void BattleShips::stop() {
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


int main()
{
	BattleShips bs;

	while (!bs.gameOver()) {
		bs.gameUpdate();
	}
	return 0;
}