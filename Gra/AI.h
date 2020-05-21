#pragma once
#include "Gracz.h"
#include <climits>
#include <algorithm>
class AI : public Player
{
public:
	AI() = default;
	AI(char sign);
	void move(Board & b);


private:
	int minimax(Board& b, int depth, bool isMaximizing);
	//void move(Board& b);

};

AI::AI(char sign) : Player(sign)
{
}

//void AI::move(Board& b)
//{
//	BestMove(b);
//}

void AI::move(Board& b)
{
	std::pair<int, int> move;
	int bestScore = -INT_MAX;
	for (int i = 0; i < b.GetSize(); i++)
	{
		for (int j = 0; j < b.GetSize(); j++)
		{
			if (b.GetSquare()[i][j] == ' ')
			{
				b.PutOnBoard(i, j, GetSign());
				int score = minimax(b, 0, false);
				b.PutOnBoard(i, j, ' ');
				if (score > bestScore)
				{
					bestScore = score;
					move = std::make_pair(i,j);
				}
			}
		}
	}
	b.PutOnBoard(move.first, move.second, GetSign());
}



int AI::minimax(Board& b, int depth, bool isMaximizing)
{
	if (isMaximizing)
	{
		int bestScore = -INT_MAX;
		for (int i = 0; i < b.GetSize(); i++)
		{
			for (int j = 0; j < b.GetSize(); j++)
			{
				if (b.GetSquare()[i][j] == ' ')
				{
					b.PutOnBoard(i, j, GetSign());
					int score = minimax(b, depth + 1, false);
					b.PutOnBoard(i, j, ' ');
					bestScore = std::max(score, bestScore);
					
				}
			}
		}
		return bestScore;
	}
	else
	{
		int bestScore = INT_MAX;
		for (int i = 0; i < b.GetSize(); i++)
		{
			for (int j = 0; j < b.GetSize(); j++)
			{
				if (b.GetSquare()[i][j] == ' ')
				{
					b.PutOnBoard(i, j, GetSign());
					int score = minimax(b, depth + 1, true);
					b.PutOnBoard(i, j, ' ');
					bestScore = std::min(score, bestScore);
				}
			}
		}
		return bestScore;
	}
}