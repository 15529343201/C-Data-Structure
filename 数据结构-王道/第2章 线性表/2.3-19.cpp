/*����һ����ͷ����ѭ��������,����ֵΪ�����������һ���㷨,
�����ҳ����н��ֵ��С�Ľ�㲢���,Ȼ�󽫸ý�����ɾ��,ֱ��������
��Ϊֹ,��ɾ����ͷ���*/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{ //���嵥����������
	ElemType data;    //������ 
	struct LNode *next;  //ָ���� 
}LNode,*LinkList;

void print(LinkList L){
	LinkList r=L->next;
	while(r!=L){
		printf("%d ",r->data);
		r=r->next;
	}
} 

//β�巨����ѭ��������
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
	r->next=L;   //β���ָ��ָ���ͷ 
	return L; 
}  
 
/*�㷨˼��:����ѭ��������L,�ڲ���ʱѭ��:ÿѭ�����β���һ����С���(��minpָ����Сֵ���,
minpreָ����ǰ�����)��ɾ����������ͷ�ͷ��㡣*/
void Del_All(LinkList &L){
	//���㷨ʵ��ÿ��ɾ��ѭ���������е���СԪ��,ֱ������Ϊ��Ϊֹ
	LNode *p,*pre,*minp,*minpre;
	while(L->next!=L){ //����,ѭ�� 
		p=L->next;
		pre=L; //pΪ����ָ��,preָ����ǰ��
		minp=p;
		minpre=pre; //minpָ����Сֵ���
		while(p!=L){ //ѭ��һ��,������Сֵ��� 
			if(p->data<minp->data){
				minp=p; //�ҵ�ֵ��С�Ľ��
				minpre=pre; 
			}
			pre=p; //������һ�����
			p=p->next; 
		} 
		printf("%d",minp->data); //�����Сֵ���Ԫ��
		minpre->next=minp->next; //��Сֵ���ӱ���"��"��
		free(minp); 
	} 
	free(L);//�ͷ�ͷ��� 
} 

int main(void){ 
	LinkList l,q;
	l=CreatList2(q);
	printf("�����е�Ԫ����:\n");
	print(l);
	Del_All(l);
	return 0;
}    

/*
3 1 5 8 7 2 9 4 9999
�����е�Ԫ����:
3 1 5 8 7 2 9 4 12345789
*/
