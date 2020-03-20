#pragma once
#include "Node.h"
#include "List.h"


template < typename Typ>
class Queue
{
private:
	List<Typ>* queue;
public:
	Queue();
	~Queue();
	void enqueue(const Typ& newElement);
	Typ dequeue();
};

template<typename Typ>
Queue<Typ>::Queue()
{
	queue = new List<Typ>();
}

template<typename Typ>
Queue<Typ>::~Queue()
{
	while (queue->head->next != nullptr) {
		Node<Typ>* temp = queue->head;
		queue->head = queue->head->next;
		delete temp;
	}
	delete queue->head;
	cout << "Kolejka zostala usunieta" << endl;
}


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