#include <iostream>

using namespace std;

double downd(int n)
{
    double suma = 0;
    for(int i = 1; i <= n; i++ )
    {
        suma += 1.0/i;
    }
    return suma;
}

double upd(int n)
{
    double suma = 0;
    for(int i = n; i > 0; i-- )
    {
        suma += 1.0/i;
    }
    return suma;
}

float downf(int n)
{
    float suma = 0;
    for(int i = 1; i <= n; i++ )
    {
        suma += 1.0f/i;
    }
    return suma;
}

float upf(int n)
{
    float suma = 0;
    for(int i = n; i > 0; i-- )
    {
        suma += 1.0f/i;
    }
    return suma;
}

int main()
{
    cout << "Dla zmiennych double" << endl;
    cout << "Dla N = 100 Roznica Up(N) - Down(N) wynosi = " << upd(100) - downd(100) << endl;
    cout << "Dla N = 100 000 Roznica Up(N) - Down(N) wynosi = " << upd(100000) - downd(100000) << endl;
    cout << "Dla N = 100 000 000 Roznica Up(N) - Down(N) wynosi = " << upd(100000000) - downd(100000000) << endl;
    cout << "Dla zmiennych float" << endl;
    cout << "Dla N = 100 Roznica Up(N) - Down(N) wynosi = " << upf(100) - downf(100) << endl;
    cout << "Dla N = 100 000 Roznica Up(N) - Down(N) wynosi = " << upf(100000) - downf(100000) << endl;
    cout << "Dla N = 100 000 000 Roznica Up(N) - Down(N) wynosi = " << upf(100'000'000) - downf(100'000'000) << endl;
}
//Różnica między double i float jest taka że dla double dłużej wynik jest prawidłowy. Dla opcji Up osiągane są większe
//liczby, ale to metoda DOWN będzie miała większą dokładność ze względu że przy metodzie UP za zakres może wyjść liczba,
//która po zaokrągleniu będzie się sporo różnić od wyniku prawidłowego.
