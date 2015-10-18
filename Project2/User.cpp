/*
 * User.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: michaelzarate
 */


#include <iostream>
#include <string>
#include <vector>
#include "User.h"
using namespace std;
/**
Constructor Name:       User
Purpose         :       Constructor for User class
Parameter       :       type--string    name--name
*/
User::User(string name) : name(name), friends(Friends(name)) //member initialization list
{
        //empty constructor body
}

/**
Function Name   :       addFriend
Purpose         :       Add a friend for the given user
*/
void User::addFriend(string user)
{
        friends.addFriend(user);
}

/**
Function Name   :       isFriend
Purpose         :       Verifies whether the name is already in the friend list of this user
*/
bool User::isFriend(string Friendname)
{
      return  friends.friendExists(Friendname);
}

/**
Function Name   :       getFriends
Purpose         :       Retrieves the friend list for a user
*/
vector<string> User::getFriends()
{
        return friends.getFriends();
}


