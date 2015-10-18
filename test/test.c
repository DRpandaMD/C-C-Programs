/*
 * test.c
 *
 *  Created on: Feb 12, 2015
 *      Author: michaelzarate
 */


/*
 * C Program to Reverse the String using Recursion
 */
#include <stdio.h>
#include <string.h>

void reverse(char [], int, int);
int main()
{
    char str1[20];
    int size;

    printf("Enter a string to reverse: ");
    scanf("%s", str1);
    size = strlen(str1);
    reverse(str1, 0, size - 1);
    printf("The string after reversing is: %s\n", str1);
    return 0;
}

void reverse(char str1[], int index, int size)
{
    char temp;
    temp = str1[index];
    str1[index] = str1[size - index];
    str1[size - index] = temp;
    if (index == size / 2)
    {
        return;
    }
    return reverse(str1, index + 1, size);
}



/*
#include <stdio.h>

int search(int [], int, int);
int main()
{

	int size, index, key;
	int list[20];
	int count = 0;
	int i;

	printf("Enter the size of the list: ");
	scanf("%d", &size);
	index = size;
	printf("Printing the list:\n");
	for (i = 0; i < size; i++)
	{
		list[i] = rand() % size;
		printf("%d\t", list[i]);
	}
	printf("\nEnter the key to search: ");
	scanf("%d", &key);
	while (index > 0)
	{
		index = search(list, index-1, key);
		/* In an array first position is indexed by 0 */

/*
	    printf("Key found at position: %d\n", index );
	    count++;
	 }
	 if (!count)
	 {
		 printf("Key not found.\n");
		 return 0;

	 }
}



	int search(int array[], int size, int key)
	{
	    int location;
	    if (size == -1)
	    {
	        return -1;
	    }
	    else if (array[size] == key)
	    {
	        return size;
	    }
	    else
	    {
	        return (location = search(array, size - 1, key));
	    }
	}


	*/

/*
	int n, i, flag=0;
	printf("Enter a positive integer: ");
	scanf("%d",&n);
	for(i=2;i<=n/2;++i)
	{
		if(n%i==0)
		{
			flag=1;
			break;
		}
	}
	if (flag==0)
		printf("%d is a prime number.",n);
	else
		printf("%d is not a prime number.",n);
	return 0;
*/



