//��LΪ��ͷ���ĵ�����,��д�㷨ʵ�ִ�β��ͷ�������ÿ���ڵ��ֵ
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{ //���嵥����������
	ElemType data;    //������ 
	struct LNode *next;  //ָ���� 
}LNode,*LinkList;

void print(LinkList L){
	while(L){
		printf("%d ",L->data);
		L=L->next;
	}
} 

//β�巨����������
LinkList CreatList2(LinkList &L){
	//�ӱ�ͷ����β����������L,ÿ�ξ��ڱ�β����Ԫ��
	int x,y; 
	L=(LinkList)malloc(sizeof(LNode));
	scanf("%d",&y);
	L->data=y;
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

/*�������� ջ�Ļ������� �ݹ�*/
//ÿ������һ�����ʱ,�ȵݹ����������Ľ��,������ý������,��������ͷ��������
void R_Print(LinkList L){
	//��β��ͷ���������L��ÿ������ֵ
	if(L->next!=NULL){
		R_Print(L->next); //�ݹ� 
	} 
	printf("%d ",L->data);  //������� 
} 

int main(void){
	int x;
	LinkList l,q;
	l=CreatList2(q);
	printf("�����е�Ԫ����:\n");
	print(l);
	printf("\n");
	R_Print(l);
	return 0;
}

/*
1 2 3 4 5 9999
�����е�Ԫ����:
1 2 3 4 5
5 4 3 2 1
*/
