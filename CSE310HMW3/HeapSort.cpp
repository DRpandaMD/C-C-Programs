/*
 * HeapSort.cpp
 *
 *  Created on: Jun 10, 2015
 *      Author: michaelzarate
 */





#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;


void build_maxheap(float array[], int size);
void max_heapify(float array[],int i,int size);
void heapsort(float array[], int size);


int counter = 0;


int main()
{

	//where do i put the comparison

	//when reading in the number skip array[0]
	//heap wont work when i*0 = 0!!!
	float sortArray[150];
	int size;
	int n = 1;

	string fileName;
	string line;

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

	size = n;

	heapsort(sortArray, size);

	cout << "Sorting done...\n";
	for(int i = 2; i < n+1; i++)
	{
		cout << " " << sortArray[i] << endl;

	}

	/*
	 *
	 */

	//write to a file
	string outputFileName = "HeapSorted_" + fileName;
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
		comparisonFile <<"HeapSort \t" <<fileName << "\t" <<
				"Number of Comparisons:  " << counter << endl << endl;
		comparisonFile.close();
	}
	else
	{
		cout << "Comparisons File could not be opened" << endl;
	}



	return 0;

}

void heapsort(float array[], int size)
{
	int i;
	float temp;

	build_maxheap(array, size);

	for(i = size; i >= 2; i--)
	{
		temp = array[i];
		array[i] = array[1];
		array[1] = temp;
		max_heapify(array, 1, i-1);
	}
}
void max_heapify(float array[],int i,int size)
{
	int j;
	float temp;
	temp = array[i];
	j = 2*i;

	while(j <= size)
	{
		//check the cases

		if (j + 1 < size && array[j+1] > array[j])
			j = j+1;
		if(temp > array[j])
			break;


		else if(temp <= array[j])
		{
			array[i] = array[j];
			array[j] = temp;
		}

		i = j;
		temp = array[i];
		j = 2*i;

		///check the book for recursive calling

	}

	return;
}


void build_maxheap(float array[], int size)
{
	int i;
	for(i = size/2; i >= 1; i--)
	{
		max_heapify(array,i,size);
	}
}
