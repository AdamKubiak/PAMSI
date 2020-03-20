#pragma once
#include "Node.h"
#include "List.h"


template < typename Typ>
class Queue
{
private:
	List<Typ>* queue;
public:
	Queue()
	{
		queue = new List<Typ>();
	}
	void enqueue(const Typ& newElement);
	Typ dequeue();
};

template<typename Typ>
Typ Queue<Typ>::dequeue()
{
	if (queue->head)
	{
		Node<Typ>* temp = queue->head;
		Typ Data = temp->data;
		queue->head = queue->head->next;
		delete(temp);
			return Data;
		
	}
	else
	{
		throw out_of_range("Kolejka nie istnieje");
	}
}

template<typename Typ>

void Queue<Typ>::enqueue(const Typ& newElement)
{
	queue->pushBack(newElement);
}