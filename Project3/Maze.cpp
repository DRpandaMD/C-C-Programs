/*
 * Maze.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: michaelzarate
 */

//the vector of nodes
//Another
//current node being built--currentNode
//New node being built
//5 node pointers adding current
//we need a vector called history
#include <iostream>
#include  "Maze.h"

using namespace std;


Node* Maze::doesNodeExist(char check)
{
	for(int i =0; i < nodeVector.size(); i++)
	{
		if((nodeVector[i])->name == check)
			return nodeVector[i];
	}
	return NULL;
}


void Maze::buildMaze(string line)
{


	//This will be the current node being built
	currentNode = line.at(0);

	if(doesNodeExist(currentNode)== NULL)
	{
		//current = new Node(currentNode);
		current = createNode(line.at(0));
		nodeVector.push_back(current);
	}
	else
		current = doesNodeExist(currentNode);//doesNodeExist either returns NULL or the pointer to the node



	//This will be at position 1
	if(line.at(1) != '*')
	{
		if(doesNodeExist(line.at(1)) == NULL)
		{
			adding =createNode(line.at(1));
			nodeVector.push_back(adding);
			current->attachNewNode(adding, NULL, NULL, NULL);
		}
		else
		{
			adding = doesNodeExist(line.at(1));
			current->attachNewNode(adding, NULL, NULL, NULL);
		}


	}

	//This will be at position 2
	if(line.at(2) != '*')
        {
                if(doesNodeExist(line.at(2)) == NULL)
                {
                        adding =createNode(line.at(2));
                        nodeVector.push_back(adding);
                        current->attachNewNode(NULL, adding, NULL, NULL);
                }
                else
                {
                        adding = doesNodeExist(line.at(2));
                        current->attachNewNode(NULL, adding, NULL, NULL);
                }


        }

	//This will be at position 3
	if(line.at(3) != '*')
        {
                if(doesNodeExist(line.at(3)) == NULL)
                {
                        adding =createNode(line.at(3));
                        nodeVector.push_back(adding);
                        current->attachNewNode(NULL, NULL, adding, NULL);
                }
                else
                {
                        adding = doesNodeExist(line.at(3));
                        current->attachNewNode(NULL, NULL, adding, NULL);
                }


        }

	//This will be at position 4
	if(line.at(4) != '*')
        {
                if(doesNodeExist(line.at(4)) == NULL)
                {
                        adding =createNode(line.at(4));
                        nodeVector.push_back(adding);
                        current->attachNewNode(NULL, NULL, NULL, adding);
                }
                else
                {
                        adding = doesNodeExist(line.at(4));
                        current->attachNewNode(NULL, NULL, NULL, adding);
                }


        }


}

void Maze::moveInMaze(int direction)
{

	//record where we are
	history.push_back(current->name);


	if(direction == 0)
	{
		current = current->North;
	}

	if(direction == 1)
        {
                current = current->East;
        }

	if(direction == 2)
        {
                current = current->South;
        }

	if(direction == 3)
        {
                current = current->West;
        }

	else
	{

	}

}

Node* Maze::createNode(char name)
{
	Node* returnNode = new Node(name);

	return returnNode;

}



