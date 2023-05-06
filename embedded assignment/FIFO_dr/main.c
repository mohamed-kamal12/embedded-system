/*
 * main.c
 *
 *  Created on: May 4, 2023
 *      Author: maste
 */

#include "fifo.h"

void main(void)
{

	element_type i,temp=0;
	FIFO_buf_t uart_fifo;
	if(FIFO_init(&uart_fifo,buffer,5)==fifo_no_error)
		printf("fifo init done \n");
	for(i=0;i<7;i++)
	{
	if(FIFO_enqueue(&uart_fifo,i)==fifo_no_error)
		printf("FIFO enqueue %x done \n",i);

	else
		printf("fifo enqueue failed \n");
	}

	FIFO_print(&uart_fifo);

	if(FIFO_dequeue(&uart_fifo,&temp)==fifo_no_error)
		printf("fifo dequeue done %x \n",temp);
	if(FIFO_dequeue(&uart_fifo,&temp)==fifo_no_error)
			printf("fifo dequeue done %x \n",temp);

	FIFO_print(&uart_fifo);



}
