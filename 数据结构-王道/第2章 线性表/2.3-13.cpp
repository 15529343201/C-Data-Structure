/*������������Ԫ��ֵ�����������е����Ա�,���Ե�������ʽ�洢�����д�㷨������
��������鲢Ϊһ����Ԫ��ֵ�ݼ��������еĵ�����,��Ҫ������ԭ������������Ľ��
��Ź鲢��ĵ�����*/
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

/*�㷨˼��:���������Ѿ���Ԫ��ֵ������������,����ϲ�ʱ,���ӵ�һ���������бȽ�,
��С�Ľ������������,ͬʱ���ƹ���ָ�롣������Ҫ��������Ԫ��ֵ�ݼ���������,����
����Ľ���Ӧ�ò���ͷ�巨���ȽϽ�����,���ܻ���һ������ǿ�,��ʱ��ͷ�巨��ʣ�µĽ��
���β����������м��ɡ�*/
void MergeList(LinkList &La,LinkList &Lb){
	//�ϲ�����������������(��ͷ���),��ʹ�ϲ��������ݼ�����
	LNode *r,*pa=La->next,*pb=Lb->next; //�ֱ��Ǳ�La��Lb�Ĺ���ָ��
	La->next=NULL; //La��Ϊ��������ͷָ��,�Ƚ���������ʼ��Ϊ��
	while(pa&&pb){ //�����������Ϊ��ʱ,ѭ��
		if(pa->data<=pb->data){  
			r=pa->next; //r�ݴ�pa�ĺ�̽��ָ�� 
			pa->next=La->next;
			La->next=pa; //��pa������ڽ������,ͬʱ����(ͷ�巨)
			pa=r; //�ָ�paΪ��ǰ���ȽϽ�� 
		}
		else{
			r=pb->next; //r�ݴ�pb�ĺ�̽��ָ��
			pb->next=La->next;
			La->next=pb; //��pb������ڽ������,ͬʱ����(ͷ�巨)
			pb=r; //�ָ�pbΪ��ǰ���ȽϽ�� 
		}
	} 
	if(pa) //ͨ������»�ʣһ������ǿ�,����ʣ�µĲ���
		pb=pa;
	while(pb){ //����ʣ�µ�һ���ǿ����� 
		r=pb->next; //���β��뵽La��(ͷ�巨)
		pb->next=La->next;
		La->next=pb;
		pb=r; 
	} 
	free(Lb);
} 
/*�����費�������鸨���ռ��ʹ��,����Ƚ���������ݸ�����������,�ٲ���ʱ�临�Ӷ�Ϊ
O(nlongn)�������㷨��������,Ȼ������Ԫ�����,ʱ�临�Ӷ�ΪO(nlogn)��*/
 
int main(void){ 
	int min,max;
	LinkList l,q,m,n;
	l=CreatList2(q);
	m=CreatList2(n);
	printf("�����е�Ԫ����:\n");
	print(l);
	printf("\n");
	print(m);
	printf("\n");
	MergeList(l,m);
	print(l);
	return 0;
}  

/*
1 3 5 7 9 9999
2 4 6 8 10 9999
�����е�Ԫ����:
1 3 5 7 9
2 4 6 8 10
10 9 8 7 6 5 4 3 2 1
*/

 
