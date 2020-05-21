#pragma once
#include <iostream>
#include <vector>

class Board
{
private:
	int BoardSize;
	std::vector<std::vector<char>> Squares;
	int MatchPoints;
public:
	Board() = default;
    Board(int size, int matchpoint);
	void PrintBoard();
    int GetSize();
    bool CheckIfEmpty(int inputx, int inputy);
    void PutOnBoard(int inputx, int inputy, char sign);
    ~Board() {};
    void printLines(int columns);
    void printNumbers(int columns);
    bool CheckWinnerHorizontally();
    bool CheckWinnerPerpendicularly();
    bool CheckWinnerDiagonally();
    bool CheckWinnerDiagonallyInverse();
    bool CheckFull();
    bool CheckWinnerUltimate();
    std::vector<std::vector<char>> GetSquare();
};

Board::Board(int size, int matchpoint) :BoardSize(size), MatchPoints(matchpoint)
{
    Squares.resize(BoardSize);
    for (int i = 0; i < BoardSize; i++)
    {
        Squares[i].resize(size, ' ');
    }
}

int Board::GetSize()
{
    return BoardSize;
}

std::vector<std::vector<char>> Board::GetSquare()
{
    return Squares;
}

bool Board::CheckIfEmpty(int inputx, int inputy)
{
    if (Squares[inputx][inputy] == ' ')
        return true;
    else
        return false;
}

bool Board::CheckWinnerHorizontally()
{
    int countX = 0;
    int countO = 0;
    for (int i = 0; i < BoardSize; i++)
    {
        for (int j = 0; j < BoardSize; j++)
        {
            if (Squares[i][j] == 'X')
            {
                countX++;
            }
            
            if (countX == MatchPoints)
            {
                //std::cout << "Wygral gracz ze znakiem: X" << std::endl;
                return true;
            }

            if (Squares[i][j] == 'O')
            {
                countO++;
            }

            if (countO == MatchPoints)
            {
                //std::cout << "Wygral gracz ze znakiem: O" << std::endl;
                return true;
            }
        }
        countX = 0;
        countO = 0;
    }
    return false;
}

bool Board::CheckWinnerPerpendicularly()
{
    int countX = 0;
    int countO = 0;

    for (int i = 0; i < BoardSize; i++)
    {
        for (int j = 0; j < BoardSize; j++)
        {
            if (Squares[j][i] == 'X')
            {
                countX++;
            }

            if (countX == MatchPoints)
            {
                //std::cout << "Wygral gracz ze znakiem: X" << std::endl;
                return true;
            }

            if (Squares[j][i] == 'O')
            {
                countO++;
            }

            if (countO == MatchPoints)
            {
                //std::cout << "Wygral gracz ze znakiem: O" << std::endl;
                return true;
            }
        }
        countX = 0;
        countO = 0;
    }
    return false;

}

bool Board::CheckWinnerDiagonally()
{
    int countX = 0; int countO = 0;
    int j = -1;

    for (int i = 0; i < BoardSize; i++)
    {
        j++;

        if (Squares[j][i] == 'X')
        {
            countX++;
        }

        if (countX == MatchPoints)
        {
            //std::cout << "Wygral gracz ze znakiem: X" << std::endl;
            return true;
        }

        if (Squares[j][i] == 'O')
        {
            countO++;
        }

        if (countO == MatchPoints)
        {
            //std::cout << "Wygral gracz ze znakiem: O" << std::endl;
            return true;
        }

    }
    return false;
}

bool Board::CheckWinnerDiagonallyInverse()
{
    int countX = 0; int countO = 0;
    int j = BoardSize;

    for (int i = 0; i < BoardSize; i++)
    {
        j--;

        if (Squares[i][j] == 'X')
        {
            countX++;
        }

        if (countX == MatchPoints)
        {
            //std::cout << "Wygral gracz ze znakiem: X" << std::endl;
            return true;
        }

        if (Squares[i][j] == 'O')
        {
            countO++;
        }

        if (countO == MatchPoints)
        {
            //std::cout << "Wygral gracz ze znakiem: O" << std::endl;
            return true;
        }

    }
    return false;
}

bool Board::CheckFull()
{
    for (int i = 0; i < BoardSize; ++i)
    {
        for (int j = 0; j < BoardSize; ++j)
        {
            if (Squares[i][j] == ' ') return false;
        }
    }
    return true;
}

bool Board::CheckWinnerUltimate()
{
    if (CheckWinnerDiagonally() == true || CheckWinnerDiagonallyInverse() == 1 || CheckWinnerHorizontally() == 1 || CheckWinnerPerpendicularly() == 1 || CheckFull() == 1)
    {
        if (CheckFull())
            //std::cout << "REMIS!!!" << std::endl;
        return true;
    }
    else
        return false;
}


void Board::PutOnBoard(int inputx, int inputy, char sign)
{
    Squares[inputx][inputy] = sign;
}

void Board::PrintBoard()
{
    printNumbers(BoardSize);
    printLines(BoardSize);
    for (int i = 0; i < BoardSize; i++)
    {
        std::cout << " " << i;
        for (int j = 0; j < BoardSize; j++)
        {
            std::cout << " | " << Squares[i][j];
        }
        std::cout << " | " << i <<std::endl;
        printLines(BoardSize);
    }
    printNumbers(BoardSize);
}

void Board::printLines(int columns)
{
    std::cout << "   ";
    for (int i = 0; i < columns; i++)
    {
       std:: cout << " ---";
    }
    std::cout << std::endl;
}

void Board::printNumbers(int columns)
{
    std::cout << "   ";
    for (int i = 0; i < columns; i++)
    {
        std::cout << "  " << i << " ";
    }
    std::cout << std::endl;
}

