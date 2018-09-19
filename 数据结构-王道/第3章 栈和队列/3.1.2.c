//顺序栈的基本操作
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef struct 
{
	ElemType data[MaxSize];
	int top;
}SqStack;

//顺序栈的初始化
void InitStack(SqStack *S)
{
	S->top = -1;
}

//判栈空
int StackEmpty(SqStack S)
{
	if(S.top==-1)
	  return TRUE;
	else
	  return FALSE;
}

//判栈满
int StackFull(SqStack S)
{
	if(S.top==MaxSize-1)
	  return TRUE;
	else
	  return FALSE;
}

//入栈
int Push(SqStack *S,ElemType x)
{
	if(S->top==MaxSize-1)
	  return FALSE;
	S->top++;
	S->data[S->top]=x;
	return TRUE;
}

//出栈
int Pop(SqStack *S,ElemType *x)
{
	if(S->top==-1)
	  return FALSE;
	*x=S->data[S->top];
	S->top--;
	return TRUE;
}

//取栈顶元素
int GetTop(SqStack *S,ElemType *x)
{
	if(S->top==-1)
	  return FALSE;
	*x=S->data[S->top];
	return TRUE;
}

//所有元素出栈
int Popall(SqStack *S,int *x)
{
	if(S->top==-1)
	  return 0;
	else
	 {
		while(S->top!=-1)
		 {
			*x=S->data[S->top];
			printf("*x");
			S->top--;
		 }
	 }
}

int main()
{
	SqStack s;
	int i,x,n,c;
    InitStack(&s);
    if(StackFull(s)==1)
	 {
		printf("这个栈已经满了!");
		return FALSE;
	 }
	printf("这个栈是空的，请输入入栈元素个数n(n<MaxSize):\n");
	scanf("%d",&n);
    for(i=0;i<n;i++)
	{
		printf("请输入第%d个元素:",i+1);
		scanf("%d",&x);
        Push(&s,x);
	 }
	 if(StackEmpty(s)==1)
	   printf("空栈!");
	 else
	   printf("栈不空!\n");
	 printf("取栈顶元素:\n");
     GetTop(&s,&c);
	 printf("%d\n",c);
	 printf("所有元素出栈:\n");
	 while(!StackEmpty(s))
	  {
		 Pop(&s,&c);
		 printf("%d\n",c);
	  }
	 printf("\n");
	 return 0;
}
/*
这个栈是空的，请输入入栈元素个数n(n<MaxSize):
5
请输入第1个元素:1
请输入第2个元素:2
请输入第3个元素:3
请输入第4个元素:4
请输入第5个元素:5
栈不空!
取栈顶元素:
5
所有元素出栈:
5
4
3
2
1
*/




