#include <stdio.h>
#include "defs.h"	  
#include "Print.h"    
#include "Data.h"    
#include <string.h>


void PrintSex(FILE* fout, LottoPlayer* p);
void PrintDate(FILE* fout, LottoPlayer* p);
void PrintBets(FILE* fout, Bets** pBets);

void PrintResults(int* pNums0, int* pNums1, LottoPlayer** pDraws, int nDrawsNo, char* sFile)
{
  FILE* fout = NULL;
  if ( ( fout = fopen( sFile , "w") ) == NULL)
  {
    printf("Cannot to open file!!!");
    return;
  }
  for (int i = 0; i < nDrawsNo; i++, pDraws++)
  {
    fprintf(fout , "%s ", (*pDraws) -> Surname);
    fprintf(fout , "%s ", (*pDraws)->Name);
    PrintSex(fout, *pDraws);
    PrintDate(fout, *pDraws);
   
    LottoPlayer* p = *pDraws;
    Swift* v1 = &(p->NofBank.SwiftNb);
    IbanNumber* v2 = &(p->NofBank.IbanNb);
    fprintf(fout, "\t %.8s%.3s %.2s%.2s%.8s%.16s %10s", v1->cPersonal, v1->cCheckDigits, //!!!!!!
     v2->cCountryID, v2 -> cCheckDigits, v2->cBank, v2->cPersonal, p->Pesel);
    Bets* bet = (*pDraws) -> PersonalBets;
    for (int j = 0; j < ( *pDraws ) -> CurrSize - 1; j++, bet++)
      PrintBets(fout, &bet );
    fprintf(fout, "\n---------------------------------------------------------------------------------------------------------\n");
  }
  fprintf(fout, "\n=========================================================\n");
  fprintf(fout, "\n           S  T  A  T  I  S  T  I  C           \n");
  fprintf(fout, "\n=========================================================\n");
  for (int i = 1; i < STATN+1; i++) 
  {
    fprintf(fout, "%2d: %2d   ", i , pNums0[i]);
    if (i % 10 == 0) fprintf( fout , "\n");
  }
  fprintf(fout, "\n\n");
  for (int j = 1; j < STATEN+1; j++)
  {
    fprintf(fout, "%2d: %2d   ", j, pNums1[j-1]);
    if (j % 5 == 0) fprintf(fout, "\n");
  }
  fclose(fout);
}

void PrintSex(FILE* fout, LottoPlayer* p)
{
  int ln = strlen( p -> Name) + strlen(p -> Surname) + 1;
  for (int i = 0; i < OFSPACE - ln; i++)
    fprintf(fout, " ");
  switch (p -> Tsex)
  {
  case female: fprintf(fout, " *Panienka*\t "); break;
  case male: fprintf(fout, " *Facet*\t "); break;
  }
}
void PrintDate(FILE* fout, LottoPlayer* p)
{
  switch (p -> TofBets.DayofWeek)
    {
      case 0: fprintf(fout, "Mon,  "); break;
      case 1: fprintf(fout, "Tue,  "); break;
      case 2: fprintf(fout, "Wed,  "); break;
      case 3: fprintf(fout, "Thu,  "); break;
      case 4: fprintf(fout, "Fri,  "); break;
      case 5: fprintf(fout, "Sat,  "); break;
      case 6: fprintf(fout, "Sun,  "); break;
  }
  fprintf(fout, "%2d/", p->TofBets.nDay);
  switch (p->TofBets.nMonth)
    {
      case 1: fprintf(fout, "Jan/"); break;
      case 2: fprintf(fout, "Feb/"); break;
      case 3: fprintf(fout, "Mar/"); break;
      case 4: fprintf(fout, "Apr/"); break;
      case 5: fprintf(fout, "May/"); break;
      case 6: fprintf(fout, "Jun/"); break;
      case 7: fprintf(fout, "Jul/"); break;
      case 8: fprintf(fout, "Aug/"); break;
      case 9: fprintf(fout, "Sep/"); break;
      case 10: fprintf(fout, "Oct/"); break;
      case 11: fprintf(fout, "Nov/"); break;
      case 12: fprintf(fout, "Dec/"); break;
    }
  fprintf(fout, "%4d", p->TofBets.nYear);
}
void PrintBets(FILE* fout, Bets** pBets)
{
  int* p5 = (*pBets) -> p5of50;
  int* p2 = (*pBets) -> p2of10;
  fprintf(fout, "\n");
  for (int i = 0; i < N1; i++, p5++)
    fprintf(fout,"%2d ", *p5);
  fprintf(fout, " ");
  for (int j = 0; j < N2; j++, p2++)
    fprintf(fout, "%2d ", *p2);
}
