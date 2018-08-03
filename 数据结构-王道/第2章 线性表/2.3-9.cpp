/*����һ����ͷ���ĵ�����,��headΪͷָ��,���ĽṹΪ(data,next),dataΪ����Ԫ��,nextΪָ��
��д���㷨:��������������������и���������Ԫ��,���ͷŽ����ռ�Ĵ洢�ռ�(Ҫ��:������ʹ��
������Ϊ�����ռ�)*/
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

/*�㷨˼��:��������б���,��ÿ�˱����в��ҳ������������СֵԪ��,������ͷŽ��
��ռ�ռ�;�ٲ��Ҵ�СֵԪ��,������ͷſռ�,�����ȥ,ֱ������Ϊ��,����ͷ�ͷ�����
ռ�洢�ռ�,���㷨��ʱ�临�Ӷ�ΪO(n^2)*/
void Min_Delete(LinkList &head){
	//head�Ǵ�ͷ���ĵ������ͷָ��,���㷨������˳������������е�����Ԫ��
	LinkList pre,u,p;
	while(head->next!=NULL){ //ѭ������ʣͷ��� 
		pre=head; //preΪԪ����Сֵ����ǰ������ָ��
		p=pre->next; //pΪ����ָ��
		while(p->next!=NULL){
			if(p->next->data<pre->next->data){
				pre=p;  //��ס��ǰ��Сֵ����ǰ��
			}
			p=p->next; 	
		}
		/*
		ͷ   1   2   3   4   5
		pre  p
		ͷ   1   2   3   4   5
							 p
		*/
		/*
		ͷ   5   4   3   2   1
		pre  p
			 pre p
			     pre p 
			         pre p
			             pre p
		*/	
		printf("%d",pre->next->data); //���Ԫ����Сֵ��������
		u=pre->next; //ɾ��Ԫ��ֵ��С�Ľ��,�ͷŽ��ռ�
		pre->next=u->next;
		free(u); 
	} 
	free(head); //�ͷ�ͷ��� 
}

int main(void){ 
	int min,max;
	LinkList l,q;
	l=CreatList2(q);
	printf("�����е�Ԫ����:\n");
	print(l);
	printf("\n");
	Min_Delete(l); 
	return 0;
} 

/*
1 2 3 4 5 9999
�����е�Ԫ����:
1 2 3 4 5
12345

5 4 3 2 1 9999
�����е�Ԫ����:
5 4 3 2 1
12345
*/

