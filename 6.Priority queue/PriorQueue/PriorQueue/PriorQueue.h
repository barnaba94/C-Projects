#ifndef  _PRIOR_QUEUE_HEADER_
#define  _PRIOR_QUEUE_HEADER_

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <time.h>

#define PRINT

typedef struct {
  int nKey;
  int prior;
}PQItem;

typedef struct {
  PQItem* PQueue;
  int PQSize;
  int PQCurrSize; //number of current items in queue
}PQueue;

PQueue* PQInit(int);
int PQisEmpty(PQueue* p);
void PQEnQueue(PQueue*, int nKey, int nPrior);
int PQDeQueue(PQueue*);
void PQRealease(PQueue**);
void DecreaseKey(PQueue* PQueue, int nKey, int nPrior); // (nPrior < PQItem.nPrior)
void IncreaseKey(PQueue* PQueue, int nKey, int nPrior); // (nPrior > PQItem.nPrior)

#endif // ! _PRIOR_QUEUE_HEADER_
