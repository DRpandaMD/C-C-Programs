/*
 * Menu.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: michaelzarate
 */


#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "Menu.h"

using namespace std;

/**
Function Name   :       addOption
Purpose         :       Add an option to Menu list
*/
void Menu::addOption(int key, string value)
{
        options[key] = value;
}

/**
Function Name   :       clearMenu
Purpose         :       Clears the Menu list
*/
void Menu::clearMenu()
{
        options.clear();
}

/**
Function Name   :       getTitle
Purpose         :       Display the Menu title
*/
void Menu::getTitle()
{
        cout << "-------" << title << "-------" << endl;
}

/**
Function Name   :       getResponse
Purpose         :       Retrieve the user choice from MEnu selection
*/

///Write Code for this??????



/**
Function        :       display
Purpose         :       Displays the menu and gets the option selected by the user.
*/

/// Write Code for this??????

