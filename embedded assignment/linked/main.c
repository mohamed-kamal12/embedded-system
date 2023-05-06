


/*
 * linkedlist.h
 *
 *  Created on: May 5, 2023
 *      Author: Mohamed
 */


#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#include "stdint.h"
#define Dprint(...) {fflush(stdout);\
	                fflush(stdin);\
                    printf(__VA_ARGS__);\
                    fflush(stdout);\
	                fflush(stdin);}
struct Sdata{
	unsigned int id;
	char name[40];
	char grade[10];
};
struct Sstudent{
	struct Sdata student;
	struct Sstudent* pnext;
};
 struct Sstudent* pbase = NULL;


 //******************************************************************************
 /*
  * linkedlist.c
  *
  *  Created on: May 5, 2023
  *      Author: Mohamed
  */

 void add_node()
 {
 	struct Sstudent* plast;
 	struct Sstudent* pnew;
 	char temp[40];

 	//check is empty
 	if (pbase==NULL)
 	{
 		pnew=(struct Sstudent*)malloc(sizeof(struct Sstudent));
 		pbase=pnew;
 	}
 	//not empty
 	else
 	{
 		plast=pbase;
 		while(plast->pnext)
 		{
 			plast=plast->pnext;
 		}
 		pnew=(struct Sstudent*)malloc(sizeof(struct Sstudent));
 		plast->pnext=pnew;
 		pnew->pnext=NULL;
 	}
 	Dprint("\t enter the id \n");
 	gets(temp);
 	pnew->student.id=atoi (temp);
 	Dprint("\t enter the name \n");
 	gets(pnew->student.name);
 	Dprint("\t enter the grade \n");
 	gets(pnew->student.grade);

 }
 int delete_node()
 {
 	char temp[40];
 	int selected_id;

 	Dprint("\t enter the id u want to delete it \n");
 	gets(temp);
 	selected_id=atoi(temp);
 	//check is not empty
 	if (pbase)
 	{
 		struct Sstudent* pselected=pbase;
 		struct Sstudent* pprivious=NULL;

 		while(pselected)
 		{
 			if(pselected->student.id==selected_id)
 			{
 				if(pprivious)
 				{
 					pprivious->pnext = pselected->pnext;
 				}
 				else
 				{
 					pbase = pselected->pnext;
 				}
 				free(pselected);
 				return 1;
 			}
 			pprivious=pselected;
 			pselected = pselected->pnext;
 		}
 		Dprint("id not found \n");
 		return 0;
 	}
 	//IS empty

 		Dprint("list is empty \n");
 		return 0;



 }
 void print_allnodes()
 {
 	struct Sstudent* pcurrent=pbase;
 	int count=0;
 	//check is empty
 	if (pbase==NULL)
 	{
 		Dprint("list is empty \n");
 	}
 	else
 	{
 		while(pcurrent)
 		{
 			Dprint("====================\n");
 			Dprint("record number %d \n",count+1);
 			Dprint("ID : %d \n",pcurrent->student.id);
 			Dprint("Name : %s \n",pcurrent->student.name);
 			Dprint("grade : %s \n",pcurrent->student.grade);
 			pcurrent = pcurrent->pnext;
 			count++;

 		}
 		Dprint("====================\n");
 	}
 }
 void delete_allnode()
 {
 	struct Sstudent* pcurrent=pbase;
 		//check is empty
 		if (pbase==NULL)
 		{
 			Dprint("list is empty \n");
 		}
 		else
 		{
 			while(pcurrent)
 			{
 				struct Sstudent* ptemp=pcurrent;
 				pcurrent = pcurrent->pnext;
 				free(ptemp);

 			}
 			pbase=NULL;
 		}
 }





 /*
  * main.c
  *
  *  Created on: May 5, 2023
  *      Author: maste
  */



 void main(void)
 {
 	char temp[40];
 	while(1)
 			{
 				Dprint("====================\n");
 				Dprint("chose the option\n");
 				Dprint("chose 1 to add\n");
 				Dprint("chose 2 to delete one node\n");
 				Dprint("chose 3 to print the list\n");
 				Dprint("chose 4 to delete all element\n");
 				Dprint("enter your choice\n");

 				gets(temp);
 				switch (atoi (temp))
 				{
 				case 1:
 					add_node();
 					break ;
 				case 2:
 					delete_node();
 					break ;
 				case 3:
 					print_allnodes();
 					break ;
 				case 4:
 					delete_allnode();
 					break ;
 				}


 			}
 }















