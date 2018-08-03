//��������������,��д�㷨�ҳ���������Ĺ������
/*���:�����������й������,Ҳ����˵���������ĳһ��㿪ʼ,���ǵ�next��ָ��ͬһ����㡣
����ÿ����������ֻ��һ��next��,��˴ӵ�һ��������㿪ʼ,֮���������еĽ�㶼���غϵ�,
�������ٳ��ֲַ档����,�����й������������غϵĵ�����,������״��������Y,����������X.
	���⼫�������뵽"��"����:�ڵ�һ��������˳�����ÿ�����,ÿ����һ�����,�ڵڶ���������
˳��������н��,����ҵ�������ͬ�Ľ��,���Ǿ��ҵ������ǵĹ�����㡣��Ȼ,���㷨��ʱ�临��
��ΪO(len1*len2)
	��������������ȥѰ��һ������ʱ�临�Ӷȵ��㷨���Ȱ������:����ж���������������û��
�������?Ӧע�⵽����һ����ʵ:�������������һ���������,��ô�ù������֮������н�㶼��
�غϵ�,�����ǵ����һ������Ȼ���غϵġ����,�����ж����������ǲ������غϵĲ���,ֻҪ�ֱ�
���������������һ����㡣�������β�����һ����,˵�������й������,������������û�й����Ľ�㡣
	Ȼ��,�������˼·��,˳�������������β����ʱ��,�����ܱ�֤������������ͬʱ����β��㡣
������Ϊ���������Ȳ�һ��һ����������һ���������һ������k�����,�������ڳ��������ϱ���k�����,
֮����ͬ������,��ʱ���Ǿ��ܱ�֤ͬʱ�������һ������ˡ�������������ӵ�һ��������㿪ʼ��
�����β���,��һ�������غϵġ����,���ǿ϶�Ҳ��ͬʱ�����һ�������ġ������ڱ�����,��һ��
��ͬ�Ľ����ǵ�һ�������Ľ�㡣
	�����˼·��,������Ҫ�ֱ������������õ����ǵĳ���,������������ȵĲ�ڳ����������ȱ�������
֮������֮��,��ͬ��������������,ֱ���ҵ���ͬ�Ľ��,����һֱ�������������ʱ,�÷�����ʱ��
���Ӷ�ΪO(len1+len2)��*/
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

//������� 
int Length(LinkList &L){
	int j=0;
	LNode *p;
	p=L->next;
	while(p!=NULL)
	{
		p=p->next;
		j++;
	}
	return j;
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

LinkList Search_1st_Common(LinkList L1,LinkList L2){
	//���㷨ʵ�������Ե�ʱ�����ҵ�����������ĵ�һ���������
	int len1=Length(L1),len2=Length(L2); //������������ı�
	int dist;
	LinkList longList,shortList;  //�ֱ�ָ��ϳ��ͽ϶̵�����
	if(len1>len2){
		longList=L1->next;
		shortList=L2->next;
		dist=len1-len2;
	} 
	else{
		longList=L2->next;
		shortList=L1->next;
		dist=len2-len1;
	}
	while(dist--){
		longList=longList->next; //���������ȱ�������dist�����,Ȼ��ͬ�� 
	}
	while(longList!=NULL){  //Ѱ�ҹ�ͬ��� 
		if(longList==shortList){ //�ҵ���һ��������� 
			printf("success");
			return longList;
		}
		else{ //����ͬ��Ѱ�� 
			longList=longList->next;
			shortList=shortList->next;
		}
	}
	return NULL;
} 

int main(void){ 
	int min,max;
	LinkList l1,l2,q1,q2,p;
	l1=CreatList2(q1);
	l2=CreatList2(q2);
	printf("�����е�Ԫ����:\n");
	print(l1);
	printf("\n");
	print(l2);
	printf("\n");
	Search_1st_Common(l1,l2);
	return 0;
}
