/*
 * question2.cpp
 *
 *  Created on: May 22, 2015
 *      Author: michaelzarate
 */


#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main ()
{
	int a, b;
	int n = 1;
	double insterstionSort;
	double mergeSort;


	cout << "please enter a number for a and b " << endl;
	cin >> a >> b;

	do
	{
		n = n*2;
		insterstionSort = a * pow(n, 2);
		cout <<"instertionSort time is: " << insterstionSort << endl;

		mergeSort = b * n *log2(n);
		cout <<"mergeSort time is: " << mergeSort << endl;




	}while(insterstionSort < mergeSort);

	cout << "the value of n that insertion sort beat merge sort is: " << n << endl;
}

