/*将一个带头结点的单链表A分解为两个带头结点的单链表A和B,使得A表中含有原
表中序号为奇数的元素,而B表中含有原表中序号为偶数的元素,且保持其相对顺序不变*/
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

/*算法思想:设置一个访问序号变量(初值为0),每访问一个结点序号自动加1,然后根据序号
的奇偶性将结点插入到A表或B表中。重复以上操作直到表尾*/
LinkList DisCreat_1(LinkList &A){
	//将表A中结点按序号的奇偶性分解到表A或表B中
	int i;
	LinkList B,p;
	i=0; //i记录表A中结点的序号
	B=(LinkList)malloc(sizeof(LNode)); //创建B表表头
	B->next=NULL; //B表的初始化
	LNode *ra=A,*rb=B; //ra和rb将分别指向将创建的A表和B表的尾结点
	p=A->next; //p为链表工作指针,指向待分解的结点
	A->next=NULL; //置空新的A表(创建A表头结点) 
	while(p!=NULL){ 
		i++;
		if(i%2==0){  //处理序号为偶数的链表结点 
			rb->next=p; //在B表尾插入新结点 
			rb=p;  //rb指向新的尾结点 
		}
		else{ //处理原序号为奇数的结点 
			ra->next=p; //在A表尾插入新结点 
			ra=p;
		}
		p=p->next; //将p恢复为指向新的待处理结点 
	} 
	ra->next=NULL;
	rb->next=NULL;
	return B;
} 
/*为了保持原来结点中的顺序,本题采用尾插法建立单链表。此外,本算法完全可以不用设置序号变量。
while循环中的代码改为将结点插入到表A中和将下一结点插入到表B中,这样while中第一处理的结点
就是奇数号结点,第二处理的结点就是偶数号结点。*/ 

int main(void){ 
	int min,max;
	LinkList l,q,m;
	l=CreatList2(q);
	printf("链表中的元素是:\n");
	print(l);
	printf("\n");
	m=DisCreat_1(l);
	print(m);
	return 0;
} 
/*
1 2 3 4 5 6 9999
链表中的元素是:
1 2 3 4 5 6
2 4 6
*/
