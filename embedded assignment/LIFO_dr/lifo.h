/*
 * lifo.h
 *
 *  Created on: May 3, 2023
 *      Author: maste
 */
#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"

typedef struct{

	unsigned int* head;
	unsigned int* base;
	unsigned int length;
	unsigned int count;
}LIFO_buf_t;

typedef enum {

	LIFO_no_error ,
	LIFO_full ,
	LIFO_empty,
	LIFO_NULL

}LIFO_status;

LIFO_status Lifo_add_item(LIFO_buf_t* lifo_buf,unsigned int item);
LIFO_status Lifo_get_item(LIFO_buf_t* lifo_buf,unsigned int* item);
LIFO_status Lifo_init(LIFO_buf_t* lifo_buf,unsigned int* buf,unsigned int len );

#endif /* LIFO_H_ */
