#pragma once

template<typename Typ>
class Node
{
public:
	Typ data;   //zawartosc danego bloku
	Node* next; // wskaznik na nastepny element
	Typ priority; // uzywane tylko dla kolejki z priorytetem

	Node(const Typ data)
	{
		this->data = data;
		next = NULL;
		priority = 0;
	}

	Node()
	{	
		next = NULL;
		priority = 0;
	}
	Node(const Typ data,Typ priority)
	{
		this->data = data;
		this->priority = priority;
		next = NULL;
	}
};