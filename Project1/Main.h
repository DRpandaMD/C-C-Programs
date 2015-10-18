/*
 * Main.h
 *
 *  Created on: Mar 14, 2015
 *      Author: michaelzarate
 */

#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>





//structure of linked list for vehicle neighbors'
typedef struct neighbor_list{
int neighbor;
struct neighbor_list *next;
}LLIST;

//structure of vehicles
typedef struct vehicle{
int personalId;
float xLocation;
float yLocation;
float speed;
float thetaAngle;
LLIST *head;
}CAR;


CAR carList[50];

#endif
