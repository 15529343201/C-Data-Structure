//��һ����ͷ���ĵ�����L,���һ���㷨ʹ��Ԫ�ص�������
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

/*�㷨˼��:����ֱ�Ӳ��������㷨˼��,�ȹ���ֻ��һ�����ݽ�����������,Ȼ������
ɨ�赥������ʣ�µĽ��*p(ֱ��p==NULLΪֹ),���������ͨ���Ƚϲ��Ҳ���*p��ǰ�����
*pre,Ȼ��*p���뵽*pre֮��*/
void Sort(LinkList &L){
	//���㷨ʵ�ֽ�������Ľ������,ʹ���������
	LNode *p=L->next,*pre;
	LNode *r=p->next;  //r����*p��̽��ָ��,�Ա�֤������
	p->next=NULL; //����ֻ��һ�����ݽ��������
	p=r;
	while(p!=NULL){
		r=p->next;  //����*p�ĺ�̽��ָ��
		pre=L;
		while(pre->next!=NULL&&pre->next->data<p->data)
			pre=pre->next;   //��������в��Ҳ���*P��ǰ�����*pre
		p->next=pre->next;  //��*p���뵽*pre֮��
		pre->next=p;
		p=r; //ɨ��ԭ��������ʣ�µĽ�� 
	} 
} 

int main(void){ 
	LinkList l,q;
	l=CreatList2(q);
	printf("�����е�Ԫ����:\n");
	print(l);
	printf("\n"); 
	printf("����������Ԫ����:\n");
	Sort(l);
	print(l);
	return 0;
}

/*
1 3 2 6 2 7 3 9 0 9999
�����е�Ԫ����:
1 3 2 6 2 7 3 9 0
����������Ԫ����:
0 1 2 2 3 3 6 7 9
*/
