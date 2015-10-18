/*
 * main.cpp
 *
 *  Created on: Apr 5, 2015
 *  Author: michaelzarate & Trevor Richardson
 *  Project2
 *  timespent: approx 30 hours
 */


#include "main.h"
#include "systemMain.h"
#include "Menu.h"
#include "Wall.h"
#include "User.h"
#include "Friends.h"
using namespace std;

int main()
{
	System* mainSystem = new System();
	Menu* mainMenu = new Menu();
	int decision, wallDecision, homeDecision;
	string desiredUser = "";


	mainSystem->initilizeUsers();
	mainMenu->displayTitle("\t\t\t#########################################",
			"\t\t\t#\tWelcome to my Scrabook App!\t#",
			"\t\t\t#########################################\n\n");
	mainMenu->addOption(0,  "(1)\t Create New User");
	mainMenu->addOption(1,  "(2)\t Post Message");
	mainMenu->addOption(2,  "(3)\t Display Wall Page");
	mainMenu->addOption(3,  "(4)\t Display Home Page");
	mainMenu->addOption(4,  "(5)\t Add Friend");
	mainMenu->addOption(5,  "(6)\t Switch to Existing User");
	mainMenu->addOption(6,  "(7)\t Quit Scrap Book");

	mainMenu->display();
	decision = 0;
	wallDecision = 0;
	homeDecision = 0;
	while(decision != 7)
	{
		//for now we dont know how to protect against letters
		cin >> decision;

		switch(decision)
		{
			case 1:
			{
				mainSystem->createNewUser();
				mainMenu->displayTitle("\t\t\t#########################################",
							"\t\t\t#\t\tWelcome " + mainSystem->currentUser->getUserName() + "\t\t#",
							"\t\t\t#########################################\n\n");
				mainMenu->display();
				cin.ignore();
				//cin >> decision;
				break;
			}
			case 2:
			{
				mainSystem->postMessage();
				mainMenu->display();
				//cin >> decision;
				break;
			}
			case 3: //**WALL**//
			{
				cout << "\n\n\n";
				cout << "Enter 1 for 'Display recent wall page messages'" << endl;
				cout << "Enter 2 for 'Display all wall page messages'" << endl;
				cin.ignore();
				cin >> wallDecision;
				mainMenu->displayTitle("\t\t\t#########################################",
											"\t\t\t#\t        " + mainSystem->currentUser->getUserName() + " WallPage\t\t#",
											"\t\t\t#########################################\n\n");
				if(wallDecision == 1)
				{
					mainSystem->displayRecentWall();

				}
				else
				{
					mainSystem->displayAllWallPage();
				}
				mainMenu->display();
				cin.ignore();
				//cin >> decision;
				break;
			}
			case 4: //**HOME**//
			{
				cout << "\n\n\n";
				cout << "Enter 1 for 'Display recent home page messages'" << endl;
				cout << "Enter 2 for 'Display all home page messages'" << endl;
				cin >> homeDecision;
				mainMenu->displayTitle("\t\t\t#########################################",
															"\t\t\t#\t        " + mainSystem->currentUser->getUserName() + " HomePage\t\t#",
															"\t\t\t#########################################\n\n");
				if(homeDecision == 1)
				{
					mainSystem->displayRecentHome();

				}
				else
				{
					mainSystem->displayALLHomepage();
				}
					mainMenu->display();
					cin.ignore();
					//cin >> decision;
					break;

			}
			case 5: //**ADD FRIEND**//
			{

				mainSystem->addFriend();
				mainMenu->display();
				cin.ignore();
				//cin >> decision;
				break;
			}
			case 6: //**SWITCH USER**//
			{

				cout << "\n\n\n";
				cout << "Enter the name of the user you wish to switch to? Or "
						" you can type in <menu> to exit this option and return to main menu" << endl;
				cin >> desiredUser;
				if(desiredUser != "menu")
				{
					mainSystem->switchUser(desiredUser);
				}

				mainMenu->displayTitle("\t\t\t#########################################",
					"\t\t\t#\t\tWelcome back " + mainSystem->currentUser->getUserName() + "\t \t#",
					"\t\t\t#########################################\n\n");

				mainMenu->display();
				cin.ignore();
				//cin >> decision;
				break;
			}
			case 7: //**QUIT OPTION**//
			{

				mainMenu->displayTitle("\t\t\t#########################################",
						"\t\t\t#  Thank You for using My ScrapBook\t#",
						"\t\t\t#########################################\n\n");


				delete mainMenu;
				delete mainSystem;
				return 1;
				break;
			}

			default:
			{
				cout << "You entered a number incorrectly" << endl;
				cout << "You must enter an integer from 1-7" << endl;
				cout << "\n\n";
				mainMenu->display();
				cin.ignore();
				//cin >> decision;
				break;
			}
		}

	}
	delete mainMenu;
	delete mainSystem;
	return 1;

}
