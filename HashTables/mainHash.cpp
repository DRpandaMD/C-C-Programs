/*
 * mainHash.cpp
 *
 *  Created on: Jun 28, 2015
 *      Author: michaelzarate
 */

#include "HashTable.h"


int main()
{

	int choice, key; //Declarations

	HashTable table; //make the table allocation FIRST


	while(true)
	{
		cout << endl << endl;
		cout << "Hash Table Example " << endl;
		cout << "-------------------" << endl;
		cout << "1. Insert a Record " << endl;
		cout << "2. Delete a Record " << endl;
		cout << "3. Search for a Record" << endl;
		cout << "4. Print out the Hash Table" << endl;
		cout << "5. Exit the Program!" << endl;


		cin >> choice;

		switch(choice)
		{
			case 1: {
					cout << endl;
					cout << "Enter a  Record to insert with its key value (between 0 and 1000): " << endl;
					cin >> key;
					Item* newItem = new Item;
					newItem->key = key;
					cout << "Enter the Student's Name: " << endl;
					cin >> newItem->name;
					cout << "Enter the Student's GPA: " << endl;
					cin >> newItem->gpa;
					cout << "Enter the Student's Academic Level, " <<endl;
					cout << "Freshman, Sophomore, Junior or Senior" << endl;
					cin >> newItem->academicLevel;
					cout << endl << endl;
					cout << "Now adding the Record to the Hash Table" << endl;
					table.insertItem(newItem);
					}
					break;

			case 2: {
					cout << endl;
					cout << "Enter a record to delete with its key value: " << endl;
					cin >> key;
					table.removeItem(key);
					cout << "Item Removed" << endl;
					}
					break;

			case 3: {
					cout << endl;
					cout << "Search for a record by its key value : " << endl;
					cin >> key;
					Item* result = table.SearchItem(key);
					if(result != NULL)
						cout << "The key you were looking for " << result->key << " is in the hash table! " << endl;
					else
						cout << "Given record with the key: " << key << " Does not exist" << endl;

					}
					break;

			case 4: {
					cout << endl;
					cout << "Printing out the Hash Table! " << endl;
					table.printTable();
					}
					break;

			case 5: {
					cout << "Exiting the Program!" << endl;
					return 0;
					}
					break;

			default: cout << "Please enter a valid option" << endl;
		}
	}



}



