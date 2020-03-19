#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template < typename Typ>
class Stack
{
	Node<Typ>* top;
public:
	Stack();
	~Stack();
	void push(const Typ& newElement);
	Typ pop();
	void display() const;
};

template<typename Typ>
Stack<Typ>::Stack()
{
	top = nullptr;
}

template<typename Typ>
Stack<Typ>::~Stack()
{
	while (top)
	{
		Node<Typ>* next = top->next;
		delete top;
		top = next;
	}
	cout << "Stos zostal usuniety" << endl;
}

template<typename Typ>
void Stack<Typ>::push(const Typ& newElement)
{
	Node<Typ>* node = new Node<Typ>(newElement);

	if (!top)
	{
		top = node; // pierwszy element stacka
	}

	else
	{
		node->next = top;// wskaznik na to co lezy pod nowym nodem
		top = node; // top wskazuje na nowego noda
	}
}

template<typename Typ>
Typ Stack<Typ>::pop()
{
	if (top)
	{
		Node<Typ>* node = top;
		Typ data = node->data;
		top = node->next;
		delete node;
		return data;
	}
	else
	{
		throw std::out_of_range("Stack is empty");
	}
}

template<typename Typ>
void Stack<Typ>::display() const
{
	Node<Typ>* temp = top;

	while (temp != NULL)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << endl;
}