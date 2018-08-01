//试编写算法将带头结点的单链表就地逆置,所谓"就地"是指辅助空间复杂度为O(1)
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

/*解法一:将头结点摘下,然后从第一个结点开始,依次前插入到头结点的后面(头插法建立单链表),
直到最后一个结点为止,则实现了链表的逆置*/
LinkList Reverse_1(LinkList L){
	//L是带头结点的单链表,本算法将L就地逆置
	LNode *p,*r;   //p为工作指针,r为p的后继,以防断链
	p=L->next;  //从第一个元素结点开始
	L->next=NULL; //先将头结点L的next域置为NULL
	while(p!=NULL){  //依次将元素结点摘下 
		r=p->next; //暂存p的后继
		p->next=L->next;  //将p结点插入到头结点之后
		L->next=p;
		p=r; 
	} 
	return L;
} 

/*解法二:假设pre,p和r指向3个相邻的结点,如下图所示。假设经过若干操作,*pre之前的结点的指针都已调整
完毕,它们的next都指向其原前驱结点。现在令*p结点的next域指向*pre结点,注意到一旦调整指针的指向后,*p
的后继结点的链就断开了,为此需要用r来指向原*p的后继结点。处理时需要注意两点:一是在处理第一个结点时,
应将其next域置为NULL,而不是指向头结点(因为它将作为新表的为结点);二是在处理完最后一个结点后,需要将
头结点的指针指向它。*/
LinkList Reverse_2(LinkList L){
	//依次遍历线性表L,并将结点指针反转
	LNode *pre,*p=L->next,*r=p->next;
	p->next=NULL; //处理第一个结点
	while(r!=NULL){ //r为空,则说明p为最后一个结点 
		pre=p; //依次继续遍历
		p=r;
		r=r->next;
		p->next=pre; //指针反转 
	} 
	L->next=p; //处理最后一个结点
	return L; 
}
 
int main(void){ 
	LinkList l,q;
	l=CreatList2(q);
	printf("链表中的元素是:\n");
	print(l);
	printf("\n");
	Reverse_1(l);
	print(l);
	printf("\n");
	Reverse_2(l);
	print(l);
	return 0;
} 

/*
1 2 3 4 5
9999
链表中的元素是:
1 2 3 4 5
5 4 3 2 1
1 2 3 4 5
*/
