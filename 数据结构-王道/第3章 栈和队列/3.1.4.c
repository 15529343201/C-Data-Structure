#include <stdio.h>
#include <stdlib.h>
#define MaxSize 60 
#define OK      1      
#define ERROR   0      
#define TRUE    1      
#define FALSE   0    
typedef int ElemType;  
typedef int Status;  
typedef struct {  
    ElemType data[MaxSize];  
    int top1;                    
    int top2;					
}Stack,*SqStack;  

Status InitStack(SqStack s)
{
	s->top1 = -1;
	s->top2 = MaxSize;
	return OK; 
}

Status Push(SqStack s,ElemType e,int stackNumber)
{
	if (s->top1+1 == s->top2)
		return ERROR;
	switch(stackNumber)
	{
		case 1:		
			s->data[++s->top1] = e;		
			break;
		case 2:		
			s->data[--s->top2] = e;		
			break;
	}
	return OK;
}

Status Pop(SqStack s,ElemType *e,int stackNumber)
{
	if (stackNumber==1)
	{	
		if (s->top1==-1)		
			return ERROR;
		*e = s->data[s->top1--];
	}
	else if (stackNumber==2)
	{
		if (s->top2==MaxSize)
			return ERROR;
		*e = s->data[s->top2++];
	}
	return OK;
}


Status TraverseStack(SqStack s, int stackNumber)
{
	int i;
	if (stackNumber==1)
	{
		if (s->top1==-1)
			return ERROR;
		printf("栈1中的元素为:\n");
		for (i=0;i<=s->top1;++i)
			printf("%d ",s->data[i]);
		printf("\n==================================\n");
	}
	else if(stackNumber==2)
	{
		if (MaxSize == s->top2)
			return ERROR;
		printf("栈2中的元素为:\n");
		for (i=MaxSize-1;i>=s->top2;--i)	
			printf("%d ",s->data[i]);
		printf("\n==================================\n");
	}
}

int main()
{
	printf("======共享栈===========\n\n");
	Stack s;
	ElemType e;
	InitStack(&s);
	Push(&s, 1, 1);
	Push(&s, 2, 1);
	Push(&s, 3, 1);
	Push(&s, 4, 1);
	Push(&s, 5, 1);
	Push(&s, 6, 1);
	Pop(&s, &e, 1);
	Push(&s, 10, 2);
	Push(&s, 9, 2);
	Push(&s, 8, 2);
	Push(&s, 7, 2);
	TraverseStack(&s, 1);
	TraverseStack(&s, 2);
	return 0;
}
/*
======共享栈===========

栈1中的元素为:
1 2 3 4 5 
==================================
栈2中的元素为:
10 9 8 7 
==================================
*/


