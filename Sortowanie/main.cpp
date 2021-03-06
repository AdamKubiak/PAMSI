﻿#include <iostream>
#include <chrono>
#include "Quick.h"
#include "Merge.h"
#include "Intro.h"
#include "Obsluga.h"


using namespace std;
using namespace std::chrono;

#define DataType int
#define number_ofTabs 100 //tutaj ustalamy ile chcemy kopii tablicy danego rozmiaru
long Size[5] = { 10000, 50000, 100000, 500000, 1000000 }; //rozmiary tablic
double Duration = 0;   //suma czasu pojedynczych operacji 
std::chrono::duration<double, std::milli> min, max;
double Percentage[8] = {0, 25.0 ,50.0 ,75.0 ,95.0 ,99.0, 99.7,100};

int main()
{
	
	const int choice = 0;
	while (choice != 4)

	{
		cout << endl;
		const int choice = menu();
		NameFile(choice);
		for (double b : Percentage)
		{
			cout << endl;
			if (b != 100)
			{
				cout << "Tablica posortowana wczesniej w " << b << " %" << endl;
				cout << "------------------------------------" << endl;
			}
			else
			{
				cout << "Tablica posortowana w odwrotnej kolejnosci" << endl;
				cout << "------------------------------------" << endl;
			}
			for (int a : Size) //for-each, przypisuje do zmiennej a kolejno wartosci tablicy Size
			{

				Duration = 0;
				min = min.max();
				max = max.zero();
				for (int i = 0; i < number_ofTabs; i++)
				{
					DataType* Array = NewArray<DataType>(a, b);
					//fill_randomTab<DataType>(Array, a);


					auto start = high_resolution_clock::now();

					switch (choice)
					{
					case 1:
						quickSort(Array, 0, a - 1);
						break;

					case 2:
						MergeSort(Array, 0, a - 1);
						break;
					case 3:
						IntroSort(Array, 0, a - 1);
						break;
					}

					auto stop = high_resolution_clock::now();

					if (check_sortedTab<DataType>(Array, a) == 1) {
						
						cout << i << '%' << '\r';
					}

					auto duration = duration_cast<milliseconds>(stop - start);

					if (std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) >
						max) {
						max = std::chrono::duration_cast<std::chrono::milliseconds>(stop -
							start);
					}
					if (std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) <
						min) {
						min = std::chrono::duration_cast<std::chrono::milliseconds>(stop -
							start);
					}

					Duration += (double)duration.count();
					delete[] Array;
				}
				writeToFile(b, a, Duration / number_ofTabs * 0.001, double(min.count() * 0.001) , double(max.count() * 0.001),choice);

				cout << "Zostalo posortowane " << number_ofTabs << " tablic o rozmiarze " << a << " czas sortowania pojedynczej tablicy wynosi " << Duration / number_ofTabs* 0.001 << " s" << endl;



			}
		}
	}
	return 0;
}