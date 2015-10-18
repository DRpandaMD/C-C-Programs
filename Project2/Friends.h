/*
 * Friends.h
 *
 *  Created on: Mar 30, 2015
 *      Author: michaelzarate
 */

#ifndef FRIENDS_H
#define FRIENDS_H

#include <vector>
#include <string>

using namespace std;
class Friends
{
	public:
	Friends(string);
	bool addFriend(string);
	bool friendExists(string);

	/**
   	Function Name   :       getFriends
    Purpose         :       retrieves the friend list
    */
    inline vector<string> getFriends()
    {
    	return friends;
    }

	private:
    vector<string> friends;
    string user;
};

#endif
