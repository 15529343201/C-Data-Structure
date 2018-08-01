//有一个带头结点的单链表L,设计一个算法使其元素递增有序
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

/*算法思想:采用直接插入排序算法思想,先构成只含一个数据结点的有序单链表,然后依次
扫描单链表中剩下的结点*p(直至p==NULL为止),在有序表中通过比较查找插入*p的前驱结点
*pre,然后将*p插入到*pre之后*/
void Sort(LinkList &L){
	//本算法实现将单链表的结点重排,使其递增有序
	LNode *p=L->next,*pre;
	LNode *r=p->next;  //r保持*p后继结点指针,以保证不断链
	p->next=NULL; //构造只含一个数据结点的有序表
	p=r;
	while(p!=NULL){
		r=p->next;  //保存*p的后继结点指针
		pre=L;
		while(pre->next!=NULL&&pre->next->data<p->data)
			pre=pre->next;   //在有序表中查找插入*P的前驱结点*pre
		p->next=pre->next;  //将*p插入到*pre之后
		pre->next=p;
		p=r; //扫描原单链表中剩下的结点 
	} 
} 

int main(void){ 
	LinkList l,q;
	l=CreatList2(q);
	printf("链表中的元素是:\n");
	print(l);
	printf("\n"); 
	printf("排序后的链表元素是:\n");
	Sort(l);
	print(l);
	return 0;
}

/*
1 3 2 6 2 7 3 9 0 9999
链表中的元素是:
1 3 2 6 2 7 3 9 0
排序后的链表元素是:
0 1 2 2 3 3 6 7 9
*/
