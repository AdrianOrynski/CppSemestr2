#include <iostream>
#include <cmath>

using namespace std;

long double Licz_Ti_metodaA(int n)
{
    long double ti;
    if (n == 0)
    {
        ti = (long double)1/ sqrt(3);
    }
    else
    {
        ti = (sqrt((pow(Licz_Ti_metodaA(n-1),2) + 1)) - 1)/ Licz_Ti_metodaA(n-1);
    }
    return ti;
}

long double Licz_Ti_metodaB(int n)
{
    long double ti;
    if (n == 0)
    {
        ti = (long double)1/ sqrt(3);
    }
    else
    {
        ti = Licz_Ti_metodaA(n-1)/(sqrt((pow(Licz_Ti_metodaB(n-1),2) + 1)) + 1);
    }
    return ti;
}

int main()
{
    long double MetodaA;
    long double MetodaB;
    for(int i = 0; i <= 30; i++)
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
