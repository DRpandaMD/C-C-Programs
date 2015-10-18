/*
 * Scope.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: michaelzarate
 */



#include <iostream>

using namespace std;

int main()
{
	int x = 10;
	int y = 20;
	{
		int x;
		x = 50;
		y = 50;
		cout << "inner block scope: \n";
		cout << "x:" << x << '\n';
		cout << "y:" << y << '\n';
	}
}
