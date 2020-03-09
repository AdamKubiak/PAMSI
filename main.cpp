#include "Quick.h"
#include "Quick.cpp"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
#define TypDanych int





template<typename Typ>
Typ* percentSort(Typ* Tab, double percent)
{

}



int main()
{
	double Duration=0;
	int number_ofTabs = 100;
	int Size[5] = { 10000, 50000, 100000, 500000, 1000000 }; //rozmiary tablic
	double percentTab[8] = { 0, 25, 50, 75, 95, 99, 99.7, 100 }; //procent w jakim tablice sa poprzednie posortowane
	for (int a : Size)
	{
		TypDanych* Array = createTab<TypDanych>(a);// glowna tablica
		TypDanych* TempArray = createTab<TypDanych>(a); // tablica na ktorej bedzie sortowanie czastkowe
		
		for (int i = 0; i < number_ofTabs; i++)
		{
			
			fill_randomTab<TypDanych>(Array, a);
			auto start = high_resolution_clock::now();
			qckSort(Array, 0, a-1);
			auto stop = high_resolution_clock::now();
			check_sortedTab<TypDanych>(Array, a);
			cout << i << '%'<< '\r';
			
			auto duration = duration_cast<milliseconds>(stop - start);
			Duration += (double)duration.count();
		}

		cout << "Zostalo posortowane " << number_ofTabs << " tablic o rozmiarze " << a << " czas sortowania pojedynczej tablicy wynosi " << Duration/number_ofTabs << " ms"<< endl;
		deleteTab<TypDanych>(Array);
		deleteTab<TypDanych>(TempArray);
	}
	return 0;
}