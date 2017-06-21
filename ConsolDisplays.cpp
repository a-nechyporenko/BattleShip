#include "ConsolDisplays.h"
#include<iostream>



ConsolDisplays::ConsolDisplays(){
}
void show()
{
	for (int i = 0; i<9; i++)
	{
		for (int j = 0; j< 9; j++)
		{
			//std::cout << map[i][j];
		}
		std::cout << "\n";
	}
}

ConsolDisplays::~ConsolDisplays(){
}
