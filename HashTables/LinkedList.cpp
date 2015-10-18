/*
 * LinkedList.cpp
 *
 *  Created on: Jun 26, 2015
 *      Author: michaelzarate
 */


#include "LinkedList.h"

//Constructs the empty linked list object

LinkedList::LinkedList()
{
	//cout << "Call to linkedList()" << endl;
	head = new Item;
	head -> next = NULL;
	length = 0;

}

void LinkedList::insertItem(Item * newItem)
{
	//cout << "Call to insertItem() " <<endl;
	if(head -> next == NULL)
	{
		head->next = newItem;
		length++;
		return;
	}

	Item *p = head;
	Item *q = head;

	while(q)
	{
		p = q;
		q = p-> next;
	}

	p->next = newItem;
	newItem -> next = NULL;
	length++;
}

bool LinkedList::removeItem(int itemKey)
{
	if(!head ->next) return false;
	Item *p = head;
	Item *q = head;
	while(q)
	{
		if(q->key == itemKey)
		{
			p-> next = q->next;
			delete q;
			length --;
			return true;
		}
		p = q;
		q = p ->next;

	}
	return true;


}

Item* LinkedList::getItem(int itemKey)
{

	Item* p = head;
	Item* q = head;

	while(q)
	{
		p = q;

		if((p != head) && (p->key == itemKey))
		{
			return p;
		}

		q = p->next;
	}
	return NULL;

}

void LinkedList::printList()
{
	//cout << "Call to printList()" << endl;

	if(length == 0)
	{
		cout << "\n{ }\n";
		return;
	}
	Item *p = head;
	Item *q = head;
	cout << "\n{ ";

	while(q)
	{
		p = q;
		if(p != head)
		{
			cout << p-> key;
			if(p->next)  cout << ", ";
			else
				cout << " ";
		}
		q = p->next;
	}
	cout << "}\n";

}

int LinkedList::getLength()
{
	return length;
}

LinkedList::~LinkedList()
{
	Item* p = head;
	Item* q = head;

	while(q)
	{
		p = q;
		q = p-> next;
		if(q) delete p;
	}
}

//END


