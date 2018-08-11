/*���һ���㷨�����жϴ�ͷ����ѭ��˫�����Ƿ�Գ�*/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{ //���嵥����������
	ElemType data;    //������ 
	struct LNode *next,*prior;  //ǰ���ͺ��ָ�� 
}DNode,*DLinkList;

DLinkList CreatList(int n){
	int m;
	//����ͷ���
	DLinkList s1=(DLinkList)malloc(sizeof(DNode));
	s1->prior=NULL;
	s1->next=NULL;
	DNode *r=s1;
	//β�巨��������
	for(int i = 0;i < n;i++){
		DNode *s=(DNode*)malloc(sizeof(DNode));
		scanf("%d",&m);
		s->data=m;
		s->prior=r;
		s->next=s1;
		r->next=s;
		s1->prior=s;
		r=s;
	} 
	return s1;
}

/*�㷨˼��:��p��������ɨ��,q��������ɨ��,ֱ������ָ��ͬһ���(p==q,��ѭ��˫����
�н�����Ϊ����ʱ)������(p->next=q��q->prior=p,��ѭ��˫�����н�����Ϊż��ʱ)
Ϊֹ,��������ָ���ֵ��ͬ,�����������ȥ,���򷵻�0�����Ƚ�ȫ�����,�򷵻�1.*/
int Symmetry(DLinkList &L){
	//���㷨����ͷɨ��ѭ��˫����,���ж������Ƿ�Գ�
	DNode *p=L->next,*q=L->prior; //��ͷ����ָ��
	while(p!=q&&q->next!=p) {//ѭ����������
		if(p->data==q->data){ //��ָ���ֵ��ͬ������Ƚ� 
			p=p->next;
			q=q->prior;
		}
		else
			return 0;
	} 
	return 1;
}
	
int main(void){
	int n;
	DLinkList l;
	printf("��������Ҫ�������ĸ���:\n");
	scanf("%d",&n);
	l=CreatList(n);
	if(Symmetry(l))
		printf("�Գ�");
	else
	 	printf("���Գ�"); 
	return 0;
}

/*
��������Ҫ�������ĸ���:
5
1 2 3 2 1
�Գ�

��������Ҫ�������ĸ���:
4
1 2 2 1
�Գ�

��������Ҫ�������ĸ���:
5
1 2 3 2 4
���Գ�
*/
