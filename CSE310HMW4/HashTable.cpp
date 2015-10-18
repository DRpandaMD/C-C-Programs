/*
 * HashTable.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: michaelzarate
 */

//chapter 10.2
//chapter 11
#include <iostream>
#include <string>

using namespace std;

/*
 * class record definition
 */

class p_Record
{
	 // fill in the class
};

void INSERT(p_Record** t, p_Record* p);
void DELETE(p_Record** t, p_Record* p);

p_Record* SEARCH(p_Record** t, int k);

int main()
{
	int choice;
	p_Record* T[1000];

	cout << "\t\tHash Table Implementation of Student Records" << endl;
	cout << "\t\t============================================" << endl;
	cout << "1. Insert a Record (key should be between 0 and 1000)" << endl;
	cout << "2. Search the Table (Enter a key between 0 and 1000 for search)" << endl;
	cout << "3. Delete a Record (Enter key of the record between 0 and 1000 to delete)" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter your Choice" << endl;
	cin >> choice;


	// make switch case statement here

}
