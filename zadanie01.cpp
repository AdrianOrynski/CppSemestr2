#include <iostream>

using namespace std;

struct Link //nazwa struktury, króra przechowuje:
{
    int value; //Wartość
    Link* next = nullptr; //Wskaźnik na następny element
};

size_t size(const Link* head) //Link* head wskaźnik na początek listy
{
    size_t count = 0;
    const Link* current = head; //Jest to wskaźnik który wykorzystam do iteracji po liście, i który zacznie od pierwszego elementu
    while(current != nullptr) //Dopóki nie trafimy na pusty element, czyli koniec listy
    {
        count++;
        current = current -> next; //Przesuwam wskaźnik na następny element
    }
    return count; //Zwracam ilość elementów listy
}

size_t sum(const Link* head)
{
    size_t totalvalue = 0; //Inicjalizuje zmienną dla sumy
    const Link* current = head;
    while(current != nullptr)
    {
        totalvalue += current -> value; //dodaje do zmiennej wartość z pod wskaźnika
        current = current -> next;
    }
    return totalvalue;
}

int main()
{
    Link* head = new Link{1}; //Tworzę nowy obiekt i przypisuje pierwszemu elementowi wartość 1
    head->next = new Link{2}; //Tworzę nowy obiekt o wartości 2 i przypisuje go jako drugi element do listy
    head->next->next = new Link{3}; //Tworzę nowy obiekt o wartości 3 i przypisuje go jako trzeci element do listy

    cout << "Rozmiar listy: " << size(head) << endl;
    cout << "Suma wartosci na liscie: " << sum(head) << endl;

    //Po zakończeniu zadania zwalniam pamięć
    while (head != nullptr) //Dopóki nie mam pustej listy
    {
        Link* temp = head; //Tworzę tymczasową zmienną z pierwszym elementem
        head = head->next; //Zmieniam pierwszy element
        delete temp; //Usuwam zmienną tymczasową
    }

    return 0;
}