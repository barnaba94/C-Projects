#ifndef _GRAF_
#define _GRAF_

#include <memory.h>
#include <stdlib.h>
#include <stdio.h>

#define SPEED 4

typedef struct tagListItem
{
	struct tagListItem* nNext;
	double dist;
	double time;
	int nInfo;  //0-house,1-shop
	int nIndex; //Nb of point
}ListItem;

typedef struct
{
	ListItem* vNext;//nearby list
	double road;
	int vInfo; //0-house,1-shop
	int nVerNumb; //Nb of nearest shop	
	int* Path;
	double allTime;
}Vertex;

double Dijkstra( Vertex* village, int nSize, int nFirst );
void DFS( Vertex* v,int*,int,int );

#endif