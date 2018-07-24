//从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。空出的位置由最后一个元素填补,若顺序表为空则显示出错信息并退出运行。 
#include<stdio.h>
#define MaxSize 50
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int length;
}SqList;

//初始化顺序表
void InitSqList(SqList *L){
	L->length=0;
} 

//顺序表的插入
bool InsertSqList(SqList *L,int i,ElemType e){
	int j; 
	if(i<1||i>L->length+1){  //判断i位置是否有效 
		return false;
	}
	if(L->length>=MaxSize){  //当前存储空间已满,不能插入 
		return false;
	}
	for(j=L->length;j>=i;j--) //将第i个元素及之后的元素后移
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
	printf("\n顺序表的元素是:\n");
	for(i=0;i<L.length;i++){
		printf("%d ",L.data[i]);
	}
	printf("\n");
	printf("删除的最小的元素是:");
	M=Del_Min(&L);
	printf("%d\n",M);
	printf("剩余的元素是:\n");
	for(i=0;i<L.length;i++){
		printf("%d ",L.data[i]);
	}
	return 0;
}

/*
顺序表的元素是:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
删除的最小的元素是:1
剩余的元素是:
15 2 3 4 5 6 7 8 9 10 11 12 13 14
*/
