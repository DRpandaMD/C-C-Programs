/*
 * SystemMain.cpp
 *
 *  Created on: Apr 5, 2015
 *  Author: michaelzarate & Trevor Richardson
 *  Project2
 *  timespent: approx 30 hours
 */



#include <vector>
#include <string>
#include "SystemMain.h"
#include <iostream>

using namespace std;

void System::initilizeUsers()
{
	User* standardUser1 = new User("Joe");
	allUsers.push_back(standardUser1);

	User* standardUser2 = new User("Bob");
	allUsers.push_back(standardUser2);

	User* standardUser3 = new User("Mark");
	allUsers.push_back(standardUser3);

	User* standardUser4 = new User("Jane");
	allUsers.push_back(standardUser4);

	standardUser4->wall.size=0;
	standardUser4->friends.friendSize=0;
	sizeKey = 4;
}

void System::createNewUser()
{
	string nameHolder;

	cout<<"Please enter your name" << endl;

	cin >> nameHolder;

	User* newUser1 = new User(nameHolder);
	allUsers.push_back(newUser1);

	currentUser = newUser1;
	sizeKey++;


}

int System::switchUser(string desiredUser)
{

	for(int i = 0; i < allUsers.size(); i++)
	{
		if(desiredUser == (*allUsers[i]).getUserName())
		{
			currentUser = allUsers[i];
			return 1;

		}



	}
	cout << "User does not exist try again!!!" << endl;
	return 0;

}

void System::postMessage()
{

	string messageStorage;
	cout << "Please enter your message: "<< endl;
	cin.ignore();

	getline(cin, messageStorage);


	currentUser->wall.addMessage(currentUser->getUserName(), messageStorage);

}

void System::displayAllWallPage()
{
	cout << "Before The for loop\n\n\n";
	for(int i = (currentUser->wall.size-1); i>=0; i = i - 1)
		{

			if((*currentUser).wall.messages[i] == currentUser->getUserName())
			{

				cout << currentUser->getUserName() + ": " << currentUser->wall.messages[i+1] << endl;

			}

		}
}

int System::addFriend()
{

	cout << "Enter the name of the user you wish to add to your friend list or enter <menu> to go back to home page" << endl;
	cin >> friendName;
	if(friendName == "menu")
		return 0;
	else
	{
		currentUser->addFriends(friendName); //trying to call the function add friends and send it friend name
		return 1;
	}
}

void System::displayALLHomepage()
{

	for(int i = (currentUser->wall.size-1); i>=0; i = i - 1)
			{
				if(currentUser->wall.messages[i] == currentUser->getUserName())
				{
					cout << currentUser->wall.messages[i] + ": " << currentUser->wall.messages[i+1] << endl;

				}

			}

	for(int j = 0; j <sizeKey ; j++)
	{

			if( currentUser->isFriend(allUsers[j]->getUserName()) == true)
			{
				for( int m= (allUsers[j]->wall.size-1); m>=0; m = m - 1)
							{
								if(allUsers[j]->wall.messages[m] == allUsers[j]->getUserName())
								{
									cout << allUsers[j]->wall.messages[m] + ": " << allUsers[j]->wall.messages[m+1] << endl;

								}

							}
			}

	}
}

void System::displayRecentHome()
{
	bool trueCheck = false;
	for(int i = 0; i < allUsers.size(); i++)
	{
		trueCheck = currentUser->isFriend(allUsers[i]->getUserName());
		if(trueCheck == true)
		{
			for(int i = (currentUser->wall.size-1); i>=0; i = i - 1)
				{
					if( currentUser->isFriend(currentUser->wall.messages[i]) == true)
					{
						cout << currentUser->wall.messages[i] + ": " << currentUser->wall.messages[i+1] << endl;
						trueCheck = false;
						break;
					}
					else if(currentUser->wall.messages[i] == currentUser->getUserName())
					{
						cout <<  currentUser->wall.messages[i] + ": " <<currentUser->wall.messages[i+1]<< endl;
						trueCheck = false;
						break;
					}


				}
		}

	}

}

void System::displayRecentWall()
{
	for(int i = (currentUser->wall.size-1); i>=0; i = i - 1)
		{
			if(currentUser->wall.messages[i] == currentUser->getUserName())
			{
				cout << currentUser->getUserName() + ": " << currentUser->wall.messages[i+1] << endl;
				break;
			}


		}
}








