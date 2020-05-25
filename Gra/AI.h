#pragma once
#include "Gracz.h"
#include <climits>
#include <ctime>
#include <algorithm>
class AI : public Player
{
public:
    AI() = default;
    AI(char sign);
    void BestMove(Board& b);


private:
    int minimax(Board& b, int depth, int isMaximizing);

    void move(Board& b);

};

AI::AI(char sign) : Player(sign)
{
}
 
void AI::move(Board& b)
{
    BestMove(b);
}
void  AI::BestMove(Board& b) {
    // AI to make its turn
    int bestScore = -INT_MAX;
    std::pair<int, int> move;
    for (int i = 0; i < b.GetSize(); i++) {
        for (int j = 0; j < b.GetSize(); j++) {
            if (b.CheckIfEmpty(i, j)) {
                b.PutOnBoard(i, j, GetSign());
                int score = minimax(b, 0, false);
                b.PutOnBoard(i, j, ' ');
                if (score > bestScore) {
                    bestScore = score;
                    move = std::make_pair(i, j);
                }
            }
        }
    }
    b.PutOnBoard(move.first, move.second, GetSign());
}


int AI::minimax(Board& b, int depth, int isMaximizing)
{

    int result = b.CheckWinnerUltimate();
    if (result == 1)
        return -10+depth;
    else if (result == -1)
        return 10-depth;
    else if (b.CheckFull())
        return 0;

    if (isMaximizing) {
        int bestScore = -INT_MAX;
        for (int i = 0; i < b.GetSize(); i++) {
            for (int j = 0; j < b.GetSize(); j++) {
                if (b.CheckIfEmpty(i, j)) {
                    b.PutOnBoard(i, j, GetSign());
                    int score = minimax(b, depth + 1, false);
                    b.PutOnBoard(i, j, ' ');
                    bestScore = std::max(score, bestScore);
                }
            }
        }
        return bestScore;
    }
    else {
        int bestScore = INT_MAX;
        for (int i = 0; i < b.GetSize(); i++) {
            for (int j = 0; j < b.GetSize(); j++) {
                if (b.CheckIfEmpty(i, j)) {
                    b.PutOnBoard(i, j, 'X');
                    int score = minimax(b, depth + 1, true);
                    b.PutOnBoard(i, j, ' ');
                    bestScore = std::min(score, bestScore);
                }
            }
        }
        return bestScore;
    }
}