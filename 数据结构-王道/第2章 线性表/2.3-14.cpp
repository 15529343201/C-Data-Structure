/*��A��B������������(��ͷ���),����Ԫ�ص�������,���һ���㷨��A��B��
����Ԫ�ز���������C,Ҫ���ƻ�A��B�Ľ��*/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{ //���嵥����������
	ElemType data;    //������ 
	struct LNode *next;  //ָ���� 
}LNode,*LinkList;

void print(LinkList L){
	while(L->next){
		printf("%d ",L->next->data);
		L=L->next;
	}
} 

//β�巨����������
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
	r->next=NULL;   //β���ָ���ÿ�
	return L; 
}  

/*�㷨˼��:��A��B������,�ɴӵ�һ��Ԫ�������αȽ�A��B�����Ԫ��,��Ԫ��ֵ
����,��ֵС��ָ��������,��Ԫ��ֵ���,�򴴽�һ��ֵ����������Ԫ��ֵ���µĽ��,
ʹ��β�巨���뵽�µ�������,������ԭ��ָ�����һλ,ֱ������һ�������������β��*/
LinkList Get_Common(LinkList &A,LinkList &B){
	//���㷨����������A��B�Ĺ���Ԫ�صĵ�����C
	LNode *p=A->next,*q=B->next,*r,*s;
	LinkList C=(LinkList)malloc(sizeof(LNode)); //������C
	r=C; //rʼ��ָ��C��β���
	while(p!=NULL&&q!=NULL){
		if(p->data<q->data)
			p=p->next; //��A�ĵ�ǰԪ�ؽ�С,����ָ��
		else if(p->data>q->data)
			q=q->next; //��B�ĵ�ǰԪ�ؽ�С,����ָ��
		else{ //�ҵ�����Ԫ�� 
			s=(LNode*)malloc(sizeof(LNode));
			s->data=p->data; //���Ʋ������*s
			r->next=s; //��*s����C��(β�巨)
			r=s;
			p=p->next;
			q=q->next; 
		} 
	} 
	r->next=NULL;
	return C;
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
	r=Get_Common(l,m);
	print(r);
	return 0;
}  

/*
1 3 4 5 6 7 8 9 10 9999
1 2 3 7 8 9 10 11 9999
�����е�Ԫ����:
1 3 4 5 6 7 8 9 10
1 2 3 7 8 9 10 11
1 3 7 8 9 10
*/


  
