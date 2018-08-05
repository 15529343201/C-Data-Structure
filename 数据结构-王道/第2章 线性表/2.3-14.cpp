/*设A和B是两个单链表(带头结点),其中元素递增有序,设计一个算法从A和B中
公共元素产生单链表C,要求不破坏A、B的结点*/
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

/*算法思想:表A、B都有序,可从第一个元素起依次比较A、B两表的元素,若元素值
不等,则值小的指针往后移,若元素值相等,则创建一个值等于两结点的元素值的新的结点,
使用尾插法插入到新的链表中,并两个原表指针后移一位,直到其中一个链表遍历到表尾。*/
LinkList Get_Common(LinkList &A,LinkList &B){
	//本算法产生单链表A和B的公共元素的单链表C
	LNode *p=A->next,*q=B->next,*r,*s;
	LinkList C=(LinkList)malloc(sizeof(LNode)); //建立表C
	r=C; //r始终指向C的尾结点
	while(p!=NULL&&q!=NULL){
		if(p->data<q->data)
			p=p->next; //若A的当前元素较小,后移指针
		else if(p->data>q->data)
			q=q->next; //若B的当前元素较小,后移指针
		else{ //找到公共元素 
			s=(LNode*)malloc(sizeof(LNode));
			s->data=p->data; //复制产生结点*s
			r->next=s; //将*s链到C上(尾插法)
			r=s;
			p=p->next;
			q=q->next; 
		} 
	} 
	r->next=NULL;
	return C;
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
	r=Get_Common(l,m);
	print(r);
	return 0;
}  

/*
1 3 4 5 6 7 8 9 10 9999
1 2 3 7 8 9 10 11 9999
链表中的元素是:
1 3 4 5 6 7 8 9 10
1 2 3 7 8 9 10 11
1 3 7 8 9 10
*/


  
