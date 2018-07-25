//长度为n的顺序表L,编写一个时间复杂度为O(n),空间复杂度为O(1)的算法,该算法删除线性表中所有值为x的数据元素 
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

//解法一:用k记录顺序表L中不等于x的元素个数(即需要保存的元素个数),边扫描L边统计k,并将不等于x的元素向前放置k位置上,最后修改L的长度 
void del_x_1(SqList *L,ElemType x){
	int k=0;  //记录值不等于x的元素个数
	int i;
	for(i=0;i<L->length;i++){
		if(L->data[i]!=x){
			L->data[k]=L->data[i];
			k++;
		}
	} 
	L->length=k;
}

//解法二:用k记录顺序表L中等于x的元素个数,边扫描L边统计k,并将不等于x的元素前移k个位置,最后修改L的长度 
void del_x_2(SqList *L,ElemType x){
	int k=0,i=0;
	while(i<L->length){
		if(L->data[i]==x)
			k++;
		else
			L->data[i-k]=L->data[i];
		i++;
	}
	L->length=L->length-k;
} 

int main(void)
{
	SqList l;
	int i;
	int m,n,x;
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
	printf("请输入你要删除的元素:");
	scanf("%d",&x);
	printf("删除所有值为x的线性元素:\n");
	//del_x_1(&l,x);
	del_x_2(&l,x);
	for(i=0;i<l.length;i++)
		printf("%d ",l.data[i]);
	return 0;
}
/*
请输入顺序表元素的个数:
5
1 2 2 2 3
顺序表的元素是:
1 2 2 2 3
请输入你要删除的元素:2
删除所有值为x的线性元素:
1 3
*/ 
