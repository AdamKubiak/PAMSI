#pragma once
#include <iostream>

int menu()
{
	int Arg;
	bool check = false;
	std::cout << "Wybierz algorytm szukania najkrotszej sciezki wpisujac przypisana cyfre do algorytmu:" << std::endl;
	std::cout << "1. Dijkstra dla Listy Sasiedztwa" << std::endl;
	std::cout << "2. Dijkstra dla Macierzy Sasiedztwa" << std::endl;
	std::cout << "3. Konczy dzialanie programu" << std::endl;
	std::cin >> Arg;

	if (Arg == 3)
		exit(1);

	while (std::cin.fail())
	{
		std::cout << "Blad wpisz ponownie" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000000, '\n');
		std::cin >> Arg;
	}

	while (check == false)
	{
		if (Arg == 1 || Arg == 2)
			check = true;
		else
		{
			std::cout << "Blad wpisz ponownie" << std::endl;
			std::cin.ignore(1000000, '\n');
			std::cin >> Arg;
		}
	}

	return Arg;
}