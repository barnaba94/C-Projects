#ifndef _DSTACK_H_
#define _DSTACK_H_

typedef struct tagdStackItem
{
	double dKey;
	tagdStackItem* pNext;
} dStackItem;

void dpush(dStackItem**, double d); // wklada na stos
double dpop(dStackItem**); // zdejmuje ze stosu i go zwraca
double dtop(dStackItem*);  // zwraca szczyt (bez usuwania), nie wystepuje modyfikacja wskaznika
void ddel(dStackItem**); // usuwa szczyt
int dIsEmpty(dStackItem*); // 1- gdy stos pusty, 0- w przeciwnym wypadku
void dInitStack(dStackItem** pHead);
void dFreeStack(dStackItem** pHead);
#endif 
