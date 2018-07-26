//从有序顺序表中删除其值在给定值s与t之间(包含s和t,要求s<t)的所有元素,如果s或t不合理或者顺序表为空则显示出错信息并退出运行 
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

bool Del_s_t(SqList *L,ElemType s,ElemType t){
	//删除有序顺序表L中值在给定值s和t之间的所有元素
	int i,k=0;
	if(L->length==0||s>=t)
		return false; //线性表为空或s、t不合法,返回
	for(i=0;i<L->length;i++){
		if(L->data[i]>=s&&L->data[i]<=t)
			k++;
		else
			L->data[i-k]=L->data[i]; //当前元素前移k个位置 
	}
	L->length-=k;
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
	printf("请输入给定区间值s和t(s<t)\n");
	scanf("%d%d",&s,&t);
	Del_s_t(&l,s,t);
	printf("删除后顺序表的元素是:\n");
	for(i=0;i<l.length;i++)
		printf("%d ",l.data[i]);
	return 0; 
} 
/*
请输入顺序表元素的个数:
10
1 2 4 6 9 9 18 20 23 23
顺序表的元素是:
1 2 4 6 9 9 18 20 23 23
请输入给定区间值s和t(s<t)
4 20
删除后顺序表的元素是:
1 2 23 23
*/
