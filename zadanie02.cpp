#include <iostream>
#include <cstdlib>

using namespace std;

int metoda(const void* a, const void* b)
{
    int x = *(const int*)a;
    int y = *(const int*)b;

    // Sortowanie rosnąco liczb parzystych
    if (x % 2 == 0 && y % 2 == 0) //Sprawdzam czy obie liczby są parzyste
    {
        return x - y; //Sprawdzam która jest większa
    }
    // Sortowanie malejąco liczb nieparzystych
    else if (x % 2 != 0 && y % 2 != 0) //Sparwdzam czy obie liczby są nieparzyste
    {
        return y - x; //Sprawdzam która jest mniejsza
    }

    // Liczby parzyste są zawsze przed liczbami nieparzystymi
    else if (x % 2 == 0) //Ustwaiam parzyste przed nieparzystymi
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int tablica[] = {1, 4, 7, 2, 5, 9, 2, 8};
    unsigned rozmiar = sizeof(tablica)/sizeof(tablica[0]);
    qsort(tablica, rozmiar, sizeof(int), metoda);
    cout << "Posortowana Tablica: ";
    for(int i = 0; i < rozmiar; i++)
    {
        cout << tablica[i] << " ";
    }
    cout << endl;
    return 0;
}