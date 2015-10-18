/*
 * Menu.h
 *
 *  Created on: Apr 24, 2015
 *      Author: michaelzarate
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
	string keyword;


public:


	int nflag, eflag, sflag, wflag;
	void addOption(int, string);
	void display(int north, int east, int south, int west, char name);
	void finalMenu(int steps);
};




#endif /* MENU_H_ */
