#ifndef _QUEUE_HEADER_
#define _QUEUE_HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TagQItem {
  int nKey;
  TagQItem* pNext;
} QItem;

typedef struct TagQueue {
  QItem* pHead;
  QItem* pTail;
} Queque;

Queque* QCreate();
void QDel(Queque** q);
int QEmpty(Queque* q);
void QEnqueue(Queque* q, int x); //insert to queque
int QDequeue(Queque* q); //delete item
void QClear(Queque* q);

#endif 