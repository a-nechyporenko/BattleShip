#pragma once
class Player {
	enum direction { horisontal, vertical };
public:
	bool defeat_flag;
	int hits[10][10];
	int ships[10][10];
	char numbers[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	char lete[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
private:
	void ships_init(); //��������� � ������ ships ��������
	void set(int deck); // ��������� �� ���� ���� ������� / deck - ���������� �����
	int place_ship(int x, int y, direction dir, int deck); // ���������, �������� �� ����������� ������� ������
	~Player();
};

