//���һ���ݹ��㷨,ɾ������ͷ���ĵ�����L������ֵΪx�Ľ�� 
/*���:
  ��f(L,x)�Ĺ�����ɾ����LΪ�׽��ָ��ĵ�����������ֵ����x�Ľ��,����Ȼ��f(L->next,x)��
������ɾ����L->nextΪ�׽��ָ��ĵ�����������ֵ����x�Ľ��.�ɴ�,�����Ƴ��ݹ�ģ������:
	��ֹ����:f(L,x)=�����κ�����;               ��LΪ�ձ�
	�ݹ�����:f(L,x)=ɾ��*L���;f(L->next,x);    ��L->data==x 
			 f(L,x)=f(L->next,x);               �������
�㷨��Ҫ����һ���ݹ鹤��ջ,���ΪO(n),ʱ�临�Ӷ�ΪO(n)���ж�����Ϊֱ��free��p���
����ɶ���,ʵ������ΪLΪ����,��ֱ�Ӷ�ԭ����Ĳ���,��˲�������� 
*/ 
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{ //���嵥����������
	ElemType data;    //������ 
	struct LNode *next;  //ָ���� 
}LNode,*LinkList;

//����n���ڵ������
LinkList CreatLinkList(int n){
	LinkList p,r,list=NULL;
	ElemType e;
	int i;
	for(i=1;i<=n;i++){
		scanf("%d",&e); //�����������
		p=(LinkList)malloc(sizeof(LNode));//Ϊ�½��Ľ�㿪���ڴ�ռ�
		p->data=e;
		p->next=NULL;
		if(!list)
			list=p;
		else
			r->next=p;
		r=p; 
	}
	return list;
} 

void Del_X_3(LinkList &L,ElemType x){
	//�ݹ�ʵ���ڵ�����L��ɾ��ֵΪx�Ľ��
	LNode *p; //pָ���ɾ�����
	if(L==NULL) //�ݹ����
		return;
	if(L->data==x){ //��L��ָ����ֵΪx 
		p=L;   //ɾ��*L,����Lָ����һ�����
		L=L->next;
		free(p);
		Del_X_3(L,x); //�ݹ���� 
	} 
	else //��L��ָ����ֵ��Ϊx 
		Del_X_3(L->next,x);//�ݹ���� 
}

//��ӡ���� 
void print(LinkList L){
	while(L){
		printf("%d ",L->data);
		L=L->next;
	}
}

int main(void){
	int i,e,m;
	LinkList l,q;
	printf("�����뽨�����ĸ���:\n");
	scanf("%d",&e);
	l=CreatLinkList(e);
	printf("��������Ҫɾ���ĵ���ֵ:\n");
	scanf("%d",&m);
	Del_X_3(l,m);
	print(l);
	return 0;
}

/*
�����뽨�����ĸ���:
10
1 2 3 2 2 2 4 7 8 19
��������Ҫɾ���ĵ���ֵ:
2
1 3 4 7 8 19
*/

