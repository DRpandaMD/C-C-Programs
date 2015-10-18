/*
 * question1.cpp
 *
 *  Created on: May 22, 2015
 *      Author: michaelzarate
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main ()
{

	int array[5];

	cout << "please enter 5 numbers separated by spaces" << endl;
	cin >> array[0] >> array[1] >> array[2] >> array[3] >> array[4];

	for(int i = 4; i >= 0; i--)
	{
		cout << array[i] << endl;
	}
}



