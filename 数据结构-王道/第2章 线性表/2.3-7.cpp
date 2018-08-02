/*设计在一个带表头结点的单链表中所有元素结点的数据值无序,试编写
一个函数,删除表中所有介于给定的两个值(作为函数参数给出)之间的元素的元素(若存在)*/
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

void RangeDelete(LinkList &L,int min,int max){
	LNode *pr=L,*p=L->next;  //p是检测指针,Pr是其前驱
	while(p!=NULL){
		if(p->data>min&&p->data<max){ //寻找到被删结点,删除 
			pr->next=p->next;
			free(p);
			p=pr->next;
		}
		else{
			pr=p;
			p=p->next;
		}
	} 
}

int main(void){ 
	int min,max;
	LinkList l,q;
	l=CreatList2(q);
	printf("链表中的元素是:\n");
	print(l);
	printf("请输入两个值(min,max),删除数据值介于它们之间的元素:\n");
	scanf("%d%d",&min,&max);
	RangeDelete(l,min,max);
	print(l);
	return 0;
}

/*
1 3 7 90 23 12 23 87 23 12 3 9999
链表中的元素是:
1 3 7 90 23 12 23 87 23 12 3 请输入两个值(min,max),删除数据值介于它们之间的元素:

3 88
1 3 90 3
*/
