//������˳�����ɾ����ֵ�ڸ���ֵs��t֮��(Ҫ��s<t)������Ԫ��,���s��t���������˳���Ϊ������ʾ������Ϣ���˳����� 
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

bool Del_s_t2(SqList *L,ElemType s,ElemType t){
	//ɾ������˳���L��ֵ�ڸ���ֵs��t֮�������Ԫ��
	int i,j;
	if(s>=t||L->length==0)
		return false;
	//1 2 4 6 9 9 18 20 23 23
	for(i=0;i<L->length&&L->data[i]<=s;i++); //Ѱ��ֵ>s�ĵ�һ��Ԫ��
	if(i>=L->length)
		return false; //����Ԫ��ֵ��С��s,�򷵻�
	for(j=i;j<L->length&&L->data[j]<t;j++); //Ѱ��ֵ>t�ĵ�һ��Ԫ��
	for(;j<L->length;i++,j++)
		L->data[i]=L->data[j];
	L->length=i;
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
	Del_s_t2(&l,s,t);
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
1 2 4 20 23 23

������˳���Ԫ�صĸ���:
10
1 2 4 6 9 9 18 20 23 23
˳����Ԫ����:
1 2 4 6 9 9 18 20 23 23
�������������ֵs��t(s<t)
3 21
ɾ����˳����Ԫ����:
1 2 23 23

������˳���Ԫ�صĸ���:
10
1 2 4 6 9 9 18 20 23 23
˳����Ԫ����:
1 2 4 6 9 9 18 20 23 23
�������������ֵs��t(s<t)
2 9
ɾ����˳����Ԫ����:
1 2 9 9 18 20 23 23
*/
