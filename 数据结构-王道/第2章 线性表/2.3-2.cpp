//在带头结点的单链表中L中,删除所有值为x的结点,并释放其空间,假设值为x的结点不唯一,试编写算法以实现上述操作。
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

//头插法建立单链表
LinkList CreatList1(LinkList &L){
	//从表尾到表头逆向建立单链表L,每次均在头结点之后插入元素
	LNode *s;
	int x;
	L=(LinkList)malloc(sizeof(LNode));     //创建头结点
	L->next=NULL;                          //初始为空链表
	scanf("%d",&x);                        //输入结点的值
	while(x!=9999){                        //输入9999表示结束 
		s=(LNode*)malloc(sizeof(LNode));   //创建新结点
		s->data=x;
		s->next=L->next;
		L->next=s;                         //将新结点插入表中,L为头指针
		scanf("%d",&x); 
	} 
	return L;
} 

/*解法一:用p从头至尾扫描单链表,pre指向*p结点的前驱。若p所指结点的值为x,则删除,并让p移向下一个结点,
否则让pre,p指针同步后移一个结点。*/
/*本算法是在无序单链表中删除满足某种条件的所有结点,这里的条件是结点的值为x。实际上,这个条件
是可以任意指定的,只要修改if条件即可,比如,我们要求删除值介于mink和maxk之间所有结点,则只需将
if语句修改为if(p->data>mink && p->data<maxk)*/ 
void Del_X_1(LinkList &L,ElemType x){
	//L为带头结点的单链表,本算法删除L中所有值为x的结点
	LNode *p=L->next,*pre=L,*q;//置p和pre的初始值
	while(p!=NULL){
		if(p->data==x){
			q=p; //q指向该结点
			p=p->next;
			pre->next=p;  //删除*q结点
			free(q);      //释放*q结点的空间 
		}
		else{  //否则pre和p同步后移 
			pre=p;
			p=p->next;
		}
	} 
}

/*解法二:采用尾插法建立单链表。用p指针扫描L的所有结点,当其值不为x时将其链接到L之后,否则将其释放。*/
void Del_X_2(LinkList &L,ElemType x){
	//L为带头结点的单链表,本算法删除L中所有值为x的结点
	LNode *p=L->next,*r=L,*q; //r指向尾结点,其初值为头结点
	while(p!=NULL){
		if(p->data!=x){ //*p结点值不为x时将其链接到L尾部 
			r->next=p;
			r=p;
			p=p->next;  //继续扫描 
		}
		else{ //*p结点值为x时将其释放 
			q=p;
			p=p->next;  //继续扫描
			free(q);    //释放空间 
		} 
	} 
	r->next=NULL;   //插入结束后置尾结点指针为NULL 
} 

//上述两个算法扫描一遍链表,时间复杂度为O(n),空间复杂度为O(1)
 
int main(void){
	int x;
	LinkList l,q;
	l=CreatList1(q);
	printf("链表中的元素是:\n");
	print(l);
	printf("请输入你要删除的元素:\n");
	scanf("%d",&x);
	//Del_X_1(l,x);
	Del_X_2(l,x); 
	print(l); 
	return 0;
}

/*
del_x_1:
1 2 2 3 4 5 6 7 8 9 10 9999
链表中的元素是:
10 9 8 7 6 5 4 3 2 2 1 请输入你要删除的元素:
9
10 8 7 6 5 4 3 2 2 1
del_x_2:
1 2 3 4 8 2 9 3 10 9999
链表中的元素是:
10 3 9 2 8 4 3 2 1 请输入你要删除的元素:
3
10 9 2 8 4 2 1
*/
