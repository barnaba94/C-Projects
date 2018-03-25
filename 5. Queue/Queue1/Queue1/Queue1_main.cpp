// Queue1.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//
#include "queue.h"

//TEST

#define MAX 100 

void QBuild( Queque*, int);
void QPrint( Queque*);

int main(int argc , char* argv[])
{
  Queque* que = QCreate();
  QBuild(que, MAX);
  QDequeue(que);
  QDequeue(que);
  QEnqueue( que, 10 );
  QPrint(que);
  QDel(&que);
  getchar();
  return 0;
}


void QBuild( Queque* pQueue, int nSize ) {
  for ( int i = 0; i < nSize ; i++ )
    QEnqueue( pQueue, i );
}

void QPrint( Queque* pQueue )
{
    if ( QEmpty ( pQueue ) ) {
      printf( "ERROR: Queue is empty!\n" );
      return;
    }
    QItem* tmp = pQueue -> pHead;
    while ( tmp ) {
      printf( " %d ", tmp -> nKey);
      tmp = tmp -> pNext;
    }
}