#pragma once
#include "Gracz.h"
#include "AI.h"
#include "Plansza.h"
class Game
{
public:
	Game(int size, int matchPoint);
	void StartGame(int choice, bool current);

private:
	Board board;
	Player player1;
	Player player2;
	AI AIplayer;
};

Game::Game(int size, int matchPoint) :board(size, matchPoint), player1('X'), player2('O'), AIplayer('O')
{
	
}

void Game::StartGame(int choice,bool current)
{
	
	bool EndGame = true;

	//bool current = false;


	while (EndGame)
	{
		std::cout << "TIC TAC TOE!!!!" << std::endl;
		board.PrintBoard();
		if (current == true)
			player1.move(board);
		else
		{
			if (choice == 1)
				AIplayer.move(board);
			else
				player2.move(board);
		}
		system("CLS");
		if (board.CheckWinnerUltimate() == 1)
		{
			std::cout << "Player X won" << std::endl;
			board.PrintBoard();
			EndGame = false;
			
		}
		else if (board.CheckWinnerUltimate() == -1)
		{
			std::cout << "Player O won" << std::endl;
			board.PrintBoard();
			EndGame = false;
		}
		else if (board.CheckFull() && board.CheckWinnerUltimate() != -1 && board.CheckWinnerUltimate() != 1) {
			std::cout << "TIE" << std::endl;
			board.PrintBoard();
			EndGame = false;
		}
		if (current == true)
			current = false;
		else
			current = true;
	}
}