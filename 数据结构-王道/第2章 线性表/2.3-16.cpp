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

/*算法思想:因为两个整数序列已存入两个链表中,操作从两个链表的第一个结点开始,若对应数据相等,
则后移指针;若对应数据不相等,则A链表从上次开始比较结点的后继结点开始,B链表仍从第一个结点开始比较
,直到B链表到尾表示匹配成功。A链表到尾而B链表未到尾表示失败。操作中应记住A链表每次的开始结点,
以便下趟匹配时好从其后继开始。*/
int Pattern(LinkList &A,LinkList &B){
	//A和B分别是数据域为整数的单链表,本算法判断B是否是A的子序列
	LNode *p=A->next; //p为A链表的工作指针
	LNode *pre=p; //pre记住每趟比较中A链表的开始结点
	LNode *q=B->next; //q是B链表的工作指针
	while(p&&q){
		if(p->data==q->data){ //结点值相同 
			p=p->next;
			q=q->next;
		}
		else{
			pre=pre->next; 
			p=pre; //A链表新的开始比较结点
			q=B->next; //q从B链表第一个结点开始 
		}
	} 
	if(q==NULL){ //B已经比较结束 
		return 1;//说明B是A的子序列 
	}else{
		return 0; //B不是A的子序列 
	}
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
	if(Pattern(l,m))
		printf("B是A的子序列\n");
	else
		printf("B不是A的子序列\n");
	return 0;
}    

/*
1 3 4 5 6 7 9 9999
3 4 5 6 9999
链表中的元素是:
1 3 4 5 6 7 9
3 4 5 6
B是A的子序列

1 2 3 4 5 7 9999
1 3 5 9999
链表中的元素是:
1 2 3 4 5 7
1 3 5
B不是A的子序列
*/
