/*
 ============================================================================
 Name        : reverse_sentence.c
 Author      : mohamed kamal
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void reverse()
{
	char c;
    scanf("%c",&c);
	if(c!='\n')
	{
		reverse();
		printf("%c",c);
	}
}
int main()
{
	printf("enter a sentecne\n");
	fflush(stdout);fflush(stdin);
	reverse();
	return 0;
}
