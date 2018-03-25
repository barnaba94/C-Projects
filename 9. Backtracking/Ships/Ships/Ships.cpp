// ships.cpp : Defines the entry point for the console application.

#include "ships.h"

int move(int** pTab, int nRow, int nCol, int nDepth, int move_nr, int x, int y, int* px, int* py, int** pRoot);
int root(int** pTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot, int x_dest, int y_dest);
void Print(int** pTab2, int nRow, int nCol);

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Usage: <input file>");
    return -1;
  }
  int** pTab1 = NULL;
  int** pTab2 = NULL;
  CreateMatrix( &pTab1 , M, N);
  CreateMatrix( &pTab2 , M, N);
  setTab( argv[1], pTab1, M, N);
  #ifdef DEBUG
    Print(pTab1, M, N);
  #endif
    printf("\n");
  if (!root(pTab1, M, N, DEPTH_MIN, 0, 0, pTab2, M - 1, N - 1))
  {
    printf("Cannot to find path to port ");
    return 0;
  }
  else
  #ifdef DEBUG
    Print(pTab2, M, N);
  #endif
  DeleteMatrix(&pTab1, M, N);
  DeleteMatrix(&pTab2, M, N);
  getchar();
  return 1;
}

int move(int** pTab, int nRow, int nCol, int nDepth, int move_nr, int x, int y, int* px, int* py, int** pTab2)
{
  switch ( move_nr )
  {
  case UP:	    *px = x - 1;	*py = y; break;
  case RIGHT:   *py = y + 1;	*px = x; break;
  case DOWN:	*px = x + 1;	*py = y; break;
  case LEFT:	*py = y - 1;	*px = x; break;
  }
  if (*px > nRow - 1 || *px < 0 || *py > nCol - 1 || *py < 0 || pTab2[ *px ][ *py ] || pTab[ *px ][ *py ] < nDepth + 1)
    return 0;				
  return 1;
}
int root(int** pTab, int nRow, int nCol, int nDepth, int x, int y, int** pTab2, int x_dest, int y_dest)
{
  pTab2[ x ] [y ] = 1;			
  if (x == x_dest && y == y_dest) 
    return 1;
  int px = x;
  int py = y;
  for (int i = UP; i <= LEFT; i++)
  {
    if ( move( pTab , nRow , nCol , nDepth , i , x, y, &px, &py, pTab2 ) )
      if ( root( pTab, nRow, nCol, nDepth, px, py, pTab2 , x_dest , y_dest) )
        return 1;
  }
  pTab2[ x ][ y ] = 0;
  return 0;
}
void Print(int** pTab2, int nRow, int nCol)
{
  for (int i = 0; i < nRow; i++)
  {
    int* p = *pTab2++;
    for (int j = 0; j < nCol; j++)
      printf("%d ", *p++);
    printf("\n");
  }
}