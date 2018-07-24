//��˳�����ɾ��������Сֵ��Ԫ��(����Ψһ)���ɺ������ر�ɾԪ�ص�ֵ���ճ���λ�������һ��Ԫ���,��˳���Ϊ������ʾ������Ϣ���˳����С� 
#include<stdio.h>
#define MaxSize 50
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int length;
}SqList;

//��ʼ��˳���
void InitSqList(SqList *L){
	L->length=0;
} 

//˳���Ĳ���
bool InsertSqList(SqList *L,int i,ElemType e){
	int j; 
	if(i<1||i>L->length+1){  //�ж�iλ���Ƿ���Ч 
		return false;
	}
	if(L->length>=MaxSize){  //��ǰ�洢�ռ�����,���ܲ��� 
		return false;
	}
	for(j=L->length;j>=i;j--) //����i��Ԫ�ؼ�֮���Ԫ�غ���
		L->data[j]=L->data[j-1];
	L->data[i-1]=e;
	L->length++;
	return true; 
}
int Del_Min(SqList *L){
	int value;
	if(L->length==0)
		return false;
	value=L->data[0];
	int pos=0;
	int i;
	for(i=1;i<L->length;i++){
		if(L->data[i]<value){
			value=L->data[i];
			pos=i;
		}
	}
	L->data[pos]=L->data[L->length-1];
	L->length--;
	return value;
}
int main(void){
	SqList L;
	int i;
	int M;
	InitSqList(&L);
	for(i=0;i<15;i++){
		InsertSqList(&L,i+1,i+1); 
	}
	printf("\n˳����Ԫ����:\n");
	for(i=0;i<L.length;i++){
		printf("%d ",L.data[i]);
	}
	printf("\n");
	printf("ɾ������С��Ԫ����:");
	M=Del_Min(&L);
	printf("%d\n",M);
	printf("ʣ���Ԫ����:\n");
	for(i=0;i<L.length;i++){
		printf("%d ",L.data[i]);
	}
	return 0;
}

/*
˳����Ԫ����:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
ɾ������С��Ԫ����:1
ʣ���Ԫ����:
15 2 3 4 5 6 7 8 9 10 11 12 13 14
*/
