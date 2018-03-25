#ifndef _SHIPS_
#define _SHIPS_

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define DEBUG

#define DEPTH_MIN 2
#define M 10
#define N 10

typedef enum { UP, RIGHT, DOWN, LEFT }Tdirect;

void setTab(char* sFile, int** pTab, int nRow, int nCol);
int CreateMatrix(int*** matrix, int nRow, int nCol);
void DeleteMatrix(int*** matrix, int nRow, int nCol);//release memory

#endif