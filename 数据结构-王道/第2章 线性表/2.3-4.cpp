//�Ա�д�ڴ�ͷ���ĵ�����L��ɾ��һ����Сֵ���ĸ�Ч�㷨(������Сֵ�����Ψһ��)
/*�㷨˼��:��P��ͷ��βɨ�赥����,preָ��*p����ǰ��,��minp����ֵ��С�Ľ���ָ��(��ֵΪp),
minpreָ��*minp����ǰ��(��ֵΪpre)��һ��ɨ��,һ�߱Ƚ�,��p->dataС��minp->data,��
p,pre�ֱ�ֵ��minp��minpre.��pɨ�����,minpָ����Сֵ���,minpreָ����Сֵ����ǰ�����,
�ٽ�minp��ָ���ɾ�����ɡ�*/ 
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

LinkList Delete_Min(LinkList &L){
	//L�Ǵ�ͷ���ĵ�����,���㷨ɾ������Сֵ���
	LNode *pre=L,*p=pre->next; //pΪ����ָ��,preָ����ǰ��
	LNode *minpre=pre,*minp=p; //������Сֵ��㼰��ǰ��
	while(p!=NULL){
		if(p->data<minp->data){
			minp=p;  //�ҵ���֮ǰ�ҵ�����Сֵ����С�Ľ��
			minpre=pre; 
		}
		pre=p;   //����ɨ����һ�����
		p=p->next; 
	} 
	minpre->next=minp->next;  // ɾ����Сֵ���
	free(minp);
	return L; 
}
int main(void){
	LinkList l,q;
	l=CreatList2(q);
	printf("�����е�Ԫ����:\n");
	print(l);
	printf("\n");
	printf("ɾ��������СֵԪ�غ���:\n");
	Delete_Min(l);
	print(l);
	return 0;
}

/*
1 2 0 3 9999
�����е�Ԫ����:
1 2 0 3
ɾ��������СֵԪ�غ���:
1 2 3
*/
