#include "Quick.h"

using namespace std;

void Zamien(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int* Tab, int start, int koniec)
{
    int pivotvot = Tab[koniec];
    int i = (start - 1);

    for (int j = start; j <= koniec - 1; j++)
    {
        if (Tab[j] < pivotvot)
        {
            i++;
            Zamien(&Tab[i], &Tab[j]);
        }
    }
    Zamien(&Tab[i + 1], &Tab[koniec]);
    return (i + 1);
}

void qckSort(int Tab[], int start, int koniec)
{
    if (start < koniec)
    {

        int pivot = partition(Tab, start, koniec);


        qckSort(Tab, start, pivot - 1);
        qckSort(Tab, pivot + 1, koniec);
    }
}


template<typename Typ>
Typ* createTab(int size)
{
    Typ* Tab = new Typ[size];

    return Tab;
}

template<typename Typ>
void deleteTab(Typ* Tab)
{
    delete[] Tab;
}


template<typename Typ>
void fill_randomTab(Typ* Tab, int size)
{
    for (int i = 0; i < size; i++)
        Tab[i] = rand();
}

template<typename Typ>
void check_sortedTab(Typ* Tab, int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        if (Tab[i] > Tab[i + 1])
        {
            cout << "Array not sorted SORRY BRUH" << endl;
            cin.get();;
            exit(1);
        }

    }
}
