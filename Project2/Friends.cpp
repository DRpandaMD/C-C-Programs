/*
 * Friends.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: michaelzarate
 */



#include <iostream>
#include <string>
#include <vector>
#include "Friends.h"
using namespace std;
/**
Constructor Name:       Friends
Purpose         :       Constructor for the Friends class for User <user>
Parameter       :       type--string    name--user
*/
Friends::Friends(string user) : user(user) //member initialization list
{
        //empty body
		//makes default empty object
}


/**
Function Name   :       friendExists
Purpose         :       Checks if the name entered is a friend or not
*/
bool Friends::friendExists(string userFriend)
{
        for (int i = 0; i < friends.size(); i++)
        {
                if (friends[i] == userFriend)
                        return true;
        }
        return false;
}

/**
Function Name   :       addFriend
Purpose         :       Add a user to the Friends
*/
bool Friends::addFriend(string user2)
{
        if (friendExists(user2)) //if entered name is already a friend
                return false;           //do not do anything
        friends.push_back(user2);  //else add nameof friend to the list
        return true;                    //push_back is a function of vector class
}


