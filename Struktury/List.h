#pragma once
#include <iostream>
#include "Node.h"
using namespace std;



template<typename Typ>
class List
{
private:
	int size;
public:
	class Iterator;
	class ConstIterator;
	Node<Typ>* head;
	

	List();
	~List();

	void pushBack(const Typ& newElement);
	void pushFront(const Typ& newElement);
	void insert(const Typ& newElement, int index);
	void remove(const Typ& element);
	void DisplayList();
	Typ& operator[] (int index);
	Iterator begin();
	Iterator end();
	ConstIterator cbegin() const;
	ConstIterator cend() const;
	

	struct Iterator
	{

		using difference_type = std::size_t;
		using value_type = Typ;
		using reference = Typ&;
		using pointer = Typ*;
		using iterator_category = std::input_iterator_tag;


		Node<Typ>* Iter;

		

		Iterator(Node<Typ>* nod = nullptr) : Iter(nod) {};

		void operator ++()
		{
			
			Iter = Iter->next;

		}

		bool operator != (Iterator const& diff) const
		{
			return Iter!=diff.Iter;
		}

		bool operator == (Iterator const& diff) const
		{
			
			return Iter == diff.Iter;
		}

		Iterator& operator = (const Iterator& diff)
		{
			Iter = diff.Iter;
			return Iter;
		}

		Typ& operator *()
		{
			return Iter->data;
		}

	};

	struct ConstIterator
	{
		Node<Typ>* Iter;

		ConstIterator(Node<Typ>* nod = nullptr) : Iter(nod) {};

		void operator++()
		{
			if (Iter != nullptr)
			Iter = Iter->next;
			else
				throw std::invalid_argument("Out of range");

		}
		bool operator != (ConstIterator const& diff) const
		{
			return Iter != diff.Iter;
		}

		Typ& operator*()
		{
			return Iter->data;
		}
	};
};

template<typename Typ>
List<Typ>::List()
{
	size = 0;
	head = NULL;
}

template<typename Typ>
List<Typ>::~List() {
	while (head->next != nullptr) {
		Node<Typ>* temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
	this->size = 0;
	cout << "Lista zostala usunieta" << endl;
}

template<typename Typ>
void List<Typ>::pushBack(const Typ& newElement)
{
	Node<Typ>* ptr = head;
	/*Jeœli head nic nie wskazuje to pushBack tworzy pierwszy elemnt listy*/
	if (head == NULL)
		head = new Node<Typ>(newElement);

	/*dochodzimy do momentu kiedy czeœæ next danego elemtu listy jest NULL i wtedy przypisujemy ten wskaŸnik do naszego nowego Noda*/
	else
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new Node<Typ>(newElement);
	}
	size++;

}

template<typename Typ>
void List<Typ>::pushFront(const Typ& newElement)
{
	Node<Typ>* ptr = new Node<Typ>; // tworze nowy node

	ptr->data = newElement; //przypisuje wartosc jaka przesylam do funkcji

	ptr->next = head; //przekazuje to co wskazywal poczatek listy nowemu nodowi

	head = ptr; // head pokazuje naszego nowego noda jako pierwszy element

	size++;
}
template<typename Typ>
void List<Typ>::insert(const Typ& newElement, int index)
{
	Node<Typ>* nowy = new Node<Typ>(newElement);
	Node<Typ>* ptr = head;

	if (index == 0)
		this->pushFront(newElement);
	else
	{
		while (index > 1 && ptr != nullptr) // poprzedni warunek by³ ca³kowicie b³êdny
		  // lista nie posiada pamiêci ci¹g³ej
		  // tj. ró¿ne wêz³y mog¹ mieæ zupe³nie ró¿ne adresy w pamiêci
		 // head[1] != head->next
		{
			--index;
			ptr = ptr->next; // szukamy wêz³a za którym wstawimy element
		}

		if (ptr == nullptr) // lista ma za ma³y rozmiar, nie mo¿na wstawiæ elementu na podany indeks
			throw std::invalid_argument("Cannot insert element at given index");

		auto temp = ptr->next;
		ptr->next = nowy;
		nowy->next = temp;
	}
	size++;
}

template<typename Typ>
void List<Typ>::remove(const Typ& element)
{
	Node<Typ>* node = head;
	Node<Typ>* preNode = nullptr;
	Node<Typ>* postNode = nullptr;
	if (head != nullptr)
	{
		if (head->data == element)
		{
			postNode = head->next;
			delete head;
			head = postNode;
		}
		else
		{
			while (node->next != nullptr)
			{
				preNode = node;
				node = node->next;
				if (node != nullptr && node->data == element)
				{
					postNode = node->next;
					delete node;
					preNode->next = postNode;
					node = preNode;
				}
			}
		}
	}
}


template<typename Typ>
void List<Typ>::DisplayList()
{
	Node<Typ>* ptr = head;
	if (!head)
		return;
	while (ptr != NULL)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
}

template<typename Typ>
Typ& List<Typ>::operator [](int index)
{
	Node<Typ>* ptr = head;

	if (index >= size || index < 0) 
	{
		throw std::invalid_argument("Podany indeks nie istnieje");
		
	}

	else
	{
		
		for (int i = 0; i < index; ++i)
			ptr = ptr->next;

		return ptr->data;
	}
}


template<typename Typ>
typename List<Typ>::Iterator List<Typ>::begin()
{
	return Iterator(head);
}


template<typename Typ>
typename List<Typ>::Iterator List<Typ>::end()
{
	return Iterator(nullptr);
}


template<typename Typ>
typename List<Typ>::ConstIterator List<Typ>::cbegin() const
{
	return ConstIterator(head);
}

template<class Typ>
typename List<Typ>::ConstIterator List<Typ>::cend() const
{
	return ConstIterator(nullptr);
}