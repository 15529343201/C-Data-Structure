/*有两个循环单链表,链表头指针分别为h1和h2,编写一个函数将链表h2链接到链表
h1之后,要求链接后的链表仍保持循环链表形式*/
/*两个整数序列A=a1,a2,a3,...,am和B=b1,b2,b3,...,bn已经存入两个单链表中,
设计一个算法,判断序列B是否是序列A的连续子序列*/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{ //定义单链表结点类型
	ElemType data;    //数据域 
	struct LNode *next;  //指针域 
}LNode,*LinkList;

void print(LinkList L){
	LinkList r=L->next;
	while(r!=L){
		printf("%d ",r->data);
		r=r->next;
	}
} 

//尾插法建立循环单链表
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
	r->next=L;   //尾结点指针指向表头 
	return L; 
}  

/*算法思想:先找到两个链表的尾指针,将第一个链表的尾指针与第二个链表的头结点链接起来,再使之成为循环的*/
LinkList Link(LinkList &h1,LinkList &h2){
	//将循环链表h2链接到循环链表h1之后,使之仍保持循环链表的形式
	LNode *p,*q; //分别指向两个链表的尾结点
	p=h1;
	while(p->next!=h1){ //寻找h1的尾结点 
		p=p->next;
	} 
	q=h2;
	while(q->next!=h2){ //寻找h2的尾结点 
		q=q->next;
	}
	p->next=h2; //将h2链接到h1之后
	q->next=h1; //令h2的尾结点指向h1
	return h1; 
} 

int main(void){ 
	int min,max;
	LinkList l,q,m,n,r;
	l=CreatList2(q);
	m=CreatList2(n);
	printf("链表中的元素是:\n");
	print(l);
	printf("\n"); 
	print(m);
	printf("\n");
	r=Link(l,m);
	print(r);
	return 0;
}    

/*
1 2 3 9999
4 5 6 9999
链表中的元素是:
1 2 3
4 5 6
1 2 3 3954592 4 5 6
*/


