/*
 * Project3.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: michaelzarate
 */



#include "Project3.h"
#include "Node.h"
#include "Maze.h"
#include "Menu.h"


using namespace std;


void callDisplay(Menu *mainMenu, int nort,int eas,int sout,int wes, char currentName );
int getResponse(Menu*);
void buildMenu(Menu *mainMenu, Maze *mainMaze);




int main()
{
	Menu* mainMenu = new Menu();
	Maze* mainMaze = new Maze();
	string line;
	int steps;
	int nort = 0;
	int eas = 0;
	int sout = 0;
	int wes = 0;

	int response = 0;
	string fileName;
	char currentName;
	char cont = 'y';

	do{
		//change to do while


		cout << "Enter the name of the maze file" << endl;
		cin >> fileName;

		ifstream inputFile (fileName);
		if(inputFile.is_open())
		{
			while (getline(inputFile,line))
			{
				mainMaze->buildMaze(line);
			}
			inputFile.close();

		}
		else
		{
			cout << "Unable to open file" << endl;
			cout << "Exiting Program!!" << endl;
			return 0;
		}



		//This makes the last node in the maze has isEnd value of 1
		mainMaze->nodeVector[mainMaze->nodeVector.size()-1]->isEnd = 1;
		mainMaze->current = mainMaze->nodeVector[0]; //makes sure we start at the beginning of maze
		printf("Maze built\n");

		buildMenu(mainMenu, mainMaze);
		printf("Menu built\n");


		while(mainMaze->current->isEnd != 1)// we are not at the end of the maze
		{

			//This if/else statements gather where we can move next
			if(mainMaze->current->North==NULL)
				nort = 0;
			else
				nort = 1;

			if(mainMaze->current->East==NULL)
				eas = 0;
			else
				eas = 1;
			if(mainMaze->current->South==NULL)
				sout = 0;
			else
				sout = 1;
			if(mainMaze->current->West==NULL)
				wes = 0;
			else
				wes = 1;

			currentName = mainMaze->current->name;
			callDisplay(mainMenu, nort, eas, sout, wes, currentName);//display


			cin.ignore(); //flush the input buffer

			//This loop gets the response of the user
			do
			{
				response = getResponse(mainMenu);
			} while(response == 4);

			mainMaze->moveInMaze(response);


		}
		mainMaze->moveInMaze(4);
		steps = mainMaze->history.size(); //gets the size
		mainMenu->finalMenu(steps);
		cout << endl;
		for(int i = 0; i < steps; i++)
		{
			cout << mainMaze->history[i];
			cout << " ";
		}
		cout << endl;

		cout << "Play again?" << endl;
		cout << "(n) no      (y) yes "<< endl;
		cout << "Please enter your choice from the above menu" <<endl;
		cin.ignore();
		cin >> cont;
		mainMaze->history.clear();
		//print out the history of our movements

	}while (cont == 'y');

	delete mainMaze;
	delete mainMenu;
	return 0;

}

void callDisplay(Menu *mainMenu,int nort,int eas,int sout,int wes, char currentName)//this will receive the necessary info
{

	mainMenu->display(nort, eas, sout, wes, currentName);
}


void buildMenu(Menu *mainMenu, Maze *mainMaze)
{

	string option4 = "You are currently in room  ";
	string option12 = "  of the Pointer-Base Maze";



	mainMenu->addOption(0,"(N) North");
	mainMenu->addOption(1,"(E) East");
	mainMenu->addOption(2,"(S) South");
	mainMenu->addOption(3,"(W) West");
	mainMenu->addOption(4, option4);
	mainMenu->addOption(5, "Please enter your choice from the Menu above: ");
	mainMenu->addOption(6, "Congratulations! You have reached the finish point");
	mainMenu->addOption(7, "You took ");
	mainMenu->addOption(8, " The nodes you visited are: ");
	mainMenu->addOption(9, "Play again ??");
	mainMenu->addOption(10, "(n) No /t (y) Yes");
	mainMenu->addOption(11, "Please enter you choice from the menu above: ");
	mainMenu->addOption(12, option12);
	mainMenu->addOption(13, "Select a direction from the available choices below");
	mainMenu->addOption(14, " steps");



}

int getResponse(Menu* mainMenu)
{
	int direction;
	char inputKey;

	cin >> inputKey;

	switch(inputKey)
	{
	case 'N' :
		if(mainMenu->nflag == 1)
		{
			cout << "Please enter an option from the above Menu" << endl;
			break;
		}
		else
		{
			direction = 0;
			return direction;
			break;
		}

	case 'E':
		if(mainMenu->eflag == 1)
		{
			cout << "Please enter an option from the above Menu" << endl;
			break;
		}
		else
		{
			direction = 1;
			return direction;
			break;
		}

	case 'S':
		if(mainMenu->sflag == 1)
		{
			cout << "Please enter an option from the above Menu" << endl;
			break;
		}
		else
		{
		direction = 2;
		return direction;
		break;
		}


	case 'W':
		if(mainMenu->wflag == 1)
		{
			cout << "Please enter an option from the above Menu" << endl;
			break;
		}
		else
		{
		direction = 3;
		return direction;
		break;
		}


	default:
		cout << "You entered an invalid key!!" << endl;
		cout << "Please use 'N', 'S', 'E' or 'W'" << endl;
		return 4;

	}
	return -1;
}
