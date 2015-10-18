/*
 * parseArgs.c
 *
 *  Created on: Mar 16, 2015
 *      Author: michaelzarate
 */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "Main.h"
#include "parseArgs.h"
#include <string.h>
#include <math.h>


FILE *fp = NULL; //creates the file pointer to perform operations with a file


void parseCmdLine(int argc, char*argv[], Args *opt)
{
	char *string;
	char *readString;
	const char tokenString[2] = ",";
	int time = 0;
	int sCount=0;
	size_t nBytes = 1024;

	for(int i = 0 ; i < argc; i++)
	{
		if(argv[i][0] == '-' && argv[i][1] == 'f')//fOption use input from file
		{
			//check to see if there is a file name
			if( argv[i+1] == NULL)
			{
				printf("expecting argument following -f \n");
			}

			//copy file name
			opt->inFilename = argv[i+1];

			fp = fopen(opt->inFilename, "r");
			if(!fp)
			{
				printf("Can not open %s \n" , opt->inFilename);
				return;
			}
			else
			//close file
			fclose(fp);

			opt->fFlag = 1;
		}

		if(argv[i][0] == '-' && argv[i][1] == 'o')//oOption to write to a file
		{
			//check to see if there is a file name
			if( argv[i+1] == NULL)
			{
				printf("expecting argument following -o \n");

			}

			//copy file name
			opt->outFilename = argv[i+1];
			fp = fopen(opt->outFilename, "w");

			//write data from user to file
			if(!fp)
			{
				printf("Can not open %s \n" , opt->outFilename);
				return;
			}
			else
			//close file
			fclose(fp);

			opt->oFlag = 1;
		}
		else
		{
			printf("The default output file will be 'result.txt' \n");

			opt->outFilename = "result.txt";
			fp = fopen(opt->outFilename, "w");

			//prepare for writing
			if(!fp)
			{
				printf("Can not open %s \n", opt->outFilename);
				return;
			}
			else
			{
				//close file
				fclose(fp);
			}

			opt->oFlag = 1;
		}

		if(argv[i][0] == '-' && argv[i][1] == 't')//tOption takes time for sleep duration
		{
			opt->tFlag = 1;

			if(opt->tFlag == 1)
			{
				printf("Standby! \n");
				printf("Please enter a time interval to sleep the program: \n");
				scanf("%d", &time);
				opt->interval = time;
			}
		}

		if(argv[i][0] == '-' && argv[i][1] == 's') //sOption silent
		{
			opt->sFlag = 1;

			//call the silent option method ( i think)
		}

		if(argv[i][0] == '-' && argv[i][1] == 'b')//bOption is verbose
		{
			opt->bFlag = 1;

			//call the verbose method
		}

		/*
		 * Here we will take input for the numbers entered
		 * (Pretty sure we have to implement a way to read out of the file if given)
		 */

/*
 * READ FROM A FUCKING FILE
 */
		if(opt->fFlag == 1)
		{
			fp = fopen(opt->inFilename, "r");
				if(!fp)
				{
					printf("Can not open %s \n" , opt->inFilename);
					return;
				}
				else
					//while((readString = getline(&string, &nBytes,fp)) != -1);
					{
						while(string != NULL)
						{

							//put the data into the array structure
							carList[sCount].personalId = sCount;
							carList[sCount].xLocation = atof(strtok(string,tokenString ));
							carList[sCount].yLocation = atof(strtok(NULL,tokenString ));
							carList[sCount].speed = atof(strtok(NULL,tokenString ));
							carList[sCount].thetaAngle = atof(strtok(NULL,tokenString ));
							sCount++;
							neighborCount++;

							//getline(string,&nBytes,fp);
						}//end WHILE
					}


			}// end OUTER WHILE

	}//end first FOR LOOP
}// END MAIN

