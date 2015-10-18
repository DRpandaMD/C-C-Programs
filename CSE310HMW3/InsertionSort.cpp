/*
 * InserstionSort.cpp
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


int insertionSort(float array[], int length, int count);



int main()
{
	int count = 0;
	int n = 0;
	float sortArray[150] = {0};

	string fileName;
	string line;
	string::size_type size;

	cout << "Enter the file name to read from" << endl;
	cin >> fileName;

	ifstream inputFile(fileName);
	if(inputFile.is_open())
	{

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


	cout << "start sorting " << endl;


	count = insertionSort(sortArray, n, count);
	cout << "Sorting done...\n";
	for(int i = 0; i < n; i++)
	{
		cout << " " << sortArray[i] << endl;

	}

	cout << "The Amount of comparisons were " << count << endl;


	/*
	 *
	 */

	//write to a file
	string outputFileName = "InsertionSorted_" + fileName;
	ofstream outputFile;
	outputFile.open(outputFileName);
	for(int i = 0; i < n; i++)
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
		comparisonFile <<"InsertionSort \t" <<fileName << "\t" <<
				"Number of Comparisons:  " << count << endl << endl;
		comparisonFile.close();
	}
	else
	{
		cout << "Comparisons File could not be opened" << endl;
	}

	return 0;

}


int insertionSort(float array[], int length, int count)
{
	int i, j, counter;
	float temp;
	counter = count;

	for(i = 1; i < length; i++)
	{
		j = i;

		while(j > 0)
		{
			counter++;

			if(array[j] < array[j-1]) {
				temp = array[j];
				array[j] = array[j-1];
				array[j-1] = temp;

			}
			j--;
		}

	}
	return counter;
}


