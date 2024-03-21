#include <iostream>
#include <cmath>

double root(double (*f)(double), double a, double b, double tolerance = 1e-10)
{
    double fa = f(a);
    double fb = f(b);

    if (fa * fb > 0)
    {
        std::cout << "Brak zmiany znaku funkcji na końcach przedziału." << std::endl;
        return NAN; // NAN to "Not a Number", zwracam błąd
    }

    double c = 0.0; //Tworze liczbe c
    while ((b - a)/2 > tolerance) //dopóki połowa różnicy między b i a jest większa od tolerancji
    {
        c = (a + b)/2; //Ustawiam wartość c na sume a + b dzieloną na dwa
        double fc = f(c); //Obliczam wartość funkcji w punkcie c przez wskaźnik na przekazaną funkcję
        if (fc == 0) //Jeżeli wartość funkcji jest równa 0
        {
            return c; //Zwracam wartość dla której funkcja przyjmuje wartość 0
        }
        else if (fa * fc < 0) //Jeżeli jest zmiana znaku
        {
            b = c; //Nowa granica b jest równa c
            fb = fc; //zmieniam granicę więc zmieniam wartość
        }
        else //Jeżeli nie ma zmiany znaku
        {
            a = c; //Przesuwam granicę A
            fa = fc; //Zmieniam wartość w punkcie A
        }
    }
    return (a + b)/2; //Zwracam przybliżony pierwiastek
}

//Tworze funkcje zależne od x
double cos_minus_x(double x)
{
    return cos(x) - x;
}

double half_minus_cos(double x)
{
    return 0.5 - cos(x);
}

int main()
{
    std::cout << "Pierwiastek Rownania cos(x) = x, w przedziale [0,2]: " << root(cos_minus_x, 0, 2, 1e-6) << std::endl;
    std::cout << "Pierwiastek Rownania cos(x) = 0.5 w przedziale [0, 1.5]: " << root(half_minus_cos, 0, 1.5, 1e-6) << std::endl;
    return 0;
}
