//���һ����Ч���㷨,��˳��������Ԫ������,Ҫ���㷨�Ŀռ临�Ӷ�ΪO(1) 
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

//��˳�����ɾ��Ԫ��
void DeleteSqList(SqList *L,int i){
	//��˳���L��ɾ����i��Ԫ��
	ElemType *delItem,*q;
	if(i<1||i>L->length)
		exit(0);
	delItem=&(L->data[i-1]);
	q=L->data+L->length-1;
	for(++delItem;delItem<=q;++delItem){
		*(delItem-1)=*delItem;
		L->length--;
	}
} 

//˳�������
void Reverse(SqList *L){
	int i;
	ElemType temp; //��������
	for(i=0;i<L->length/2;i++){
		temp=L->data[i];
		L->data[i]=L->data[L->length-i-1];
		L->data[L->length-i-1]=temp;
	} 
	
} 

int main(void)
{
	SqList l;
	int i;
	InitSqList(&l);
	for(i=0;i<15;i++)
		InsertSqList(&l,i+1,i+1);
	printf("˳����Ԫ����:\n");
	for(i=0;i<l.length;i++)
		printf("%d ",l.data[i]);
	printf("\n");
	Reverse(&l);
	printf("���ú��˳�����:\n");
	for(i=0;i<l.length;i++)
		printf("%d ",l.data[i]);
	return 0;
}
/*
˳����Ԫ����:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
���ú��˳�����:
15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
*/


 
