#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int number;
	struct node *next;
	struct node *prev;
}node,*LinkList;

//建立
LinkList Create(int n)
{
	LinkList head=(LinkList)malloc(sizeof(node));
	node *tail;
	int i;
	head->next=head;
	head->prev=head;
	head->number=1;
	tail=head;
	for(i=2;i<=n;i++)
	 {
		node *p=(node*)malloc(sizeof(node));
		p->number=i;
		p->next=tail->next;
		p->prev=tail;
		tail->next=p;
		tail=p;
		head->prev=tail;
	 }
	return head;
}

//jose排列
void joseph(LinkList head,int m)
{
	int i;
	node *p,*q;
	p=head;
	while(head->next!=head)
	 {
		for(i=1;i<m;i++)
		 {
			p=p->next;
		 }
		q=p->next;
		q->prev=p->prev;
		p->prev->next=q;
		printf("%d ",p->number);
		if(p==head)
		  head=q;
		free(p);
		p=q;
	 }
	printf("%d\n",head->number);
}

int main()
{
	LinkList head;
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	head=Create(n);
	joseph(head,m);
	return 0;
}
