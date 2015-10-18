/*
 * options.c
 *  Created on: Feb 9, 2015
 *  Author: michaelzarate
 *  CSE220 SPRING 2015, Programming for Computer Engineering
 *  HomeWorkd Number: 3
 *  Estimated time :20 + hours
 */

#include "options.h"



void options()
{
	printf("Usage: ./prog [option] \n  "  );
	printf("Options: \n");
	printf("\t -h \t\t Display a help message and exit. \n");
	printf("\t -p \t\t Check if the given number is prime or not. \n");
	printf("\t -r \t\t Compute the reverse of given number. \n");
	printf("\t -d \t\t Check if the given number is a palindrome. \n");
	printf("\t -f filename \t Read input from textfile named filename. \n");
	printf("\t -o filename \t Output the results to the file named filename. \n");
}
