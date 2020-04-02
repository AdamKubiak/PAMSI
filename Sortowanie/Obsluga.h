#pragma once
using namespace std;






template<typename Typ>
bool check_sortedTab(Typ* Tab, int size)
{

	for (int i = 0; i < size - 1; i++)
	{
		if (Tab[i] > Tab[i + 1])
		{
			cout << "Array not sorted, something went wrong" << endl;
			return false;

		}

	}
	return true;
}



template<typename Typ>
Typ* NewArray(int size, double percentage)
{
	Typ* Tab = new Typ[size];

	if (percentage)
	{
		for (int i = 0; i < size * percentage * 0.01; ++i)
		{
			Tab[i] = i;
		}

		for (int i = int(size * percentage * 0.01); i < size; ++i)
		{
			Tab[i] = rand();
		}
		return Tab;
	}

	if (!percentage)
	{
		for (int i = 0; i < size; i++)
			Tab[i] = rand();

		return Tab;
	}
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
		return Arg;

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