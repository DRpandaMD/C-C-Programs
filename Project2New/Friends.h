/*
 * Friends.h
 *
 Created on: Apr 54, 2015
 *  Author: michaelzarate & Trevor Richardson
 *  Project2
 *  timespent: approx 30 hours
 */

#ifndef FRIENDS_H_
#define FRIENDS_H_


#include <vector>
#include <string>

using namespace std;


/*
 * this class handles all the friends for the User
 */

class Friends
{

private:

	string user;
	vector<string> friends;
public:

	int friendSize;
	Friends(string user);
	bool addFriend(string userFriend);
	bool friendExists(string userFriend);

	inline vector<string> getFriends()
	{
		return friends;
	}

};


#endif /* FRIENDS_H_ */
