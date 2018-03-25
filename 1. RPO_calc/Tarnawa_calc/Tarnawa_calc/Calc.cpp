
#include <stdlib.h>
#include "Stack.h"
#include "dStack.h"
#include <math.h>
#include <iostream>
using namespace std;


double GetNum();
double Eval(double farg1, double farg2, char c);
char GetOper();
int IsDotorDigit(char c);
void SkipSpaces();
int IsDigit(char c);
int IsOper(char c);
int prior(char c);
double ONP();

int main(int argc, char* argv[])
{
	printf("Podaj wyrazenie z nawiasami: ");
	cout << ONP();
	getchar();
	return 0;
}

double GetNum()   //get numbers for RPN
{
	char c;
	double res = 0;
	SkipSpaces();
	while (IsDigit(c = getchar()))
		res = res * 10 + (c - '0');
	if (c == '.') 
	{
		double tmp = 0.1;
		while (IsDigit(c = getchar()))
		{
			res += (c - '0')*tmp;
			tmp *= 0.1;
		}
	}
	ungetc(c, stdin);
	return res;
}

void SkipSpaces() //if input is space
{
	char c;
	while ((c = getchar()) == ' ');
	ungetc(c, stdin);
}

int IsDigit(char c)
{
	return (c >= '0') && (c <= '9');
}
int IsDotorDigit(char c)
{
	return ((c == '.') || (c >= '0') && (c <= '9'));
}

char GetOper() //get operators for RPN
{
	SkipSpaces();
	return getchar();
}

int IsOper(char c)
{
	switch (c)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '(':
	case ')': return 1;
	default: return 0;
	}
}

int prior(char c)
{
	switch (c) {
	case '+':
	case '-': return 1;
	case '*':
	case '/': return 2;
	case '^': return 3;
	default: return 0;
	}
	return 0;
}
double ONP()
{
	StackItem* pCS = NULL; //pionter to the stack of chars
	dStackItem* pDS = NULL; //pointer to the stack of digits
	char c;
	while ((IsOper(c = GetOper()) || (IsDotorDigit(c)))) //while input is operator or dot or number
	{
		if (IsOper(c))
		{
			if (c == '(')
				push(&pCS, c);
			else if (c == ')') 
			{
				while ((c = pop(&pCS)) != '(') 
				{
					double temp = dpop(&pDS);
					dpush(&pDS, Eval(dpop(&pDS), temp, c));
				}
			}
			else 
			{
				while (prior(c) <= prior(top(pCS)))
				{
					double temp = dpop(&pDS);
					dpush(&pDS, Eval(dpop(&pDS), temp, pop(&pCS)));
				}
				push(&pCS, c);
			}
		}

		else if (IsDigit(c) || c == '.')
		{
			ungetc(c, stdin);
			dpush(&pDS, GetNum());
		}
	}

	while (!(IsEmpty(pCS)))
	{
		double tmp = dpop(&pDS);
		dpush(&pDS, Eval(dpop(&pDS), tmp, pop(&pCS)));
	}
	return dpop(&pDS);
}
//------------------------------------------------
double Eval(double farg1, double farg2, char c)
{
	switch (c) {
	case '+': return farg1 + farg2;
	case '-': return farg1 - farg2;
	case '*': return farg1 * farg2;
	case '/':									
		if (fabs(farg2) < 1e-10)//divide by zero
		{
			cout << "error";
			return 0;
		}
		else return farg1 / farg2;
	case '^': return pow(farg1, farg2);//math.h

	}
	return 0;
}