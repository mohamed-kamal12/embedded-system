/*
 ============================================================================
 Name        : frequency_of_char.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int freq[26]={0};
	char str[100],character;
	int cnt=0,x;
	printf("enter the string :");
	fflush(stdout); fflush(stdin);
	gets(str);
	int i=0;
	while(str[i]!='\0')
	{
		freq[str[i]-'a']++;
		i++;
	}
	printf("enter a character to find frequency: ");
	fflush(stdout); fflush(stdin);
    scanf("%c",&character);
    x=character-'a';


    printf("frequency of %c = %d",character,freq[x]);
	return 0;
}
