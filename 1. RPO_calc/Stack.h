#pragma once
#ifndef _STACK_H_
#define _STACK_H_

typedef struct tagStackItem
{
	char cKey;
	tagStackItem* pNext;
} StackItem;

typedef StackItem* StackType;
void push(StackItem**, char c); // wklada na stos
char pop(StackItem**); // zdejmuje ze stosu i go zwraca
char top(StackItem*);  // zwraca szczyt (bez usuwania), nie wystepuje modyfikacja wskaznika
void del(StackItem**);  // usuwa szczyt
int IsEmpty(StackItem*); // 1- gdy stos pusty, 0- w przeciwnym wypadku
void InitStack(StackItem** pHead);   //inicjuje stos na wskaznik pusty
void FreeStack(StackItem** pHead);     // czyszczenie stosu
#endif 