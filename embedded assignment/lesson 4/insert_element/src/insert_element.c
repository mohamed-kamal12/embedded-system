/*
 ============================================================================
 Name        : insert_element.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int arr[30],num,element,location;
	printf("enter number of elements: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter the element to insert it: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&element);
	printf("enter the location: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&location);
	for(int i=num;i>=location;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[location-1]=element;
	for(int i=0;i<=num;i++)
		{
			printf("%d ",arr[i]);
		}


	return 0;
}
