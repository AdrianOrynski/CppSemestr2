#include <iostream>

using namespace std;

struct Link //nazwa struktury, króra przechowuje:
{
    int value; //Wartość
    Link* next = nullptr; //Wskaźnik na następny element
};

void reverse(Link** phead)
{
    Link* prev = nullptr; //Tworzę zmienną dla poprzedniego elementu
    Link* current = *phead; //Tworzę zmienną dla obecnego elementu
    Link* next = nullptr; //Tworzę zmienną dla następnego elementu
    while(current != nullptr)//Dopóki nie wyjdę za zasięg
    {
        next = current->next; // Zapisuje wskaźnik na następny element
        current->next = prev; // Odwracam wskazanie na poprzedni element

        prev = current; // Przesuwamy wskaźnik na poprzedni element
        current = next; // Przesuwamy wskaźnik na następny element
    }
    *phead = prev; // Nowy początek listy to ostatni element
}

void release(Link** phead) //Funkcja z zadania 2
{
    if (*phead == nullptr)
    {
        return;
    }
    Link* tmp = *phead;
    *phead = (*phead)->next;
    delete tmp;
    cout << "Usuwam" << endl;
    release(phead);
}

void showList(const Link* head)
{
    const Link* current = head; //Wskaźnik na pierwszy element
    while (current != nullptr)  //Dopóki nie trafię na koniec listy
    {
        cout << current->value << " "; //Wyświet przypisaną wartość
        current = current->next; //Zmień wskaźnik
    }
    cout << endl;
}

int main()
{
    //Tworzę listę
    Link *head = new Link{1};
    head->next = new Link{2};
    head->next->next = new Link{5};
    head->next->next->next = new Link{9};

    cout << "Przed odwroceniem: " << endl;
    showList(head);
    reverse(&head);

    cout << "Po odwroceniu: " << endl;
    showList(head); //Odwrocenie jest prawdziwe ponieważ odwołuje się do tego samego obiektu

    release(&head); //Zwolnij pamięć
    return 0;
}