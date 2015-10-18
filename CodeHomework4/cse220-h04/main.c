/*
 * main.c
 *
 *  Created on: Feb 17, 2015
 *  Author: michaelzarate
 *  CSE220 SPRING 2015, Programming for Computer Engineering
 *  HomeWorkd Number: 4
 *  Estimated time :20 + hours
 *
 *  *arrays and structures* for cyrpto analysis
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "count.h"


char *inFile;
char *outFile;
char imputStream[100];


FILE *fp = NULL;

int main ( int argc, char *argv[] )
{

	int readFlag = 0;
	int writeFlag = 0;
	int csvFlag = 0;
	int fileFlag = 0;
	char *standardInFile = "standardInFile.txt";
	char *standardOutFile = "standardOutFile.txt";

	int terminalOutFile;


	FILE *fp = NULL;



	for(int i = 0 ; i < argc; i++)
	{


		if(argv[i][0] == '-' && argv[i][1] == 'f')// get file name and READ from File
		{

			//check to see if there is a file name
			if( argv[i+1] == NULL)
			{
				printf("expecting argument following -f \n");
			}
			//copy file name
			inFile = argv[i+1];

			fp = fopen(inFile, "r");

			if(!fp)
			{
				printf("Can not open %s \n" , inFile);
				return 0;
			}
			else
			{
				//read data from file
				fclose(fp);

				readFlag = 1;
				fileFlag = 1;
			}
		}

		if(argv[i][0] == '-' && argv[i][1] == 'o')
		{
			//check to see if there is a file name
			if( argv[i+1] == NULL)
			{
			printf("expecting argument following -o \n");
			}

			//copy file name
			outFile = argv[i+1];

			fp = fopen(outFile, "w");

			//write data from user to file

			if(!fp)
			{
			printf("Can not open %s \n" , outFile);
			return 0;
			}
			else
			{
				//write to file
				fclose(fp);

				writeFlag = 1;
				fileFlag = 1;
			}
		}

		if(argv[i][0] == '-' && argv[i][1] == 'c')
		{
			csvFlag = 1;
		}



	}
	/*
	 * So for this section we need to make sure that the user
 	 * enters in the read file the write file to ensure that we can pass
 	 * the argument to the method the right way.
	 */

	if((readFlag == 0 ) && (writeFlag == 0 ) && (csvFlag == 0))
	{
		printf("Welcome to the Cytographic Letter Tracker.\n");
		printf("This program will count the occurrence of letters,\n "
				"And the occurrence of lettered Pairs \n");
		printf("Please Enter your string Now! (be sure to leave\n"
				"one extra space at the end of the last word!! Use the return key to stop.)");
		/*printf("Please specify the file you want to read from and the file "
				"you want the output to go to\n");
		printf("Usage: ./prog [-c] –f filename –o filename \n");
		*/
		gets(imputStream);
		printf("Entered string: %s\n", imputStream);
		fp = fopen(standardInFile, "w");
		if(!fp)
		{
			puts("cannot open data file!");
			return 0;
		}


		fprintf(fp,imputStream);
		fclose(fp);

		csvFlag = 0;
		fileFlag = 1;
		computeOccurrences(standardInFile, standardOutFile, fileFlag, csvFlag);

		//Now open the file for reading
		fp = fopen(standardOutFile, "r");
		if(!fp)
		{
			printf("Can not open %s \n" , standardOutFile);
			return 0;
		}

		terminalOutFile = fgetc(fp);

		while(terminalOutFile != EOF)
		{

			putchar(terminalOutFile);
			terminalOutFile = fgetc(fp);
		}

		fclose(fp);



	}
	if((readFlag == 1 ) && (writeFlag == 0 ) && (csvFlag == 0))
	{

		printf("Please specify the file you want to read from and the file \n"
				"you want the output to go to\n");
		printf("Usage: ./prog [-c] –f filename –o filename \n");

	}

	if((readFlag = 0 ) && (writeFlag == 1 ) && (csvFlag == 0))
	{

		printf("Please specify the file you want to read from and the file \n"
				"you want the output to go to\n");
		printf("Usage: ./prog [-c] –f filename –o filename \n");
	}

	if((readFlag = 1 ) && (writeFlag == 1 ) && (csvFlag == 0))
	{
		computeOccurrences(inFile, outFile, fileFlag, csvFlag);
	}

	if((readFlag = 1 ) && (writeFlag == 1 ) && (csvFlag == 1))
	{
		computeOccurrences(inFile, outFile, fileFlag, csvFlag);
	}



}
