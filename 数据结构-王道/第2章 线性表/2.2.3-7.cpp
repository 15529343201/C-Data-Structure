//将两个有序顺序表合成一个新的有序顺序表,并由函数返回结果顺序表 
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

bool Merge(SqList *A,SqList *B,SqList *C){
	if(A->length+B->length>C->MaxSize)
		return false;
	int i=0,j=0,k=0;
	while(i<A->length&&j<B->length){
		if(A->data[i]<=B->data[j])
			C->data[k++]=A->data[i++];
		else
			C->data[k++]=B->data[j++];
	}
	while(i<A->length)
		C->data[k++]=A->data[i++];
	while(j<B->length)
		C->data[k++]=B->data[j++];
	C->length=k;
	return true;
}

int main(void)
{
	SqList A,B,C;
	int i;
	int m,n,s,t;
	InitSqList(&A);
	InitSqList(&B);
	InitSqList(&C);
	printf("请输入顺序表A元素的个数:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		InsertSqList(&A,i+1,m);
	}
	printf("请输入顺序表B元素的个数:\n");
	scanf("%d",&s);
	for(i=0;i<s;i++){
		scanf("%d",&t);
		InsertSqList(&B,i+1,t);
	}
	printf("顺序表A,B的元素分别是:\n");
	for(i=0;i<A.length;i++)
		printf("%d ",A.data[i]);
	printf("\n");
	for(i=0;i<B.length;i++)
		printf("%d ",B.data[i]);
	printf("\n");
	Merge(&A,&B,&C);
	printf("合并后顺序表的元素是:\n");
	for(i=0;i<C.length;i++)
		printf("%d ",C.data[i]);
	return 0; 
}  
/*
请输入顺序表A元素的个数:
5
1 3 4 6 9
请输入顺序表B元素的个数:
5
0 2 5 10 11
顺序表A,B的元素分别是:
1 3 4 6 9
0 2 5 10 11
合并后顺序表的元素是:
0 1 2 3 4 5 6 9 10 11
*/
