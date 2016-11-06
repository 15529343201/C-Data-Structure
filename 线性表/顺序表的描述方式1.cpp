//顺序表的基本操作
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
#define ERROR 0
#define TRUE 1
#define OVERFLOW 0
typedef int ElemType;
typedef struct
{
   ElemType elem[MAXSIZE];
   int length;
}SeqList;

SeqList *L;

//顺序表的初始化
void init_SeqList(SeqList *L)
{
    L->length=0;
}

//顺序表的查找,按内容查找
int Locate(SeqList *L,ElemType x)
{
	int i=1;
	while(i <= L->length && L->elem[i]!=x)
	  i++;
	if(i<=L->length)
	 {
		return i;
	 }
	else
	 {
		return 0;
	 }
}

//顺序表的插入
int Insert_SeqList(SeqList *L,int i,ElemType x)
{
	int j;
	if(L->length = MAXSIZE-1)
	 {
		printf("表满");
		return OVERFLOW;
	 }
	if(i<1 || i>L->length+1)
	 {
		printf("位置错");
		return ERROR;
	 }
	for(j=L->length;j>=i;j--)
	 {
		L->elem[j+1]=L->elem[j];
	 }
	L->elem[i]=x;
	L->length++;
	return TRUE;
}

//顺序表的删除
int Delete_SeqList(SeqList *L,int i)
{
	int j;
	SeqList *e;
	if(i<1 || i>L->length);
	 {
		printf("不存在第i个元素");
		return ERROR;
	 }
	*e=L->elem[i];
	for(j=1;j<=L->length-1;j++)
	 {
		L->elem[j]=L->elem[j+1];
	 }
}

//遍历顺序表
void TraverSeqList(SeqList *L)
{
	int i;
	for(i=0;i<L->length;i++)
	 {
		printf("%d ",L->elem[i]);
	 }
	printf("\n");
	return;
}

//顺序表的逆置
void ListReverse(SeqList L)
{
	int j;
	ElemType t;
	for(i=1;i<=L.length/2;i++)
	 {
		t=L.elem[i];
		L.elem[i]=L.elem[L.lenght-i+1];
		L.elem[L.length-i+1]=t;
	 }
}

//顺序表的归并
void merge(SeqList *LA,SeqList *LB,SeqList *LC)
{
	i=1;
	j=1;
	k=1;
	while(i<=LA->length && j<=LB->length)//当LA和LB均有元素
	 {
		if(LA->elem[i]<=LB->elem[j])
		 {
			LC->elem[k]=LA->elem[i];
			i++;
			k++;
		 }
		else
		 {
			LC->elem[k]=LB->elem[j];
			j++;
			k++;
		 }
	 }
	while(i<=LA->length)//当LA有剩余元素
	 {
		LC->elem[k]=LA->elem[i];
		i++;
		k++;
	 }
	while(j<=LB->length)//当LB有剩余元素
	 {
		LC->elem[k]=LB->elem[j];
		j++;
		k++;
	 }
	LC->length=LA->length+LB->length;//修改表长
}

