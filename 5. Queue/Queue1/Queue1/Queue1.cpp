#include "queue.h"

Queque* QCreate()
{
  Queque* que = ( Queque* ) calloc ( 1, sizeof( Queque ) );
  if ( !que )
  {
    printf( "Unable to allocate memory" );
    return 0;
  }
  return que;
}

void QEnqueue( Queque* pQueue, int nKey )
{
  QItem* qitem = ( QItem* ) calloc ( 1, sizeof( QItem ) );
  if (!qitem)
  {
    printf("Unable to allocate memory");
    return;
  }
    qitem -> nKey = nKey;
    //qitem -> pNext = NULL;
    if( QEmpty( pQueue ) ) //if (!(pQueue -> pHead))
      pQueue -> pHead = qitem;
    if ( pQueue -> pTail )
      pQueue -> pTail -> pNext = qitem;
    pQueue -> pTail = qitem;
}

int QDequeue( Queque* pQueue )
{
  if ( QEmpty( pQueue ) ) {
    printf( "ERROR: Queue is empty!\n" );
    return 0;
  }

  int res = pQueue -> pHead -> nKey;

  QItem* tmp = pQueue -> pHead;
  pQueue -> pHead = tmp -> pNext;
  free( tmp );

  return res; //deleted item
}

int QEmpty(Queque* pQueue)
{
  return !( pQueue -> pHead );
}

void QClear(Queque* pQueue)
{
  while ( !QEmpty( pQueue ) )
    QDequeue( pQueue );
}

void QDel( Queque** pQueue )
{
  QClear( *pQueue );
  free( *pQueue );//!!!!!!!!!!!! //add * 13.12
  *pQueue = NULL;
}