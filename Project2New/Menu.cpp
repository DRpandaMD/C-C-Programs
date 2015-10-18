/*
 * Menu.cpp
 *
 *  Created on: Apr 4, 2015
 *  Author: michaelzarate & Trevor Richardson
 *  Project2
 *  timespent: approx 30 hours
 */



#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include "Menu.h"

using namespace std;


void Menu::addOption(int key, string option)
{
	options[key] = option;

}

void Menu::clearMenu()
{
	options.clear();
}

void Menu::removeOption(int key)
{
	options.erase(key);
}

void Menu::display()
{
	cout << options[0] << endl;
	cout << options[1] << endl;
	cout << options[2] << endl;
	cout << options[3] << endl;
	cout << options[4] << endl;
	cout << options[5] << endl;
	cout << options[6] << endl;
}

void Menu::displayTitle(string firstLine, string secondLine, string thirdLine)
{
	cout << firstLine << endl;
	cout << secondLine << endl;
	cout << thirdLine << endl;
}
