#ifndef _GLOBAL_INCLUDE_FILE
#define _GLOBAL_INCLUDE_FILE

#include "stdafx.h"
#include <stdio.h>//!!!!!!!!!!!!!
#include <stdlib.h>
#include "global.h"

typedef struct tagListItem { //struct of singly linked list
	LISTINFO*    m_pInfo;
	tagListItem* m_pNext;
} ListItem;

ListItem* MakeEmptyList();
ListItem* Find( ListItem* pList,const void*, ListItem** pPrev, int(_cdecl *comp )( const void*, const void* ));
void Insert( ListItem* pAfter, LISTINFO* pInfo);
void InsertFront( ListItem* pList, LISTINFO* pInfo);
void Remove( ListItem* pAfter);
void RemoveFront( ListItem* pList);
int  isEmpty( ListItem* pList);
void FreeList( ListItem* pList);
void DelList( ListItem** pList);
void PrintList( ListItem* pList);
void SortList( ListItem* pList, int(_cdecl *comp)( const void*, const void* ));
#endif
//----------------------------------------------------------------------------
//convert from C to C++
//selection sort, 3 pointers