/*��֪��������A��B�ֱ��ʾ��������,��Ԫ�ص������С����ƺ���,
��A��B�Ľ���,�������A������*/
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

/*�㷨˼��:���ù鲢��˼��,������������ָ��pa��pb,������������й鲢ɨ��,ֻ��ͬʱ�������������е�
Ԫ�ز����ӵ���������ҽ�����һ��,�����Ľ��ȫ���ͷš���һ�����������Ϻ�,�ͷ���һ������ʣ�µ�ȫ�����*/
LinkList Union(LinkList &la,LinkList &lb){
	LinkList pa,pb,pc,u;
	pa=la->next; //�蹤��ָ��ֱ�Ϊpa��pb
	pb=lb->next;
	pc=la; //������е�ǰ�ϲ�����ǰ��ָ�� 
	while(pa&&pb){
		if(pa->data==pb->data){ //�������������� 
			pc->next=pa; //A�н�����ӵ������
			pc=pa;
			pa=pa->next;
			u=pb; //B�н���ͷ� 
			pb=pb->next;
			free(u); 
		}
		else if(pa->data<pb->data){ //��A�е�ǰ���ֵС��B�е�ǰ���ֵ 
			u=pa;
			pa=pa->next; //����ָ�� 
			free(u); //�ͷ�B�е�ǰ��� 
		}
		else{ //��B�е�ǰֵС��A�е�ǰ���ֵ 
			u=pb; 
			pb=pb->next; //����ָ��
			free(u); //�ͷ�B�е�ǰ��� 
		}
	}
	while(pa){ //B�ѱ�����,Aδ�� 
		u=pa;
		pa=pa->next;
		free(u);
	}
	while(pb){ //A�ѱ�����,Bδ�� 
		u=pb;
		pb=pb->next;
		free(u);
	}
	pc->next=NULL; //�ý������βָ��ΪNULL
	free(lb);
	return la; 
}
/*����鲢���͵����ڸ�ѧУ���������г��ֵ�Ƶ�ʺܸ�,��Ӧ��ʵ���ս�����������˼�롣
���㷨��ʱ�临�Ӷ�ΪO(len1+len2),�ռ临�Ӷ�ΪO(1)��*/ 

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
	r=Union(l,m);
	print(r);
	return 0;
}   

/*
1 3 4 5 6 7 8 9999
1 2 4 6 8 9999
�����е�Ԫ����:
1 3 4 5 6 7 8
1 2 4 6 8
1 4 6 8
*/
