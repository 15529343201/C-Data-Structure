/*�����һ������ͷ���ĵ�����������Ԫ�ؽ�������ֵ����,�Ա�д
һ������,ɾ���������н��ڸ���������ֵ(��Ϊ������������)֮���Ԫ�ص�Ԫ��(������)*/
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

void RangeDelete(LinkList &L,int min,int max){
	LNode *pr=L,*p=L->next;  //p�Ǽ��ָ��,Pr����ǰ��
	while(p!=NULL){
		if(p->data>min&&p->data<max){ //Ѱ�ҵ���ɾ���,ɾ�� 
			pr->next=p->next;
			free(p);
			p=pr->next;
		}
		else{
			pr=p;
			p=p->next;
		}
	} 
}

int main(void){ 
	int min,max;
	LinkList l,q;
	l=CreatList2(q);
	printf("�����е�Ԫ����:\n");
	print(l);
	printf("����������ֵ(min,max),ɾ������ֵ��������֮���Ԫ��:\n");
	scanf("%d%d",&min,&max);
	RangeDelete(l,min,max);
	print(l);
	return 0;
}

/*
1 3 7 90 23 12 23 87 23 12 3 9999
�����е�Ԫ����:
1 3 7 90 23 12 23 87 23 12 3 ����������ֵ(min,max),ɾ������ֵ��������֮���Ԫ��:

3 88
1 3 90 3
*/
