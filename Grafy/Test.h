#pragma once
#include "ListGraph.h"
#include "MatrixGraph.h"
#include <fstream>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;
class Test
{
private:
	std::ofstream List, Matrix;
	ListGraph* g = new ListGraph();
	MatrixGraph* g2 = new MatrixGraph();
public:
	int choice;
	void writeToFile(int size, double density, double duration);
	void openFile();
	void TestDijkstra();
	Test() {};

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
	const int number_ofGraphs = 100; //tutaj ustalamy ile chcemy kopii tablicy danego rozmiaru
	long size[5] = { 10, 30, 50, 70, 100 }; //rozmiary tablic
	double Duration = 0;   //suma czasu pojedynczych operacji 
	double density[4] = {0.25 ,0.50 ,0.75 ,1 };
	openFile();
	while (choice != 3)
	{
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
					if (choice == 1)
						g->GenerateRandomGraph(a, b);
					else
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
					//cout << i << '%' << '\r';


					auto duration = duration_cast<milliseconds>(stop - start);



					Duration += (double)duration.count();
					if (choice == 1)
						delete g;
					else
						delete g2;
				}
				writeToFile(a, b, Duration / number_ofGraphs * 0.001);

				cout << "Algorytm Dijkstry zostal wykonany dla " << number_ofGraphs << " grafow z  " << a << "wierzcholkami" << " sredni czas wykonania algorytmu wynosi: " << Duration / number_ofGraphs * 0.001 << " s" << endl;



			}
		}
	}
}

