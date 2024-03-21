#include <iostream>
#include <vector>
#include <sstream>

std::string nimGameStrategy(const std::vector<int>& piles)
{
    //XOR zwraca 1 gdy bity są różne i 0 gdy są takie same
    // Obliczanie bitowego XOR wszystkich liczb kamieni w kolejnych rzędach.
    //W kontekście gry Nim, operacja bitowego XOR jest używana do obliczenia sumy bitowej XOR
    // liczby kamieni w każdym rzędzie. Jest to istotne, ponieważ w strategii gry Nim,
    // gdy suma bitowa XOR wszystkich liczb kamieni w rzędach jest równa zero, to
    // gracz, który wykonuje ruch, nie ma możliwości wykonania ruchu, który
    // zagwarantuje mu zwycięstwo w jednym ruchu. Z drugiej strony, jeśli suma bitowa XOR
    // jest różna od zera, istnieje przynajmniej jeden rząd, w którym można podjąć ruch, aby
    // utrzymać przewagę nad przeciwnikiem.
    int xorSum = 0;
    for (int pile : piles)
    {
        xorSum ^= pile;
    }
    // Jeśli suma bitowego XOR wszystkich liczb kamieni w kolejnych rzędach wynosi zero,
    // oznacza to, że gracz nie ma możliwości wygrania w jednym ruchu.
    if (xorSum == 0)
    {
        return "rob co chcesz, strategia wygrywajaca nie istnieje";
    }
    else
    {
    // W przeciwnym razie, iterujemy przez wszystkie rzędy kamieni.
        for (size_t i = 0; i < piles.size(); ++i)
        {
        // Jeśli wykonanie operacji XOR na liczbie kamieni w danym rzędzie i xorSum
        // daje mniejszą wartość niż oryginalna liczba kamieni w danym rzędzie,
        // to istnieje możliwość wykonania optymalnego ruchu.
            if ((piles[i] ^ xorSum) < piles[i])
            {
                std::ostringstream oss;
                oss << "z rzedu nr " << (i+1) << " zabierz " << (piles[i] - (piles[i] ^ xorSum)) << " kamienie";
            // Zwracam wiadomość w postaci ciągu znaków.
                return oss.str();
            }
        }
    }
// Ta gałąź jest osiągalna tylko wtedy, gdy w grze Nim coś poszło nie tak,
// ponieważ każda poprawna gra ma strategię wygrywającą dla jednego z graczy.
return ""; // Ta gałąź nie powinna być osiągalna w przypadku gry w nim.
}

void printHelp()
{
    std::cout << "Program pomaga wygrac w grę nim." << std::endl;
    std::cout << "skladnia: nim liczba_1 liczba_2 ..." << std::endl;
    std::cout << "gdzie liczba_1,... to liczby kamieni w kolejnych rzedach" << std::endl;
}

int main(int argc, char *argv[])
{
    // Sprawdź, czy liczba argumentów przekazanych do programu jest mniejsza niż 2,
    // lub czy pierwszy argument jest równy "--help" lub "-h".
    if (argc < 2 || (std::string(argv[1]) == "--help") || (std::string(argv[1]) == "-h"))
    {
        // Jeśli warunek jest spełniony, wywołaj funkcję printHelp(),
        // która wyświetla informacje o sposobie użycia programu.
        printHelp();
    }
    else
    {
        // Jeśli warunek nie jest spełniony, utwórz wektor 'piles', który będzie przechowywał liczby kamieni w kolejnych rzędach.
        std::vector<int> piles;
        // Iteruj przez argumenty przekazane do programu, zaczynając od indeksu 1,
        // ponieważ argv[0] zawiera nazwę programu.
        for (int i = 1; i < argc; ++i) {
            // Konwertuj każdy argument na liczbę całkowitą i dodaj go do wektora 'piles'.
            piles.push_back(std::stoi(argv[i]));
        }
        // Wywołaj funkcję nimGameStrategy(piles), aby znaleźć optymalny ruch w grze Nim
        // i wyświetl wynik na standardowym wyjściu.
        std::cout << nimGameStrategy(piles) << std::endl;
    }
    // Zwróć zero, aby oznaczyć pomyślne zakończenie programu.
    return 0;
}