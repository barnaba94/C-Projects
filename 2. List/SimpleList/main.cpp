#include <stdlib.h>
#include <stdio.h>
#include "List.h"
#include "global.h"

#define TEST
int comp( const void* , const void* );

int main(int argc, char* argv[])
{
	//init
	ListItem* Ltest = MakeEmptyList();
	#ifdef TEST
	//insert elements
	ListInfo* mKey = ( ListInfo* )malloc( sizeof( ListInfo ));
	mKey -> nKey = 14;
	InsertFront(Ltest, mKey);
	ListInfo* mKey1 = ( ListInfo* )malloc( sizeof( ListInfo ));
	mKey1 -> nKey = 56.1;
	InsertFront( Ltest, mKey1 );
	ListInfo* mKey2 = ( ListInfo* )malloc( sizeof( ListInfo));
	mKey2 -> nKey =79.6;
	InsertFront( Ltest, mKey2 );
	ListInfo* mKey3 = ( ListInfo* )malloc(sizeof( ListInfo ));
	mKey3 -> nKey = 59.1;
	InsertFront( Ltest, mKey3 );
	ListInfo* mKey4 = ( ListInfo* )malloc( sizeof( ListInfo ));
	mKey4->nKey = 70.1;
	InsertFront( Ltest, mKey4 );
	ListInfo* mKey5 = ( ListInfo* )malloc( sizeof( ListInfo ));
	mKey5 -> nKey = 12.9;
	Insert( Ltest -> m_pNext -> m_pNext, mKey5 );
    ListInfo* mKey6 =  ( ListInfo* )malloc( sizeof( ListInfo ));
    mKey6->nKey = 69.1;
    InsertFront( Ltest, mKey6);
	RemoveFront( Ltest );
	SortList( Ltest, comp );
	ListItem* prev = NULL;
	Find( Ltest, Ltest -> m_pNext-> m_pNext -> m_pInfo, &prev, comp);
	Remove( prev );
    PrintList( Ltest );
    FreeList( Ltest );
	getchar();
	return 0;
#endif
}

int comp ( const void *p1, const void *p2 ) //comparison function p1>p2 = 1, p1==p2 = 0, p1<p2 =-1
{
  if (((LISTINFO*) p1 ) -> nKey < ((LISTINFO*) p2 ) -> nKey) //cast to LISTINFO*
    return -1;
  if (((LISTINFO*) p1 ) -> nKey > ((LISTINFO*) p2 ) -> nKey)
    return 1;
  return 0; //correction 13.11
}
