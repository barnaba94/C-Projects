#ifndef _QUEUE_HEADER_
#define _QUEUE_HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define TEST

typedef struct tagQItem
{
  int nKey;
  tagQItem* pNext;
} QItem;

typedef struct
{
  QItem* pTail;
  QItem* pHead;
} Queque;


Queque* QCreate();						  
int QEmpty( Queque* );					  
void QEnqueue( Queque* , int );			  
int QDequeue( Queque* );					
void QClear( Queque* );					  
void QDel( Queque** );

#endif