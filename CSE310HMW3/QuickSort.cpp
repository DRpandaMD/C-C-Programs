/*
 * QuickSort.cpp
 *
 *  Created on: Jun 10, 2015
 *      Author: michaelzarate
 */



#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iosfwd>

using namespace std;




void quickSort(float array[], int left, int right);
void swap(float *a, float *b);
int partition(float array[], int pivot, int start, int end);



int counter= 0;


int main()
{

	float sortArray[150];
	float left = 0;
	float right = 0;
	int n = 0;

	string fileName;
	string line;

	cout << "Enter the file name to read from" << endl;
	cin >> fileName;

	ifstream inputFile(fileName);
	if(inputFile.is_open())
	{
		cout << " after .is_open()  " << endl;
		while(getline(inputFile,line))
		{

			if(line.empty())
				break;
			sortArray[n] = (float)atof(line.c_str());
			n++;

			cout << line << endl;
		}
		inputFile.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
	}


	left = 0;
	right = n;

	quickSort(sortArray,left,right);



	cout << "Sorting done...\n";
	for(int i = 1; i < n+1; i++)
	{
		cout << " " << sortArray[i] << endl;

	}

	cout << "The Amount of comparisons were " << counter << endl;


	/*
	 *
	 */

	//write to a file
	string outputFileName = "QuickSorted_" + fileName;
	ofstream outputFile;
	outputFile.open(outputFileName);
	for(int i = 1; i < n+1; i++)
	{
		outputFile << sortArray[i] << endl;
	}
	outputFile.close();

	/*
	 *
	 */



	ofstream comparisonFile;
	comparisonFile.open("Comparisons.txt", ios::app);
	if(comparisonFile.is_open())
	{


		comparisonFile <<"QuickSort \t" <<fileName << "\t" <<
				"Number of Comparisons:  " << counter << endl << endl;
		comparisonFile.close();
	}
	else
	{
		cout << "Comparisons File could not be opened" << endl;
	}

}




//where to put the comparison counter

void quickSort(float array[], int left, int right)
{

	float pivot = array[left];
	int middle;

	if(right > left)
	{
		middle = partition(array, pivot, left, right);

		array[middle] = pivot;
		quickSort(array, left, middle-1);
		quickSort(array, middle+1, right);
	}

}

int partition(float array[], int pivot, int start, int end)
{
	int leftSide = start;
	int rightSide = end;

	//how is this comparing
	counter += (end - start) + 1;

	while(leftSide < rightSide)
	{
		while(pivot < array[rightSide] && rightSide > leftSide)
		{
			rightSide--;
		}
		swap(array[leftSide], array[rightSide]);

		while(pivot >= array[leftSide] && leftSide < rightSide)
		{
			leftSide++;
		}
		swap(array[rightSide], array[leftSide]);


	}
	return leftSide;

}

void swap(float *a, float *b)
{
	float temp = *a;
	*a = *b;
	*b = temp;
}




