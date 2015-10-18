/*
 * count.h
 *
 *  Created on: Feb 19, 2015
 *  Author: michaelzarate
 *  CSE220 SPRING 2015, Programming for Computer Engineering
 *  HomeWorkd Number: 4
 *  Estimated time :20 + hours
 *
 *  *arrays and structures* for cyrpto analysis
 */

#ifndef COUNT_H_
#define COUNT_H_

#define COUNT 26

#include <stdio.h>

typedef struct letterOccurrences
{
    int letters[COUNT];
    int totalLetters;

}LETTER;

typedef struct pairOccurrences
{
	int pairs[COUNT][COUNT];
	int totalPairs;
}PAIR;

void computeOccurrences(char* inFile, char *outFile, int fileflag, int csv);
void counting(LETTER *l, PAIR *p, char rWord[], int c);

#endif
