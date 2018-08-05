/*在一个递增有序的线性表中,有数值相同的元素存在。若存储方式为单链表
,设计算法去掉数值相同的元素,使表中不再有重复的元素。例如
(7,10,10,21,30,42,42,42,51,70)将变作(7,10,21,30,42,51,70)*/
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

/*算法思想:由于是有序表,所有相同值域的结点都是相邻的。用p扫描递增单链表L,
若*p结点的值域等于其后继结点的值域,则删除后者,否则p移向下一个结点。*/ 
void Del_Same(LinkList &L){
	//L是递增有序的单链表,本算法删除表中数值相同的元素
	LNode *p=L->next,*q; //p为扫描工作指针
	if(p==NULL)
		return;
	while(p->next!=NULL){
		q=p->next; //q指向*p的后继结点 
		if(p->data==q->data){ //找到重复的结点值 
			p->next=q->next; //释放*q结点
			free(q); //释放相同元素值的结点 
		}
		else
			p=p->next;
	} 
}
/*时间复杂度O(n),空间复杂度O(1)
本题也可用尾插法,将头结点摘下,然后从第一结点开始,依次与已经插入结点的链表
的最后一个结点比较,若不相等则直接插入,否则将当前遍历的结点删除并处理下一个
结点,直到最后一个结点为止*/
 
int main(void){ 
	int min,max;
	LinkList l,q,m;
	l=CreatList2(q);
	printf("链表中的元素是:\n");
	print(l);
	printf("\n");
	Del_Same(l);
	print(l);
	return 0;
}  

/*
7 10 10 21 30 42 42 42 51 70 9999
链表中的元素是:
7 10 10 21 30 42 42 42 51 70
7 10 21 30 42 51 70
*/

