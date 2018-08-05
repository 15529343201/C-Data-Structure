/*设C={a1,b1,a2,b2,...,an,bn}为线性表,采用带头结点的hc单链表存放,设计一个
就地算法,将其拆分为两个线性表,使得A={a1,a2,...,an},B={bn,...,b2,b1}*/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{ //定义单链表结点类型
	ElemType data;    //数据域 
	struct LNode *next;  //指针域 
}LNode,*LinkList;

void print(LinkList L){
	while(L->next){
		printf("%d ",L->next->data);
		L=L->next;
	}
} 

//尾插法建立单链表
LinkList CreatList2(LinkList &L){
	//从表头到表尾建立单链表L,每次均在表尾插入元素
	int x; 
	L=(LinkList)malloc(sizeof(LNode));
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

LinkList DisCreat_2(LinkList &A){
	LinkList B=(LinkList)malloc(sizeof(LNode));//创建B表表头
	B->next=NULL;//B表的初始化
	LNode *p=A->next,*q; //p为工作指针
	LNode *ra=A; //ra始终指向A的尾结点
	while(p!=NULL){
		ra->next=p;
		ra=p; //将*p链到A的表尾
		p=p->next;
		q=p->next; //头插后,*p将断链,因此用q记忆*p的后继
		p->next=B->next; //将*p插入到B的前端
		B->next=p;
		p=q; 
	} 
	ra->next=NULL; //A尾结点的next域置空
	return B; 
}
/*采用头插法插入节点后,*p的指针域已改变,如果不设变量保存其后继结点会引起断链,从而导致算法出错*/ 

int main(void){ 
	int min,max;
	LinkList l,q,m;
	l=CreatList2(q);
	printf("链表中的元素是:\n");
	print(l);
	printf("\n");
	m=DisCreat_2(l);
	print(m);
	return 0;
}  

/*
1 2 3 4 5 6 7 8 9 10 9999
链表中的元素是:
1 2 3 4 5 6 7 8 9 10
10 8 6 4 2
*/
