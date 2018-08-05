/*假设有两个按元素值递增次序排列的线性表,均以单链表形式存储。请编写算法将这两
个单链表归并为一个按元素值递减次序排列的单链表,并要求利用原来两个单链表的结点
存放归并后的单链表*/
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

/*算法思想:两个链表已经按元素值递增次序排序,将其合并时,均从第一个结点起进行比较,
将小的结点链入链表中,同时后移工作指针。该问题要求结果链表按元素值递减次序排列,故新
链表的建立应该采用头插法。比较结束后,可能会有一个链表非空,此时用头插法将剩下的结点
依次插入新链表中即可。*/
void MergeList(LinkList &La,LinkList &Lb){
	//合并两个递增有序链表(带头结点),并使合并后的链表递减排列
	LNode *r,*pa=La->next,*pb=Lb->next; //分别是表La和Lb的工作指针
	La->next=NULL; //La作为结果链表的头指针,先将结果链表初始化为空
	while(pa&&pb){ //当两链表均不为空时,循环
		if(pa->data<=pb->data){  
			r=pa->next; //r暂存pa的后继结点指针 
			pa->next=La->next;
			La->next=pa; //将pa结点链于结果表中,同时逆置(头插法)
			pa=r; //恢复pa为当前待比较结点 
		}
		else{
			r=pb->next; //r暂存pb的后继结点指针
			pb->next=La->next;
			La->next=pb; //将pb结点链于结果表中,同时逆置(头插法)
			pb=r; //恢复pb为当前待比较结点 
		}
	} 
	if(pa) //通常情况下会剩一个链表非空,处理剩下的部分
		pb=pa;
	while(pb){ //处理剩下的一个非空链表 
		r=pb->next; //依次插入到La中(头插法)
		pb->next=La->next;
		La->next=pb;
		pb=r; 
	} 
	free(Lb);
} 
/*若题设不限制数组辅助空间的使用,则可先将链表的数据复制在数组里,再采用时间复杂度为
O(nlongn)的排序算法进行排序,然后将数组元素输出,时间复杂度为O(nlogn)。*/
 
int main(void){ 
	int min,max;
	LinkList l,q,m,n;
	l=CreatList2(q);
	m=CreatList2(n);
	printf("链表中的元素是:\n");
	print(l);
	printf("\n");
	print(m);
	printf("\n");
	MergeList(l,m);
	print(l);
	return 0;
}  

/*
1 3 5 7 9 9999
2 4 6 8 10 9999
链表中的元素是:
1 3 5 7 9
2 4 6 8 10
10 9 8 7 6 5 4 3 2 1
*/

 
