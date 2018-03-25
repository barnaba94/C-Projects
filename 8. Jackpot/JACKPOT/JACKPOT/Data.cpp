#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include "defs.h"	  
#include "Print.h"     
#include "Data.h"    


int AllocAddMemBet( Bets** pBetTab, int nCurrSize);
int AllocAddMem(LottoPlayer*** pTab, int nCurrSize); //!!!!

int AllocAddMem(LottoPlayer*** pTab, int nCurrSize)
{
  LottoPlayer** pCopyArray = *pTab;
  *pTab = ( LottoPlayer** ) realloc ( *pTab , ( NPLAYER + nCurrSize ) * sizeof( LottoPlayer* ) );
  if (!( *pTab ))
  {
    printf(" Error AllocAddMemBet: Memory not allocated!\n "); //!!!!!
    *pTab = pCopyArray;
    return 0;
  }
  memset(*pTab + nCurrSize, 0, NPLAYER * sizeof( LottoPlayer* ) );
  return NPLAYER;
}

int AllocAddMemBet(Bets** pBetTab, int nCurrSize)
{
  Bets* pCopyB = *pBetTab;
  *pBetTab = (Bets*) realloc (*pBetTab, (BETS + nCurrSize) * sizeof( Bets ) );
  if (!( *pBetTab ))
  {
    printf("Error AllocAddMemBet: Memory not allocated!\n");
    *pBetTab = pCopyB;
    return 0;
  }
  memset( *pBetTab + nCurrSize, 0, BETS * sizeof( Bets ) );
  return BETS;
}
//---------------------------------------------------------------
int ReadData(LottoPlayer*** pAllDraws, const char* sFileName)
{
  FILE* fin = NULL;
  if ((fin = fopen(sFileName, "r")) == NULL)
  {
    printf("Cannot to open file!!!");
    return 0;
  }
  int impcounter = 0;
  int MaxSizeTab = 0;
  LottoPlayer** pCopyAllD = *pAllDraws;
  char c;
  while (!feof( fin ))
  {
    if ((c = fgetc(fin)) == '*')
    {
      if (impcounter == MaxSizeTab)
      {
        MaxSizeTab += AllocAddMem( &pCopyAllD , impcounter);
        if ( impcounter == MaxSizeTab )
          break;
      }
      LottoPlayer* p = pCopyAllD[impcounter] = ( LottoPlayer* ) calloc ( 1, sizeof( LottoPlayer ) ); //next player
      if ( !p )
      {
        printf(" Unable to allocate memory ");
        return 0;
      }
      char s;
      int d;
      int m;
      int y;
      Swift* v1 = &( p->NofBank.SwiftNb );
      IbanNumber* v2 = &( p->NofBank.IbanNb );
      fscanf(fin,"%s %s %c %8c%3c %2c%2c%8c%16c %d/%d/%d %10c\n", p -> Surname, p -> Name, &s, v1 -> cPersonal, v1 -> cCheckDigits,
        v2 -> cCountryID, v2 -> cCheckDigits, v2->cBank, v2 -> cPersonal, &d, &m, &y, p->Pesel);
      
      if (! (SetDate(p, d, m, y)))
      {
        printf(" Error in SetDate!!!"); 
        return impcounter;
      }

      if (! (SetSex( p , s)))
      {
        printf(" Error in SetSex!!!");
        return impcounter;
      }
      //import bets
      while ((c = fgetc(fin)) != '*')
      {
        if( feof( fin ) )
          break;
        ungetc(c, fin);
        if ( p-> CurrSize == p->MaxSize)
        {
          p->MaxSize += AllocAddMemBet(&(p->PersonalBets), p->CurrSize);
          if (p->CurrSize == p->MaxSize)
             break;
        }
        int* p5 = p->PersonalBets[ p->CurrSize ].p5of50 = ( int* )calloc( N1, sizeof( int ) );
        if ( !p5 )
        {
          printf("Unable to allocate memory!!!");
          return 0;
        }
        int* p2 = p->PersonalBets[p->CurrSize].p2of10 = ( int* )calloc( N2 , sizeof( int ) );
        if (!p2)
        {
          printf("Unable to allocate memory!!!");
          return 0;
        }
        for (int i = 0; i < N1; i++, p5++)
          fscanf(fin, "%d", p5);
        fscanf(fin,"%d %d",p2, p2+1);
        p->CurrSize++;
        fscanf(fin, "\n");
      }
      impcounter++;
      if (c == '*')
        ungetc(c, fin);
    }
  }
  *pAllDraws = pCopyAllD;
  fclose( fin );
  return impcounter;
}
//--------------------------------------
int SetSex( LottoPlayer* p, char c)
{
  if (c != 'f' && c != 'm' && c != 'F' && c != 'M')
    return 0;
  switch (c)
  {
    case 'f':
    case 'F': p -> Tsex = female; break;
    case 'm':
    case 'M': p -> Tsex = male; break;
  }
  return 1;
}
//---------------------------------------------------
int SetDate(LottoPlayer* p, int d, int m, int y)
{
  if ( !( ( d > 0) && ( d < 32 ) && (m > 0) && (m < 13) && ( y > 1900 ) ) )
    return 0;

  tm readTime; //tm structure time.h
  readTime.tm_year = y - 1900;
  readTime.tm_mon = m - 1;
  readTime.tm_mday = d - 1;

  readTime.tm_hour = readTime.tm_min = readTime.tm_sec = 0;

  if ( !(mktime( &readTime )) )
  {
    printf("ERROR IN ");
    return 0;
  }
  switch ( readTime . tm_wday )
  {
    case 0: p->TofBets.DayofWeek = Mon; break;
    case 1: p->TofBets.DayofWeek = Tue; break;
    case 2: p->TofBets.DayofWeek = Wed; break;
    case 3: p->TofBets.DayofWeek = Thu; break;
    case 4: p->TofBets.DayofWeek = Fri; break;
    case 5: p->TofBets.DayofWeek = Sat; break;
    case 6: p->TofBets.DayofWeek = Sun; break;
  }
  switch ( m )
  {
    case 1 : p->TofBets.nMonth = Jan; break;
    case 2 : p->TofBets.nMonth = Feb; break;
    case 3 : p->TofBets.nMonth = Mar; break;//!!!!!!!!!!!!!!!!!!!!!!!1
    case 4 : p->TofBets.nMonth = Apr; break;
    case 5 : p->TofBets.nMonth = May; break;
    case 6 : p->TofBets.nMonth = Jun; break;
    case 7 : p->TofBets.nMonth = Jul; break;
    case 8 : p->TofBets.nMonth = Aug; break;
    case 9 : p->TofBets.nMonth = Sep; break;
    case 10 : p->TofBets.nMonth = Oct; break;
    case 11 : p->TofBets.nMonth = Nov; break;
    case 12 : p->TofBets.nMonth = Dec; break;
  }
  p -> TofBets . nDay = d;
  p -> TofBets . nYear = y;
  return 1;
}
void FreeMem(LottoPlayer** pTab, int nDrawsNo)
{
  for (int i = 0; i<nDrawsNo; i++)
  {
    LottoPlayer* v = pTab[ i ];
    Bets* g = v -> PersonalBets;
    for (int j = 0; j< v -> CurrSize; j++)
    {
      free(g[ j ].p5of50);
      free(g[ j ].p2of10);
    }
    free( g );
    free( v );
  }
  free( pTab );
  pTab = NULL;
}