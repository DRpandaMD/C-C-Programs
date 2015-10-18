/*
 * testfile.cpp
 *
 *  Created on: Apr 3, 2015
 *      Author: michaelzarate
 */


#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

#include "Wall.h"
#include "User.h"
#include "Menu.h"
//#include "SystemMain.h"

using namespace std;



void initializeUsers();
void createUser();


int main()

{
	vector<User*> newusers;


	cout << "Welcome to the test file app" << endl;
	cout << "we will run and make a few new users:" << endl;
	initializeUsers();

	cout << "we have made new users!" << endl;
	cout << "they are: " << endl << "Joe" << endl << "Bob" << endl
			<< "Mark"<< endl << "Jane" << endl
			<< "that is it!!! " <<endl;
	cout << "\n \n";

	cout << "now we will try to add a user... " << endl;

	createUser();

	cout << "additional user created!!!" << endl;
	cout << "Welcome to the party: " << User::name << endl;


	cout << "************ END OF PROGRAM *************** " << endl;


}


void initializeUsers() //will create the predetermined list of users
{


	User user1 = new User("Joe");
	User user2 = new User("Bob");
	User user3 = new User("Mark");
	User user4 = new User("Jane");

	newusers.push_back(user1);
}


void createUser()
{
	int number = 5;

	string holderName = "user" + number;
	string objectName = holderName;

	string userName;
	cout <<  "Please enter your name :";
	cin >> userName;

	User objectName = new User(userName);  //creates a new object of that type with user defined name


	number++;
}
