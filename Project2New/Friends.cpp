/*
 * Friends.cpp
 *
 *  Created on: Apr 4, 2015
 *  Author: michaelzarate & Trevor Richardson
 *  Project2
 *  timespent: approx 30 hours
 */



#include <iostream>
#include <string>
#include <vector>
#include "Friends.h"

using namespace std;


/*
 * Making all the bodies of the member functions for 'Friends'
 */


Friends::Friends(string user)
{
	//user = "";
}

bool Friends::friendExists(string userFriend)
{

	for(int i = 0; i < friendSize; i++)
	{

		if(friends[i] == userFriend)
			return true;

	}
	return false;

}

bool Friends:: addFriend(string userFriend)
{

	if(friendExists(userFriend))
	{

		return false;
	}
	friendSize = friendSize + 1;
	friends.push_back(userFriend);
	return true;
}
