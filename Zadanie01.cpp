#include <iostream>
#include <vector>

template <typename T> //Definiuje szablon typów abym mógł przeciążyć operator dla wektorów wszystkich typów danych
double operator*(const std::vector<T>& v, const std::vector<T>& w) //Gdzie <T>& to referencja na typ którą mi umożliwia zastosowanie szablonu
{
    if(v.size() != w.size())
    {
        std::cout << "Wektory musza byc tych samych rozmiarow, Zwracam Zero" << std::endl;
        return 0;
    }

    double wynik = 0.0;
    for (size_t i = 0; i < v.size(); i++)
    {
        wynik += static_cast<double>(v[i]) * static_cast<double>(w[i]);
    }
    return wynik;
}

int main()
{
    //Tworze dwa wektoru typu int
    std::vector<int> Vi1 = {1, 2, 3};
    std::vector<int> Vi2 = {9, 8, 7};

    //Tworze dwa wektory typu double
    std::vector<double> Vd1 = {1.5, 2.5, 8.5, 9.5};
    std::vector<double> Vd2 = {3.5, 4.5, 6.5, 7.5};

    //Wyświetlam komunikat z wynikiem iloczynu skalarnego
    std::cout << "Wynik iloczynu sklalarnego dwoch wektorow typu int: " << Vi1 * Vi2 << std::endl;
    std::cout << "Wynik iloczynu sklalarnego dwoch wektorow typu double: " << Vd1 * Vd2 << std::endl;

    return 0;
}
