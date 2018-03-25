#define _CRT_SECURE_NO_WARNINGS
#include "matrix.h"

//prototypes private functions
void DivDet(double** pTab, int nSize, double det);
void Complement(double** matrix, double** mComp, int nSize, int nRow, int nCol);
void ComplMatrix(double** matrix, double** pTab, int nSize);
void TransMatrix(double** matrix, int nSize);


int CreateMatrix( double*** matrix, int nSize ) 
{
	*matrix = ( double** )calloc( nSize, sizeof( double* ) );
    if (!matrix) {
      printf( "\nUnable to allocate memory\n" );
      return 0;
    }
	double** ptr = *matrix;
	for (int i = 0; i < nSize; i++, ptr++)
	{
		*ptr = ( double* )calloc( nSize , sizeof ( double ) );
        if ( !ptr ) {
          printf( "\nUnable to allocate memory\n" );
          return 0;
        }
	}
    return 1;
}
//-----------------------------------------------------
void DeleteMatrix ( double*** matrix, int nSize )//release memory
{
	double** ptr = *matrix;
	for (int i = 0; i < nSize; i++)
	{
		free( *ptr++ );
	}
	free( *matrix );
	*matrix = NULL;
}
//----------------------------------------------------
void PrintMatrix( double** matrix, int nSize)
{
	for (int i = 0; i < nSize; i++)
	{
		double* p = matrix[i];
		for (int j = 0; j < nSize; j++)
		{
			printf( "%5.2lf ", *p++);
		}
		printf( "\n" );
	}
}
//===================================================================
double Det( double** matrix, int nSize) //recursive evaluation of the determinant //Laplace expansion
{
	double det = 0.0;
	double** mComp;

    if (nSize == 1)
      return matrix[0][0];
	if (nSize == 2) 
		return matrix[0][0]*matrix[1][1]-matrix[1][0]*matrix[0][1];
	CreateMatrix( &mComp , nSize - 1 );
	int coef = 1;
	for (int i = 0; i < nSize; i++)
	{
		Complement( matrix , mComp , nSize , 0 , i);
		det += coef * matrix[0][i] * Det( mComp , nSize - 1);
		coef =- coef;

	}
	DeleteMatrix( &mComp , nSize-1 );
	return det;
}
//-------------------------------------------------------------------
void Complement( double** matrix, double** mComp, int nSize, int nRow, int nCol ) //complement matrix
{
	double** ptr = mComp;
	double** m = matrix;
	for (int i = 0; i < nSize ; i++ , m++ )
	{
		if (i == nRow)
			continue;
		double* p = *ptr++;
		double* m1 = *m;

		for (int j = 0; j < nSize; j++, m1++)
		{
			if (j == nCol)
				continue;
			*p++ = *m1;
		}
	}
}
//-------------------------------------------------------------------
void InverseMatrix( double** matrix, double**inv, double det, int nSize)//inversion of Mat
{
	ComplMatrix( matrix , inv , nSize );
	TransMatrix( inv , nSize );
	DivDet( inv , nSize , det );
}
//----------------------------------------------------------------------
void TransMatrix( double** matrix, int nSize)
{
	double temp;
	double** ptr = matrix;
	for ( int i = 0 ; i < nSize ; i++ )
	{
		double* p = ( *ptr++ + i + 1 );
		for (int j = i + 1; j < nSize ; j++)
		{
			temp  = *p;
			*p++ = matrix[ j ][ i ];
			matrix[ j ][ i ] = temp;
		}
	}
}
//----------------------------------------------------------------------
void ComplMatrix(double** matrix, double** pTab,int nSize)//Adjugate matrix
{
	double** mComp;
	CreateMatrix( &mComp, nSize);
	double** ptr = pTab;
    
	for (int i = 0; i < nSize ; i++)
	{   
        int coef = (i % 2) ? -1:1;
		double* ptr2 = *ptr++;
		for (int j=0; j< nSize ; j++)
		{
			Complement( matrix , mComp, nSize, i, j);
			*ptr2++ = coef * Det( mComp, nSize - 1 );
			coef = -coef;
		}
	}
    DeleteMatrix(&mComp,nSize); //correction 18.11 release memory
    //!!!!
}
//--------------------------------------------------------
void DivDet(double** pTab, int nSize, double det)//divide matrix by det
{
	double** ptr = pTab;
	for (int i = 0; i < nSize; i++)
	{
		double* p = *ptr++;
		for (int j = 0; j < nSize; j++) 
			*p++ /= det;
	}
}
//--------------------------------------------------------
void LayoutEqu(double** pInv, double* pB, double* pRes, int nSize)//layout solution function
{
	double** ptr = pInv;
	double* p2 = pRes;
	for (int i = 0; i < nSize; i++ , p2++)
	{
        double* p1 = pB;
		double* ptr1 = *ptr++;
		for (int j = 0; j < nSize; j++)
			*p2 += *ptr1++ * *p1++;
	}
	p2 = pRes;
}