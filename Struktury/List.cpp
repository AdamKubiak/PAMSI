#include "List.h"


template<typename Typ>
Node<Typ>::Node()
{
    next = NULL;
}

template<typename Typ>
Node<Typ>::Node(const Typ data)
{
    this->data = data;
    next = NULL;
}




template<typename Typ>
List<Typ>::List()
{
    head = NULL;
}






template<typename Typ>
void List<Typ>::pushBack(const Typ& newElement)
{
    Node<Typ>* ptr = head; 
    if (head == NULL)
        head = new Node<Typ>(newElement);
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next; 
        }
        ptr->next = new Node<Typ>(newElement); 
    }

}

template<typename Typ>
void List<Typ>::pushFront(const Typ& newElement)
{
    Node<Typ>* ptr = new Node<Typ>(); // tworze nowy node

    ptr->data = newElement; //przypisuje wartosc jaka przesylam do funkcji

    ptr->next = head; //przekazuje to co wskazywal poczatek listy nowemu nodowi

    head = ptr; // head pokazuje naszego nowego noda jako pierwszy element

}

template<typename Typ>
void List<Typ>::DisplayList()
{
    Node<Typ>* ptr = head;
    if (!head)
        return;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}







































