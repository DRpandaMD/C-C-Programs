/*
 * Wall.h
 *
 * Created on: Apr 4, 2015
 *  Author: michaelzarate & Trevor Richardson
 *  Project2
 *  timespent: approx 30 hours
 */

#ifndef WALL_H_
#define WALL_H_

#include <sstream>
#include <string>


using namespace std;


/*
 *
 * This class Handles the Wall
 *
 * NOTES:: i am pretty sure that we have to move the wall
 * manipulation and user storage to just user
 * let User be a simple version of itself
 *
 */

class User; //we had to find this solution on the internet we didn't go over anything like this in class

class Wall
{
private:

	//string &messageBuffer;
	string user;
	string allMessages();


public:

	int size;
	vector <string> messages;
	void addMessage(string user1, string message1);
	//void display(User& mainUser);
	bool msgPostedByUser(string, string);


};



#endif /* WALL_H_ */
