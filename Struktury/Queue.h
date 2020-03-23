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
	Queue(const Queue<Typ>* Queue);
	~Queue();
	void enqueue(const Typ& newElement);
	Typ dequeue();
	Queue<Typ>& operator = (const Queue<Typ>& queue);
};

template<typename Typ>
Queue<Typ>::Queue()
{
	queue = new List<Typ>();
}

template<typename Typ>
Queue<Typ>::Queue(const Queue<Typ>* Queue)
{
	this->queue = new List<Typ>(Queue->queue);
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
		throw std::out_of_range("Kolejka nie istnieje");
	}
}

template<typename Typ>

void Queue<Typ>::enqueue(const Typ& newElement)
{
	queue->pushBack(newElement);
}

template<typename Typ>
Queue<Typ>& Queue<Typ>::operator = (const Queue<Typ>& Queue)
{
	delete this->queue;
	this->queue = new List<Typ>(*Queue.queue);
	return *this;
}