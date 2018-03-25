//definicja sta³ych i typów
#pragma once

#define NCOUNTRYID 2
#define NCHECKDIGITS 2 
#define NBANK 8
#define NPERSONAL 16
#define SWIFTTYPE 9
#define CONTROL 4
#define MAX 12
#define PESEL 11
#define STATN 50
#define STATEN 10
#define NPLAYER 7
#define N1 5
#define N2 2
#define OFSPACE 35
#define BETS 3

typedef enum { Mon, Tue, Wed, Thu, Fri, Sat, Sun} Day;
typedef enum { Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec}Month;
typedef enum { male, female }Sex;

typedef struct {
  Month nMonth;
  Day DayofWeek;
  int nDay;
  int nYear;
} Time;

typedef struct
{
  char cCountryID[ NCOUNTRYID ];
  char cCheckDigits[ NCHECKDIGITS ];
  char cBank[ NBANK ];
  char cPersonal[ NPERSONAL ];
} IbanNumber; //International Bank Account Number// 2COUNTRY + 2CHECKDIGITS + 8 BANK + 16 NPERSONAL 

typedef struct
{
    char cPersonal[ SWIFTTYPE ];
    char cCheckDigits[ CONTROL ];
} Swift; //Society for Worldwide Interbank Financial Telecommunication // 8personal + 3checkdigits

typedef struct
{
  Swift SwiftNb;
  IbanNumber IbanNb;
} Bank;
typedef struct
{
    int* p5of50;
    int* p2of10;
} Bets;

typedef struct
{
  char Name[ MAX+1 ];
  char Surname[ MAX+1 ];
  char Pesel[ PESEL ];
  int MaxSize;
  int CurrSize;
  Bank NofBank;
  Bets* PersonalBets;
  Time TofBets;
  Sex Tsex;
}LottoPlayer;