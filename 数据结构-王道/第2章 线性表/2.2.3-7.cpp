//����������˳���ϳ�һ���µ�����˳���,���ɺ������ؽ��˳��� 
#include<stdio.h>
#include<stdlib.h>
#define InitSize 50 //���ȵĳ�ʼ���� 
typedef int ElemType;
typedef struct{
	int *data; //ָʾ��̬����������ָ�� 
	int length; //����ĵ�ǰ���� 
	int MaxSize; //������������ 
}SqList;

//��ʼ��һ��˳���
void InitSqList(SqList *L){
	L->data=(int *)malloc(InitSize*sizeof(ElemType));
	if(!L->data)
		exit(0);
	L->length=0;
	L->MaxSize=InitSize;
} 

//��˳����в���Ԫ��
void InsertSqList(SqList *L,int i,ElemType item){
	//��˳���L�е�i��λ���ϲ���Ԫ��item
	ElemType *base,*insertPtr,*p;
	if(i<1||i>L->length+1)
		exit(0);
	if(L->length>=L->MaxSize){
		//reallocָ����=����������*��realloc��Ҫ�ı��ڴ��С��ָ�������µĴ�С����
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
	printf("������˳���AԪ�صĸ���:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		InsertSqList(&A,i+1,m);
	}
	printf("������˳���BԪ�صĸ���:\n");
	scanf("%d",&s);
	for(i=0;i<s;i++){
		scanf("%d",&t);
		InsertSqList(&B,i+1,t);
	}
	printf("˳���A,B��Ԫ�طֱ���:\n");
	for(i=0;i<A.length;i++)
		printf("%d ",A.data[i]);
	printf("\n");
	for(i=0;i<B.length;i++)
		printf("%d ",B.data[i]);
	printf("\n");
	Merge(&A,&B,&C);
	printf("�ϲ���˳����Ԫ����:\n");
	for(i=0;i<C.length;i++)
		printf("%d ",C.data[i]);
	return 0; 
}  
/*
������˳���AԪ�صĸ���:
5
1 3 4 6 9
������˳���BԪ�صĸ���:
5
0 2 5 10 11
˳���A,B��Ԫ�طֱ���:
1 3 4 6 9
0 2 5 10 11
�ϲ���˳����Ԫ����:
0 1 2 3 4 5 6 9 10 11
*/
