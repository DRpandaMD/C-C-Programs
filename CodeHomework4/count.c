/*
 * main.c
 *
 *  Created on: Feb 19, 2015
 *  Author: michaelzarate
 *  CSE220 SPRING 2015, Programming for Computer Engineering
 *  HomeWorkd Number: 4
 *  Estimated time :20 + hours
 *
 *  *arrays and structures* for cyrpto analysis
 *
 *  I want to make a quick note an bring to your attention the absolute
 *  Ridiculousness of these assignments.  If the graduate tutors at the center point tutoring
 *  center are unable to assist us after we have put in 20 + hours of work
 *  which equates to a PART TIME JOB.  Then there is a serious problem.
 *
 *  Also the make file doesn't want to work becuase of the old version of the GCC doesn't have any way
 *  to suppress the "implicit declaration of function 'isalpha' is invalid in C99 [-Wimplicit-function-
 *  declaration]" error.  Yes I looked it up.  And there are no available mac ports at the moment for
 *  the most recent version of Mac OS X Yosemite

 */

#include <string.h>
#include <ctype.h>
#include "count.h"
#define WORDCOUNT 5000

void computeOccurrences(char* inFile, char *outFile, int fileflag, int csv)
{
	LETTER inLetters;
	for(int i = 0 ; i <26; i++)
	{
		inLetters.letters[i] = 0;
	}
	inLetters.totalLetters = 0;

	PAIR inPairs;
	for(int i = 0; i < 26; i++)
	{
		for(int j = 0; j < 26; j ++)
		{
			inPairs.pairs[i][j] = 0;
		}

	}

	inPairs.totalPairs = 0;
	FILE *fin = fopen(inFile, "r");
	FILE *fout = fopen(outFile, "w");
	char word[WORDCOUNT];
	size_t i,j;
	float freq;
	int index=0;
	int wordSize = 0;
	int csvFlag = 0;
	char AlphaBetaChar;
	char AlphaBetaCharTwo;

	csvFlag = csv;


	//read the first character from the input file
	int ch = fgetc(fin);
	//printf("%c", ch);

	//traverse the complete until  EOF is encountered
	while(ch!=EOF)
	{

		//add the character to a word until a space or newline is found
		if((isspace(ch) == 0))
		{
			//make sure the character isalpha
			if(isalpha(ch))
			{
				word[index]= tolower(ch);
				index ++;
			}
		}
		else
		{
			//compute the length of the word
			wordSize = index;
			counting(&inLetters, &inPairs, word, wordSize);
			for(int i = 0; i< index; i++ ) //reset the array to NULL
			{
				word[i] = '\0';
			}

			index =0;
		}

		ch = fgetc(fin);
	}

		if(csvFlag == 0)
		{

			fprintf(fout, "%d Letters \n", (inLetters.totalLetters));
			//when the whole file is scanned -- print out the values
			for (i = 0; i < COUNT; i++)
			{
				freq = (float)inLetters.letters[i] / inLetters.totalLetters *100;
				AlphaBetaChar = i + 97;
				fprintf(fout,"%c%9d%9.5f \n",AlphaBetaChar, inLetters.letters[i],freq);
			}
			fprintf(fout,"%d Letter Pairs \n",(inPairs.totalPairs));

			for (i = 0; i < COUNT; i++)
			{
				AlphaBetaChar = i + 97;
				for (j = 0; j < COUNT; j++)
				{
					AlphaBetaCharTwo = j +97;
					freq = (float)inPairs.pairs[i][j] / inPairs.totalPairs *100;
					fprintf(fout,"%c%c%9d %9.5f\n",AlphaBetaChar, AlphaBetaCharTwo, inPairs.pairs[i][j],freq);

				}
			}

		}

		if(csvFlag == 1)
		{
			fprintf(fout, "%d \"Letters\"\n", (inLetters.totalLetters));
			//when the whole file is scanned -- print out the values in excel format
			for (i = 0; i < COUNT; i++)
			{
				freq = (float)inLetters.letters[i] / inLetters.totalLetters *100;
				AlphaBetaChar = i + 97;
				fprintf(fout,"\"%c\",%d,%.5f \n",AlphaBetaChar, inLetters.letters[i],freq);
			}
			fprintf(fout,"%d \"Letter Pairs\"\n",(inPairs.totalPairs));
			for (i = 0; i < COUNT; i++)
			{
				AlphaBetaChar = i + 97;
				for (j = 0; j < COUNT; j++)
				{
					AlphaBetaCharTwo = j +97;
					freq = (float)inPairs.pairs[i][j] / inPairs.totalPairs *100;
					fprintf(fout,"\"%c%c\",%d,%.5f\n",AlphaBetaChar, AlphaBetaCharTwo, inPairs.pairs[i][j],freq);
				}

			}

		}
}


void counting(LETTER *l, PAIR *p, char rWord[], int c)
{

	int j =0;

	int count = c;
	int charToASCII = 0;
	int charToASCIITwo = 0;
	int position = 0;
	int positionTwo = 0;


	for(int i = 0; i < count; i++)
	{
		charToASCII = rWord[i];

		position = charToASCII - 97;
		l->letters[position]++;
		l->totalLetters++;
	}

	while(rWord[j +1] != '\0')
	{
		charToASCII = rWord[j];
		charToASCIITwo = rWord[j+1];

		position = charToASCII -97;
		positionTwo = charToASCIITwo - 97;

		p->pairs[position][positionTwo] ++;
		p->totalPairs++;

		j ++;
	}
}







