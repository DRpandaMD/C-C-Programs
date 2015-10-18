/*
 * User.h
 *
 Created on: Apr 4, 2015
 *  Author: michaelzarate & Trevor Richardson
 *  Project2
 *  timespent: approx 30 hours
 */

#ifndef USER_H_
#define USER_H_

#include <iostream>
#include <string>
#include <vector>
#include "Friends.h"
#include "Wall.h"



using namespace std;

/*
 * This class handles the Wall and Friends aslo manupulates the wall
 * we had to move the functionality of wall into user to get it cooperate
 */

class User
{
private:
	string userName;



public:
	Friends friends; //class compostition

	Wall wall;
	User(string);
	void addFriends(string newFriends);

	inline string getUserName()
	{
		return userName;
	}

	bool isFriend(string);

	vector<string> getFriends();



};


#endif /* USER_H_ */
