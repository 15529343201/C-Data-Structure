/*给定一个带头结点的单链表,设head为头指针,结点的结构为(data,next),data为整型元素,next为指针
试写出算法:按递增次序输出单链表中各结点的数据元素,并释放结点所占的存储空间(要求:不允许使用
数组作为辅助空间)*/
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

/*算法思想:对链表进行遍历,在每趟遍历中查找出整个链表的最小值元素,输出并释放结点
所占空间;再查找次小值元素,输出并释放空间,如此下去,直至链表为空,最后释放头结点所
占存储空间,该算法的时间复杂度为O(n^2)*/
void Min_Delete(LinkList &head){
	//head是带头结点的单链表的头指针,本算法按递增顺序输出单链表中的数据元素
	LinkList pre,u,p;
	while(head->next!=NULL){ //循环到仅剩头结点 
		pre=head; //pre为元素最小值结点的前驱结点的指针
		p=pre->next; //p为工作指针
		while(p->next!=NULL){
			if(p->next->data<pre->next->data){
				pre=p;  //记住当前最小值结点的前驱
			}
			p=p->next; 	
		}
		/*
		头   1   2   3   4   5
		pre  p
		头   1   2   3   4   5
							 p
		*/
		/*
		头   5   4   3   2   1
		pre  p
			 pre p
			     pre p 
			         pre p
			             pre p
		*/	
		printf("%d",pre->next->data); //输出元素最小值结点的数据
		u=pre->next; //删除元素值最小的结点,释放结点空间
		pre->next=u->next;
		free(u); 
	} 
	free(head); //释放头结点 
}

int main(void){ 
	int min,max;
	LinkList l,q;
	l=CreatList2(q);
	printf("链表中的元素是:\n");
	print(l);
	printf("\n");
	Min_Delete(l); 
	return 0;
} 

/*
1 2 3 4 5 9999
链表中的元素是:
1 2 3 4 5
12345

5 4 3 2 1 9999
链表中的元素是:
5 4 3 2 1
12345
*/

