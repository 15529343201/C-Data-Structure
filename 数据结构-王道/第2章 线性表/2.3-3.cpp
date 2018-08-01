//设L为带头结点的单链表,编写算法实现从尾到头反向输出每个节点的值
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{ //定义单链表结点类型
	ElemType data;    //数据域 
	struct LNode *next;  //指针域 
}LNode,*LinkList;

void print(LinkList L){
	while(L){
		printf("%d ",L->data);
		L=L->next;
	}
} 

//尾插法建立单链表
LinkList CreatList2(LinkList &L){
	//从表头到表尾建立单链表L,每次均在表尾插入元素
	int x,y; 
	L=(LinkList)malloc(sizeof(LNode));
	scanf("%d",&y);
	L->data=y;
	LNode *s,*r=L;   //r为表尾指针
	scanf("%d",&x);
	while(x!=9999){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;  //r指向新的表尾结点
		scanf("%d",&x); 
	} 
	r->next=NULL;   //尾结点指针置空
	return L; 
} 

/*链表逆置 栈的基本操作 递归*/
//每当访问一个结点时,先递归输出它后面的结点,再输出该结点自身,这样链表就反向输出了
void R_Print(LinkList L){
	//从尾到头输出单链表L中每个结点的值
	if(L->next!=NULL){
		R_Print(L->next); //递归 
	} 
	printf("%d ",L->data);  //输出函数 
} 

int main(void){
	int x;
	LinkList l,q;
	l=CreatList2(q);
	printf("链表中的元素是:\n");
	print(l);
	printf("\n");
	R_Print(l);
	return 0;
}

/*
1 2 3 4 5 9999
链表中的元素是:
1 2 3 4 5
5 4 3 2 1
*/
