/*��һ����ͷ���ĵ�����A�ֽ�Ϊ������ͷ���ĵ�����A��B,ʹ��A���к���ԭ
�������Ϊ������Ԫ��,��B���к���ԭ�������Ϊż����Ԫ��,�ұ��������˳�򲻱�*/
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

/*�㷨˼��:����һ��������ű���(��ֵΪ0),ÿ����һ���������Զ���1,Ȼ��������
����ż�Խ������뵽A���B���С��ظ����ϲ���ֱ����β*/
LinkList DisCreat_1(LinkList &A){
	//����A�н�㰴��ŵ���ż�Էֽ⵽��A���B��
	int i;
	LinkList B,p;
	i=0; //i��¼��A�н������
	B=(LinkList)malloc(sizeof(LNode)); //����B���ͷ
	B->next=NULL; //B��ĳ�ʼ��
	LNode *ra=A,*rb=B; //ra��rb���ֱ�ָ�򽫴�����A���B���β���
	p=A->next; //pΪ������ָ��,ָ����ֽ�Ľ��
	A->next=NULL; //�ÿ��µ�A��(����A��ͷ���) 
	while(p!=NULL){ 
		i++;
		if(i%2==0){  //�������Ϊż���������� 
			rb->next=p; //��B��β�����½�� 
			rb=p;  //rbָ���µ�β��� 
		}
		else{ //����ԭ���Ϊ�����Ľ�� 
			ra->next=p; //��A��β�����½�� 
			ra=p;
		}
		p=p->next; //��p�ָ�Ϊָ���µĴ������� 
	} 
	ra->next=NULL;
	rb->next=NULL;
	return B;
} 
/*Ϊ�˱���ԭ������е�˳��,�������β�巨��������������,���㷨��ȫ���Բ���������ű�����
whileѭ���еĴ����Ϊ�������뵽��A�кͽ���һ�����뵽��B��,����while�е�һ����Ľ��
���������Ž��,�ڶ�����Ľ�����ż���Ž�㡣*/ 

int main(void){ 
	int min,max;
	LinkList l,q,m;
	l=CreatList2(q);
	printf("�����е�Ԫ����:\n");
	print(l);
	printf("\n");
	m=DisCreat_1(l);
	print(m);
	return 0;
} 
/*
1 2 3 4 5 6 9999
�����е�Ԫ����:
1 2 3 4 5 6
2 4 6
*/
