#include "QueueHead.h"

Queque* QCreate()
{
  Queque* que = ( Queque* ) calloc ( 1 , sizeof( Queque ) );
  if ( !que )
  {
    printf( "Unable to allocate memory" );
    return 0;
  }
  QItem* node = ( QItem* ) calloc ( 1, sizeof( QItem ) );
  if ( !node )
  {
    printf( "Unable to allocate memory" );
    return 0;
  }
  que -> pHead = que -> pTail = node;
  return que;
}

void QEnqueue ( Queque* pQueue, int nKey )
{
  QItem* item = ( QItem* ) calloc (1, sizeof ( QItem ) );
  if ( !item )
  {
    printf("\nQueue Overflow!\n");
    return;
  }
  item -> nKey = nKey;
  pQueue -> pTail -> pNext = item;
  pQueue -> pTail = item;
}

int QDequeue(Queque* pQueue)
{
 
  if (QEmpty ( pQueue ) ) {
    printf( "ERROR: Queue is empty!\n" );
    return 0;
  }
  QItem* item = pQueue -> pHead -> pNext;
  int res = item -> nKey;
  pQueue -> pHead -> pNext = item -> pNext;
  free( item );

  if( QEmpty( pQueue ) ) //if (pQueue -> pHead -> pNext == NULL) //isempty
    pQueue -> pTail = pQueue -> pHead;
  return res; //deleted item
}

int QEmpty( Queque* pQueue )
{
  return !( pQueue -> pHead -> pNext );
}

void QClear( Queque* pQueue )
{
  while ( !QEmpty( pQueue ) )
    QDequeue( pQueue );
}

void QDel(Queque** pQueue)
{
  QClear( *pQueue );
  free( *pQueue );
  *pQueue = NULL;
}