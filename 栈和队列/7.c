//栈应用举例:数制转换(十进制数N转换成其他n进制数。)
#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0

typedef struct node
{
	int data;
	struct node *next;
}StackNode,*SqStack;

typedef struct LNode
{
	SqStack Top;
	SqStack Bottom;
}LNode,*LStack;

LStack InitStack();
void conversion(LStack,int N,int n);
void Push(LStack,int e);
void Pop(LStack,int *e);
int Empty(LStack);

int main()
{
	int N,n;
	LStack pStack=InitStack();
	printf("Please input the number and its radix:");
	scanf("%d%d",&N,&n);
	printf("\n");
	printf("Now the %d radix is:",n);
	conversion(pStack,N,n);
	return 0;
}

LStack InitStack()
{
	SqStack p=(SqStack)malloc(sizeof(StackNode));
	LStack q=(LStack)malloc(sizeof(LNode));
	if(!p||!q)
	 {
		printf("Malloc failed!");
		exit(-1);
	 }
	q->Top=q->Bottom=p;
	p->data=0;
	q->Bottom->next=NULL;
	return q;
}

void conversion(LStack S,int N,int n)
{
	int d;
	while(N)
	 {
		Push(S,N%n);
		N=N/n;
	 }
	while(!Empty(S))
	 {
		Pop(S,&d);
		printf("%d",d);
	 }
	printf("\n");
}

void Push(LStack S,int e)
{
	SqStack p=(SqStack)malloc(sizeof(StackNode));
	if(!p)
	  {
		 printf("Malloc failed!");
		 exit(-1);
	  }
	p->data=e;
	p->next=S->Top;
	S->Top=p;
}

void Pop(LStack S,int *e)
{
	SqStack q,p=S->Top;
	q=p->next;
	*e=p->data;
	free(p);
	S->Top=q;
}

int Empty(LStack S)
{
	if(S->Top->next)
	  return false;
	else
	  return true;
}
