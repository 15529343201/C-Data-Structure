//������˳�����ɾ����ֵ�ڸ���ֵs��t֮��(����s��t,Ҫ��s<t)������Ԫ��,���s��t���������˳���Ϊ������ʾ������Ϣ���˳����� 
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

bool Del_s_t(SqList *L,ElemType s,ElemType t){
	//ɾ������˳���L��ֵ�ڸ���ֵs��t֮�������Ԫ��
	int i,k=0;
	if(L->length==0||s>=t)
		return false; //���Ա�Ϊ�ջ�s��t���Ϸ�,����
	for(i=0;i<L->length;i++){
		if(L->data[i]>=s&&L->data[i]<=t)
			k++;
		else
			L->data[i-k]=L->data[i]; //��ǰԪ��ǰ��k��λ�� 
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
	printf("������˳���Ԫ�صĸ���:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		InsertSqList(&l,i+1,m);
	}
	printf("˳����Ԫ����:\n");
	for(i=0;i<l.length;i++)
		printf("%d ",l.data[i]);
	printf("\n");
	printf("�������������ֵs��t(s<t)\n");
	scanf("%d%d",&s,&t);
	Del_s_t(&l,s,t);
	printf("ɾ����˳����Ԫ����:\n");
	for(i=0;i<l.length;i++)
		printf("%d ",l.data[i]);
	return 0; 
} 
/*
������˳���Ԫ�صĸ���:
10
1 2 4 6 9 9 18 20 23 23
˳����Ԫ����:
1 2 4 6 9 9 18 20 23 23
�������������ֵs��t(s<t)
4 20
ɾ����˳����Ԫ����:
1 2 23 23
*/
