/*
 * referenceVariables.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: michaelzarate
 */


#include <iostream>

using namespace std;

int main()
{
	int x = 3;
	int &y = x;

	cout << "x =" <<x<< endl << "y=" <<y<< endl;
}
