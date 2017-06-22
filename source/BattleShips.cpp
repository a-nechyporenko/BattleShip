#include "BattleShips.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include"Enum.h"
#include<thread>

//pause
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
	human.message = 0;
	e = 0;
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
//destructor
BattleShips::~BattleShips() {
	BattleShips::stop();
}
void BattleShips::map_init()
{
	for (int i = 0; i<10; i++)
		for (int j = 0; j<10; j++)
		{
			if (human.ships[i][j] == 1)
			{
				map[2 + 2 * i][5 + 2 * j] = ' ';
			}
			else if (human.ships[i][j] == 2)
			{
				map[2 + 2 * i][5 + 2 * j] = 2;
			}
			else if (human.ships[i][j] == 3)
			{
				map[2 + 2 * i][5 + 2 * j] = '.';
			}
			else if (human.ships[i][j] == 4)
			{
				map[2 + 2 * i][5 + 2 * j] = 'X';
			}
			////////////////////////
			if (human.hits[i][j] == 0)
			{
				map[2 + 2 * i][41 + 2 * j] = ' ';
			}
			else if (human.hits[i][j] == 1)
			{
				map[2 + 2 * i][41 + 2 * j] = '.';
			}
			else if (human.hits[i][j] == 2)
			{
				map[2 + 2 * i][41 + 2 * j] = 'X';
			}
		}
}
bool BattleShips::gameOver() {
	if (checkEnd() == 2) {
		system("cls");

		return false; 
	}
	else return true;
	
}

void BattleShips::gameUpdate() {
	setlocale(LC_CTYPE, "Russian");
		srand(static_cast<unsigned int>(time(NULL)));
		int user_input = 0;
		system("cls");
		map_init();
		Fild::showMas();
		if (human.message == 1) //Message code 1 - an invalid value was entered
		{ 
			std::cout << "Вы ввели неверное значение!\n";
		}
		human.message = 0;
		int character, digit;
		user_input = human.input(character, digit,human.message);
		if (user_input == 1)
		{
			human.message = 1;
		}
		e = turnHuman(character, digit);
		if (e == 1) {
			e = turnComputer();
		}
		if (human.defeat_flag == 1) { "\n\n\n\n\n\n\t\t\t\Your loose!\n"; }
		if (computer.defeat_flag == 1) { "\n\n\n\n\n\n\t\t\t\Win!\n"; }
		human.message = BattleShips::checkEnd();
	_getch();
}