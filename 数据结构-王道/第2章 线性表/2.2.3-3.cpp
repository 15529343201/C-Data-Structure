//����Ϊn��˳���L,��дһ��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)���㷨,���㷨ɾ�����Ա�������ֵΪx������Ԫ�� 
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

//�ⷨһ:��k��¼˳���L�в�����x��Ԫ�ظ���(����Ҫ�����Ԫ�ظ���),��ɨ��L��ͳ��k,����������x��Ԫ����ǰ����kλ����,����޸�L�ĳ��� 
void del_x_1(SqList *L,ElemType x){
	int k=0;  //��¼ֵ������x��Ԫ�ظ���
	int i;
	for(i=0;i<L->length;i++){
		if(L->data[i]!=x){
			L->data[k]=L->data[i];
			k++;
		}
	} 
	L->length=k;
}

//�ⷨ��:��k��¼˳���L�е���x��Ԫ�ظ���,��ɨ��L��ͳ��k,����������x��Ԫ��ǰ��k��λ��,����޸�L�ĳ��� 
void del_x_2(SqList *L,ElemType x){
	int k=0,i=0;
	while(i<L->length){
		if(L->data[i]==x)
			k++;
		else
			L->data[i-k]=L->data[i];
		i++;
	}
	L->length=L->length-k;
} 

int main(void)
{
	SqList l;
	int i;
	int m,n,x;
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
	printf("��������Ҫɾ����Ԫ��:");
	scanf("%d",&x);
	printf("ɾ������ֵΪx������Ԫ��:\n");
	//del_x_1(&l,x);
	del_x_2(&l,x);
	for(i=0;i<l.length;i++)
		printf("%d ",l.data[i]);
	return 0;
}
/*
������˳���Ԫ�صĸ���:
5
1 2 2 2 3
˳����Ԫ����:
1 2 2 2 3
��������Ҫɾ����Ԫ��:2
ɾ������ֵΪx������Ԫ��:
1 3
*/ 
