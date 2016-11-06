//链栈的基本操作
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node *next;
}LinkStackNode,*LinkStack;

//链栈的初始化
LinkStack InitLinkStack()
{
	LinkStackNode *L;
	L=(LinkStack)malloc(sizeof(LinkStackNode));

//入栈
int Push(LinkStack top,ElemType x)
{
	LinkStackNode *temp;
	temp=(LinkStack)malloc(sizeof(LinkStackNode));
	if(temp==NULL)
	  return FALSE;
	temp->data=x;
	temp->next=top->next;
	top->next=temp;
	return TRUE;
}

//出栈
int Pop(LinkStack top,ElemType *x)
{
	LinkStackNode *temp;
	temp=top->next;
	if(temp==NULL)
	  return FALSE;
	top->next=temp->next;
	*x=temp->data;
	free(temp);
	return TRUE;
}
