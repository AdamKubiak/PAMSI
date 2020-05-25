#include "Plansza.h"
#include "Gracz.h"
#include "AI.h"
#include "Rozgrywka.h"
#include <stdlib.h>
#include<chrono>
#include <thread>

int main()
{
	/*Board b(3,3);
	Player p1('X');
	AI p2('O');
	int k = 1;

	bool current = false;


	while (k == 1)
	{
		std::cout << "TIC TAC TOE!!!!" << std::endl;
		b.PrintBoard();
		if (current == true)
			p1.move(b);
		else
			p2.move(b);
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
	}*/
	int size = 0;
	bool choice2 = 1;
	int choice;
	int matchPoint = 0;
	bool playing = true;

	while (playing)
	{
		std::cout << "Wybierz tryb gry: "<< std::endl;
		std::cout << "1. Tryb jednoosobowy" << std::endl;
		std::cout << "2. Tryb dla dwoch graczy" << std::endl;
		std::cin >> choice;
		while (std::cin.fail())
		{
			std::cout << "Blad wpisz ponownie" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000000, '\n');
			std::cin >> choice;
		}
		std::cout << "Podaj wymiar tablicy: ";
		std::cin >> size;
		while (std::cin.fail())
		{
			std::cout << "Blad wpisz ponownie" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000000, '\n');
			std::cin >> size;
		}
		std::cout << "Liczba potrzebnych znakow w rzedzie do wygranej: ";
		std::cin >> matchPoint;
		while (std::cin.fail())
		{
			std::cout << "Blad wpisz ponownie" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000000, '\n');
			std::cin >> matchPoint;
		}

		if (choice == 1)
		{
			std::cout << "0 - zaczyna AI" << std::endl << "1- zaczyna gracz " << std::endl;
			std::cin >> choice2;
			while (std::cin.fail())
			{
				std::cout << "Blad wpisz ponownie" << std::endl;
				std::cin.clear();
				std::cin.ignore(1000000, '\n');
				std::cin >> matchPoint;
			}
		}
		system("CLS");
		Game g(size, matchPoint);
		g.StartGame(choice, choice2);

		std::cout << "Chcesz zagrac jeszcze raz? 0 - nie ;;; 1 - tak ";
		std::cin >> playing;

	}
	
	return 0;
}