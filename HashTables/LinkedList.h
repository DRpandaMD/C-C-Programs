/*
 * LinkedList.h
 *
 *  Created on: Jun 26, 2015
 *      Author: michaelzarate
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


#include <iostream>
#include <string>

using namespace std;

struct Item
{
	int key;
	string name;
	double gpa;
	string academicLevel;
	Item* next;
};


/*
 * Make the Linked list to store on the hash table
 */

class LinkedList
{
private:
	//pointer to the head of the list
	Item* head;

	//the length of the number in the data nodes
	int length;

public:
	//constructs the linked list object
	LinkedList();

	//inserts item at the end of the list
	void insertItem(Item* newItem);

	//removes an time from list by key
	//returns true if successful
	bool removeItem(int itemKey);

	// searches for an item by the key
	//Returns a reference to the first match
	//Returns NULL pointer on no match
	Item* getItem(int itemKey);

	//displays list
	void printList();

	//Returns the length of the list
	int getLength();

	//Deletes list and frees memory back to the system
	~LinkedList();




};

#endif /* LINKEDLIST_H_ */
