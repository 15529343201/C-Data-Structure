//已知在一维数组A[m+n]中依次存放着两个线性表(a1,a2,a3,...am)和(b1,b2,b3,...bn).试编写一个函数,将数组中两个顺序表的位置互换,即将(b1,b2,b3,...,bn)放在(a1,a2,a3,...,am)的前面。
#include<stdio.h>
typedef int DataType;
void Reverse(DataType A[],int left,int right,int arraySize){
	//逆转(aleft,aleft+1,aleft+2...,aright)为(aright,aright-1,...,aleft)
	if(left>=right||right>=arraySize)
		return;
	int mid=(left+right)/2;  //left=0,right=12,mid=6
	for(int i=0;i<=mid-left;i++){ //mid-left=6
		DataType temp=A[left+i];
		A[left+i]=A[right-i];
		A[right-i]=temp;
	}
}
/*算法思想: 首先将数组A[m+n]的元素原地逆置,再对前n个元素和后m个元素分别使用逆置算法*/ 
void Exchange(DataType A[],int m,int n,int arraySize){
	/*数组A[m+n]中,从0到m-1存放顺序表(a1,a2,a3,...,am),从m到m+n-1存放顺序表(b1,b2,...,bn),算法将这两个表的位置互换*/
	//1 2 4 6 9 18 20 23 27 29
	//0 1 2 3 4 5  6  7  8  9
	Reverse(A,0,m+n-1,arraySize);//m=6,n=4,m+n-1=9
	Reverse(A,0,n-1,arraySize);
	Reverse(A,n,m+n-1,arraySize); 
} 

int main(void)
{
	int i;
	//A[m+n],m,n代表两个数组的大小 
	DataType A[]={1,2,4,6,9,18,20,23,27,29};
	Exchange(A,6,4,sizeof(A)/sizeof(A[0]));
	for(i=0;i<sizeof(A)/sizeof(A[0]);i++)
		printf("%d ",A[i]);
	return 0;
}   
/*
20 23 27 29 1 2 4 6 9 18
*/ 
