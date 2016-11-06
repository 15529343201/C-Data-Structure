//双端栈的基本操作
#include<stdio.h>
#include<stdlib.h>
#define M 100
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef struct
{
	ElemType Stack[M];
	int top[2];
}DqStack;

//双端栈的初始化
void InitStack(DqStack *S)
{
	S->top[0]=-1;
	S->top[1]=M;
}

//入栈
int Push(DqStack *S,ElemType x,int i)
{
	if(S->top[0]+1 == top[1])
	  return FALSE;
    switch(i)
	 {
		case 0:
		  S->top[0]++;
		  S->Stack[S->top[0]]=x;
		  break;
		case 1:
		  S->top[1]--;
		  S->Stack[S->top[1]]=x;
		  break;
		default:
		  return FALSE;
	 }
	return TRUE;
}

//出栈
int Pop(DqStack *S,ElemType *x,int i)
{
	switch(i)
	 {
		case 0:
		  if(S->top[0]==-1)
			return FALSE;
		  *x=S->Stack[S->top[0]];
		  S->top[0]--;
		  break;
		case 1:
		  if(S->top[1]==M)
			return FALSE;
          *x=S->Stack[S->top[1]];
		  S->top[1]++;
		  break;
		default:
		  return FALSE;
	 }
	return TRUE;
}

