#include "PriorQueue.h"

//private functions
int PQisFull(PQueue* pQue);
void UpdateDown(PQueue*, int l, int p);
void UpdateUp(PQueue*, int l, int p);

PQueue* PQInit( int nSize )
{
  PQueue* pQue = ( PQueue* ) calloc ( 1 , sizeof( PQueue ));
  if ( !pQue )
  {
    printf(" Unable to allocate memory ");
    return 0;
  }
  PQItem* pQItem = ( PQItem* ) calloc ( nSize , sizeof( PQItem ) );
  if ( !pQItem )
  {
    printf(" Unable to allocate memory ");
    return 0;
  }
  //pQue-> PQCurrSize = 0;
  pQue-> PQSize = nSize;
  pQue -> PQueue = pQItem;
  return pQue;
}

//=========================================

int PQisEmpty(PQueue* pQue)
{
  return !( pQue -> PQCurrSize );
}

//=========================================

int PQisFull(PQueue* pQue)
{
  return  pQue -> PQCurrSize == pQue -> PQSize ;
}

//=========================================

void PQEnQueue(PQueue* Que, int nKey, int prior)
{
  if ( PQisFull( Que ) )
  {
    printf(" Queue is full ");
    return;
  }
  Que -> PQueue[ Que -> PQCurrSize ] = { nKey , prior };
  UpdateUp( Que , 0 , Que -> PQCurrSize );
  Que -> PQCurrSize++;
}

//==================================================================

int PQDeQueue(PQueue* pQue)
{
  if ( PQisEmpty( pQue ) )
  {
    printf(" Empty queue ");
    return 0;
  }
  int del = pQue -> PQueue[0].nKey;
  pQue -> PQCurrSize--;
//memset( pQue -> PQueue, 0, sizeof( PQItem ) );
  pQue -> PQueue[ 0 ] = pQue -> PQueue[ pQue -> PQCurrSize ];
  UpdateDown( pQue, 0, pQue -> PQCurrSize );
  return del;
}
//==================================================================
void PQRealease( PQueue** pQue )
{
  free( ( *pQue ) -> PQueue );
  free( *pQue );
  *pQue = NULL;
}

//==================================================================

void DecreaseKey(PQueue* PQueue, int nKey, int nPrior) // (nPrior < PQItem.nPrior)
{
  for (int i = 0; i < PQueue -> PQCurrSize; i++)
  {
    if ( PQueue -> PQueue[ i ].nKey == nKey && PQueue -> PQueue[ i ].prior > nPrior)
    {
      PQueue -> PQueue[ i ].prior = nPrior;
      UpdateDown( PQueue, i, PQueue -> PQCurrSize - 1 );
    }
  }
}

//==================================================================

void IncreaseKey( PQueue* PQueue, int nKey, int nPrior ) // (nPrior > PQItem.nPrior)
{
  for (int i = 0; i < PQueue -> PQCurrSize; i++)
  {
    if ( PQueue -> PQueue[ i ] . nKey == nKey && PQueue -> PQueue[ i ].prior < nPrior )
    {
      PQueue -> PQueue[ i ] . prior = nPrior;
      UpdateUp( PQueue , 0 , i );
    }
  }
}

//==================================================================

void UpdateUp(PQueue* queue, int left, int right) {
  if (left == right)
    return;
  int i = right;
  int j = (i - 1) / 2;
  PQItem temp = queue -> PQueue[ i ];
  while (i > left && queue -> PQueue[ j ].prior > temp.prior) {
    queue -> PQueue[ i ] = queue -> PQueue[ j ];
    //queue -> PQueue[ j ] = temp;
    i = j;
    j = (i - 1) / 2;
  }
  queue -> PQueue[ i ] = temp; 
}

//===========================================================

void UpdateDown(PQueue* queue, int left, int right) {
  if (left == right) return;
  int i = left;
  int j = (i * 2) + 1;
  PQItem temp = queue -> PQueue[ i ];
  while (j <= right) {
    if (j < right) {
      if (queue -> PQueue[ j ].prior > queue -> PQueue[ j + 1 ].prior)
        j++;
    }
    if (temp.prior < queue -> PQueue[ j ].prior)
      break;
    queue -> PQueue[ i ] = queue -> PQueue[ j ];
    i = j;
    j = ( 2 * i ) + 1;
  }
  queue -> PQueue[ i ] = temp;
}