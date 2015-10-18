/*
 * BinarySearchTree.cpp
 *
 *  Created on: Jun 24, 2015
 *      Author: michaelzarate
 */



/*
 * This Class will implement Binary Search Tree concepts
 * and the main() to run the implementation
 */

#include <iostream>
#include <string>

using namespace std;

class BinarySearchTree
{

public:
	class node
	{
	public:

		node* left;
		node* right;
		node* parent;
		int key;
		string data;

	};



	node* root;
	BinarySearchTree() //constructor sets root to null
	{
		root = NULL;
	}

	bool isEmpty () const
	{
		return root == NULL; // checks to see if the root is null
	}

	void INORDER_TREE_WALK(node*);
	void PREORDER_TREE_WALK(node* x);
	void POSTORDER_TREE_WALK(node* x);
	BinarySearchTree::node* TREE_MAXIMUM(node* x);
	BinarySearchTree::node* TREE_MINIMUM(node* x);
	BinarySearchTree::node* TREE_SUCCESOR(node* x);
	BinarySearchTree::node* TREE_SEARCH(int x);
	void TREE_INSERT(int key);
	BinarySearchTree::node* TREE_DELETE_NODE(int key, node* root);


};

void BinarySearchTree::TREE_INSERT(int number)
{
	//Implements the alorithm on page 261 of the textbook

	node* z = new node();
	z->key = number;
	z->left = NULL;
	z->right = NULL;

	node* y = NULL;
	node* x = root;
	node* parent = NULL;

	while(x != NULL) //we don't have an empty tree
	{
		y = x;

		if(z->key < x->key) //if the number we are putting in is less than the root

			x = x->left; //move it on the left

		else
			x = x->right; // move it on the right
	}

	parent = y;

	if (y == NULL)
		root = z;
	// we have no parent thus the tree is empty z the new number becomes root

	else if(z->key < y->key)
		y->left = z;  //put the new number in the left side
	else
		y->right = z; //put the new number on the right side
}

void BinarySearchTree::INORDER_TREE_WALK(node* x)
{
	if(x != NULL)
	{
		if(x->left)INORDER_TREE_WALK(x->left);
		cout << " " << x->key << " ";
		if(x->right)INORDER_TREE_WALK(x->right);
	}
}

void BinarySearchTree::PREORDER_TREE_WALK(node* x)
{

	if(x != NULL)
	{
		cout << " " << x->key << " ";
		if(x->left)PREORDER_TREE_WALK(x->left);
		if(x->right)PREORDER_TREE_WALK(x->right);
	}
}

void BinarySearchTree::POSTORDER_TREE_WALK(node* x)
{
	if(x != NULL)
	{
		if(x->left)POSTORDER_TREE_WALK(x->left);
		if(x->right)POSTORDER_TREE_WALK(x->right);
		cout << " " << x->key << " ";
	}
}

BinarySearchTree::node * BinarySearchTree::TREE_MAXIMUM(node* x)
{
	while(x->right != NULL)
	{
		x = x->right;
	}
	return x;
}

BinarySearchTree::node* BinarySearchTree::TREE_MINIMUM(node* x)
{
	while(x->left != NULL)
	{
		x = x->left;
	}
	return x;
}

BinarySearchTree::node* BinarySearchTree::TREE_SEARCH(int x)
{
	node* y = root;

	while(y != NULL && x != y->key )
	{
		if(x < y->key)
		{
			y = y->left;
		}
		else
		{
			y = y->right;
		}
	}
	return y;
}

BinarySearchTree::node* BinarySearchTree::TREE_SUCCESOR(node* x)
{
	node* y = NULL;


	if(x->right != NULL)
	{
		return TREE_MINIMUM(x->right);
	}
	else
	{
		y = x->parent;

		while(y != NULL && x == y->right)
		{
			x = y;
			y = y->parent;
		}
		return y;

	}

}

BinarySearchTree::node* BinarySearchTree::TREE_DELETE_NODE(int key, node* root)
{
	if(root == NULL) return root;
	else if( key < root->key) root->left = TREE_DELETE_NODE(key,root->left);
	else if( key > root->key) root->right = TREE_DELETE_NODE(key,root->right);

	//done with the root
	//on to the case handeling

	else
	{
		//Case1: there are no children nodes
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}

		//Case 2: only one child

		else if(root ->left == NULL)
		{
			BinarySearchTree::node* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL)
		{
			BinarySearchTree::node* temp = root;
			root = root->left;
			delete temp;
		}

		else
		{
			BinarySearchTree::node* temp = TREE_MINIMUM(root->right);
			root->key = temp->key;
			root->right = TREE_DELETE_NODE(temp->key,root->right);
		}
	}
	return root;


}




/*
 * Below here is the Main function
 */


int main()
{

//	BinarySearchTree::node* searchNode;
//	BinarySearchTree::node* returnNode;
	BinarySearchTree bst;
	int choice, key;

	while(true)
	{
		cout << endl << endl;
		cout << "Binary Search Tree Example " << endl;
		cout << " -----------------------------" << endl;
		cout << "1. Insert a Node" << endl;
		cout << "2. Pre-Order Traversal" << endl;
		cout << "3. Post-Order Traversal" << endl;
		cout << "4. In-Order Traversal " << endl;
		cout << "5. Find Maximum " << endl;
		cout << "6. Successor" << endl;
		cout << "7. Delete a Node" << endl;
		cout << "8. Exit! " << endl;

		cin >> choice;

		switch(choice)
		{
			case 1: cout << "Enter a key (int value) to be inserted to the BST : " << endl;
					cin >> key;
					bst.TREE_INSERT(key);
					break;

			case 2: cout << endl;
					cout << " Pre-Order Traversal " << endl;
					cout << " --------------------" << endl;
					bst.PREORDER_TREE_WALK(bst.root);
					break;

			case 3: cout << endl;
					cout << " Post-Order Traversal " << endl;
					cout << " --------------------" << endl;
					bst.POSTORDER_TREE_WALK(bst.root);
					break;

			case 4: cout << endl;
					cout << " In-Order Traversal " << endl;
					cout << " --------------------" << endl;
					bst.INORDER_TREE_WALK(bst.root);
					break;

			case 5: cout << endl;
					cout << "Finding Maximum Value " << endl;
					cout << "----------------------" << endl;
					cout << "the maximum is: " << bst.TREE_MAXIMUM(bst.root)->key;
					break;

			case 6: cout << endl;
					cout << "Find a successor node" << endl;
					cout << "Enter node to find successor of:" << endl;
					cin >> key;
					cout << "the Succesor of " << key << "is: " <<   bst.TREE_SUCCESOR(bst.TREE_SEARCH(key))->key;
					break;

			case 7: cout << endl;
					cout << "Delete a Node: " << endl;
					cout << "Enter a key value to delete specific node:" << endl;
					cin >> key;
					bst.TREE_DELETE_NODE(key,bst.root);
					cout << "Node deleted!!" << endl;
					break;


			case 8: cout << endl;
					cout << "Exiting the program!!" << endl;
					system("pause");
					return 0;
					break;

			default:
					cout << "invalid choice try again" << endl;

		}
	}

}
