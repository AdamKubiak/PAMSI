#pragma once
#include "List.h"
#include<string>
#define quantity 11

template < typename KeyType, typename ValueType >
class Map // Tablica z haszowaniem
{
	List<ValueType>* kontener;
	//static int quantity = 11;
public:
	Map();
	Map(const Map<KeyType, ValueType>* Map);
	~Map();
	int hash(int key);
	int hash(const std::string& key);
	void insert(const KeyType& key, const ValueType& value);
	ValueType& operator []( const KeyType& key );
	void remove(const KeyType& key);
	Map<KeyType, ValueType>& operator = (const Map<KeyType, ValueType>& Map);
	void DisplayHash();
};


template<typename KeyType, typename ValueType>
Map<KeyType, ValueType>::Map()
{
	kontener = new List<ValueType>();
	for (int i = 0; i < quantity; i++)  //konstruktor robi 'kontener' 11 elementów z NULL korzystajac z pushBack listy
		kontener->pushBack(NULL);  
}
template<typename KeyType, typename ValueType>
Map<KeyType, ValueType>::Map(const Map<KeyType, ValueType>* Map)
{
	this->kontener = new List<ValueType>(Map->kontener);
}

template<typename KeyType, typename ValueType>
Map<KeyType, ValueType>::~Map()
{
	delete kontener; //destruktor listy
	cout << "Tablica hashujaca zostala usunieta" << endl;
}

template<typename KeyType, typename ValueType>
int Map<KeyType, ValueType>::hash(int key)
{
	return key % quantity;       //klucz modulo ilosc elementow w liscie
}

template<typename KeyType, typename ValueType>
int Map<KeyType, ValueType>::hash(const std::string& key)
{
	int hash = 0;
	for (const char& letter : key)
	{
		hash += int(letter);
	}
	return hash % quantity;
}

template<typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::remove(const KeyType& key)
{
	(*kontener)[hash(key)] = NULL; //wykorzystuje przeciezenie napisane dla list (*kontener)[indeks](podpowiedz ochmana)
}

template<typename KeyType, typename ValueType>
ValueType& Map<KeyType, ValueType>::operator[](const KeyType& key)
{
	return (*kontener)[hash(key)];
}

template<typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value)
{
	(*kontener)[hash(key)] = value;
}

template<typename KeyType, typename ValueType>
Map<KeyType, ValueType>& Map<KeyType, ValueType>::operator = (const Map<KeyType, ValueType>& Map)
{
	delete kontener;
	kontener = new List<ValueType>(Map.kontener);
	return *this;
}

template<typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::DisplayHash()
{
	for (int i = 0; i < quantity; i++)
	{
		if ((*kontener)[i])
		{
			cout << "Indeks: " << i << "; Wartosc: " << (*kontener)[i] << endl;
		}
	}

	cout << endl;
}