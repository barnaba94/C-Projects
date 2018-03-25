#ifndef _FIFO_TAB_
#define _FIFO_TAB_

#define _PRINT_DEBUG_

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct tagFifoTab{
	int Elem;  
	int nHead;
	int nTail;
	int MaxFifo;
	int* Tab;
} Queue;

Queue* QCreate(int nSize);
int QEmpty(Queue* q);
void QEnqueue(Queue* q, int x); //insert
int QDequeue(Queue* q); //delete
void QClear(Queue* q);
void QDel(Queue** q);

#endif