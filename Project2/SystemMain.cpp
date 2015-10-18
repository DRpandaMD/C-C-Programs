/*
 * SystemMain.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: michaelzarate
 */



/*
 * Setting up the main and defining all the functions to be used
 *
 */


#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

#include "Wall.h"
#include "User.h"
#include "Menu.h"

using namespace std;

void main()
{

	start();
	initializeUsers();

	/*
	 * Loop while to keep the app running
	 */



	quit();
}



/*
 * Everything else but main
 *
 */

void start()
{
	//what is supposed to go in here
}

bool userExists(string)
{
	//check to see if the user exsists
	//where are we putting users?

}

User* getUser(string)
{
	//does this get the user we are looking for to make
	//them the current user?
}

bool validateName(string) //check to see if the name is taken
{
	if(User::getName() == string )
	{

	}
}

bool validateUser(string)
{

}

void outputBanner(string)
{
	//is this a default banner
	// or is this a banner that we are supposed
	// to know how to change when ever?


}

void updateMenu(Menu&)
{

//what is this supposed to do
	//are we adding things to the menu?
	//does the menu change?

}

void initializeUsers() //will create the predetermined list of users
{

	User::User(Joe);
	User::User(Bob);
	User::User(Mark);
	User::User(Jane);

}

void createUser()
{
	string userName;
	cout <<  "Please enter your name :";
	cin >> userName;

	User::User(userName); //creates a new object of that type with user defined name

}

void postMessage()
{

	//where are we posting to?

}

void displayWall()
{

	//how do i display Wall?
	//which wall are we talking about

}

void displayHome()
{
	//where is home?


}

void switchUser()
{
	//how do i switch user?

}

void quit()
{
	//how do i quit
	//how do i even start


}
