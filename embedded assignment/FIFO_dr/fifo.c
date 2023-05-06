/*
 * fifo.c
 *
 *  Created on: May 4, 2023
 *      Author: maste
 */

#include "fifo.h"

FIFO_status FIFO_init(FIFO_buf_t* fifo_buf,element_type* buf, unsigned int length )
{
	if(buf == NULL)
		return fifo_null;
	fifo_buf->head=buf;
	fifo_buf->base=buf;
	fifo_buf->tail=buf;
	fifo_buf->count=0;
	fifo_buf->length=length;
	return fifo_no_error;
}
FIFO_status FIFO_enqueue(FIFO_buf_t* fifo_buf,element_type item)
{
	if(!fifo_buf->head || !fifo_buf->base || !fifo_buf->tail)
		return fifo_null;
	if(FIFO_isfull(fifo_buf)==fifo_full)
			return fifo_full;
	*(fifo_buf->head)=item;
	fifo_buf->count++;
	if(fifo_buf->head==(fifo_buf->base + (sizeof(element_type)*fifo_buf->length)))
		fifo_buf->head=fifo_buf->base;
	else
		fifo_buf->head++;
	return fifo_no_error;
}
FIFO_status FIFO_dequeue(FIFO_buf_t* fifo_buf,element_type* item)
{
	if(!fifo_buf->head || !fifo_buf->base || !fifo_buf->tail)
			return fifo_null;
	if(fifo_buf->count==0)
		return fifo_empty;
	*item= *(fifo_buf->tail);
	fifo_buf->count--;
	if(fifo_buf->tail==(fifo_buf->base + (sizeof(element_type)*fifo_buf->length)))
			fifo_buf->tail=fifo_buf->base;
		else
			fifo_buf->tail++;
		return fifo_no_error;
}
FIFO_status FIFO_isfull(FIFO_buf_t* fifo_buf)
{
	if(fifo_buf->count==fifo_buf->length)
			return fifo_full;
		else
		return fifo_no_error;
}
void FIFO_print(FIFO_buf_t* fifo_buf)
{
    element_type* temp;
	if(fifo_buf->count==0)
	printf("========FIFO is empty======\n");
	else
	{
		temp=fifo_buf->tail;
		printf("========print of FIFO======\n");

	for(int j=0; j<fifo_buf->count ;j++)
	{
		printf("FIFO element : %x \n",*temp);
		temp++;
	}
	}
}
