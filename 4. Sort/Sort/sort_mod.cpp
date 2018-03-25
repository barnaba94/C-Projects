
#include "sort.h"

int Create( int** p, int Size )
{
	*p = ( int* ) calloc ( Size, sizeof( int ) );
	if ( !p )
	{
		printf( "Unable to allocate memory \n" );
		return 0;
	}
	return 1;
}
//===============================
void InitTab( int* t, int Size )
{
	srand( ( unsigned int ) time ( NULL ) );
	for ( int i = 0; i < Size; i++ )
		t[ i ] = rand() % Size;
}
//===================================
void SelectionSort( int* t, int Size )
{
	for ( int i = 0; i < Size - 1; i++ )
	{
		int k = i;
		int x = t[ i ];
		for (int j = i + 1; j < Size; j++)
		{
			if (t[ j ] < x)
			{
				x = t[ j ];
				k = j;
			}
		}
		t[ k ] = t[ i ];
		t[ i ] = x;
	}
}
//===================================
void InsertionSort( int* t, int Size )
{
	for ( int i = 1; i < Size; i++ )
	{
		int x = t[ i ];
		int j = i - 1;
		while ( j >= 0 && x < t[ j ] )
		{
			t[ j + 1] = t[ j-- ];
		}
		t[j + 1] = x;
	}	
}
//===================================
void HeapSort(int* t, int nSize)
{
	for (int i = nSize / 2; i >= 0; i--)
		Update( i, nSize - 1, t );

	for (int i = nSize - 1; i > 0; i--)
	{
		int x = t[ 0 ];
		t[ 0 ] = t[ i ];
		t[ i ] = x;
		Update( 0, i - 1 , t );
	}
}
//++++++++++++++++++++++++++++++++++++++++++
void Update(int l, int p, int* t)
{
		if (l == p) return;
		int i = l;
		int j = 2 * i + 1;
		int x = t[ i ];
		while ( j <= p )
		{
			if ( j < p )
				if (t[ j ] < t[ j + 1 ] ) j++;
			if (x > t[ j ]) break;
			t[ i ] = t[ j ];
			i = j;
			j = 2 * i + 1;
		}
		t[ i ] = x;
}
//=============================================
void QuickSort(int* t, int l, int p)
{
    int i = l;
    int j = p;
    int x = t[ (p + l) / 2];
	do
	{
		while (t[ i ] < x)
          i++;
		while (t[ j ] > x)
          j--;
        if (i <= j)
        {
          if (i != j)
          {
            int temp = t[i];
            t[i] = t[j];
            t[j] = temp;
          }
          i++;
          j--;
        }
	} while (i <= j);
	if (l < j) QuickSort( t, l, j );
	if (i < p) QuickSort( t, i, p );
}
//==========================================
void MergeSort(int* t, int* tmp, int Size, int l, int p) //recursive method
{
	if (l < p)
	{
		int m = ( l + p ) / 2;
		MergeSort( t , tmp , Size , l , m );
		MergeSort( t , tmp , Size , m + 1 , p );
		Merge( t , tmp , Size , l , m , p );
	}
}
//==========================================
void Merge(int* tab, int* tmp1, int Size, int l, int m, int  p)
{
	//for (int i = l; i <= p; i++)   //memcpy
	//	tmp1[ i ] = tab[ i ];
    memcpy(tmp1 + l, tab + l, (p - l + 1) * sizeof( int ) ); //changed
	int i = l;
	int j = m + 1;
	int q = l;
	while (i <= m && j <= p)
	{
		if (tmp1[ i ] < tmp1[ j ]) tab[ q++ ] = tmp1[ i++ ];
		else  tab[ q++ ] = tmp1[ j++ ];
	}
	while (i <= m) tab[ q++ ] = tmp1[ i++ ];
}
//=============================================
void HalfSort(int* t, int Size)
{
  for (int i = 1; i < Size; i++)
  {
    int l = 0;
    int r = i - 1;
    int x = t[ i ];
    while (l <= r)
    {
      int m = ( l + r ) / 2;
      if (x < t[ m ]) r = m - 1;
      else l = m + 1;
    }
    for (int j = i - 1; j >= l; j--)
    {
      t[ j + 1 ] = t[ j ];
    }
    t[ l ] = x;
  }
}
//=============================================
void ShakeSort(int* t, int Size)
{
  int l = 1;
  int r = Size - 1;
  int k = Size - 1;

  do
  {
    for (int j = r; j >= l; j--)
    {
      if (t[ j - 1 ] > t[ j ])
      {
        int x = t[j - 1];
        t[j - 1] = t[j];
        t[ j ] = x;
        k = j;
      }
    }
    l = k + 1;
    for (int j = l; j <= r; j++)
    {
      if (t[j - 1] > t[j])
      {
        int x = t[j - 1];
        t[j - 1] = t[j];
        t[j] = x;
        k = j;
      }
    }
    r = k - 1;
  } while (l <= r);
}
//--------------------------------------------------------------------
void CopySeries(int *arr, int *i, int *tempArr, int *res, int end) {
  int tmp = 0;
  do {
    tmp = Copy(arr, i, tempArr, res, end);
  } while ( !tmp );
}
//--------------------------------------------------------------------
bool Copy(int* arr , int *i , int *tempArr , int *res , int end)
{
  arr[ ( *i )++ ] = tempArr[ (*res)++ ];
  if ( *res == end ) 
    return 1;
  return (tempArr[ *res - 1 ] > tempArr[ *res ]);
}
//---------------------------------------------------------------------------
void NaturalSort(int *arr, int *tempArrLeft, int *tempArrRight, int nMAX)
{
  int index;
  do {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < nMAX)
    {
      while (i < nMAX - 1 && arr[i] <= arr[i + 1]) tempArrLeft[j++] = arr[i++];

      tempArrLeft[j++] = arr[i++];

      while (i < nMAX - 1 && arr[i + 1]) tempArrRight[k++] = arr[i++];

      if (i < nMAX) tempArrRight[k++] = arr[i++];
    }

    int endLeft = j;
    int endRight = k;

    index = 0;
    i = j = k = 0;

    while ((j < endLeft) && (k < endRight))
    {
      int ifEndSerie = 0;
      while (!ifEndSerie)
      {
        if (tempArrLeft[j] <= tempArrRight[k])
        {
          ifEndSerie = Copy(arr, &i, tempArrLeft, &j, endLeft);
          if (ifEndSerie)	CopySeries(arr, &i, tempArrRight, &k, endRight);
        }
        else
        {
          ifEndSerie = Copy(arr, &i, tempArrRight, &k, endRight);
          if (ifEndSerie)	CopySeries(arr, &i, tempArrLeft, &j, endLeft);
        }
      }
      index++;

      while (j < endLeft)
      {
        CopySeries( arr, &i, tempArrLeft, &j, endLeft);
        index++;
      }
      while (k < endRight)
      {
        CopySeries( arr, &i, tempArrRight, &k, endRight);
        index++;
      }
    }
  } while (index > 1);
}
//============================================
void CopyTab(int* p, int* r, int Tabsize)
{
  memcpy( p , r , Tabsize * sizeof( int ));
}