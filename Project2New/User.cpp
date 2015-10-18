/*
 * User.cpp
 *
 * Created on: Apr 4, 2015
 *  Author: michaelzarate & Trevor Richardson
 *  Project2
 *  timespent: approx 30 hours
 */





#include <iostream>
#include <string>
#include <vector>
#include "User.h"




using namespace std;


//constructor for User
User::User(string newUser) :  friends(Friends(newUser)), wall(Wall())
{
	userName = newUser;
	//friends = new Friends;
	//userName = new string;
}

void User::addFriends(string newFriends)
{

	friends.addFriend(newFriends);
}


bool User::isFriend(string newFriends)
{
	return friends.friendExists(newFriends);
}


vector <string> User::getFriends()
{
	return friends.getFriends();
}




/*User::~User() //destructor to clean up heap memory leaks are bad!!
{

	delete friends;
	delete userName;
}
*/
