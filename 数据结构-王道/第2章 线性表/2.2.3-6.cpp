//������˳�����ɾ��������ֵ�ظ���Ԫ��,ʹ��������Ԫ�ص�ֵ����ͬ��
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

bool Delete_Same(SqList *L){
	if(L->length==0)
		return false;
	int i,j; //i�洢��һ������ͬ��Ԫ��,j����ָ�� 
	for(i=0,j=1;j<L->length;j++){
		if(L->data[i]!=L->data[j]){ //������һ�����ϸ�Ԫ��ֵ��ͬ��Ԫ�� 
			L->data[++i]=L->data[j]; //�ҵ���,��Ԫ��ǰ�� 
		}
	}
	L->length=i+1;
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
	Delete_Same(&l);
	printf("ɾ���ظ�Ԫ�غ�˳����Ԫ����:\n");
	for(i=0;i<l.length;i++)
		printf("%d ",l.data[i]);
	return 0; 
}  
/*
������˳���Ԫ�صĸ���:
11
1 2 2 2 2 3 3 3 4 4 5
˳����Ԫ����:
1 2 2 2 2 3 3 3 4 4 5
ɾ���ظ�Ԫ�غ�˳����Ԫ����:
1 2 3 4 5
*/ 
