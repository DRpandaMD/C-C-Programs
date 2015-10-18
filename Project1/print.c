/*
 * print.c
 *
 *  Created on: Mar 18, 2015
 *      Author: michaelzarate
 */


#include <stdio.h>
#include <stdlib.h>
#include "parseArgs.h"
#include "Main.h"
#include <math.h>
int neigborListSize;

FILE *fw = NULL;

void printToScreen()
{
	LLIST *temp;
	for(int i = 0; i < neighborCount ; i++)
	{
		printf("Vehicle %d",carList[i].personalId);
		printf(" at Location %f, %f", carList[i].xLocation,carList[i].yLocation);
		printf(" moving with Velocity %f", carList[i].speed);
		printf(" it's neighbors are:");
		temp = carList[i].head;
			while(temp != NULL)
			{
				printf(" Vehicle ");
				printf("%d", temp->neighbor);
				temp = temp->next;
			}
		printf("\n");
	}


}


void printToFile(Args *fOpt)
{
	LLIST *temp;

	fw = fopen(fOpt->outFilename, "w");

	//prepare for writing
	if(!fw)
	{
		printf("Can not open %s \n", fOpt->outFilename);
		return;
	}
	else
	{
		for(int i = 0; i < neighborCount ; i++)
		{
			fprintf(fw, "Vehicle %d",carList[i].personalId);
			fprintf(fw, " at Location %f, %f", carList[i].xLocation,carList[i].yLocation);
			fprintf(fw, " moving with Velocity %f", carList[i].speed);
			fprintf(fw, " it's neighbors are:");
			temp = carList[i].head;
			while(temp != NULL)
			{
				fprintf(fw, " Vehicle ");
				fprintf(fw, "%d", temp->neighbor);
				temp = temp->next;
			}
			fprintf(fw, "\n");

		}
		if(fOpt->bFlag == 1)
		{
			printToScreen();
		}


		//close file
		fclose(fw);
	}

}

