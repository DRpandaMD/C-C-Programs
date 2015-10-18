/*
 * vehicles.h
 *
 *  Created on: Mar 14, 2015
 *      Author: michaelzarate
 */

#ifndef VEHICLES_H
#define VEHICLES_H
#include <stdio.h>
#include <stdlib.h>
#include "parseArgs.h"
#include "Main.h"
#include <math.h>

void addNeighbor(CAR *gcar,int aNeighbor); // add neighbor

void delNeighbor(CAR *dcar, int dNeighbor); //delete neighbor

void updateNeighbors( Args *nOpt);//update neighbors of all vehicles

void updateValues(Args *uOpt);//update location of all vehicles

int searchList(CAR *sCAR, int position);

void initializeVehicles(CAR *ptr, Args *vOpt);//parse input file and initialize vehicle structure array

#endif
