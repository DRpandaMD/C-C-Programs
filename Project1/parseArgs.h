/*
 * parseArgs.h
 *
 *  Created on: Mar 14, 2015
 *      Author: michaelzarate
 */

#ifndef PARSEARGS_H
#define PARSEARGS_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int neighborCount = 0;

//structure for keeping track of the command line options requested by user
typedef struct arguments{
        char *inFilename;
        char *outFilename;
        int fFlag;
        int	oFlag;
        int tFlag;
        int sFlag;
        int bFlag;
        int interval;
        int NODES;
} Args;



//function to scan command line arguments and set options
void parseCmdLine(int argc, char*argv[], Args *opt);

#endif
