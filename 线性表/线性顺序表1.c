//顺序表的基本操作
#include<stdio.h>
#define MaxSize 100
typedef int DataType;
typedef struct 
{
	DataType list[MaxSize];
	int size;
}SeqList;

//初始化顺序表L
void InitList(SeqList *L)
{
	L->size=0;
}

//当前数据元素个数
int ListLength(SeqList L)
{
	return L.size;
}

//插入元素
int ListInsert(SeqList *L,int i,DataType x)
{
	int j;
	if(L->size>=MaxSize)
	 {
		printf("顺序表已满无法插入!\n");
		return 0;
	 }
	else if(i<0||i>L->size)
	 {
		printf("位置错误,无法插入!\n");
		return 0;
	 }
	else
	 {
		for(j=L->size;j>i-1;j--)
		  L->list[j]=L->list[j-1];
		L->list[i-1]=x;
		L->size++;
		return 0;
	 }
}

//删除数据元素
int ListDelete(SeqList *L,int i)
{
	int j;
	if(L->size<=0)
	 {
		printf("顺序表已无数据可删!\n");
		return 0;
	 }
	else if(i<0||i>L->size-1)
	 {
		printf("删除位置错误!\n");
		return 0;
	 }
	else
	 {
		for(j=i;j<=L->size-1;j++)
		 L->list[j-1]=L->list[j];
		L->size--;
		return 0;
	 }
}

//查找数据元素
int ListSearch(SeqList L,DataType x)
{
	int i;
	for(i=0;i<L.size;i++)
	 {
		if(L.list[i]==x)
		 {
			printf("找到,%d在第%d个位置",x,i+1);
			return 0;
		 }
	 }
	printf("没有找到%d",x);
	return 0;
}

//逆置
int ListReverse(SeqList *L)
{
	int i,m=L->size/2,n=L->size;
	DataType temp;
	for(i=0;i<m;i++)
	 {
		temp=L->list[i];
		L->list[i]=L->list[n-i-1];
		L->list[n-1-i]=temp;
	 }
}

//合并
int ListMerger(SeqList *La,SeqList *Lb,SeqList *Lc)
{
	int i=0,j=0,k=0;
	while(i<La->size&&j<Lb->size)
	 {
		if(La->list[i]<Lb->list[j])
		 {
			Lc->list[k]=La->list[i];
			i++;
			k++;
		 }
		else
		 {
			Lc->list[k]=Lb->list[j];
			j++;
			k++;
		 }
	 }
    while(i<La->size)
     {
		Lc->list[k++]=La->list[i++];
	 }
	while(j<Lb->size)
	{
		Lc->list[k++]=Lb->list[j++];
	}
	Lc->size=k;
	return 0;
}

int main()
{
	SeqList La,Lb,Lc;
	int i,x;
	int n,m;//线性表长度

    InitList(&La);
	printf("请输入线性表La的长度:");
	scanf("%d",&n);
	La.size=n;
	printf("请输入线性表La中的元素:");
	for(i=0;i<n;i++)
	 {
		scanf("%d",&La.list[i]);
     }

	printf("请输入要插入到线性表La中的数字x和插入的位置i:");
	scanf("%d%d",&x,&i);
	ListInsert(&La,i,x);
	printf("线性表La=");
	for(i=0;i<La.size;i++)
	 {
		printf("%d ",La.list[i]);
	 }

	printf("\n请输入要删除的数字的位置:");
	scanf("%d",&i);
	ListDelete(&La,i);
	printf("线性表La=");
	for(i=0;i<La.size;i++)
	 {
		printf("%d ",La.list[i]);
	 }

	printf("\n请输入要查找的数字:");
	scanf("%d",&x);
    ListSearch(La,x);
    ListReverse(&La);
    printf("\n逆置后的线性表La=");
    for(i=0; i<La.size; i++)
        printf("%d ",La.list[i]);

    InitList(&Lb);
    printf("\n请输入线性表Lb的长度:");
    scanf ("%d",&m);
    Lb.size=m;
    printf("请输入线性表Lb中的元素:");
    for(i=0; i<m; i++)
        scanf ("%d",&Lb.list[i]);
    InitList(&Lc);

    ListMerger(&La,&Lb,&Lc);
    printf("\n合并后La和Lb后的线性表:");
    for(i=0; i<Lc.size; i++)
        printf ("%d ",Lc.list[i]);
    return 0;
}
