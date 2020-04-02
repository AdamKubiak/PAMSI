#pragma once

void Swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int* Tab, int start, int end)
{
    int pivotvot = Tab[end];
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++)
    {
        if (Tab[j] < pivotvot)
        {
            i++;
            Swap(&Tab[i], &Tab[j]);
        }
    }
    Swap(&Tab[i + 1], &Tab[end]);
    return (i + 1);
}

void quickSort(int Tab[], int start, int end)
{
    if (start < end)
    {

        int pivot = partition(Tab, start, end);


        quickSort(Tab, start, pivot - 1);
        quickSort(Tab, pivot + 1, end);
    }
}