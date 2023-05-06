/*
 * fifo.h
 *
 *  Created on: May 4, 2023
 *      Author: maste
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"
//user configuration
#define element_type uint8_t
#define width 5

element_type buffer[width];
//create FIFo buffer
typedef struct {
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_buf_t;

//create fifo status

typedef enum{
	fifo_null,
	fifo_full,
	fifo_empty,
	fifo_no_error
}FIFO_status;


//APIs
FIFO_status FIFO_init(FIFO_buf_t* fifo_buf,element_type* buf, uint32_t length );
FIFO_status FIFO_enqueue(FIFO_buf_t* fifo_buf,element_type item);
FIFO_status FIFO_dequeue(FIFO_buf_t* fifo_buf,element_type* item);
FIFO_status FIFO_isfull(FIFO_buf_t* fifo_buf);
void FIFO_print(FIFO_buf_t* fifo_buf);


#endif /* FIFO_H_ */
