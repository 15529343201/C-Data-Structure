/*线性表(a1,a2,a3,...,an)中元素递增有序且按顺序存储于计算机内。要求设计一个算法
完成用最少时间在表中查找数值为x的元素,若找到将其与后继元素位置交换,若找不到将其
插入表中并使表中元素仍递增有序。*/
#include<stdio.h>
typedef int ElemType;

void print(ElemType A[],int n){
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
}

void SearchExchangeInsert(ElemType A[],ElemType x,int n){
	int low=0,high=n-1,mid,t,i;
	while(low<=high){
		mid=(low+high)/2;
		if(A[mid]==x)
			break;
		else if(A[mid]<x)
			low=mid+1;
		else 
			high=mid-1;
	}
	if(A[mid]==x&&mid!=n-1){ //若最后一个元素与x相等,则不存在与其后继交换的操作 
		t=A[mid];
		A[mid]=A[mid+1];
		A[mid+1]=t;
		print(A,n);
	}
	
	if(low>high){ //查找失败,插入数据元素x 
		for(i=n-1;i>high;i--)
			A[i+1]=A[i]; //后移元素
		A[i+1]=x;//插入x 
		print(A,n+1);
	}
}


int main(void){
	ElemType A[]={1,2,4,6,9,18,20,23,27,29};
	int a=sizeof(A)/sizeof(A[0]);
	int x;
	print(A,a);
	printf("\n");
	printf("请输入你要查找的元素:\n");
	scanf("%d",&x);
	SearchExchangeInsert(A,x,a);
	return 0;
}

/*
1 2 4 6 9 18 20 23 27 29
请输入你要查找的元素:
10
1 2 4 6 9 10 18 20 23 27 29

1 2 4 6 9 18 20 23 27 29
请输入你要查找的元素:
23
1 2 4 6 9 18 20 27 23 29
*/
