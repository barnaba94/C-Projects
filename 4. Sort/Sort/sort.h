#ifndef _sort_h_
#define _sort_h_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <cstring>

#define DEBUG_PRINT

typedef void ( *pFp )( int* pTab, int nSize);

int Create( int** p, int nSize );
void InitTab( int* t, int nSize );
void SelectionSort( int* t, int nSize );
void InsertionSort( int* t, int nSize );
void HeapSort( int* t, int nSize );
void MergeSort( int* t, int* tmp, int Size, int l, int p );
void Merge(int* tab, int* tmp, int nSize, int l, int m, int p);
void QuickSort( int* t, int l, int p);
void Update( int l, int p, int* t );
void CopyTab( int* p, int* r, int Tabsize );
void ShakeSort( int* t, int nSize );
void HalfSort( int* t , int nSize );
bool Copy(int* arr, int *i, int *tempArr, int *res, int end);
void CopySeries(int *arr, int *i, int *tempArr, int *res, int end);
void NaturalSort(int *arr, int *tempArrLeft, int *tempArrRight, int nMAX);

#endif
