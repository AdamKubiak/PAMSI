#pragma once
#include <iostream>
#include "Node.h"
using namespace std;



template<typename Typ>
class List
{
	
public:
	Node<Typ>* head;
	int size;

	List();
	~List();

	void pushBack(const Typ& newElement);
	void pushFront(const Typ& newElement);
	void insert(const Typ& newElement, int index);
	void remove(const Typ& element);
	void DisplayList();
	Typ& operator [] (int index);
};







template<typename Typ>
List<Typ>::List()
{
	head = NULL;
}

template<typename Typ>
List<Typ>::~List() {
	while (head->next != nullptr) {
		Node<Typ>* temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
	this->size = 0;
	cout << "Lista zostala usunieta" << endl;
}

template<typename Typ>
void List<Typ>::pushBack(const Typ& newElement)
{
	Node<Typ>* ptr = head;
	/*Jeœli head nic nie wskazuje to pushBack tworzy pierwszy elemnt listy*/
	if (head == NULL)
		head = new Node<Typ>(newElement);

	/*dochodzimy do momentu kiedy czeœæ next danego elemtu listy jest NULL i wtedy przypisujemy ten wskaŸnik do naszego nowego Noda*/
	else
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new Node<Typ>(newElement);
	}
	size++;

}

template<typename Typ>
void List<Typ>::pushFront(const Typ& newElement)
{
	Node<Typ>* ptr = new Node<Typ>; // tworze nowy node

	ptr->data = newElement; //przypisuje wartosc jaka przesylam do funkcji

	ptr->next = head; //przekazuje to co wskazywal poczatek listy nowemu nodowi

	head = ptr; // head pokazuje naszego nowego noda jako pierwszy element

	size++;
}
template<typename Typ>
void List<Typ>::insert(const Typ& newElement, int index)
{
	Node<Typ>* nowy = new Node<Typ>(newElement);
	Node<Typ>* ptr = head;

	if (index == 0)
		this->pushFront(newElement);
	else
	{
		while (index > 1 && ptr != nullptr) // poprzedni warunek by³ ca³kowicie b³êdny
		  // lista nie posiada pamiêci ci¹g³ej
		  // tj. ró¿ne wêz³y mog¹ mieæ zupe³nie ró¿ne adresy w pamiêci
		 // head[1] != head->next
		{
			--index;
			ptr = ptr->next; // szukamy wêz³a za którym wstawimy element
		}

		if (ptr == nullptr) // lista ma za ma³y rozmiar, nie mo¿na wstawiæ elementu na podany indeks
			throw std::invalid_argument("Cannot insert element at given index");

		auto temp = ptr->next;
		ptr->next = nowy;
		nowy->next = temp;
	}
	size++;
}

template<typename Typ>
void List<Typ>::remove(const Typ& element)
{
	Node<Typ>* tempNEXT, * temp;

	temp = head;

	tempNEXT = head->next;

	/*przypadek dla pierwszego elementu*/

	if (temp->data == element)
	{
		head = tempNEXT;

		delete(temp);
	}

	else
	{
		/*poruszanie siê po liœcie*/
		while (tempNEXT->data != element)
		{
			tempNEXT = tempNEXT->next;
			temp = temp->next;
		}
		/*przypadek dla ostatniego elementu*/
		if (tempNEXT->next == NULL)
		{
			temp->next = NULL;
			delete(tempNEXT);
		}
		/*przypadek dla elementu w œrodku*/
		else
		{
			temp->next = tempNEXT->next;
			delete(tempNEXT);
		}
	}

	size--;
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

template<typename Typ>
Typ& List<Typ>::operator [](int index)
{
	Node<Typ>* ptr = head;

	if (index >= size || index < 0) 
	{
		cout << ("Podany indeks nie istnieje") << endl;
	}

	else
	{
		
		for (int i = 0; i < index; ++i)
			ptr = ptr->next;

		return ptr->data;
	}
}



