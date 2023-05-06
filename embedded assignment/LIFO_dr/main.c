/*
 * main.c
 *
 *  Created on: May 3, 2023
 *      Author: maste
 */

#include "lifo.h"

unsigned int buffer[5];

void main(void)
{

	int i,temp=0;
	LIFO_buf_t uart_lifo;
    Lifo_init(&uart_lifo,buffer,5);
    for(i=0;i<5;i++)
    {
    	if(Lifo_add_item(&uart_lifo,i) == LIFO_no_error)
    	printf("uart_lifo added : %d\n",i);
    }
    for(i=0;i<5;i++)
    {
    	if(Lifo_get_item(&uart_lifo,&temp) == LIFO_no_error)
    	printf("uart_lifo get : %d\n",temp);
    }

}
