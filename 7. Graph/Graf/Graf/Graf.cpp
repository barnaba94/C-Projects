// Graf.cpp : Defines the entry point for the console application.

#include "Graf.h"
#include "PQueue.h"

void ReadFile( Vertex* village, FILE* fin );

int main(int argc, char** argv)
{
	if(argc != 3)
	{
		printf(" Usage: <input file> <output file> ");
		return -1;
	}
	FILE* fin = NULL;
	if( !( fin = fopen( argv[ 1 ], "r" ) ))
	{
		printf( "Error: Cannot open a file! \n" );
		return -1;
	}
	int nSize;
	fscanf( fin, "%d", &nSize );
	Vertex* village = ( Vertex* ) calloc ( nSize , sizeof( Vertex ) );
	if( !village)
	{
		printf( "Error: Unable to allocate memory! " );
		return -1;
	}
	for( int i = 0; i < nSize ; i++ )
		village[ i ].vNext = NULL;
	for( int i = 0; i < nSize ; i++)
	{
		village[i].Path = ( int* ) calloc ( nSize , sizeof( int ) );
		if( !village[i].Path )
		{
			printf( "Error: Unable to allocate memory! " );
			return -1;
		}
	}
	ReadFile( village , fin );
	fclose( fin );
	int* pVisit = ( int* )calloc(nSize, sizeof( int ) );
	if( !pVisit )
	{
		printf( "Error: Unable to allocate memory! " );
		return -1;
	}
	for( int i=0; i < nSize ; i++ )
		DFS( village , pVisit , i , SPEED);
	int* CopyPath = ( int* )calloc( nSize , sizeof( int ) );
	if( !CopyPath)
	{
		printf( "Error: Unable to allocate memory! " );
		return -1;
	}
	for( int i = 0; i < nSize; i++ )
      if (!village[i].vInfo)
      {
        Dijkstra( village , nSize, i );
		memcpy( CopyPath,  village[ i ] . Path, nSize * sizeof( int ) );
		memset( village[ i ] . Path , -1 , nSize * sizeof( int) );
		int k = village[i] . nVerNumb;
		village[ i ].Path[ 0 ] = k;
		for(int j = 1; k != i; j++)
			{
				village[ i ].Path[ j ] = CopyPath[ k ];
				k = CopyPath[ k ];
			}
		}
      
		int tmp;
		int tmpcnt = 0;
		for( int i = 0; i < nSize; i++ )
		{
			for( int j = 0; j < nSize; j++ )
				if( village[ i ].Path[ j ] >= 0 )
                  tmpcnt++;
            for (int k = 0; k < tmpcnt / 2; k++)
            {
              tmp = village[ i ].Path[ tmpcnt - k - 1 ];
              village[ i ].Path[ tmpcnt - k - 1 ] = village[ i ].Path[ k ];
              village[ i ].Path[ k ] = tmp;
            }
            tmpcnt = 0;
		}
	//output file
	FILE* fout = NULL;
	if( !( fout = fopen( argv[2], "w" ) ))
	{
		printf( "Error: Cannot open a file! \n" );
		return -1;
	}
	for( int i = 0; i < nSize; i++ )
		if( !village[ i ].vInfo )
		{			
			fprintf( fout, "%d. \tNearest shop: %d \tDistance: %.3lf [km] \tTime: %.3lf [h] \tPath: ", i, village[ i ].nVerNumb , village[ i ].road , village[i].allTime );
			for( int j = 0; j < nSize; j++ )
			{
				if( village[ i ].Path[ j ] < 0 ) continue;
				fprintf( fout, "%d ", village[ i ].Path[ j ] );
			}
			fprintf( fout,"\n" );
		}
	fclose( fout );
	free( village -> vNext );
	free( village );
	getchar();
	return 0;
}
//=======================================================

void ReadFile( Vertex* village, FILE* fin )
{
	int nVer;
	while( !feof( fin ) )
	{
		fscanf( fin, "%d", &nVer );
		ListItem* vert = ( ListItem* )calloc( 1 , sizeof( ListItem ) );
		if( !vert )
		{
			printf( "Error: Unable to allocate memory! " );
			return;
		}
		if( ! village[nVer].vNext )
		{
			village[nVer]. vNext = vert;
			fscanf( fin, "%d %lf %d ", &( vert -> nIndex ), &( vert -> dist ),&( vert -> nInfo));
			village[ nVer ].vInfo = vert -> nInfo;
		}
		else
		{
			ListItem* a = village[ nVer ].vNext;
			while( a -> nNext )
				a = a -> nNext;
			a -> nNext = vert;
			fscanf( fin, "%d %lf %d ", &( vert -> nIndex ), &( vert -> dist ),&( vert -> nInfo));
			village[ nVer ] . vInfo = vert -> nInfo;
		}
	}
}