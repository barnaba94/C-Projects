#include "PriorQueue.h"

#define MAX 20

void PQPrint( PQueue* );  //inorder
void BuildQueue( PQueue* );

int main(int argc, char* argv[])
{
  PQueue* que = PQInit( MAX );
  BuildQueue( que );
  #ifdef PRINT
    PQPrint( que );
  #endif
  PQDeQueue( que );
  printf(" \n ");
  printf(" \n ");
  #ifdef PRINT
    PQPrint( que );
  #endif
  DecreaseKey( que , 10, 1);
  printf(" \n ");
  printf(" \n ");
  #ifdef PRINT
    PQPrint( que );
  #endif
  printf(" \n ");
  printf(" \n ");
  PQEnQueue(que, 10, 10);
  #ifdef PRINT
    PQPrint(que);
  #endif
  PQDeQueue(que);
  printf(" \n ");
  printf(" \n ");
  #ifdef PRINT
    PQPrint( que );
  #endif
  getchar();
  return 0;
}

//=============================================================

void BuildQueue(PQueue* pQue)
{
  srand( ( unsigned ) time ( NULL ) );
  for (int i = 0; i < MAX ; i++ )
    PQEnQueue( pQue, i, rand() % 500 );
}

void PQPrint(PQueue* pQue) //inorder
  {
    if ( PQisEmpty( pQue ) )
    {
      printf(" Empty queue ");
      return;
    }
    for (int i = 0; i < pQue -> PQCurrSize; i++)
    {
      printf(" %4d %4d ", pQue -> PQueue[ i ].nKey, pQue -> PQueue[ i ].prior);
      printf(" \n ");
    }
  }