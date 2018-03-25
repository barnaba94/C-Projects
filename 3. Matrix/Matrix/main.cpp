// main.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.

#include "matrix.h"

void printPbOrRes(double* pRes, int Size);
void ReadData(FILE* file, double** matrix, double* pb, int nSize);


int main( int argc, char* argv[] )
{
	if (argc != 2)
	{
		printf( "Usage: <input file>" );
		return -1;
	}

	int Size;
	FILE* fin;

	if (!(fin = fopen(argv[1], "r" ) ) )
	{
		printf("ERROR: Cannot open file \n");
		return 1;
	}

	fscanf( fin, "%d" , &Size );
    printf(" dim= %d\n" , Size );
	double** Matrix = NULL;
    CreateMatrix(&Matrix, Size);
	double* pb = ( double* ) malloc ( Size * sizeof( double ) );
    if ( !pb )
    {
      printf( "\nUnable to allocate memory\n" );
      return -1;
    }//!!!
	memset( pb, 0, Size * sizeof( double ) );
	double* Res = ( double* )malloc( Size * sizeof( double ) );
    if ( !Res )
    {
      printf( "\nUnable to allocate memory\n" );
      return 1;
    }
	memset( Res, 0, Size * sizeof( double ) );

	ReadData( fin, Matrix, pb, Size );
    #ifdef _DEBUG_PRINT_INIT_
	  PrintMatrix( Matrix, Size );
	  printPbOrRes( pb, Size );
    #endif

    double det_temp = Det( Matrix , Size );
    if (fabs(det_temp) < 1e-10) //correction 18.11 if det=0
	{
		printf( "Cannot invert matrix -> det=0 " );
		return -1;
	}
   #ifdef _DEBUG_PRINT_
	printf("\n det = %lf \n", det_temp);
    #endif
    double** Invert = NULL;
    CreateMatrix(&Invert, Size);
	InverseMatrix( Matrix, Invert, det_temp, Size);
    #ifdef _DEBUG_INVERSE_
	  PrintMatrix( Invert, Size);
    #endif
	  LayoutEqu( Invert, pb, Res, Size ); //Results
 
	  printPbOrRes( Res, Size);

	free( pb );
	free( Res );
	DeleteMatrix( &Matrix , Size);
	DeleteMatrix( &Invert, Size);
	getchar();
	return 0;
}

//-----------------------------------
void printPbOrRes(double* pRes,int Size)
{
  double* p = pRes;
  for (int i = 0; i < Size; i++)
  {
    printf("\n%lf", *p++);
  }
  p = pRes;
}
//------------------------------------------------------------
void ReadData(FILE* file, double** matrix, double* pb, int nSize)
{
  double** ptr = matrix;
  double*  p1 = pb;
  for (int i = 0; i< nSize; i++)
  {
    double* ptr1 = *ptr++;
    for (int j = 0; j < nSize; j++)
    {
      fscanf(file, "%lf", ptr1++);
    }
    fscanf(file, "%lf", p1++); //last column
  }
  fclose(file);
}