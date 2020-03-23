#pragma once
#include "Queue.h"
#include "Node.h"
#include "List.h"

template < typename Typ>
class PriorityQueue
{
private:
	List<Typ>* queue;
public:
	PriorityQueue();
	PriorityQueue(const PriorityQueue<Typ>* PriorityQueue);
	~PriorityQueue();
	void enqueue(const Typ& newElement, int priority);
	Typ dequeue();
	PriorityQueue<Typ>& operator = (const PriorityQueue<Typ>& PriorityQueue);
};

template<typename Typ>
PriorityQueue<Typ>::PriorityQueue()
{
	queue = new List<Typ>();
}

template<typename Typ>
PriorityQueue<Typ>::PriorityQueue(const PriorityQueue<Typ>* PriorityQueue)
{
	this->queue = new List<Typ>(PriorityQueue->queue);
}

template<typename Typ>
PriorityQueue<Typ>::~PriorityQueue()
{
	while (queue->head->next != nullptr) {
		Node<Typ>* temp = queue->head;
		queue->head = queue->head->next;
		delete temp;
	}
	delete queue->head;
	cout << "Kolejka z priorytetem zostala usunieta" << endl;
}

template<typename Typ>
void PriorityQueue<Typ>::enqueue(const Typ& newElement, int priority)
{
	Node<Typ>* node = new Node<Typ>(newElement, priority);
	Node<Typ>* temp = queue->head;

	if (queue->head == NULL)
	{
		queue->head = node;
	}

	else if (node->priority >= queue->head->priority)
	{
		node->next = queue->head;
		queue->head = node;
	}

	else
	{
		while (temp->next->priority > node->priority)
		{
			temp = temp->next;
		}
		auto ptr = temp->next;
		temp->next = node;
		node->next = ptr;
	}
}

template<typename Typ>
Typ PriorityQueue<Typ>::dequeue()
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

template<class Typ>
PriorityQueue<Typ>& PriorityQueue<Typ>::operator = (const PriorityQueue<Typ>& PriorityQueue)
{
	delete this->queue;
	this->queue = new List<Typ>(PriorityQueue.queue);
	return *this;
}