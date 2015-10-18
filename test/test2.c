/*
 * test2.c
 *
 *  Created on: Mar 16, 2015
 *      Author: michaelzarate
 */


#include <stdio.h>


void swapByValue(int i,int j);
void swapByReference(int *i,int *j);
int main()
{
	int i = 10, j = 20;

	swapByValue(i,j);
	printf("%d, %d\n", i, j);

	swapByReference(&i,&j);
	printf("%d, %d\n", i, j);


}

void swapByValue(i,j)
{
	int temp = 0;
	temp = i;
	i = j;
	j = temp;
}

void swapByReference(int *i, int *j)
{
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}
