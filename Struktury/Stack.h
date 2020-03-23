#pragma once
#include <iostream>
#include "Node.h"
#include "List.h"
using namespace std;

template < typename Typ>
class Stack
{
	List<Typ>* top;
public:
	Stack();
	Stack(Stack<Typ>* stack);
	~Stack();
	void push(const Typ& newElement);
	Typ pop();
	void DisplayStack() const;
	Stack<Typ>& operator = (const Stack<Typ>& stack);
};

template<typename Typ>
Stack<Typ>::Stack()
{
	top = new List<Typ>();
}

template<typename Typ>
Stack<Typ>::Stack(Stack<Typ>* stack)
{
	this->top = new List<Typ>(stack->top);
}

template<typename Typ>
Stack<Typ>::~Stack()
{
	while (top->head != NULL)
	{
		Node<Typ>* next = top->head->next;
		delete top->head;
		top->head = next;
	}
	cout << "Stos zostal usuniety" << endl;
}

template<typename Typ>
void Stack<Typ>::push(const Typ& newElement)
{
	Node<Typ>* node = new Node<Typ>(newElement);

	if (!top->head)
	{
		top->head = node; // pierwszy element stacka
	}

	else
	{
		node->next = top->head;// wskaznik na to co lezy pod nowym nodem
		top->head = node; // top wskazuje na nowego noda
	}
}

template<typename Typ>
Typ Stack<Typ>::pop()
{
	if (top->head)
	{
		Node<Typ>* node = top->head;
		Typ data = node->data;
		top->head = node->next;
		delete node;
		return data;
	}
	else
	{
		throw std::out_of_range("Stack is empty");
	}
}

template<typename Typ>
void Stack<Typ>::DisplayStack() const
{
	Node<Typ>* temp = top->head;

	while (temp != NULL)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << endl;
}

template<typename Typ>
Stack<Typ>& Stack<Typ>::operator = (const Stack<Typ>& stack)
{
	delete this->top;
	this->top = new List<Typ>(stack.top);
	return *this;
}