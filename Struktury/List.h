#pragma once
#include <iostream>
using namespace std;

template<typename Typ>
class Node
{
public:
	Typ data;   //zawartosc danego bloku
	Node *next; // wskaznik na nastepny element

	Node(const Typ data)
	{
		this->data = data;
		next = NULL;
	}

	Node()
	{
		data = NULL;
		next = NULL;
	}
};

template<typename Typ>
class List
{
public:
	Node<Typ>* head;

	List()
	{
		head = NULL;
	}


	void pushBack(const Typ& newElement)
	{
		Node<Typ>* ptr = head; 
		/*Jeśli head nic nie wskazuje to pushBack tworzy pierwszy elemnt listy*/
		if (head == NULL)
			head = new Node<Typ>(newElement);

		/*dochodzimy do momentu kiedy cześć next danego elemtu listy jest NULL i wtedy przypisujemy ten wskaźnik do naszego nowego Noda*/
		else
		{
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = new Node<Typ>(newElement);
		}

	}


	void pushFront(const Typ& newElement)
	{
		Node<Typ>* ptr = new Node<Typ>; // tworze nowy node

		ptr->data = newElement; //przypisuje wartosc jaka przesylam do funkcji

		ptr->next = head; //przekazuje to co wskazywal poczatek listy nowemu nodowi

		head = ptr; // head pokazuje naszego nowego noda jako pierwszy element

	}


	void insert(const Typ& newElement, int index)
	{
		Node<Typ>* nowy = new Node<Typ>(newElement);
		Node<Typ>* ptr = head;
		Node<Typ>* temp;

		while(ptr != (head + index))
		{
			ptr = ptr->next;
		}
		temp = ptr->next;
		ptr->next = nowy;
		nowy->next = temp;
	}


	void remove(const Typ& element)
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
			/*poruszanie się po liście*/
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
			/*przypadek dla elementu w środku*/
			else
			{
				temp->next = tempNEXT->next;
				delete(tempNEXT);
			}
		}

		
	}


	void DisplayList()
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

};


