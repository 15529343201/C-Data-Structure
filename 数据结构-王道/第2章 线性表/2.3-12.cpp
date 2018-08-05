/*��һ��������������Ա���,����ֵ��ͬ��Ԫ�ش��ڡ����洢��ʽΪ������
,����㷨ȥ����ֵ��ͬ��Ԫ��,ʹ���в������ظ���Ԫ�ء�����
(7,10,10,21,30,42,42,42,51,70)������(7,10,21,30,42,51,70)*/
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

/*�㷨˼��:�����������,������ֵͬ��Ľ�㶼�����ڵġ���pɨ�����������L,
��*p����ֵ��������̽���ֵ��,��ɾ������,����p������һ����㡣*/ 
void Del_Same(LinkList &L){
	//L�ǵ�������ĵ�����,���㷨ɾ��������ֵ��ͬ��Ԫ��
	LNode *p=L->next,*q; //pΪɨ�蹤��ָ��
	if(p==NULL)
		return;
	while(p->next!=NULL){
		q=p->next; //qָ��*p�ĺ�̽�� 
		if(p->data==q->data){ //�ҵ��ظ��Ľ��ֵ 
			p->next=q->next; //�ͷ�*q���
			free(q); //�ͷ���ͬԪ��ֵ�Ľ�� 
		}
		else
			p=p->next;
	} 
}
/*ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
����Ҳ����β�巨,��ͷ���ժ��,Ȼ��ӵ�һ��㿪ʼ,�������Ѿ������������
�����һ�����Ƚ�,���������ֱ�Ӳ���,���򽫵�ǰ�����Ľ��ɾ����������һ��
���,ֱ�����һ�����Ϊֹ*/
 
int main(void){ 
	int min,max;
	LinkList l,q,m;
	l=CreatList2(q);
	printf("�����е�Ԫ����:\n");
	print(l);
	printf("\n");
	Del_Same(l);
	print(l);
	return 0;
}  

/*
7 10 10 21 30 42 42 42 51 70 9999
�����е�Ԫ����:
7 10 10 21 30 42 42 42 51 70
7 10 21 30 42 51 70
*/

