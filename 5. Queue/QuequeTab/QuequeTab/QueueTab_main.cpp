#include "queueTab.h"

//private functions
void QBuild(Queue* q, int nSize);
void QPrint(Queue* q);

int main(int argc, char* argv[])
{
  int nSize = 5;
  Queue* TabFifo = QCreate( nSize);
  QBuild( TabFifo , nSize - 1 );
  #ifdef _PRINT_DEBUG_
    QPrint( TabFifo );
  #endif
  printf("\n");
  QEnqueue( TabFifo , 3 );
#ifdef _PRINT_DEBUG_
  QPrint(TabFifo);
#endif
  printf( "\n" );
  QDequeue( TabFifo );
  #ifdef _PRINT_DEBUG_
    QPrint( TabFifo );
  #endif
  QDel( &TabFifo );
  getchar();
  return 0;
}

void QBuild( Queue* q, int nSize )
{
  for ( int i = 0; i < nSize ; i++ )
    QEnqueue( q , i );
}
//=================================================

void QPrint(Queue* q)
{
  if ( QEmpty( q ) )
  {
    printf("ERROR: Queue is empty!\n");
    return;
  }
  int x = q -> nHead;
  while (x < (q -> nTail) )
  {
    printf(" Tab[%d] == %d", x, q -> Tab[ x ]);
    x++;
  }
}