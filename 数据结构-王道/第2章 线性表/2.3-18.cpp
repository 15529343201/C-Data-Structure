/*������ѭ��������,����ͷָ��ֱ�Ϊh1��h2,��дһ������������h2���ӵ�����
h1֮��,Ҫ�����Ӻ�������Ա���ѭ��������ʽ*/
/*������������A=a1,a2,a3,...,am��B=b1,b2,b3,...,bn�Ѿ�����������������,
���һ���㷨,�ж�����B�Ƿ�������A������������*/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{ //���嵥����������
	ElemType data;    //������ 
	struct LNode *next;  //ָ���� 
}LNode,*LinkList;

void print(LinkList L){
	LinkList r=L->next;
	while(r!=L){
		printf("%d ",r->data);
		r=r->next;
	}
} 

//β�巨����ѭ��������
LinkList CreatList2(LinkList &L){
	//�ӱ�ͷ����β����������L,ÿ�ξ��ڱ�β����Ԫ��
	int x; 
	L=(LinkList)malloc(sizeof(LNode));
	LNode *s,*r=L;   //rΪ��βָ��
	scanf("%d",&x);
	while(x!=9999){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;  //rָ���µı�β���
		scanf("%d",&x); 
	} 
	r->next=L;   //β���ָ��ָ���ͷ 
	return L; 
}  

/*�㷨˼��:���ҵ����������βָ��,����һ�������βָ����ڶ��������ͷ�����������,��ʹ֮��Ϊѭ����*/
LinkList Link(LinkList &h1,LinkList &h2){
	//��ѭ������h2���ӵ�ѭ������h1֮��,ʹ֮�Ա���ѭ���������ʽ
	LNode *p,*q; //�ֱ�ָ�����������β���
	p=h1;
	while(p->next!=h1){ //Ѱ��h1��β��� 
		p=p->next;
	} 
	q=h2;
	while(q->next!=h2){ //Ѱ��h2��β��� 
		q=q->next;
	}
	p->next=h2; //��h2���ӵ�h1֮��
	q->next=h1; //��h2��β���ָ��h1
	return h1; 
} 

int main(void){ 
	int min,max;
	LinkList l,q,m,n,r;
	l=CreatList2(q);
	m=CreatList2(n);
	printf("�����е�Ԫ����:\n");
	print(l);
	printf("\n"); 
	print(m);
	printf("\n");
	r=Link(l,m);
	print(r);
	return 0;
}    

/*
1 2 3 9999
4 5 6 9999
�����е�Ԫ����:
1 2 3
4 5 6
1 2 3 3954592 4 5 6
*/


