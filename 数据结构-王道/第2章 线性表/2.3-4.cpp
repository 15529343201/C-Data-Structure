//试编写在带头结点的单链表L中删除一个最小值结点的高效算法(假设最小值结点是唯一的)
/*算法思想:用P从头至尾扫描单链表,pre指向*p结点的前驱,用minp保存值最小的结点的指针(初值为p),
minpre指向*minp结点的前驱(初值为pre)。一边扫描,一边比较,若p->data小于minp->data,则将
p,pre分别赋值给minp、minpre.当p扫描完毕,minp指向最小值结点,minpre指向最小值结点的前驱结点,
再将minp所指结点删除即可。*/ 
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

LinkList Delete_Min(LinkList &L){
	//L是带头结点的单链表,本算法删除其最小值结点
	LNode *pre=L,*p=pre->next; //p为工作指针,pre指向其前驱
	LNode *minpre=pre,*minp=p; //保存最小值结点及其前驱
	while(p!=NULL){
		if(p->data<minp->data){
			minp=p;  //找到比之前找到的最小值结点更小的结点
			minpre=pre; 
		}
		pre=p;   //继续扫描下一个结点
		p=p->next; 
	} 
	minpre->next=minp->next;  // 删除最小值结点
	free(minp);
	return L; 
}
int main(void){
	LinkList l,q;
	l=CreatList2(q);
	printf("链表中的元素是:\n");
	print(l);
	printf("\n");
	printf("删除链表最小值元素后是:\n");
	Delete_Min(l);
	print(l);
	return 0;
}

/*
1 2 0 3 9999
链表中的元素是:
1 2 0 3
删除链表最小值元素后是:
1 2 3
*/
