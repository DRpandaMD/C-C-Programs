/*
 * Maze.h
 *
 *  Created on: Apr 24, 2015
 *      Author: michaelzarate
 */



#ifndef MAZE_H_
#define MAZE_H_
#include <vector>
#include "Node.h"

using namespace std;

class Maze
{

public:
	int north;
	int east;
	int south;
	int west;
	vector<Node*> nodeVector;
	vector<char> history;
	char currentNode;
	Node *current;
	Node *adding;

	void buildMaze(string line);
	void moveInMaze(int direction);
	Node* doesNodeExist(char check);
	Node* createNode(char name);

};


#endif /* MAZE_H_ */
