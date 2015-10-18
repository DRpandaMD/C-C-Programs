/*
 * prog1.c
 *
 *  Created on: Feb 9, 2015
 *  Author: michaelzarate
 *  CSE220 SPRING 2015, Programming for Computer Engineering
 *  HomeWorkd Number: 3
 *  Estimated time :20 + hours
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "options.h"

#define FILE_NAME 30
#define INPUT_DATA 30


/*
 * ToDo project
 *
 */


/*
 * SECTION 1 VARIABLE DECLARATION AND SETTING UP MAIN
 */
int primes = 0;
int reversal = 0;
char *filename;
char inputData[INPUT_DATA];
char *inFile;
char *outFile;

void options();
int checkPrime(int x);
int reverseNum(int y);
int palindrome(int z);



int main ( int argc, char *argv[] )
{

	int primeCheckStorage;
	int reverseNumStorage;
	int palindromeCheckStorage;
	int input = 0;
	int x = 0;
	//int y = 0;
	//int z = 0;
	int primeFlag = 0;
	int reverseFlag = 0;
	int palidromeFlag = 0;
	int readFlag = 0;
	int writeFlag = 0;


	int output;
	//char *stringToParse;
	FILE *fp = NULL;


/*
 * SECTION 2 FLAG RAISING
 * For this section we are taking the command line arguments and  going through them
 * and checking to see which ones were entered by the user
 * Additionally if one was entered by the user we will raise its appropriate flag to call associated
 * code and functions form it
 */
	for(int i = 0 ; i < argc; i++)
	{
		if(argv[i][0] == '-' && argv[i][1] == 'h')
		{
			options(); //here we are checking if there is a -h giving it precedence and breaking out of the loop
			primeFlag = 0;
			reverseFlag = 0;
			palidromeFlag = 0;
			readFlag = 0;
			writeFlag = 0;
			break;
		}

		if(argv[i][0] == '-' && argv[i][1] == 'p')
		{
			primeFlag = 1;
		}

		if(argv[i][0] == '-' && argv[i][1] == 'r')
		{
			reverseFlag = 1;
		}

		if(argv[i][0] == '-' && argv[i][1] == 'd')
		{
			palidromeFlag = 1;
		}

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
			//read data from file
			fclose(fp);

			readFlag = 1;
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
					//write to file
				fclose(fp);

			writeFlag = 1;
		}



	}
	/*
	 * For this section we will be checking if there were 3 commands entered or 2 of each command OR
	 * both of the read/write commands entered
	 * IF ANY of these conditions occur we throw and error message to the user.
	 */

	if((primeFlag == 1 && reverseFlag == 1 && palidromeFlag == 1) ||
			(primeFlag ==1 && reverseFlag == 1)|| (primeFlag == 1 && palidromeFlag == 1) ||
			(reverseFlag ==1 && palidromeFlag == 1))
	{
		printf("Please use only 1 command at a time. \n");
		printf("Usage: ./prog [-p/-r/-d] –f filename –o filename \n");


		//we are going to reset the flags to stop program flow.
		primeFlag = 0;
		reverseFlag = 0;
		palidromeFlag = 0;
		readFlag = 0;
		writeFlag = 0;

/*
 * SECION 3
 * This section of code is where all my manipulations on the files and the user input
 * happens.  WE are also check certain conditions to differentate whether or not we
 * want to take user input or input to a file or write to a file
 */

	}
	else if((primeFlag == 1) && (readFlag == 0) && (writeFlag == 0))
	{

		printf("You have selected finding a prime number. \n");
		printf("Please enter a positive integer:  \n");
		scanf("%d", &x);

		primeCheckStorage = checkPrime(x);

		if(primeCheckStorage == -1)
		{
			printf("Please enter a positive integer. \n");
		}
		else if(primeCheckStorage == 1)
		{
			printf("Number %d is a prime number. \n", x);
		}
		else
		{
			printf("Number %d is NOT a prime number. \n", x);
		}

	}
	else if((reverseFlag == 1)&& (readFlag == 0) && (writeFlag == 0))
	{
		printf("You have selected reversing a number. \n");
		printf("Please enter the integer you wish to reverse: \n");
		scanf("%d", &input);

		reverseNumStorage = reverseNum(input);
		printf("Reverse of %d is %d. \n", input, reverseNumStorage);
	}
	else if((palidromeFlag == 1) && (readFlag == 0) && (writeFlag == 0))
	{
		printf("You have selected checking if a number is  a palindrome. \n");
		printf("Please enter the integer you wish to check: \n");
		scanf("%d" , &input);
		palindromeCheckStorage = palindrome(input);
		if( palindromeCheckStorage == 1)
		{
			printf("The number %d is a palindrome \n", input);
		}
		else
		{
			printf("The number %d is NOT a palidrome \n", input);
		}


	}

	if((readFlag == 1) && (primeFlag == 1))
	{
		fp = fopen(inFile, "r");

		fscanf(fp, "%d", &output);

			//if else (call the approbate function)
			if(primeFlag == 1)
			{

				primeCheckStorage = checkPrime(output);

				if(primeCheckStorage == -1)
				{
					printf("Please enter a positive integer. \n");
				}
				else if(primeCheckStorage == 1)
				{
					printf("Number %d is a prime number. \n", output);
				}
				else
				{
				printf("Number %d is NOT a prime number. \n", output);
				}
			}

			fclose(fp);

	}
	if((readFlag == 1) && (reverseFlag == 1)) //reverse the number
	{
		fp = fopen(inFile, "r");

		fscanf(fp, "%d", &output);

		reverseNumStorage = reverseNum(output);

		printf("Reverse of %d is %d. \n", output, reverseNumStorage);
	}
	if((readFlag == 1) && (palidromeFlag == 1)) //expcitely dictate this condition
	{
		fp = fopen(inFile, "r");

		fscanf(fp, "%d", &output);
		palindromeCheckStorage = palindrome(output); //get the num from the function

		if( palindromeCheckStorage == 1)
		{
			printf("The number %d is a palindrome. \n",output );

		}
		else
		{
			printf("The number %d is NOT a palindrome. \n", output);
		}
	}


	if((writeFlag == 1) && (primeFlag == 1))
	{
		fp = fopen(outFile , "w");

		if(!fp)
		{
			puts("cannot open data file!");
			return 0;
		}

		printf("You have selected finding a prime number. \n");
		printf("Please enter a positive integer:  \n");
		scanf("%d", &x);

		primeCheckStorage = checkPrime(x);

		if(primeCheckStorage == -1)
		{
			fprintf(fp,"Please enter a positive integer. \n");
		}
		else if(primeCheckStorage == 1)
		{
			fprintf(fp,"Number %d is a prime number. \n", x);
		}
		else
		{
			fprintf(fp, "Number %d is NOT a prime number. \n", x);
		}
	}

	if((writeFlag == 1) && (reverseFlag == 1))
	{
		fp = fopen(outFile , "w");

		if(!fp)
		{
			puts("cannot open data file!");
			return 0;
		}

		printf("You have selected reversing a number. \n");
		printf("Please enter the integer you wish to reverse: \n");
		scanf("%d", &input);

		reverseNumStorage = reverseNum(input);
		fprintf(fp,"Reverse of %d is %d. \n", input, reverseNumStorage);

		}

	if((writeFlag == 1) && (palidromeFlag == 1))
	{
		fp = fopen(outFile , "w");

		if(!fp)
		{
			puts("cannot open data file!");
			return 0;
		}

		printf("You have selected checking if a number is  a palindrome. \n");
		printf("Please enter the integer you wish to check: \n");
		scanf("%d" , &input);
		palindromeCheckStorage = palindrome(input);
		if( palindromeCheckStorage == 1)
		{
			fprintf(fp,"The number %d is a palindrome \n", input);
		}
		else
		{
			fprintf(fp,"The number %d is NOT a palidrome \n", input);
		}

	}

if((writeFlag == 1) && (primeFlag == 0) && (reverseFlag == 0) && (palidromeFlag == 0))
	{
		fp = fopen(outFile , "w");

		if(!fp)
		{
			puts("cannot open data file!");
			return 0;
		}

		//get data from user
		printf("Please enter a number to write to the file");
		scanf("%s", inputData);
		fprintf(fp, "%s ",inputData); // write to the file

	}


}

/*
 * SECTION 4 (THE METHODS)
 */


int checkPrime(int x)
{
	int i;
	int primeCheck;

	if(x <= -1) // we don't want negative numbers
	{
		primeCheck = -1;
		return primeCheck;
	}
	for(i=2;i<=x/2;++i) //check the number is prime
	{
		if(x%i==0)
		{
			return 0;

		}
	}
	return 1;

/*	if(flag==0)
	{
		primeCheck = 1;
		return primeCheck;
	}

	  else
	  {
		  primeCheck = 0;
		  return primeCheck;
	  }
*/

	}


int reverseNum(int y) //reverse the number
{
	int num = y;
	int reverse = 0;
	//int input;

	while (num != 0) //here we mod 10 and reverse the number
	{
		reverse = reverse * 10;
		reverse = reverse + num%10;
		num = num/10;
	}

	return reverse;
}


int palindrome(int z) //palidrome function
{
	int num = z;
	int input =z;
	int reversed = 0;

	while (num != 0) //take a number mod 10 it and flip it
	{
	reversed = reversed * 10;
	reversed = reversed + num%10;
	num = num/10;
	}

	if(reversed == input) //make the comparison
		return 1;
	else
		return 0;
}

