/*
 * Menu.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: michaelzarate
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

/*
void Menu::clearOptions()
{
	options.clear();
}

*/
/*
void Menu::removeOption(string keyword)
{
	options.erase('keyword');
}
*/

void Menu::display(int north, int east, int south, int west, char name)
{
	nflag = 0;
	eflag = 0;
	sflag = 0;
	wflag = 0;
	cout << endl;
	cout << endl;
	cout << options[4];
	cout << name;
	cout << " ";
	cout << options[12];
	cout << endl;
	cout << options[13];
	cout << "\n";
	if(north == 1)
		cout << options[0] + "\t";
	else
		nflag = 1;
	if(east == 1)
		cout << options[1] + "\t";
	else
		eflag =1;
	if(south == 1)
		cout << options[2] + "\t";
	else
		sflag =1;
	if(west == 1)
		cout << options[3] + "\t";
	else
		wflag = 1;

	cout << endl;
	cout << options[11];


}

void Menu::finalMenu(int steps)
{
	cout << endl;
	cout << endl;
	cout << options[6] << endl;
	cout << options[7];
	cout << steps;
	cout << options[14];
	cout << options[8];

}

/*
void Menu::displayTitle(string firstLine, string secondLine, string thirdLine)
{
	cout << firstLine << endl;
	cout << secondLine << endl;
	cout << thirdLine << endl;
}
*/

/*
void getResponse()
{
	int direction;
	char inputKey;

	cin >> inputKey;

	switch(inputKey)
	{
	case 'N' :
		direction = 0;
		break;

	case 'E':
		direction = 1;
		break;

	case 'S':
		direction = 2;
		break;

	case 'W':
		direction = 3;
		break;

	default:
		cout << "You entered an invalid key!!" << endl;
		cout << "Please use 'N', 'S', 'E' or 'W'" << endl;


	}
}

*/





