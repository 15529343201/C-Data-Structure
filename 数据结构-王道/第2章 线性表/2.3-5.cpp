//�Ա�д�㷨����ͷ���ĵ�����͵�����,��ν"�͵�"��ָ�����ռ临�Ӷ�ΪO(1)
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

/*�ⷨһ:��ͷ���ժ��,Ȼ��ӵ�һ����㿪ʼ,����ǰ���뵽ͷ���ĺ���(ͷ�巨����������),
ֱ�����һ�����Ϊֹ,��ʵ�������������*/
LinkList Reverse_1(LinkList L){
	//L�Ǵ�ͷ���ĵ�����,���㷨��L�͵�����
	LNode *p,*r;   //pΪ����ָ��,rΪp�ĺ��,�Է�����
	p=L->next;  //�ӵ�һ��Ԫ�ؽ�㿪ʼ
	L->next=NULL; //�Ƚ�ͷ���L��next����ΪNULL
	while(p!=NULL){  //���ν�Ԫ�ؽ��ժ�� 
		r=p->next; //�ݴ�p�ĺ��
		p->next=L->next;  //��p�����뵽ͷ���֮��
		L->next=p;
		p=r; 
	} 
	return L;
} 

/*�ⷨ��:����pre,p��rָ��3�����ڵĽ��,����ͼ��ʾ�����辭�����ɲ���,*pre֮ǰ�Ľ���ָ�붼�ѵ���
���,���ǵ�next��ָ����ԭǰ����㡣������*p����next��ָ��*pre���,ע�⵽һ������ָ���ָ���,*p
�ĺ�̽������ͶϿ���,Ϊ����Ҫ��r��ָ��ԭ*p�ĺ�̽�㡣����ʱ��Ҫע������:һ���ڴ����һ�����ʱ,
Ӧ����next����ΪNULL,������ָ��ͷ���(��Ϊ������Ϊ�±��Ϊ���);�����ڴ��������һ������,��Ҫ��
ͷ����ָ��ָ������*/
LinkList Reverse_2(LinkList L){
	//���α������Ա�L,�������ָ�뷴ת
	LNode *pre,*p=L->next,*r=p->next;
	p->next=NULL; //�����һ�����
	while(r!=NULL){ //rΪ��,��˵��pΪ���һ����� 
		pre=p; //���μ�������
		p=r;
		r=r->next;
		p->next=pre; //ָ�뷴ת 
	} 
	L->next=p; //�������һ�����
	return L; 
}
 
int main(void){ 
	LinkList l,q;
	l=CreatList2(q);
	printf("�����е�Ԫ����:\n");
	print(l);
	printf("\n");
	Reverse_1(l);
	print(l);
	printf("\n");
	Reverse_2(l);
	print(l);
	return 0;
} 

/*
1 2 3 4 5
9999
�����е�Ԫ����:
1 2 3 4 5
5 4 3 2 1
1 2 3 4 5
*/
