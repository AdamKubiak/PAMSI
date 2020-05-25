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
	int k = 1;

	bool current = true;


	while (k == 1)
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
			b.PrintBoard();
			std::cout <<std::endl<< "Chcesz zagrac jeszcze raz? 1-Tak;;; 0-Nie" << std::endl;
			std::cin >> k;
		}
		else if (b.CheckWinnerUltimate() == -1)
		{
			std::cout << "Player O won" << std::endl;
			b.PrintBoard();
			std::cout << std::endl << "Chcesz zagrac jeszcze raz? 1-Tak;;; 0-Nie" << std::endl;
			std::cin >> k;
		}
		else if (b.CheckFull()) {
			std::cout << "TIE" << std::endl;
			b.PrintBoard();
			std::cout << std::endl << "Chcesz zagrac jeszcze raz? 1-Tak;;; 0-Nie" << std::endl;
			std::cin >> k;
		}
		if (current == true)
			current = false;
		else
			current = true;
	}
	return 0;
}