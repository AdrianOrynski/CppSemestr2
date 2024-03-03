#include <iostream>

using namespace std;
//Kopiuje zadanie pierwsze aby było co czyścić z pamięci.

struct Link
{
    int value;
    Link* next = nullptr;
};

void release(Link** phead) //Funkcja do zadania 2
{
    if (*phead == nullptr)
    {
        return; // Warunek zakończenia rekurencji: jeśli lista jest pusta, wychodzę z funkcji
    }

    Link* tmp = *phead; // Tymczasowy wskaźnik na pierwszy element listy
    *phead = (*phead)->next; // Przesunięcie wskaźnika na następny element listy
    delete tmp; // Usunięcie bieżącego elementu
    cout << "Usuwam" << endl; //Wstawiam komunikat do konsoli aby pokazać że coś się dzieje
    release(phead); // Wywołanie rekurencyjne dla reszty listy
}

size_t size(const Link* head)
{
    size_t count = 0;
    const Link* current = head;
    while(current != nullptr)
    {
        count++;
        current = current -> next;
    }
    return count;
}

size_t sum(const Link* head)
{
    size_t totalvalue = 0;
    const Link* current = head;
    while(current != nullptr)
    {
        totalvalue += current -> value;
        current = current -> next;
    }
    return totalvalue;
}

int main()
{
    Link* head = new Link{2};
    head->next = new Link{4};
    head->next->next = new Link{6};

    cout << "Rozmiar listy: " << size(head) << endl;
    cout << "Suma wartosci na liscie: " << sum(head) << endl;

    //Wywołanie rekurencyjne funkcji zwalniającej pamięć
    release(&head); //Wskazuje na początek listy

    return 0;
}
