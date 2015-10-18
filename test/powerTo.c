/*
 * powerTo.c
 *
 *  Created on: Feb 24, 2015
 *      Author: michaelzarate
 */


#include <stdio.h>

int powNum(int, int);
int main ()
{
	int x, y = 0;
	int result = 0;

	printf("welcome to the 'x to power of y' program");
	printf("Please enter a number for x: \n");
	scanf("%d", &x);
	printf("Please enter a number for y: \n");
	scanf("%d", &y);
	result = powNum(x,y);
	printf("%d raised to power %d is:  %d\n", x,y,result);
}

int powNum(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else
	{
		return(a*powNum(a,b-1));
	}
}


