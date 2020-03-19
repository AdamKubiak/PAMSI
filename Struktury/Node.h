#pragma once

template<typename Typ>
class Node
{
public:
	Typ data;   //zawartosc danego bloku
	Node* next; // wskaznik na nastepny element

	Node(const Typ data)
	{
		this->data = data;
		next = NULL;
	}

	Node()
	{	
		next = NULL;
	}
};