/*��C={a1,b1,a2,b2,...,an,bn}Ϊ���Ա�,���ô�ͷ����hc��������,���һ��
�͵��㷨,������Ϊ�������Ա�,ʹ��A={a1,a2,...,an},B={bn,...,b2,b1}*/
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

LinkList DisCreat_2(LinkList &A){
	LinkList B=(LinkList)malloc(sizeof(LNode));//����B���ͷ
	B->next=NULL;//B��ĳ�ʼ��
	LNode *p=A->next,*q; //pΪ����ָ��
	LNode *ra=A; //raʼ��ָ��A��β���
	while(p!=NULL){
		ra->next=p;
		ra=p; //��*p����A�ı�β
		p=p->next;
		q=p->next; //ͷ���,*p������,�����q����*p�ĺ��
		p->next=B->next; //��*p���뵽B��ǰ��
		B->next=p;
		p=q; 
	} 
	ra->next=NULL; //Aβ����next���ÿ�
	return B; 
}
/*����ͷ�巨����ڵ��,*p��ָ�����Ѹı�,�����������������̽����������,�Ӷ������㷨����*/ 

int main(void){ 
	int min,max;
	LinkList l,q,m;
	l=CreatList2(q);
	printf("�����е�Ԫ����:\n");
	print(l);
	printf("\n");
	m=DisCreat_2(l);
	print(m);
	return 0;
}  

/*
1 2 3 4 5 6 7 8 9 10 9999
�����е�Ԫ����:
1 2 3 4 5 6 7 8 9 10
10 8 6 4 2
*/
