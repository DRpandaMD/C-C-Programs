/*
 * SystemMain.h
 *
 * Created on: Apr 5, 2015
 *  Author: michaelzarate & Trevor Richardson
 *  Project2
 *  timespent: approx 30 hours
 */

#ifndef SYSTEMMAIN_H_
#define SYSTEMMAIN_H_


#include <vector>
#include <string>
#include "Wall.h"
#include "User.h"
#include "Menu.h"

#include <iostream>

using namespace std;

/*
 * This class handles the robust handling all the all the objects
 * in the creation of itself being an object
 * our main() relys heavily on this class for usage
 */

class System
{

private:
	vector<User*> allUsers;

	string friendName;
	int sizeKey;
public:
	User *currentUser;
	void createNewUser();
	void initilizeUsers();
	int switchUser(string desiredUser);
	void postMessage();
	void displayAllWallPage();
	void displayALLHomepage();
	int addFriend();
	void displayRecentHome();
	void displayRecentWall();


};


#endif /* SYSTEMMAIN_H_ */
