#pragma once
#include "Node.h"
#include "List.h"


template < typename Typ>
class Queue
{
private:
	List<Typ>* queue;
public:
	void enqueue(const Typ& newElement);
	Typ dequeue();
};

template<typename Typ>
Typ Queue<Typ>::dequeue()
{
	Node<Typ>* tempNEXT, * temp;
	Typ Data;
	if (queue->head)
	{
		temp = queue->head;
		Data = temp->data;
		tempNEXT = queue->head->next;
		queue->head = tempNEXT;
		delete(temp);

		return Data;
	}
	throw out_of_range("Kolejka nie istnieje");
}

template<typename Typ>

void Queue<Typ>::enqueue(const Typ& newElement)
{
	queue->pushBack(newElement);
}