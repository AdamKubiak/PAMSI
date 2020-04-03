#include <iostream>
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
double Percentage[7] = {0, 25.0 ,50.0 ,75.0 ,95.0 ,99.0, 99.7 };




int main()
{
	const int choice = 0;
	while (choice != 4)

	{
		cout << endl;
		const int choice = menu();
		for (double b : Percentage)
		{
			cout << endl;
			cout << "Tablica posortowana wczesniej w " << b << " %" << endl;
			cout << "------------------------------------" << endl;
			for (int a : Size) //for-each, przypisuje do zmiennej a kolejno wartosci tablicy Size
			{
				//DataType* Array = new DataType[a];// glowna tablica

				Duration = 0;
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

					if (check_sortedTab<DataType>(Array, a) == 1) {};
					cout << i << '%' << '\r';

					auto duration = duration_cast<milliseconds>(stop - start);

					Duration += (double)duration.count();
					delete[] Array;
				}


				cout << "Zostalo posortowane " << number_ofTabs << " tablic o rozmiarze " << a << " czas sortowania pojedynczej tablicy wynosi " << Duration / number_ofTabs << " ms" << endl;



			}
		}
	}
	return 0;
}