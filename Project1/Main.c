/*
 * Main.c
 *
 *  Created on: Mar 14, 2015
 *      Author: michaelzarate
 */

//array of car structures (add and delete) size 50
//sleep
// Cycle while CTRL ^ C
// calling the important function


#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "Main.h"
#include "parseArgs.h"
#include "print.h"
#include "vehicles.h"
#include <math.h>



unsigned sleep(unsigned seconds);
volatile sig_atomic_t stop;
void inthand(int signum)
{
    stop = 1;
}



int main ( int argc, char *argv[] )
{

	Args * opt = NULL;

	opt = (struct arguments*)malloc(sizeof(struct arguments));


	parseCmdLine( argc, argv, opt);
	printf("we have passed parsing the command line \n");




	//unsigned  time = (double)1;
	signal(SIGINT, inthand);



//write the initit() function make these point somewhere

	printf("we are starting the loop \n");
	while (!stop)
	{
		printf("loop\n"); //Call the update Run time from the rest of the program.
		updateNeighbors(opt);
		updateValues(opt);
		printToFile(opt);
		sleep(opt->interval);
	}
	printf("exiting safely!\n");
	printf("System stopped.\n");

		return 0;

}
