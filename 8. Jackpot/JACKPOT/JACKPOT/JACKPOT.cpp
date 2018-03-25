#include <stdio.h>
#include <stdlib.h>
#include <string.h>    
#include <memory.h>
#include <malloc.h>
#include "defs.h"
#include "Data.h" 
#include "Print.h"

void InitTab(int** pBetsP, int nSize);
void HeapCheck(); //msdn
void CalcStat(int* pNum0, int* pNum1 , LottoPlayer** pDraws, int nDrawsNo);
void Sort( LottoPlayer** pDraws, int nDrawsNo );
int StrComp( char* s1, char* s2 );

//==================================================
int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    printf("Usage: <input file> <output file>");
    return 0;
  }

  LottoPlayer** players = NULL;
  int Nbofimported;
  if (!( Nbofimported = ReadData( &players , argv[1] ) ))
  { 
   printf( "Cannot read data!!!" );
   return 2;
  }
  int* pBetsP1 = NULL;
  int* pBetsP2 = NULL;
  InitTab( &pBetsP1 , STATN + 1);
  InitTab( &pBetsP2 , STATEN + 1 );
  Sort( players, Nbofimported );
  CalcStat( pBetsP1 , pBetsP2, players, Nbofimported );
  PrintResults( pBetsP1, pBetsP2, players , Nbofimported, argv[2] );
  FreeMem( players, Nbofimported );
  HeapCheck();
  getchar();
  return 0;
}
//================================================================================
void InitTab(int** pBetsP, int nSize)
{
  *pBetsP = (int*) calloc (nSize, sizeof(int));
  if (!(*pBetsP))
  {
    printf("Unable to allocate memory");
    return;
  }
}
//================================================================================
void HeapCheck()//helpcheck spr w helpie jakos heapchk jest msdn
{
  int  heapstatus;
  char *buffer;
  // Allocate and deallocate some memory
  if ((buffer = (char *) malloc ( 100 ) ) != NULL)
    free(buffer);
  // Check heap status
  heapstatus = _heapchk();
  switch (heapstatus)
  {
  case _HEAPOK:
    printf(" OK - heap is fine\n");
    break;
  case _HEAPEMPTY:
    printf(" OK - heap is empty\n");
    break;
  case _HEAPBADBEGIN:
    printf("ERROR - bad start of heap\n");
    break;
  case _HEAPBADNODE:
    printf("ERROR - bad node in heap\n");
    break;
  }
}

void CalcStat(int* pNums0, int* pNums1, LottoPlayer** nDraws, int nDrawsNo)
{
  int* p5of50 = pNums0;
  int* p2of10 = pNums1;

  for (int i = 0; i < nDrawsNo; i++)
  {
    LottoPlayer* p1 = nDraws[ i ];
    Bets* p2 = nDraws[i] -> PersonalBets;
    for (int j = 0; j < p1 -> CurrSize ; j++, p2++)
    {
      int* pArray5 = p2 -> p5of50;
      for (int k = 0; k < N1; pArray5++, k++)
      {
        if (( *pArray5 < 1 ) || (*pArray5 > STATN))
        {
          printf("ERROR!!! 1");
          return;
        }
       p5of50[*pArray5 - 1]++;
      }
      int* pArray2 = p2 -> p2of10;
      for (int k = 0; k < N2; k++)
      {
        if (*pArray2 < 1 || *pArray2 > STATEN )
        {
          printf("ERROR!!! 2");
          return;
        }
        p2of10[*pArray2++ - 1]++;
      }
    }
  }
}

void Sort(LottoPlayer** pDraws, int nDrawsNo)
{
  LottoPlayer** temp = pDraws;
  for (int i = 0; i < nDrawsNo; i++)
  {
    LottoPlayer* x = temp[ i ];
    int xi = i;
    for (int j = i + 1; j < nDrawsNo; j++)
    {
      if (!(StrComp(temp[ j ] -> Surname, temp[xi] -> Surname)))
      {
        if (StrComp(temp[ j ] -> Name, temp[xi] -> Name) < 0)
        {
          x = temp[j];
          xi = j;
        }
      }
      else if (StrComp(temp[j]->Surname, temp[xi]->Surname) < 0)
      {
        x = temp[j];
        xi = j;
      }
    }
      temp[xi] = temp[i];
      temp[i] = x;
    }
  }

int StrComp(char* s1, char* s2)
{
  char* cTmp1 = (char*) calloc ( 1 , (strlen(s1) + 1) * sizeof( char ));
  if ( !cTmp1 )
  {
    printf(" Unable to allocate memory ");
    return 0;
  }
  strcpy( cTmp1 , s1);
  char* cTmp2 = ( char* ) calloc ( 1 , (strlen(s2) + 1) * sizeof( char ));
  if ( !cTmp2 )
  {
    printf("Unable to allocate memory");
    return 0;
  }
  strcpy( cTmp2 , s2 );
  _strlwr(cTmp1);
  _strlwr(cTmp2);
  int res = strcmp( cTmp1 , cTmp2 );
  free( cTmp1 );
  free( cTmp2 );
  return res;
}