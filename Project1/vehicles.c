/*
 * vehicles.c
 *
 *  Created on: Mar 14, 2015
 *      Author: michaelzarate
 *      Date Started: March 14 2015
 *      Date Completed:
 *      Time
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "parseArgs.h"
#include "Main.h"
#include "vehicles.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 *
 */
void addNeighbor(CAR *gcar,int aNeighbor)// add neighbor  **??**
{
	struct neighbor_list *newNeighbor;
	newNeighbor = (struct neighbor_list*) malloc(sizeof(struct neighbor_list));

	newNeighbor-> neighbor = aNeighbor;
	newNeighbor-> next = gcar-> head;
	gcar-> head = newNeighbor;


}

void delNeighbor(CAR *dcar, int dNeighbor)//delete neighbor
{
	struct neighbor_list* previous;
    struct neighbor_list* current;


    previous = dcar-> head;
    current = dcar-> head;
    //Case 0 The case where there is nothing in the linked list
    if(previous == NULL)
    {
    	//We do nothing to the list if head == NULL
    }
    else
    {
    	//case 1 where I am deleting the head
    	if(current-> neighbor == dNeighbor)
        {

    		previous = current->next;
    		free(current);
    		current = NULL;


        }

        else // CASE 2
        {
        	current = current -> next;
        	while(current->neighbor != dNeighbor)
        	{
        		current = current->next;
        		previous = previous->next;
        	}

        	previous->next = current->next;
        	free(current);
        	current = NULL;
        }
    }


}

void updateNeighbors( Args *nOpt)//update neighbors of all vehicles
{
	int x, y, z;
	float distance;
	x =0;
	y = 0;
	z = 0; //This is the value that gets returned from the search function 1 if it needs to be checked for deletion and 0 if it needs to be checked for addition
	distance = 0.0;
	int i;

	CAR* addCar;
	CAR* searchCar;

	//main calls this function after each sleep interval has been met
	 //24 -- represents the number of bytes of each element in the array


	for(i = 0 ; i <neighborCount; i++)
	{
		while(y<neighborCount)
		{
			searchCar = &carList[i];
			z = searchList(searchCar, y);
			//compute the new location of the car
			updateValues(nOpt);  //I do not know how to send this function what it needs
			if(carList[y].personalId == carList[i].personalId)
			{

			}
			else
			{
				distance = sqrt(pow((carList[y].xLocation - carList[i].xLocation),2) + pow((carList[y].yLocation - carList[i].yLocation),2)) ;

				if(distance <= 250)
				{
					if(z == 0)
					{
						addCar = &carList[i];
						addNeighbor(addCar, carList[y].personalId);
					}

				}
				else //If a car is now at a greater distance and was in the list we need to delete it
				{
					if(z ==1)
					{
						addCar = &carList[i];
						delNeighbor(addCar, carList[y].personalId);
					}
				}

			}
			y++;
		}
		y = 0;
	}
}




void updateValues(Args *uOpt)//update location of all vehicles
{



	 int xnew, ynew, time;
	 time =0;
	 xnew = 0;
	 ynew = 0;
	 int i;
	 //I dont know how to get the number of seconds for sleep --the user is
	 //supposed to input it after the -t option
	 //get the sleep amount here
	 for(i = 0; i <neighborCount;i++)
	 {

		 xnew = carList[i].xLocation + carList[i].speed*cos(carList[i].thetaAngle)*time;
		 //remember Idont know how to get time
		 ynew = carList[i].yLocation + carList[i].speed*cos(carList[i].thetaAngle)*time;

		 carList[i].xLocation = xnew;
		 carList[i].yLocation = ynew;

	 }
}




int searchList(CAR *sCAR, int position) // This gives me the car that I want to reset and the position of the car I'm searching to find if it is in the linked list
{
	int id;
	struct neighbor_list* temp;
	id = carList[position].personalId; //This gets the cars Id we will besearching to see if it is currently in the linked list or not


	//If there are no people in the linked list then return a struc person
    //pointer pointing to null

	if(sCAR->head == NULL)
    {
		return 0;
    }
	else
	{
		temp = sCAR->head;

		//The following if statement checks to see is the first node
		//in the linked list

        if(temp->neighbor == id)
        	return 1;

        //If the name is not the first node we go through the while
        //loop to check all other nodes
        temp = temp->next;

        while(temp != NULL)
        {
        	if(temp->neighbor == id )
        		return 1;
        	else
        	{
        		temp = temp->next;

             }

        }
        return 0;

        //If we exit the while loop without finding the node then we
        //send error and exit loop

	}
}





