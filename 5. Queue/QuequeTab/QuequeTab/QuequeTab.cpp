#include "queueTab.h"

//private functions
int QFull( Queue* );

Queue* QCreate( int nSize )
{
  Queue* que = ( Queue* ) calloc ( 1 , sizeof( Queue ) );
  if ( !que )
  {
    printf( "Unable to allocate memory" );
    return 0;
  }
  que->Tab = ( int* ) calloc ( nSize , sizeof( int ) );
  if (!( que -> Tab ) )
    {
      printf("Unable to allocate memory");
      return 0;
    }
  que -> Elem = 0;
  que -> MaxFifo = nSize;
  que -> nHead = 0;
  que -> nTail = 0;
  return que;
}
//======================================
void QEnqueue(Queue* q, int nKey)
{
  if ( QFull( q ) )
  {
    printf( "ERROR: Queue is full!\n" );
    return;
  }
    q -> Tab[ q->nTail ] = nKey;
    q-> nTail = (q -> nTail + 1) %  q->MaxFifo;
    q -> Elem++;
}
//==================================================
int QDequeue( Queue* q )
{
  if ( QEmpty( q ) )
  {
    printf( "ERROR: Queue is empty!\n" );
    return 0;
  }

  int x = q -> Tab[ q -> nHead ]; //top, del item
  
 // q -> Tab[ q -> nHead ] = 0;
  q -> nHead = ( ( q -> nHead +1 ) % ( q -> MaxFifo ) );
  q -> Elem-- ;
  return x;
}
//==================================================
int QEmpty( Queue* q )
{
  return !( q -> Elem );
}
//==================================================
int QFull(Queue* q)
{
  if (q -> Elem == ( q -> MaxFifo ) )
    return 1;
  return 0;
}
//==================================================
void QClear(Queue* q)
{
  q -> Elem = 0;
  q -> nHead = 0;
  q -> nTail = 0;
 // free( q -> Tab);
}
//==================================================
void QDel(Queue** q)
{
  QClear( *q );
  free(( *q )->Tab);
  free( *q );
}