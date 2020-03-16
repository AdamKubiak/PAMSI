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


	void pushFront(const Typ& newElement)
	{
		Node<Typ>* ptr = new Node<Typ>; // tworze nowy node

		ptr->data = newElement; //przypisuje wartosc jaka przesylam do funkcji

		ptr->next = head; //przekazuje to co wskazywal poczatek listy nowemu nodowi

		head = ptr; // head pokazuje naszego nowego noda jako pierwszy element

	}


	//void insert(const Typ& newElement, int index);
	void remove(const Typ& element)
	{
		Node<Typ>* tempNEXT, * temp;

		temp = head;
		
		tempNEXT = head->next;

		if (temp->data == element)
		{
			head = tempNEXT;

			delete(temp);
		}

		else
		{
			while (tempNEXT->data != element)
			{
				tempNEXT = tempNEXT->next;
				temp = temp->next;
			}

			if (tempNEXT->next == NULL)
			{
				temp->next = NULL;
				delete(tempNEXT);
			}

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


