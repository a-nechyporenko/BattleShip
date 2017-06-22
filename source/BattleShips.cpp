#include "BattleShips.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include"Enum.h"
#include<thread>

//pause
void BattleShips::start(){
	if (mState != MachinState::start) {
		mState = MachinState::start;
		std::thread thr(&BattleShips::mStepState, this);
		thr.detach();
	}
}

void BattleShips::stop(){
	mState = MachinState::stop;
}

//constructor 

BattleShips::BattleShips() 
					: mStepState(StepState::Human)
					, mState(MachinState::undefined)
{
	human.message = 0;
	e = 0;
	BattleShips::start();
}

bool BattleShips::turnHuman(int character, int digit)
{
	setlocale(LC_CTYPE, "Russian");
	
	//bool e = false;
	if ((human.hits[digit][character] == 1) || (human.hits[digit][character] == 2))
	{
		std::cout << "�� ���� ��� ��������! ������� ��� ���...";
		return true;
	}
	else
	{
		human.countShots++;
		if (computer.ships[digit][character] == 1)
		{
			human.hits[digit][character] = 1;
			std::cout << "���������!)))";
			return false;
		}
		else if (computer.ships[digit][character] == 2)
		{
			human.hits[digit][character] = 2;
			computer.ships[digit][character] = 3;
			std::cout << "������!((( ������ ��� ���...";
			human.scoreCounter++;
			return true;
		}
	}
	//return e;
}

bool BattleShips::turnComputer()
{
	bool e = false;
	while (e == false)
	{
		int digit = rand() % 10;
		int character = rand() % 10;
		if (computer.hits[digit][character] == 1) return false;
		else
		{
			computer.countShots++;
			if (human.ships[digit][character] == 1)
			{
				computer.hits[digit][character] = 1;
				human.ships[digit][character] = 3;
				return true;
			}
			else if (human.ships[digit][character] == 2)
			{
				computer.hits[digit][character] = 1;
				human.ships[digit][character] = 4;
				computer.scoreCounter++;
				return false;
			}
		}
	}
	return false;
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
	while (mState == MachinState::start) {
		switch (mStepState) {				//change color
		case StepState::Human:

			mStepState = StepState::Computer;
			break;
		case StepState::Computer:

			mStepState = StepState::Human;
			break;

		}
	}
}
//destructor
BattleShips::~BattleShips() {
	BattleShips::stop();
}
void BattleShips::mapInit()
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
void BattleShips::scoreCounter() {
	std::cout << std::endl;
	std::cout << "______________________________����������_____________________________________________________________" << std::endl;
	std::cout << "���� ���������� ���������: " << human.countShots << " �� ��� ���������: " << human.scoreCounter << std::endl;
	std::cout << "��������� ���������: " << computer.countShots << " �� ��� ���������: " << computer.scoreCounter << std::endl;
}
void BattleShips::gameUpdate() {
	setlocale(LC_CTYPE, "Russian");
		srand(static_cast<unsigned int>(time(NULL)));
		int user_input = 0;
		system("cls");
		mapInit();
		Fild::showMas();
		int character, digit;
		do {
			do {
				system("cls");
				Fild::showMas();
				if (human.message == 1) //Message code 1 - an invalid value was entered
				{
					std::cout << "�� ����� �������� ��������!\n";
				}
				human.message = 0;
				user_input = human.input(character, digit, human.message);
		
				if (user_input == 1)
				{
					human.message = 1;
				}
			} while (user_input != 0);
		 
				e = turnHuman(character, digit);
				system("cls");
				Fild::showMas();
		 } while (e);
			e = turnComputer();
			system("cls");
			Fild::showMas();
			_getch();
		human.message = BattleShips::checkEnd();
		scoreCounter();
	_getch();
}
void BattleShips::Win() {
	if (human.defeat_flag == 1) { "\n\n\n\n\n\n\t\t\t\Your loose!\n"; }
	if (computer.defeat_flag == 1) { "\n\n\n\n\n\n\t\t\t\Win!\n"; }
}