#ifndef _MATRIX_
#define _MATRIX_

#define _DEBUG_PRINT_INIT_
#define _DEBUG_INVERSE_
#define _DEBUG_RESULT_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <memory.h> //correction 18.11 change "" to <>

int CreateMatrix( double*** matrix, int nSize ); //correction 18.11 rename
void DeleteMatrix( double*** matrix, int nSize );
void PrintMatrix( double** matrix, int nSize );
double Det( double** matrix, int nSize );//determinant evaluate
void InverseMatrix( double** matrix, double** inv, double det, int nSize);//inversion of Mat
void LayoutEqu( double** pInv, double* pB, double* pRes, int nSize );//result
#endif