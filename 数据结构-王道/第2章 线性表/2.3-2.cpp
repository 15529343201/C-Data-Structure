//�ڴ�ͷ���ĵ�������L��,ɾ������ֵΪx�Ľ��,���ͷ���ռ�,����ֵΪx�Ľ�㲻Ψһ,�Ա�д�㷨��ʵ������������
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

//ͷ�巨����������
LinkList CreatList1(LinkList &L){
	//�ӱ�β����ͷ������������L,ÿ�ξ���ͷ���֮�����Ԫ��
	LNode *s;
	int x;
	L=(LinkList)malloc(sizeof(LNode));     //����ͷ���
	L->next=NULL;                          //��ʼΪ������
	scanf("%d",&x);                        //�������ֵ
	while(x!=9999){                        //����9999��ʾ���� 
		s=(LNode*)malloc(sizeof(LNode));   //�����½��
		s->data=x;
		s->next=L->next;
		L->next=s;                         //���½��������,LΪͷָ��
		scanf("%d",&x); 
	} 
	return L;
} 

/*�ⷨһ:��p��ͷ��βɨ�赥����,preָ��*p����ǰ������p��ָ����ֵΪx,��ɾ��,����p������һ�����,
������pre,pָ��ͬ������һ����㡣*/
/*���㷨��������������ɾ������ĳ�����������н��,����������ǽ���ֵΪx��ʵ����,�������
�ǿ�������ָ����,ֻҪ�޸�if��������,����,����Ҫ��ɾ��ֵ����mink��maxk֮�����н��,��ֻ�轫
if����޸�Ϊif(p->data>mink && p->data<maxk)*/ 
void Del_X_1(LinkList &L,ElemType x){
	//LΪ��ͷ���ĵ�����,���㷨ɾ��L������ֵΪx�Ľ��
	LNode *p=L->next,*pre=L,*q;//��p��pre�ĳ�ʼֵ
	while(p!=NULL){
		if(p->data==x){
			q=p; //qָ��ý��
			p=p->next;
			pre->next=p;  //ɾ��*q���
			free(q);      //�ͷ�*q���Ŀռ� 
		}
		else{  //����pre��pͬ������ 
			pre=p;
			p=p->next;
		}
	} 
}

/*�ⷨ��:����β�巨������������pָ��ɨ��L�����н��,����ֵ��Ϊxʱ�������ӵ�L֮��,�������ͷš�*/
void Del_X_2(LinkList &L,ElemType x){
	//LΪ��ͷ���ĵ�����,���㷨ɾ��L������ֵΪx�Ľ��
	LNode *p=L->next,*r=L,*q; //rָ��β���,���ֵΪͷ���
	while(p!=NULL){
		if(p->data!=x){ //*p���ֵ��Ϊxʱ�������ӵ�Lβ�� 
			r->next=p;
			r=p;
			p=p->next;  //����ɨ�� 
		}
		else{ //*p���ֵΪxʱ�����ͷ� 
			q=p;
			p=p->next;  //����ɨ��
			free(q);    //�ͷſռ� 
		} 
	} 
	r->next=NULL;   //�����������β���ָ��ΪNULL 
} 

//���������㷨ɨ��һ������,ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)
 
int main(void){
	int x;
	LinkList l,q;
	l=CreatList1(q);
	printf("�����е�Ԫ����:\n");
	print(l);
	printf("��������Ҫɾ����Ԫ��:\n");
	scanf("%d",&x);
	//Del_X_1(l,x);
	Del_X_2(l,x); 
	print(l); 
	return 0;
}

/*
del_x_1:
1 2 2 3 4 5 6 7 8 9 10 9999
�����е�Ԫ����:
10 9 8 7 6 5 4 3 2 2 1 ��������Ҫɾ����Ԫ��:
9
10 8 7 6 5 4 3 2 2 1
del_x_2:
1 2 3 4 8 2 9 3 10 9999
�����е�Ԫ����:
10 3 9 2 8 4 3 2 1 ��������Ҫɾ����Ԫ��:
3
10 9 2 8 4 2 1
*/
