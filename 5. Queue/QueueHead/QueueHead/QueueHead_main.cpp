// Queue1.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "QueueHead.h"

#define MAX 100 

//proto
void QBuild( Queque* pQueue, int nSize );
void QPrint( Queque* pQueue );

int main(int  argc, char* argv[])
{

  Queque* kolejka = QCreate();
#ifdef TEST
  QBuild( kolejka , MAX);
  QDequeue( kolejka );
  QDequeue( kolejka );
  QEnqueue( kolejka , 10 );
 // QClear( kolejka );
  QPrint( kolejka );
  QDel( &kolejka );
#endif
  getchar();
  return 0;
}
//=====================================================

void QBuild( Queque* pQueue, int nSize ) {
  for ( int i = 0; i < nSize; i++ )
    QEnqueue( pQueue, i );
}

void QPrint(Queque* pQueue)
{
  if (QEmpty( pQueue ))
    printf("\nEmpty Queue!\n");
  else
  {
    QItem* node = pQueue -> pHead -> pNext;
    while ( node != pQueue -> pTail )
    {
      printf( "%d ", node -> nKey );
      node = node -> pNext;
    }
    printf( "%d", node -> nKey );
  }
}