#include <iostream>
#include <cmath>

using namespace std;

long double Licz_Ti_metodaA(int n)
{
    long double ti;
    if (n == 0)
    {
        ti = 1.0L/ sqrt(3.0L);
    }
    else
    {
        auto tmp = Licz_Ti_metodaA(n-1);
        ti = (sqrt(tmp * tmp  + 1.0L) - 1.0L) / tmp;
    }
    return ti;
}

long double Licz_Ti_metodaB(int n)
{
    long double ti;
    if (n == 0)
    {
        ti = 1.0L/ sqrt(3.0L);
    }
    else
    {
        auto tmp = Licz_Ti_metodaB(n-1);
        ti = tmp / (sqrt(tmp * tmp + 1.0) + 1.0);
    }
    return ti;
}

int main()
{
    long double MetodaA;
    long double MetodaB;
    cout.precision(10);
    for(int i = 0; i <= 40; i++)
    {
        long double tia = Licz_Ti_metodaA(i);
        long double tib = Licz_Ti_metodaB(i);
        MetodaA = 6 * pow(2, i) * tia;
        MetodaB = 6 * pow(2, i) * tib;
        cout << "Dla I = " << i << " Przyblizenie metoda A wynosi: " << MetodaA << endl;
        cout << "Dla I = " << i << " Przyblizenie metoda B wynosi: " << MetodaB << endl;
    }
    //Obserwując wyniki ciężko stwierdzić która z metod jest dokładniejsza ponieważ raz jedna oferuje dokładniejszy wynik
    //a innym razem ta druga. Jednak nie zawsze wzrost Iteratora powoduje wzrost dokładności
}
