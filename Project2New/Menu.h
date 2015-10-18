/*
 * Menu.h
 *
 Created on: Apr 4, 2015
 *  Author: michaelzarate & Trevor Richardson
 *  Project2
 *  timespent: approx 30 hours
 */

#ifndef MENU_H_
#define MENU_H_


#include <string>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

/*
 * This class handles the menu creation and menu map
 */

class Menu
{
private:

	map<int, string> options; ///a map of options
	string title;


public:
	void addOption(int, string);
	void clearMenu();
	void removeOption(int);
	void display();

	inline void setTitle(string newTitle)
	{
		title = newTitle;
	}
	void displayTitle(string firstLine, string secondLine, string thirdLine);

};


#endif /* MENU_H_ */
