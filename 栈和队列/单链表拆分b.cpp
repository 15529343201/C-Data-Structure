//单链表拆分:以第一个元素为基准，小于的放在前面，大于的放在后面 
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int value;
	struct node *next;
}Node;

int main()
{
	Node *head;
	Node *p,*q,*t;
	Node *mySort(Node *head);
	int i=0,n;
	p=(Node*)malloc(sizeof(Node));
	printf("please input number of list:");
	scanf("%d",&n); 
	printf("please input one number:");
	scanf("%d",&p->value);
	p->next=NULL;
	head=p;
	
	t=NULL;
	for(i=1;i<n;i++)//create list of 5 nodes
	{
		t=(Node*)malloc(sizeof(Node));
		printf("please input one number:");
		scanf("%d",&t->value);
		t->next=NULL;
		p->next=t;
		p=t;
	}
	
	q=head;
	printf("source list:");
	while(q!=NULL)
	{
		int a=q->value;
		printf("%d",q->value);
		q=q->next;
	}
	printf("\n");
	p=mySort(head);
	
	printf("sorted list:");
	while(p!=NULL)
	{
		printf("%d",p->value);
		p=p->next;
	}
	printf("\n");
	system("pause");
	return 0;
}

Node *mySort(Node *head)
{
	Node *shead,*stail;//smaller link
	Node *bhead,*btail;//bigger link
	Node *temp1,*temp2,*temp3;
	int temp4;
	temp4=head->value;//the first value
	temp2=temp1=head;
	shead=stail=bhead=btail=NULL;
	while(temp1!=NULL)
	{
		if(temp1==head)
		  temp1=temp1->next;
		else
		{
			temp3=temp1;
			temp1=temp1->next;
			if(temp3->value<temp4)
			{
				if(shead==NULL)
				{
					shead=stail=temp3;
					stail->next=NULL;
				}
				stail->next=temp3;
				stail=stail->next;
				stail->next=NULL;
			}
			else
			{
				if(bhead==NULL)
				{
					bhead=btail=temp3;
					btail->next=NULL;
				}
				btail->next=temp3;
				btail=btail->next;
				btail->next=NULL;
			}
		}
	}
	if(stail==NULL)
	{
		temp2->next=bhead;
		btail->next=NULL;
		head=temp2;
	}
	else
	{
		if(btail==NULL)
		{
			stail->next=temp2;
			temp2->next=NULL;
			head=shead;
		}
		else
		{
			stail->next=temp2;
			temp2->next=bhead;
			btail->next=NULL;
			head=shead;
		}
	}
	
}
