//��֪��һά����A[m+n]�����δ�����������Ա�(a1,a2,a3,...am)��(b1,b2,b3,...bn).�Ա�дһ������,������������˳����λ�û���,����(b1,b2,b3,...,bn)����(a1,a2,a3,...,am)��ǰ�档
#include<stdio.h>
typedef int DataType;
void Reverse(DataType A[],int left,int right,int arraySize){
	//��ת(aleft,aleft+1,aleft+2...,aright)Ϊ(aright,aright-1,...,aleft)
	if(left>=right||right>=arraySize)
		return;
	int mid=(left+right)/2;  //left=0,right=12,mid=6
	for(int i=0;i<=mid-left;i++){ //mid-left=6
		DataType temp=A[left+i];
		A[left+i]=A[right-i];
		A[right-i]=temp;
	}
}
/*�㷨˼��: ���Ƚ�����A[m+n]��Ԫ��ԭ������,�ٶ�ǰn��Ԫ�غͺ�m��Ԫ�طֱ�ʹ�������㷨*/ 
void Exchange(DataType A[],int m,int n,int arraySize){
	/*����A[m+n]��,��0��m-1���˳���(a1,a2,a3,...,am),��m��m+n-1���˳���(b1,b2,...,bn),�㷨�����������λ�û���*/
	//1 2 4 6 9 18 20 23 27 29
	//0 1 2 3 4 5  6  7  8  9
	Reverse(A,0,m+n-1,arraySize);//m=6,n=4,m+n-1=9
	Reverse(A,0,n-1,arraySize);
	Reverse(A,n,m+n-1,arraySize); 
} 

int main(void)
{
	int i;
	//A[m+n],m,n������������Ĵ�С 
	DataType A[]={1,2,4,6,9,18,20,23,27,29};
	Exchange(A,6,4,sizeof(A)/sizeof(A[0]));
	for(i=0;i<sizeof(A)/sizeof(A[0]);i++)
		printf("%d ",A[i]);
	return 0;
}   
/*
20 23 27 29 1 2 4 6 9 18
*/ 
