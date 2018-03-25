
#include "defs.h"  // // definicje typow i stalych
#include "Print.h"    // interfejs mpodulu drukowania 
#include "Data.h"     // interfejs modulu wczytywania danych

//--------------------------------------------------
//   Modul wczytywania danych DATA zawiera (wszystkie w pliku naglowkowym Data.h) 
int  ReadData( LottoPlayer*** pAllDraws, const char* sfileName );
int  AllocAddMem( LottoPlayer*** pTab, int nCurrSize );
void FreeMem( LottoPlayer** pTab, int nDrawsNo );
int  SetSex( LottoPlayer* p, char c );
int  SetDate( LottoPlayer* p, int d, int m, int y );

//--------------------------------------------------
//   Modul drukowania PRINT
void PrintResults( int* pNums, LottoPlayer** pDraws, int nDrawsNo ); // w pliku Print.h
void PrintSex( FILE* fout, LottoPlayer* p );                         // prywatna modulu
void PrintDate( FILE* fout, LottoPlayer* p );                        // prywatna modulu
void PrintBets( FILE* fout, int** pBets );                           // prywatna modulu //tu nie nie bedzie int** JackPotbet**



//-------------
void InitTab();
void HeapCheck();//helpcheck spr w helpie jakos heapchk jest msdn
void CalcStat( int* pNums, LottoPlayer** pDraws, int nDrawsNo );
void Sort( LottoPlayer** pDraws, int nDrawsNo );


//==================================================
int main( int argc, char* argv[] )
{
// Parametrem progrmu jest plik tekstowy z zakladami

  //definicja dynamicznej tablicy typu LottoPlayer**
  
  // zdeiniowac zmienna dla pamiatania ilosci wczytanych danych (ilosci gracczy)

  if( ilosc_wczytanych danych == 0  )
  { //komunikat;
    return 2;
  }
  // definicja tablicy dla pamiatania statystyk dla wyboru 5 z 50 i 2 z 10 (tak jak w EuroJackpot)

  //przetwarzanie danych
     // obliczenie statystyk 
     // posortowac ze wzgledu na nazwisko i imie (przestawiac wskazniki w tablicy typu LottoPlayer**)
  // wydrukowac dane do pliku wyniki.txt
  
  //zwolnic pamiec
  ///HeapCheck(); --   mozna dodac ta funkcje - mozna skopiowac z helpow //czy sterta wolnej pamieci jest wolna


  return 0;
}




//--------------------------------------------------------------
int AllocAddMem( LottoPlayer*** pTab, int nCurrSize )
{
  // uzywa funkcji "realloc" i memset przy czym jesli sie nie powiodlo
  // to nie mozna stracic do tej pory czytanych danych i program ma dzialac dalej
  // z tym ze zwraca wtedy wartosc zero
  // w przypadku powodzenia realokacji zwaraca o ile realokowano!!!

}


//---------------------------------------------------------------
int ReadData( LottoPlayer*** pAllDraws, const char* sFileName )
{
  //na pocz jest null
// otwiera plik do odczytu z badaniem bledu otwarcie - gdy blad to funkcja 
  //wypisuje komunikat i zwraca zero

  // zdefiniowac zmienna liczaca ilosc wczytanyc danych (poczatkowo 0) oraz 
  // zmienna aktualny maxym rozmiar tablicy pAllDraws (poczatkowo 0 )
  
  // zrobic kopie parametru *pAllDraws
  while( !feof( fin ) )
  {
    // jesli trzeba to realokowac  (ilosc wczytanych danych == maxym rozmiar) 
            // dodac do zmiennej maxym rozmiar wynik funkcji realokujacej (5- ilosc o ktora realokujemy)

    // wczytac kolejnego gracza
          // wczytywac jedna instrukcja fscanf wszystkie dane opidujace gracza
          // przy czym dane dot. plci i daty do zmiennych pomocniczych
          // ktore beda parametrami funkcji SetSex() i SetDate()
          
          // jesli nie powiodlo sie ustawic plci lub daty to wyjscie z funkcji z odpowiednim komunikatem z dotychczas 
          // wczytanymi danymi
    
         // czytanie zakladow  - realokacja co 3 zaklady
  }  

  // przywrocic wskaznik *pAllDraws;
  // ewentualne sprawdzenie sterty pamieci wolnej HeapCheck();

  return ilosc_wczytanych_danych;
}
//--------------------------------------
int SetSex( LottoPlayer* p, char c )
{
//jesli literka c nie jest f F m lub M to zwaraca 0 a jesli OK to 1
// uzywa nazw zdefiniowanych w typie wyliczeniowym
}
//---------------------------------------------------
int SetDate( LottoPlayer* p, int d, int m, int y )
{
  // sprawdza czy d jest z przewdzialu od 1 do 31
  // m od 1 do 12
  // y wieksze od 1900
  // w przeciwnym przyp zwraca 0

  // uzywa nazw zdefiniowanych w typach wyliczeniowych
  return 1;
}

//---------------------------------------------------------------
void CalcStat( int* pNumsAll, LottoPlayer** pDraws, int nDrawsNo )
{
  // wykorzystywac tylko zmienne wskaznikowe do przegladania
  // tablicy wsk do struktur pDraws i mozna indeksowac tablice pNumsAll
}


