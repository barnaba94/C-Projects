// Sort.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.

#include "sort.h"

//private
void Testujsort(pFp  pTabf[], const char* pFun[], int nFun, int* pPattern, int* pArrayCopy, int nSize);
void PrintTab(int* p, int Size);

int main(int argc, char* argv[])
{
	if ( argc != 2 )
	{
		printf( "Usage: Sort <tab_size> \n" );
		return 1;
	}
	int TabSize = atoi( argv[ 1 ] );
	int* p = NULL;
	int* r = NULL;
	Create( &p , TabSize );
	Create( &r, TabSize );	
	const char* nf[] = { "SelectionSort" , "InsertionSort" , "ShakeSort" , "HalfSort", "HeapSort"};
	pFp tf[] = { SelectionSort , InsertionSort , ShakeSort , HalfSort , HeapSort};
	int nSize = sizeof( tf ) / sizeof( pFp );
    #ifdef DEBUG_PRINT
	  printf( "%d" , nSize );
    #endif
    //InitTab( p, TabSize );
    Testujsort( tf , nf , nSize , p , r , TabSize );
	free( p );
	free( r );
	getchar();
    return 0;
}

//================================
void PrintTab(int* p, int Size)
{
  for (int i = 0; i < Size; i++)
  {
    if (!(i % 10)) 
      printf("\n");
    printf("%8d", *p++);
  }
}
//================================
void Testujsort(pFp  pTabf[], const char* pFun[], int nFun, int* pPattern, int* pArrayCopy, int nSize)
{
  InitTab(pPattern, nSize);
  for (int i = 0; i< nFun; i++)
  {
    CopyTab(pArrayCopy , pPattern , nSize);
    printf("\n \n Sortowanie: %s\n", pFun[ i ]);
    int tStart = clock();
    pTabf[ i ]( pArrayCopy , nSize );
    int tTime = (clock() - tStart) * 1000 / CLOCKS_PER_SEC;
    printf("\nCzas sortowania: %d [ms]\n", tTime);
  }

  //QuickSort
  CopyTab(pArrayCopy, pPattern, nSize);
  printf("\nSortowanie: QuickSort\n");
  int tStart = clock();
  QuickSort(pArrayCopy, 0, nSize - 1);
  int tTime = (clock() - tStart) * 1000 / CLOCKS_PER_SEC;
  printf("\nCzas sortowania: %d [ms]\n", tTime);

  //MergeSort
  CopyTab(pArrayCopy, pPattern, nSize);
  int* tmp = NULL;
  Create( &tmp , nSize );
  printf( "\nSortowanie: MergeSort\n" );
  int tStart2 = clock();
  MergeSort( pArrayCopy, tmp, nSize - 1, 0, nSize - 1 );
  int tTime2 = (clock() - tStart2) * 1000 / CLOCKS_PER_SEC;
  printf( "\nCzas sortowania: %d [ms]\n" , tTime2 );
  free( tmp );
  
  //MergeSort 2.0
  CopyTab(pArrayCopy , pPattern , nSize);
  int* tmp1;
  int* tmp2;
  Create( &tmp1, nSize );
  Create( &tmp2, nSize );
  printf("\nSortowanie: NaturalSort\n");
  int tStart3 = clock();
  NaturalSort( pArrayCopy, tmp1 , tmp2 , nSize );
  int tTime3 = ( clock() - tStart3 ) * 1000 / CLOCKS_PER_SEC;
  printf( "\nCzas sortowania: %d [ms]\n" , tTime );
  free( tmp1 );
  free( tmp2 );
}