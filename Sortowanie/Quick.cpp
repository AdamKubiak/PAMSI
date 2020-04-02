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

