/*
 * Wall.cpp
 *
 *  Created on: Apr 4, 2015
 *  Author: michaelzarate & Trevor Richardson
 *  Project2
 *  timespent: approx 30 hours
 */




#include <sstream>
#include <string>
#include <vector>
#include "systemMain.h"
#include "Wall.h"
#include "User.h"


// wall should just display the USERS messages
// home is USER and FRIENDS messages
using namespace std;





void Wall::addMessage(string user1, string message1)
{

	 messages.push_back(user1);
	 messages.push_back(message1);
	 size = size + 2;
}
