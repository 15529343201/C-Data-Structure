//给定两个单链表,编写算法找出两个链表的公共结点
/*解答:两个单链表有公共结点,也就是说两个链表从某一结点开始,它们的next都指向同一个结点。
由于每个单链表结点只有一个next域,因此从第一个公共结点开始,之后它们所有的结点都是重合的,
不可能再出现分叉。所以,两个有公共结点而部分重合的单链表,拓扑形状看起来像Y,而不可能像X.
	本题极容易联想到"蛮"方法:在第一个链表上顺序遍历每个结点,每遍历一个结点,在第二个链表上
顺序遍历所有结点,如果找到两个相同的结点,于是就找到了它们的公共结点。显然,该算法的时间复杂
度为O(len1*len2)
	接下来我们试着去寻找一个线性时间复杂度的算法。先把问题简化:如何判断两个单向链表有没有
公共结点?应注意到这样一个事实:如果两个链表有一个公共结点,那么该公共结点之后的所有结点都是
重合的,即它们的最后一个结点必然是重合的。因此,我们判断两个链表是不是有重合的部分,只要分别
遍历两个链表到最后一个结点。如果两个尾结点是一样的,说明它们有公共结点,否则两个链表没有公共的结点。
	然而,在上面的思路中,顺序遍历两个链表到尾结点的时候,并不能保证在两个链表上同时到达尾结点。
这是因为两个链表长度不一定一样。但假设一个链表比另一个链表长k个结点,我们先在长的链表上遍历k个结点,
之后再同步遍历,此时我们就能保证同时到达最后一个结点了。由于两个链表从第一个公共结点开始到
链表的尾结点,这一部分是重合的。因此,它们肯定也是同时到达第一公共结点的。于是在遍历中,第一个
相同的结点就是第一个公共的结点。
	在这个思路中,我们先要分别遍历两个链表得到它们的长度,并求出两个长度的差。在长的链表上先遍历长度
之差个结点之后,在同步遍历两个链表,直到找到相同的结点,或者一直到链表结束。此时,该方法的时间
复杂度为O(len1+len2)。*/
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

//求链表表长 
int Length(LinkList &L){
	int j=0;
	LNode *p;
	p=L->next;
	while(p!=NULL)
	{
		p=p->next;
		j++;
	}
	return j;
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

LinkList Search_1st_Common(LinkList L1,LinkList L2){
	//本算法实现在线性的时间内找到两个单链表的第一个公共结点
	int len1=Length(L1),len2=Length(L2); //计算两个链表的表长
	int dist;
	LinkList longList,shortList;  //分别指向较长和较短的链表
	if(len1>len2){
		longList=L1->next;
		shortList=L2->next;
		dist=len1-len2;
	} 
	else{
		longList=L2->next;
		shortList=L1->next;
		dist=len2-len1;
	}
	while(dist--){
		longList=longList->next; //表长的链表先遍历到第dist个结点,然后同步 
	}
	while(longList!=NULL){  //寻找共同结点 
		if(longList==shortList){ //找到第一个公共结点 
			printf("success");
			return longList;
		}
		else{ //继续同步寻找 
			longList=longList->next;
			shortList=shortList->next;
		}
	}
	return NULL;
} 

int main(void){ 
	int min,max;
	LinkList l1,l2,q1,q2,p;
	l1=CreatList2(q1);
	l2=CreatList2(q2);
	printf("链表中的元素是:\n");
	print(l1);
	printf("\n");
	print(l2);
	printf("\n");
	Search_1st_Common(l1,l2);
	return 0;
}
