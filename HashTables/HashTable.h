/*
 * HashTable.h
 *
 *  Created on: Jun 26, 2015
 *      Author: michaelzarate
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "LinkedList.h"

//HashTable class declaration and definition
// Hash Table array elements consisted of Linked List objects

class HashTable
{
private:
	//Array is a reference to an array of linked list
	LinkedList* array;

	// int Length is the size hash Table array
	int length;

	//Return an array location for a given item key
	int hash(int itemKey );

public:

	//Constructs  the empty hash table
	// Array length is set to 13 by default
	HashTable(int tableLength = 1000);

	//adds an item to the Hash Table
	void insertItem(Item * newItem);

	//Deletes an Item by key from the Hash Table
	//Returns true if the operation is successful.
	bool removeItem(int itemKey);

	//searches for an item by its key
	Item* SearchItem(int itemKey);

	//prints table
	void printTable();

	// returns the number of locations in the Hash Table
	int getLength();

	// Returns he number of Items in the Hash Table
	int getNumberOfItem();

	//De-allocates all memory used for the Hash Table
	~HashTable();


};


#endif /* HASHTABLE_H_ */
