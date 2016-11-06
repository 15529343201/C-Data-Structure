//多栈的基本操作
#include<stdio.h>
#include<stdlib.h>
#define M 10
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node *next;
}LinkStackNode,*LinkStack;
LinkStack top[M];

//多栈的初始化
void Init_LinkList(LinkStack top[M])
{
	LinkStackNode *temp;
	int i;
	for(i=0;i<M;i++)
	 {
		temp=(LinkStack)malloc(sizeof(LinkStackNode));
		temp->next=NULL;
		top[i]=temp;
	 }
}

//入栈
/*将元素x进入第i号链栈*/
int Push(LinkStack top[M],int i,ElemType x)
{
	LinkStackNode *temp;
	temp=(LinkStack)malloc(sizeof(LinkStackNode));
	if(temp==NULL)
	  return FALSE;
    temp->data=x;
	temp->next=top[i]->next;
	top[i]->next=temp;
	return TRUE;
}

//出栈
/*将第i号栈栈顶元素弹出，放到x中*/
int Pop(LinkStack top[M],int i,ElemType *x)
{
	LinkStackNode *temp;
	temp=top[i]->next;
	if(temp==NULL)
	  return FALSE;
	top[i]->next=temp->next;
	*x=temp->data;
	free(temp);
	return TRUE;
}
