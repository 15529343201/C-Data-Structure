//顺序栈的基本操作
#include<stdio.h>
#include<stdlib.h>
#define Stack_Size 50
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef struct 
{
	ElemType elem[Stack_Size];
	int top;
}SeqStack;

//顺序栈的初始化
void InitStack(SeqStack *S)
{
	S->top = -1;
}

//判栈空
int IsEmpty(SeqStack S)
{
	if(S.top==-1)
	  return TRUE;
	else
	  return FALSE;
}

//判栈满
int IsFull(SeqStack S)
{
	if(S.top==Stack_Size-1)
	  return TRUE;
	else
	  return FALSE;
}

//入栈
int Push(SeqStack *S,ElemType x)
{
	if(S->top==Stack_Size-1)
	  return FALSE;
	S->top++;
	S->elem[S->top]=x;
	return TRUE;
}

//出栈
int Pop(SeqStack *S,ElemType *x)
{
	if(S->top==-1)
	  return FALSE;
	*x=S->elem[S->top];
	S->top--;
	return TRUE;
}

//取栈顶元素
int Poptop(SeqStack *S,ElemType *x)
{
	if(S->top==-1)
	  return FALSE;
	*x=S->elem[S->top];
	return TRUE;
}

//所有元素出栈
int Popall(SeqStack *st,int *x)
{
	if(st->top==-1)
	  return 0;
	else
	 {
		while(st->top!=-1)
		 {
			*x=st->elem[st->top];
			printf("*x");
			st->top--;
		 }
	 }
}

int main()
{
	SeqStack st;
	int i;
	int x;
	int n;
	int c;
    InitStack(&st);
    if(IsFull(st)==1)
	 {
		printf("这个栈已经满了!");
		return FALSE;
	 }
	printf("这个栈是空的，请输入入栈元素个数n(n<Stack_Size):\n");
	scanf("%d",&n);
     for(i=0;i<n;i++)
	 {
		printf("请输入第%d个元素:",i+1);
		scanf("%d",&x);
        Push(&st,x);
	 }
	 if(IsEmpty(st)==1)
	   printf("空栈!");
	 else
	   printf("栈不空!\n");
	 printf("取栈顶元素:\n");
     Poptop(&st,&c);
	 printf("%d\n",c);
	 printf("所有元素出栈:\n");
	 while(!IsEmpty(st))
	  {
		 Pop(&st,&c);
		 printf("%d\n",c);
	  }
	 printf("\n");
	 return 0;
}






