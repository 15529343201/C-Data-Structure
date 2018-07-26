//从有序顺序表中删除所有其值重复的元素,使表中所有元素的值均不同。
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

bool Delete_Same(SqList *L){
	if(L->length==0)
		return false;
	int i,j; //i存储第一个不相同的元素,j工作指针 
	for(i=0,j=1;j<L->length;j++){
		if(L->data[i]!=L->data[j]){ //查找下一个与上个元素值不同的元素 
			L->data[++i]=L->data[j]; //找到后,则将元素前移 
		}
	}
	L->length=i+1;
	return true; 
} 

int main(void)
{
	SqList l;
	int i;
	int m,n,s,t;
	InitSqList(&l);
	printf("请输入顺序表元素的个数:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		InsertSqList(&l,i+1,m);
	}
	printf("顺序表的元素是:\n");
	for(i=0;i<l.length;i++)
		printf("%d ",l.data[i]);
	printf("\n");
	Delete_Same(&l);
	printf("删除重复元素后顺序表的元素是:\n");
	for(i=0;i<l.length;i++)
		printf("%d ",l.data[i]);
	return 0; 
}  
/*
请输入顺序表元素的个数:
11
1 2 2 2 2 3 3 3 4 4 5
顺序表的元素是:
1 2 2 2 2 3 3 3 4 4 5
删除重复元素后顺序表的元素是:
1 2 3 4 5
*/ 
