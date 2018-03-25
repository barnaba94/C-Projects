#include "ships.h"
//==================================================
int CreateMatrix(int*** matrix, int nRow, int nCol)
{
  *matrix = ( int** )calloc( nRow , sizeof( int* ));
  if ( !matrix ) 
  {
    printf("\nUnable to allocate memory\n");
    return 0;
  }
  int** ptr = *matrix;
  for (int i = 0; i < nCol; i++, ptr++)
  {
    *ptr = ( int* )calloc( nCol, sizeof( int ) );
    if ( !ptr ) {
      printf( "\nUnable to allocate memory\n" );
      return 0;
    }
  }
  return 1;
}
//==================================================
void DeleteMatrix(int*** matrix, int nRow, int nCol)//release memory
{
  int** ptr = *matrix;
  for (int i = 0; i < nRow; i++)
  {
    free( *ptr++ );
  }
  free( *matrix );
  *matrix = NULL;
}
//==================================================
void setTab(char* sFile, int** pTab, int nRow, int nCol)
{
  FILE* file;
  if (!( file = fopen( sFile , "r" ) ) )
  {
    printf("ERROR: Cannot open file \n");
    return;
  }
  int** ptr = pTab;
  for (int i = 0; i< nRow; i++)
  {
    int* ptr1 = *ptr++;
    for (int j = 0; j < nCol; j++)
      fscanf(file, "%d", ptr1++);
  }
}