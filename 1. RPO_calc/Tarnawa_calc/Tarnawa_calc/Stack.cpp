#include "Stack.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void InitStack(StackItem** pHead)
{

	*pHead = NULL;
}


void push(StackItem** pHead, char c)
{
	StackItem* p = (StackItem*)malloc(sizeof(StackItem));
	if (p) {

		p->cKey = c;
		p->pNext = *pHead;
		(*pHead) = p;
	}
	else {
		cout << "Stack overflow!!\n\n";
	}

}
//....................................

char pop(StackItem** pHead)
{
	char c;
	if (c = top(*pHead))
		del(pHead);
	else
		cout << "** ERROR: Stack underflow \n\n";
	return c;

}
//....................................

char top(StackItem* pHead)
{
	if (!IsEmpty(pHead))
		return (pHead)->cKey;

	return 0;
}
//....................................

void del(StackItem** pHead)
{
	if (!IsEmpty(*pHead))
	{
		StackItem* p = *pHead;
		*pHead = p->pNext;
		free(p); 
	}

	else
		cout << "** ERROR: Stack underflow \n\n";

}
//....................................

int IsEmpty(StackItem* pHead)
{
	return !pHead;
}
//....................................
void FreeStack(StackItem** pHead)
{
	while (!IsEmpty(*pHead))
		del(pHead);
}