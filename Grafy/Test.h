#pragma once
#include "ListGraph.h"
#include "MatrixGraph.h"
#include <fstream>
#include <chrono>
#include <iostream>
class Test
{
private:
	
public:
	int choice;
	void writeToFile(int size, double density, double duration, int a);
	int menu();
	Test() {};
};

void Test::writeToFile(int size, double density, double duration, int a)
{
	std::ofstream file;

	switch (a)
	{
	case 1:
		file.open("List.txt", std::ios::out);
		file << size << "; " << density << "; " << duration << std::endl;
		break;
	case 2:
		file.open("Matrix.txt", std::ios::out);
		file << size << "; " << density << "; " << duration << std::endl;
		break;
    }
}


