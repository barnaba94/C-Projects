// List.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include <stdlib.h>
#include <stdio.h>
#include "List.h"
#include "global.h"


ListItem* MakeEmptyList()  //init empty list//only pHead
{
//	ListItem* pHead = NULL;
	ListItem* pHead = ( ListItem* )malloc( sizeof( ListItem ) );
	if( pHead )
	{
		memset( pHead, 0, sizeof( ListItem ) );
		//Elem->m_pInfo = NULL;
		//Elem->m_pNext = NULL;
		//pHead = Elem;
	}
	else printf( "List Overflow!\n" );
	return pHead;
}
//-----------------------------------
void Insert( ListItem* pAfter, LISTINFO* pInfo )
{
	ListItem* InsItem = ( ListItem* )malloc( sizeof( ListItem ) );
    if (!InsItem)
    { printf("ERROR\n");
      return;
    }
	memset( InsItem, 0, sizeof( ListItem ) );
	InsItem -> m_pInfo = pInfo;
	InsItem -> m_pNext = pAfter -> m_pNext;
	pAfter -> m_pNext = InsItem;
}
//-----------------------------------
void InsertFront( ListItem* pList, LISTINFO* pInfo )
{
	Insert( pList, pInfo );
}
/* last version 13.11.2017
//---------------------
ListItem* Find(ListItem* pList, const void* a, ListItem** pPrev, int(_cdecl *comp)( const void* , const void* ))
{
  ListItem* temp = pList;
  while (temp -> m_pNext != NULL)
  {
    if ( comp( temp -> m_pNext -> m_pInfo, a ) == 0) //temp->m_pNext -init from front of list ////correction 13.11
    {
      *pPrev = temp;
      return temp -> m_pNext;
    }
    temp = temp -> m_pNext;
  }
  *pPrev = NULL; // if value cannot find
  return NULL;
}*/
////new correction 14.11// add prev //change temp //cast to void*
ListItem* Find(ListItem* pList, const void* a, ListItem** pPrev, int(_cdecl *comp)(const void*, const void*))
{
  ListItem* prev = pList;
  ListItem* temp = prev->m_pNext;
  
  while (temp != NULL)
  {
    if (comp((void*)(temp->m_pInfo),a) == 0)//correction 14.11
    {
      *pPrev = prev;
      return temp;
    }
    prev = prev->m_pNext;
    temp = temp->m_pNext;
  }
  *pPrev = NULL; // if value cannot find
  return NULL;
}
//-----------------------------------
void SortList(ListItem* pList, int(_cdecl *comp)( const void*, const void* ))// comp from global.h
{
	ListItem* p = pList;
	while (p -> m_pNext) {
		ListItem* pMin = p;
		ListItem* v = p -> m_pNext;
		while (v -> m_pNext)
		{
			if (comp( pMin -> m_pNext -> m_pInfo, v-> m_pNext -> m_pInfo ) == 1)//if p1>p2 ////correction 13.11
				pMin = v;
			v = v -> m_pNext;
		}
		if (pMin != p)
		{
			v = pMin -> m_pNext -> m_pNext;
			pMin -> m_pNext -> m_pNext = p -> m_pNext;
			p -> m_pNext = pMin -> m_pNext;
			pMin -> m_pNext = v;
		}
		p = p -> m_pNext;
	}
}
//-----------------------------------
void Remove(ListItem* pAfter)
{
	//if (pAfter->m_pNext)
    if(!isEmpty( pAfter ))
	{
		ListItem* delItem = pAfter -> m_pNext;
		pAfter -> m_pNext = delItem -> m_pNext;
        free( delItem -> m_pInfo ); //correction 13.11
		free( delItem );
	}
	else printf( "ERROR!\n" );
}
//-----------------------------------
void RemoveFront(ListItem* pList)
{
	Remove( pList );
}
//-----------------------------------
int  isEmpty(ListItem* pList)//boolean
{
	return !( pList -> m_pNext );
}
//-----------------------------------
void FreeList( ListItem* pList )
{
	while ( !isEmpty( pList ) )
		RemoveFront( pList );
}
//-----------------------------------
void DelList( ListItem** pList )
{
    FreeList( *pList );//correction 13.11
    free( *pList );//!!!!
	*pList = NULL;
}
//-----------------------------------
void PrintList( ListItem* pList )
{
	ListItem* temp = pList -> m_pNext;
	if (!isEmpty( pList ))
	{
		do
		{
			printf("%lf\n", temp -> m_pInfo -> nKey);
			temp = temp -> m_pNext;
		} while ( temp != NULL );
	}
	else printf( "Empty List!\n" );
}

