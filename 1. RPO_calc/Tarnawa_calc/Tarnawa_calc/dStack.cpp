#include "dStack.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void dInitStack(dStackItem** pHead)
{
	*pHead = NULL;
}
void dpush(dStackItem** pHead, double d)
{
	dStackItem* p = (dStackItem*)malloc(sizeof(dStackItem));
	if (!p) {
		cout << "Stack overflow!!\n\n";
		return;
	}
	p->dKey = d;
	p->pNext = *pHead;
	(*pHead) = p;	
}


double dpop(dStackItem** dpHead)
{
	double d = 0;
	if (!dIsEmpty(*dpHead))
	{
		d = dtop(*dpHead);
		ddel(dpHead);
	}
	else
		cout << "** ERROR: Stack underflow \n\n";
	return d;


}


double dtop(dStackItem* pHead)
{
	if (!dIsEmpty(pHead))
		return (pHead)->dKey;

	return 0;
}


void ddel(dStackItem** pHead)
{
	if (!dIsEmpty(*pHead))
	{
		dStackItem* p = *pHead;
		*pHead = p->pNext;
		free(p);
	}

	else
		cout << "** ERROR: Stack underflow \n\n";

}


int dIsEmpty(dStackItem* pHead)
{
	return !pHead;
}
void dFreeStack(dStackItem** pHead)
{
	while (!dIsEmpty(*pHead))
	{
		ddel(pHead);
	}
}
