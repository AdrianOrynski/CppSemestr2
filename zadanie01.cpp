#include <iostream>

using namespace std;

int suma(const int tab[], unsigned size)
{
    int wynik = 0;
    for (unsigned i = 0; i < size; i++) //Korzystanie z unsigned jest zalecane do iteracji po tablicach ponieważ nie trzeba sprawdzać znaku indeksu
    {
        wynik += tab[i];
    }
    return wynik;
}

void sumaw(const int tab[], unsigned size, int* result)
{
    *result = 0;
    for (unsigned i = 0; i < size; i++)
    {
        *result += tab[i];
    }
}

void pisz(const int* tab, size_t size, ostream * out) //size_t typ danych który przechowuje informacje o rozmiarze
{
    for (size_t i = 0; i < size; i++)
    {
        *out << tab[i] << " ";
    }
    *out << endl;
}

void iota(int tab[], size_t size)
{
    for (unsigned i = 0; i < size; i++)
    {
        tab[i] = i;
    }
}

void revers(int* tab, size_t size)
{
    for (size_t i = 0; i < size / 2; ++i)
    {
        swap(tab[i], tab[size - i - 1]); //swap zamienia elementy w tablicy
    }
}

int dot_product(const int* tab1 , const int* tab2, size_t size)
{
    int wynik = 0;
    for (size_t i = 0; i < size; i++)
    {
        wynik += tab1[i] * tab2[i];
    }
    return wynik;
}

int main()
{
    int tab[] = {1, 2, 3, 4, 5};
    unsigned size = sizeof(tab)/sizeof(tab[0]);

    //Podpunkt a
    cout << "Podpunkt a) Suma = " << suma(tab, size) << endl;

    //Podpunkt b
    int wynik;
    sumaw(tab, size, &wynik);
    cout << "Podpunkt b) Suma = " << wynik << endl;

    //Podpunkt c
    cout << "Podpunkt c) ";
    pisz(tab, size, &cout);

    //Podpunkt d
    int tabd[5];
    unsigned sized = sizeof(tabd)/sizeof(tabd[0]);
    cout << "Podpunkt d) ";
    iota(tabd, sized);
    pisz(tabd, sized, &cout);

    //Podpunkt e
    int tabe[] = {1, 2, 3, 4, 5};
    unsigned sizee = sizeof(tabe)/sizeof(tabe[0]);
    cout << "Podpunkt e) ";
    revers(tabe, sizee);
    pisz(tabe, sizee, &cout);

    //Podpunkt f
    int tab1[] = {1, 2, 3, 4, 5};
    int tab2[] = {5, 4, 3, 2, 1};
    unsigned sizef = sizeof(tab1)/sizeof(tab1[0]);
    cout << "Podpunkt f) Iloczyn Skalarny = " << dot_product(tab1, tab2, sizef) << endl;

    return 0;
}
