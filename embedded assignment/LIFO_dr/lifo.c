/*
 * lifo.c
 *
 *  Created on: May 3, 2023
 *      Author: maste
 */
#include "lifo.h"

LIFO_status Lifo_add_item(LIFO_buf_t* lifo_buf,unsigned int item)
{
	if(!lifo_buf->head || !lifo_buf->base)
		return LIFO_NULL;
	if(lifo_buf->count==lifo_buf->length)
		return LIFO_full;
	*(lifo_buf->head)=item;
	lifo_buf->head ++;
	return LIFO_no_error;
}
LIFO_status Lifo_get_item(LIFO_buf_t* lifo_buf,unsigned int* item)
{
	if(!lifo_buf->head || !lifo_buf->base)
		return LIFO_NULL;
	if(lifo_buf->count==0)
		return LIFO_empty;
	lifo_buf->head--;
	*item=*(lifo_buf->head);
	return LIFO_no_error;
}
LIFO_status Lifo_init(LIFO_buf_t* lifo_buf,unsigned int* buf,unsigned int length)
{
	if(buf==NULL)
		return LIFO_NULL;
	lifo_buf->base = buf;
	lifo_buf->head =buf;
	lifo_buf->count=0;
	lifo_buf->length=length;
	return LIFO_no_error;
}
