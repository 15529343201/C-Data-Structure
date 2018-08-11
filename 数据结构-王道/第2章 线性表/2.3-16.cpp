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

/*�㷨˼��:��Ϊ�������������Ѵ�������������,��������������ĵ�һ����㿪ʼ,����Ӧ�������,
�����ָ��;����Ӧ���ݲ����,��A������ϴο�ʼ�ȽϽ��ĺ�̽�㿪ʼ,B�����Դӵ�һ����㿪ʼ�Ƚ�
,ֱ��B����β��ʾƥ��ɹ���A����β��B����δ��β��ʾʧ�ܡ�������Ӧ��סA����ÿ�εĿ�ʼ���,
�Ա�����ƥ��ʱ�ô����̿�ʼ��*/
int Pattern(LinkList &A,LinkList &B){
	//A��B�ֱ���������Ϊ�����ĵ�����,���㷨�ж�B�Ƿ���A��������
	LNode *p=A->next; //pΪA����Ĺ���ָ��
	LNode *pre=p; //pre��סÿ�˱Ƚ���A����Ŀ�ʼ���
	LNode *q=B->next; //q��B����Ĺ���ָ��
	while(p&&q){
		if(p->data==q->data){ //���ֵ��ͬ 
			p=p->next;
			q=q->next;
		}
		else{
			pre=pre->next; 
			p=pre; //A�����µĿ�ʼ�ȽϽ��
			q=B->next; //q��B�����һ����㿪ʼ 
		}
	} 
	if(q==NULL){ //B�Ѿ��ȽϽ��� 
		return 1;//˵��B��A�������� 
	}else{
		return 0; //B����A�������� 
	}
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
	if(Pattern(l,m))
		printf("B��A��������\n");
	else
		printf("B����A��������\n");
	return 0;
}    

/*
1 3 4 5 6 7 9 9999
3 4 5 6 9999
�����е�Ԫ����:
1 3 4 5 6 7 9
3 4 5 6
B��A��������

1 2 3 4 5 7 9999
1 3 5 9999
�����е�Ԫ����:
1 2 3 4 5 7
1 3 5
B����A��������
*/
