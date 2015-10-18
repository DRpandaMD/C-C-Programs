/*
 * HashTable.cpp
 *
 *  Created on: Jun 26, 2015
 *      Author: michaelzarate
 */

#include "HashTable.h"

//Constructs the empty Hash Table Object
//Array Length is set to 13 by default

HashTable::HashTable(int tableLength)
{

	array = new LinkedList[tableLength];
	length = tableLength;

}

//returns an array location for a given item key
int HashTable::hash(int itemKey)
{
//int value = 0;
//	for(int i = 0; i < itemKey; i++)
//	{
//		value += itemKey[i];
//	}
	//doing k mod m where k is key and m is length or 1000
	return (itemKey % length);
}


//adds an item to the Hash Table.
void HashTable::insertItem(Item* newItem)
{
	int index = hash(newItem->key);
	array[index].insertItem(newItem);
}

//removes an item by key from the hash table
//returns true if the operation is successful

bool HashTable::removeItem(int itemKey)
{
	int index = hash(itemKey);
	return array[index].removeItem(itemKey);
}

//searches for an item by a given key

Item* HashTable::SearchItem(int itemKey)
{

	int index = hash(itemKey);
	return array[index].getItem(itemKey);
}

//prints out the Hash Table
void HashTable::printTable()
{
	cout << "\n\n Hash Table: \n ";
	for(int i = 0; i < length; i ++)
	{
		cout << "Bucket " << i + 1 << ": ";
		array[i].printList();
	}
}


//returns the number of locations in the hash table
int HashTable::getLength()
{
	return length;
}

//returns the number of Items in the Hash Table
int HashTable::getNumberOfItem()
{
	int itemCount = 0;
	for(int i = 0; i < length; i ++)
	{
		itemCount += array[i].getLength();
	}
	return itemCount;
}

//deallocates memory from hashtable
HashTable::~HashTable()
{
	delete [] array;
}



