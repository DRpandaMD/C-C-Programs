/*
 * Wall.h
 *
 *  Created on: Mar 30, 2015
 *      Author: michaelzarate
 */

#ifndef WALL_H
#define WALL_H
#include <sstream>
#include <string>
#include "User.h"

using namespace std;

class Wall
{
        public:
                Wall(string, string&);
                void addMessage(string);
                void display();
                bool msgPostedByUser(string, string); //(user, message)
        private:
                string &messageBuffer; // A reference to the main messageBuffer.
                string user; // Name of the user.
                string allMessages();
};
#endif
