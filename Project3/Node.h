/*
 * Node.h
 *
 *  Created on: Apr 24, 2015
 *      Author: michaelzarate
 */

#ifndef NODE_H_
#define NODE_H_


using namespace std;

class Node
{
public:
	char name;
	int isEnd;
	Node* North;
	Node* East;
	Node* South;
	Node* West;

	Node(char);
	void attachNewNode(Node *nN, Node *nS, Node *nE, Node *nW);
	//Node* getAttachedNode(int node);
	void buildMaze(string line);

};



#endif /* NODE_H_ */
