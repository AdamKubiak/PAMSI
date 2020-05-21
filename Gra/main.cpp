#include "Plansza.h"
#include "Gracz.h"
#include "AI.h"
#include <stdlib.h>
#include<chrono>
#include <thread>

int main()
{
	Board b(3,3);
	Player p1('X');
	AI p2('O');
	

	bool current = false;


	while (1)
	{
		std::cout << "TIC TAC TOE!!!!" << std::endl;
		b.PrintBoard();
		if (current == true)
			p1.move(b);
		else
			p2.BestMove(b);
		system("CLS");
		if (b.CheckWinnerUltimate() == 1)
		{
			std::cout << "Player X won" << std::endl;
			return 0;
		}
		else if (b.CheckWinnerUltimate() == -1)
		{
			std::cout << "Player O won" << std::endl;
			return 0;
		}
		else if (b.CheckFull())
			return 0;
		if (current == true)
			current = false;
		else
			current = true;
	}

}