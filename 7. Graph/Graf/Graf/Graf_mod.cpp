#include "Graf.h"
#include "PQueue.h"

double Dijkstra( Vertex* village, int nSize, int nFirst )
{
	PQueue* que = PQInit( nSize );
	double* PathLen = ( double* )calloc(nSize, sizeof( double ) );
	if( !PathLen )
	{
		printf( "Error: Unable to allocate memory! " );
		return -1;
	}
	double* PathTime = ( double* )calloc(nSize, sizeof( double ) );
	if( !PathTime )
	{
		printf( "Error: Unable to allocate memory! " );
		return -1;
	}
	PQEnQueue( que , nFirst , 0);
    for (int i = 0; i < nSize; i++)
    {
      if (i == nFirst) continue;
      PathLen[i] = INT_MAX;
    }
    double x = 0;
	while( !PQisEmpty( que ) )
	{
		int k = PQDeQueue( que ) ;
		if ( village[ k ] . vNext -> nInfo)
		{
			village[ nFirst ].nVerNumb = k;
			village[ nFirst ].allTime = PathTime[k];
			x = village[ nFirst ].road = PathLen[k];
			PQRealease( &que );
			break;
		}
		ListItem* pVert = village[k] . vNext;
		while( pVert )
		{
			int nNode = pVert -> nIndex;
			if( PathLen[k] +  pVert -> dist < PathLen[ nNode ] )
			{
				PathLen[ nNode ] = PathLen[k] + pVert -> dist;
				PathTime[nNode] = PathTime[k]+ pVert->time;
				PQEnQueue( que , nNode , PathLen[ nNode ] );
				village[ nFirst ] . Path[ nNode ] = k;
			}
			pVert = pVert -> nNext;
		}
	}
	free( PathLen );
	free( PathTime );
	return x;
}

void DFS( Vertex* vill, int* pVisit, int x, int speed )
{
	vill[ x ] . vNext -> time = vill[ x ] . vNext -> dist / speed;
	for( ListItem* pV = vill[x].vNext; pV ; pV = pV -> nNext )
		pV -> time = pV -> dist / speed;
	pVisit[ x ] = 1;
	for(ListItem* pV2 = vill[x].vNext; pV2 ; pV2 = pV2 -> nNext)
		if( !pVisit[ pV2 -> nIndex ] )
			DFS( vill , pVisit , pV2 -> nIndex , speed);
}