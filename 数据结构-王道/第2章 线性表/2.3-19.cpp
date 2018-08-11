/*设有一个带头结点的循环单链表,其结点值为正整数。设计一个算法,
反复找出表中结点值最小的结点并输出,然后将该结点从中删除,直到单链表
空为止,再删除表头结点*/
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
 
/*算法思想:对于循环单链表L,在不空时循环:每循环依次查找一个最小结点(由minp指向最小值结点,
minpre指向其前驱结点)并删除它。最后释放头结点。*/
void Del_All(LinkList &L){
	//本算法实现每次删除循环单链表中的最小元素,直到链表为空为止
	LNode *p,*pre,*minp,*minpre;
	while(L->next!=L){ //表不空,循环 
		p=L->next;
		pre=L; //p为工作指针,pre指向其前驱
		minp=p;
		minpre=pre; //minp指向最小值结点
		while(p!=L){ //循环一趟,查找最小值结点 
			if(p->data<minp->data){
				minp=p; //找到值更小的结点
				minpre=pre; 
			}
			pre=p; //查找下一个结点
			p=p->next; 
		} 
		printf("%d",minp->data); //输出最小值结点元素
		minpre->next=minp->next; //最小值结点从表中"断"开
		free(minp); 
	} 
	free(L);//释放头结点 
} 

int main(void){ 
	LinkList l,q;
	l=CreatList2(q);
	printf("链表中的元素是:\n");
	print(l);
	Del_All(l);
	return 0;
}    

/*
3 1 5 8 7 2 9 4 9999
链表中的元素是:
3 1 5 8 7 2 9 4 12345789
*/
