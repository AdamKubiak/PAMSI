#pragma once
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "Obsluga.h"
#include <fstream>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;
class Test
{
private:
	std::ofstream List, Matrix;
	
public:
	int choice;
	void writeToFile(int size, double density, double duration);
	void openFile();
	void TestDijkstra();
	Test():choice(0)
	{};

};

void Test::writeToFile(int size, double density, double duration)
{
	switch (choice)
	{
	case 1:
		List << size << "; " << density << "; " << duration << std::endl;
		break;
	case 2:
		Matrix << size << "; " << density << "; " << duration << std::endl;
		break;
    }
}

void Test::openFile()
{
	switch (choice)
	{
	case 1:
		List.open("List.txt", std::ios::out);
		List << "size; density; duration \n";
		break;
	case 2:
		Matrix.open("Matrix.txt", std::ios::out);
		Matrix << "size; density; duration \n";
		break;
	}
}

void Test::TestDijkstra()
{
	const int number_ofGraphs = 2; //tutaj ustalamy ile chcemy kopii tablicy danego rozmiaru
	long size[5] = { 10, 50, 100, 150, 200 }; //rozmiary tablic
	double Duration = 0;   //suma czasu pojedynczych operacji 
	double density[4] = {0.25 ,0.50 ,0.75 ,1 };
	

	while (choice != 3)
	{

		choice = menu();
		openFile();

		for (double b : density)
		{
			std::cout << std::endl;

			cout << "Gestosc grafu " << b * 100 << " %" << std::endl;
			cout << "------------------------------------" << std::endl;


			for (int a : size) //for-each, przypisuje do zmiennej a kolejno wartosci tablicy Size
			{
				

				Duration = 0;
				for (int i = 0; i < number_ofGraphs; i++)
				{
					ListGraph* g = new ListGraph();
					MatrixGraph* g2 = new MatrixGraph();

					if (choice == 1)
						g->GenerateRandomGraph(a, b);
					if(choice == 2)
						g2->GenerateRandomGraph(a, b);
					
					


					auto start = high_resolution_clock::now();

					switch (choice)
					{
					case 1:
						g->dijkstra();
						break;

					case 2:
						g2->dijkstra();
						break;
					}

					auto stop = high_resolution_clock::now();
					cout << i+1 << '%' << '\r';

					auto duration = duration_cast<microseconds>(stop - start);



					Duration += (double)duration.count();
					if (choice == 1)
						delete g;
					else
						delete g2;
				}
				writeToFile(a, b, Duration / number_ofGraphs);

				cout << "Algorytm Dijkstry zostal wykonany dla " << number_ofGraphs << " grafow z  " << a << " wierzcholkami" << " sredni czas wykonania algorytmu wynosi: " << Duration / number_ofGraphs << " microsec" << endl;



			}
		}
	}
}

