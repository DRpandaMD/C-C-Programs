
#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(char letter)
{
	North = NULL;
	South = NULL;
	East = NULL;
	West = NULL;
	name = letter;
	isEnd = 0;
}


void Node::attachNewNode(Node *nN, Node *nE, Node *nS, Node *nW) //The following will receive one node at a time to set, the rest of the input variables will receive NULL
{
	if(nN != NULL)
	{
		North = nN;
	}
	if(nS != NULL)
	{
		South = nS;
	}
	if(nE != NULL)
	{
		East = nE;
	}
	if(nW != NULL)
	{
		West = nW;
	}

}

/*

Node* Node::getAttachedNode(int node)
{
	if(node == 0)
		return North;
	else if(node == 1)
		return East;
	else if(node == 2)
		return South;
	else if(node == 3)
		return West;
	else
		return NULL;
}


*/



