/*设计一个算法用于判断带头结点的循环双链表是否对称*/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{ //定义单链表结点类型
	ElemType data;    //数据域 
	struct LNode *next,*prior;  //前驱和后继指针 
}DNode,*DLinkList;

DLinkList CreatList(int n){
	int m;
	//定义头结点
	DLinkList s1=(DLinkList)malloc(sizeof(DNode));
	s1->prior=NULL;
	s1->next=NULL;
	DNode *r=s1;
	//尾插法建立链表
	for(int i = 0;i < n;i++){
		DNode *s=(DNode*)malloc(sizeof(DNode));
		scanf("%d",&m);
		s->data=m;
		s->prior=r;
		s->next=s1;
		r->next=s;
		s1->prior=s;
		r=s;
	} 
	return s1;
}

/*算法思想:让p从左向右扫描,q从右向左扫描,直到它们指向同一结点(p==q,当循环双链表
中结点个数为奇数时)或相邻(p->next=q或q->prior=p,当循环双链表中结点个数为偶数时)
为止,若它们所指结点值相同,则继续进行下去,否则返回0。若比较全部相等,则返回1.*/
int Symmetry(DLinkList &L){
	//本算法从两头扫描循环双链表,以判断链表是否对称
	DNode *p=L->next,*q=L->prior; //两头工作指针
	while(p!=q&&q->next!=p) {//循环跳出条件
		if(p->data==q->data){ //所指结点值相同则继续比较 
			p=p->next;
			q=q->prior;
		}
		else
			return 0;
	} 
	return 1;
}
	
int main(void){
	int n;
	DLinkList l;
	printf("请输入你要建立结点的个数:\n");
	scanf("%d",&n);
	l=CreatList(n);
	if(Symmetry(l))
		printf("对称");
	else
	 	printf("不对称"); 
	return 0;
}

/*
请输入你要建立结点的个数:
5
1 2 3 2 1
对称

请输入你要建立结点的个数:
4
1 2 2 1
对称

请输入你要建立结点的个数:
5
1 2 3 2 4
不对称
*/
