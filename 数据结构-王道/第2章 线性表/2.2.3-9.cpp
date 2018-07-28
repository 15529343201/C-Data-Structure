/*���Ա�(a1,a2,a3,...,an)��Ԫ�ص��������Ұ�˳��洢�ڼ�����ڡ�Ҫ�����һ���㷨
���������ʱ���ڱ��в�����ֵΪx��Ԫ��,���ҵ���������Ԫ��λ�ý���,���Ҳ�������
������в�ʹ����Ԫ���Ե�������*/
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
	if(A[mid]==x&&mid!=n-1){ //�����һ��Ԫ����x���,�򲻴��������̽����Ĳ��� 
		t=A[mid];
		A[mid]=A[mid+1];
		A[mid+1]=t;
		print(A,n);
	}
	
	if(low>high){ //����ʧ��,��������Ԫ��x 
		for(i=n-1;i>high;i--)
			A[i+1]=A[i]; //����Ԫ��
		A[i+1]=x;//����x 
		print(A,n+1);
	}
}


int main(void){
	ElemType A[]={1,2,4,6,9,18,20,23,27,29};
	int a=sizeof(A)/sizeof(A[0]);
	int x;
	print(A,a);
	printf("\n");
	printf("��������Ҫ���ҵ�Ԫ��:\n");
	scanf("%d",&x);
	SearchExchangeInsert(A,x,a);
	return 0;
}

/*
1 2 4 6 9 18 20 23 27 29
��������Ҫ���ҵ�Ԫ��:
10
1 2 4 6 9 10 18 20 23 27 29

1 2 4 6 9 18 20 23 27 29
��������Ҫ���ҵ�Ԫ��:
23
1 2 4 6 9 18 20 27 23 29
*/
