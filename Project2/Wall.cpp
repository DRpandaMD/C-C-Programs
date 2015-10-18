/*
 * Wall.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: michaelzarate
 */




#include <sstream>
#include <string>
#include "User.h"
#include "Wall.h"

using namespace std;

Wall::Wall(string)
{
	&messageBuffer = string;

}

void Wall::addMessage(string)
{
	&messageBuffer += string;

}

void Wall::display()
{
	cout << "Message buffer content is: " << messageBuffer;

}

bool Wall::msgPostedByUser(string aUser, string theMessage)
{
	// if the user doesn't exist don't do anything
	// if the user does exist but the message doesn't
	// if both check out then return true
	return true;
}
