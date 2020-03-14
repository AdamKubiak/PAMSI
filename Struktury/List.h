#pragma once
#include <iostream>
using namespace std;

template<typename Typ>
class Node
{
public:
	Typ data;   //zawartosc danego bloku
	Node *next; // wskaznik na nastepny element

	Node(const Typ data);
	Node();
};

template<typename Typ>
class List
{
public:
	Node<Typ>* head;

	List();
	void pushBack(const Typ& newElement);
	void pushFront(const Typ& newElement);
	//void insert(const Typ& newElement, int index);
	//void remove(const Typ& element);
	void DisplayList();

};


int main()
{
	List<int>* kontener = new List<int>();

	int a = 1;
	int b = 2;

	kontener->pushBack(a);
	kontener->pushBack(a);
	kontener->pushBack(a);
	kontener->pushFront(b);

	kontener->DisplayList();

	return 0;

}
