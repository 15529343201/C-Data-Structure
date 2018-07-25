//设计一个高效的算法,将顺序表的所有元素逆置,要求算法的空间复杂度为O(1) 
#include<stdio.h>
#include<stdlib.h>
#define InitSize 50 //表长度的初始定义 
typedef int ElemType;
typedef struct{
	int *data; //指示动态分配的数组的指针 
	int length; //数组的当前个数 
	int MaxSize; //数组的最大容量 
}SqList;

//初始化一个顺序表
void InitSqList(SqList *L){
	L->data=(int *)malloc(InitSize*sizeof(ElemType));
	if(!L->data)
		exit(0);
	L->length=0;
	L->MaxSize=InitSize;
} 

//向顺序表中插入元素
void InsertSqList(SqList *L,int i,ElemType item){
	//向顺序表L中第i个位置上插入元素item
	ElemType *base,*insertPtr,*p;
	if(i<1||i>L->length+1)
		exit(0);
	if(L->length>=L->MaxSize){
		//realloc指针名=（数据类型*）realloc（要改变内存大小的指针名，新的大小）。
		base=(ElemType*)realloc(L->data,(L->MaxSize+10)*sizeof(ElemType));
		L->data=base;
		L->MaxSize=L->MaxSize+10;
	}
	insertPtr=&(L->data[i-1]);
	for(p=&(L->data[L->length-1]);p>=insertPtr;p--)
		*(p+1)=*p;
	*insertPtr=item;
	L->length++; 
}

//从顺序表中删除元素
void DeleteSqList(SqList *L,int i){
	//从顺序表L中删除第i个元素
	ElemType *delItem,*q;
	if(i<1||i>L->length)
		exit(0);
	delItem=&(L->data[i-1]);
	q=L->data+L->length-1;
	for(++delItem;delItem<=q;++delItem){
		*(delItem-1)=*delItem;
		L->length--;
	}
} 

//顺序表逆置
void Reverse(SqList *L){
	int i;
	ElemType temp; //辅助变量
	for(i=0;i<L->length/2;i++){
		temp=L->data[i];
		L->data[i]=L->data[L->length-i-1];
		L->data[L->length-i-1]=temp;
	} 
	
} 

int main(void)
{
	SqList l;
	int i;
	InitSqList(&l);
	for(i=0;i<15;i++)
		InsertSqList(&l,i+1,i+1);
	printf("顺序表的元素是:\n");
	for(i=0;i<l.length;i++)
		printf("%d ",l.data[i]);
	printf("\n");
	Reverse(&l);
	printf("逆置后的顺序表是:\n");
	for(i=0;i<l.length;i++)
		printf("%d ",l.data[i]);
	return 0;
}
/*
顺序表的元素是:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
逆置后的顺序表是:
15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
*/


 
