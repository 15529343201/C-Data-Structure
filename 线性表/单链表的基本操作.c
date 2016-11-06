//单链表的基本操作
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define ERROR 0
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node *next;
}LNode,*LinkList;

//单链表的初始化
LinkList init_LinkList()
{
	LNode *L;
	L=(LinkList)malloc(sizeof(LNode));//申请节点空间
	if(L==NULL) //判断是否有足够的内存空间
	  printf("申请内存空间失败!");
	L->next=NULL;//将next设置为NULL,初始长度为0的单链表
}

//单链表的建立1,头插法建立单链表
LinkList Creat_LinkList1()
{
	LNode *L;
	L=(LinkList)malloc(sizeof(LNode));//申请头节点空间
	L->next=NULL;//初始化一个空链表
	ElemType x;//x为链表数据域中的数据
	while(scanf("%d",&x)!=EOF)
	 {
		LNode *p;
		p=(LinkList)malloc(sizeof(LNode));//申请新的节点
		p->data=x;//结点数据域赋值
		p->next=L->next;//将结点插入到表头
		L->next=p;
	 }
	return L;
}

//单链表的建立2,尾插法建立单链表
LinkList Creat_LinkList2()
{
	LNode *L;
	L=(LinkList)malloc(sizeof(LNode));//申请头结点空间
	L->next=NULL;//初始化一个空链表
	LNode *r;
	r=L;
	ElemType x;//x为链表数据域中的数据
	while(scanf("%d",&x)!=EOF)
	 {
		LNode *p;
		p=(LinkList)malloc(sizeof(LNode));//申请新的结点
		p->data=x;
		r->next=p;
		r=p;
	 }
	return L;
}

//尾插法建立单链表
/*void CreatFromTail(LinkList L,int n)
{
	int i;
	LNode *r,*s;
	r=L;
	for(i=0;i<n;i++)
	 {
		s=(LNode*)malloc(sizeof(LNode));
		scanf("%d",&s->data);
		r->next=s;
		r=s;
	 }
	r->next=NULL;
}

void CreatFromTail(LinkList L)
{
	LNode *r,*s;
	char c;
	r=L;
	while(1)
	 {
		c=getchar();
		if(c!='$')
		 {
			s=(LNode*)malloc(sizeof(LNode));
			s->data=c;
			r->next=s;
			r=s;
		 }
		else
		 {
			r->next=NULL;
			break;
		 }
	 }
}
*/

//头插法建立单链表
/*void CreatFromHead(LinkList L,int n)
{
	int i;
	LNode *s;
	for(i=0;i<n;i++)
	 {
		s=(LNode*)malloc(sizeof(LNode));
		scanf("%d",&s->data);
		s->next=L->next;
		L->next=s;
	 }
}

void CreatFromHead(LinkList L)
{
	LNode *r,*s;
	char c;
	while(1)
	 {
		c=getchar();
		if(c!='$')
		 {
			s=(LNode*)malloc(sizeof(LNode));
			s->data=c;
			s->next=L->next;
			L->next=s;
		 }
		else
		  break;
	 }
}
*/

//求单链表表长
int Length_LinkList(LinkList L)
{
	LNode *p=L;
	int j=0;
	while(p->next != NULL)
	 {
		p=p->next;
		j++;
	 }
	return j;
}

//单链表中按序号查找
LinkList Get_LinkList(LinkList L,int k)
{
	LNode *p=L;
	int j=0;
	while(p->next!=NULL && j<k)
	 {
		p=p->next;
		j++;
	 }
	if(j == k)
	 {
		return p;
	 }
	else
	  return NULL;
}

//单链表中按值查找
LNode *Locate(LinkList L,ElemType x)
{
	LNode *p=L->next;
	while(p!=NULL && p->data != x)
	 {
		p=p->next;
	 }
	return p;
}

//单链表的插入
int Insert_LinkList(LinkList L,int i,ElemType x)
{
	//在单链表L中的第i个位置上插入值为x的元素
	LNode *p,*s;
	p=Get_LinkList(L,i-1);
	if(p==NULL)
	 {
		printf("插入位置i出错");
		return ERROR;
	 }
	else
	 {
		s=(LinkList)malloc(sizeof(LNode));
		s->data=x;
		s->next=p->next;
		p->next=s;
		return TRUE;
	 }
}

//单链表的删除
int Del_LinkList(LinkList L,int i)
{
	LinkList p,q;
	p=Get_LinkList(L,i-1);
	if(p==NULL)
	 {
		printf("第i-1个结点不存在");
		return ERROR;
	 }
	else
	 {
		if(p->next==NULL)
		 {
			printf("第i-1个结点不存在");
			return ERROR;
		 }
		else 
		 {
			q=p->next;
			p->next=q->next;
			free(q);
			return TRUE;
		 }
	 }
}

//单链表的逆置
void Reverse(LinkList L)
{
	LNode *p,*q;
	p=L->next;
	L->next=NULL;
	while(p)
	 {
		q=p;
		p=p->next;
		q->next=L->next;
		L->next=q;
	 }
}

//单链表销毁
void ListDestroy(LinkList L)
{
	LNode *p;
	p=L->next;
	while(p!=NULL)
	 {
		L->next=p->next;
		free(p);
		p=L->next;
	 }
}

//单链表的打印
void PrintLinkList(LNode *h)
{
	LNode *p;
	p=h->next;
	while(p)
	 {
		printf("%d",p->data);
		p=p->next;
	 }
}




