#pragma once
#include <fstream>
#include "Quick.h"
using namespace std;

ofstream quick, merge, intro;

void writeToFile(double percentage,int size, double duration, double min, double max, int a)
{
	
	switch (a)
	{
	case 1:
		quick << percentage << "; " << size << "; " << duration << "; " << max << "; " << min << std::endl;
		break;
	case 2:
		merge << percentage << "; " << size << "; " << duration << "; " << max << "; " << min << std::endl;
		break;
	case 3:
		intro << percentage << "; " << size << "; " << duration << "; " << max << "; " << min << std::endl;
		break;
	}
}

void NameFile(int a)
{
	switch (a)
	{
	case 1:
		quick.open("quick.txt", std::ios::out);
		quick << "percentage sorted; size; average time; max; min \n";
		break;
	case 2:
		merge.open("merge.txt", std::ios::out);
		merge << "percentage sorted; size; average time; max; min \n";
		break;
	case 3:
		intro.open("intro.txt", std::ios::out);
		intro << "percentage sorted; size; average time; max; min \n";
		break;
	}
}


template<typename T>
bool check_sortedTab(T* Tab, int size)
{

	for (int i = 0; i < size - 1; i++)
	{
		if (Tab[i] > Tab[i + 1])
		{
			cout << "Array not sorted, something went wrong" << endl;
			exit(1);

		}

	}
	return true;
}



template<typename T>
T* NewArray(int size, double percentage)
{
	T* Tab = new T[size];

	if (percentage!=100 && percentage != 0)
	{
		for (int i = 0; i < size * percentage * 0.01; ++i)
		{
			Tab[i] = T(i);
		}

		for (int i = int(size * percentage * 0.01); i < size; ++i)
		{
			Tab[i] = T(rand());
		}
		return Tab;
	}
	
	if (percentage == 100)
	{
		for (int i = 0; i < size; i++)
			Tab[i] = T(rand());

		ReverseQuickSort(Tab, 0, size - 1);
		return Tab;
	}

	if (!percentage)
	{
		for (int i = 0; i < size; i++)
			Tab[i] = T(rand());

		return Tab;
	}
	return 0;
}

int menu()
{
	int Arg;
	bool check = false;
	cout << "Wybierz algorytm sortowania wpisujac przypisana cyfre do danego algorytmu:" << endl;
	cout << "1. Quicksort" << endl;
	cout << "2. Mergesort" << endl;
	cout << "3. Introsort" << endl;
	cout << "4. Konczy dzialanie programu" << endl;
	cin >> Arg;
	
	if (Arg == 4)
		exit(1);

	while (cin.fail())
	{
		cout << "Blad wpisz ponownie" << endl;
		cin.clear();
		cin.ignore(1000000, '\n');
		cin >> Arg;
	}

	while (check == false)
	{
		if (Arg == 1 || Arg == 2 || Arg == 3)
			check = true;
		else
		{
			cout << "Blad wpisz ponownie" << endl;
			cin.ignore(1000000, '\n');
			cin >> Arg;
		}
	}

	return Arg;
}