//单链表的拆分:
//输入N个整数顺序建立一个单链表，将该单链表拆分成两个子链表
//第一个存放了所有的偶数，第二个存放了所有的奇数。
//输入:第一行输入整数N，第二行依次输入N个整数
//输出:第一行分别输出偶数链表与奇数链表的元素个数，第二行依次输出偶数子链表的所有数据，第三行输出奇数子链表的所有数据 
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}Node;

Node *creat(int n)
{
	Node *head,*p,*tail;
	head=(Node*)malloc(sizeof(Node));
	head->next=NULL;
	tail=head;
	while(n--)
	{
		p=(Node*)malloc(sizeof(Node));
		scanf("%d",&p->data);
		p->next=NULL;
		tail->next=p;
		tail=p;
	}
	return head;
}

Node *split(Node *head1)
{
	Node *head2,*p,*tail1,*tail2,*q;
	int a=0,b=0;
	head2=(Node*)malloc(sizeof(Node));
	head2->next=NULL;
	tail2=head2;
	p=head1->next;
	head1->next=NULL;
	tail1=head1;
	q=p->next;
	while(p!=NULL)
	{
		if(p->data%2==0)
		{
			p->next=NULL;
			tail1->next=p;
			tail1=p;
			++a;
		}
		else
		{
			p->next=NULL;
			tail2->next=p;
			tail2=p;
			++b;
		}
		p=q;
		if(q!=NULL)
		  q=q->next;
	}
	printf("%d %d\n",a,b);
	return head2;
}

void display(Node *head)
{
	Node *p;
	p=head->next;
	while(p!=NULL)
	{
		if(p->next!=NULL)
		  printf("%d ",p->data);
		else
		  printf("%d\n",p->data);
		p=p->next;
	}
}

int main()
{
	int n;
	Node *head1,*head2;
	scanf("%d",&n);
	head1=creat(n);
	head2=split(head1);
	display(head1);
	display(head2);
	return 0;
}
