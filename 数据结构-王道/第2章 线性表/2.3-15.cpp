/*已知两个链表A和B分别表示两个集合,其元素递增排列。编制函数,
求A和B的交集,并存放于A链表中*/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{ //定义单链表结点类型
	ElemType data;    //数据域 
	struct LNode *next;  //指针域 
}LNode,*LinkList;

void print(LinkList L){
	while(L->next){
		printf("%d ",L->next->data);
		L=L->next;
	}
} 

//尾插法建立单链表
LinkList CreatList2(LinkList &L){
	//从表头到表尾建立单链表L,每次均在表尾插入元素
	int x; 
	L=(LinkList)malloc(sizeof(LNode));
	LNode *s,*r=L;   //r为表尾指针
	scanf("%d",&x);
	while(x!=9999){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;  //r指向新的表尾结点
		scanf("%d",&x); 
	} 
	r->next=NULL;   //尾结点指针置空
	return L; 
}  

/*算法思想:采用归并的思想,设置两个工作指针pa和pb,对两个链表进行归并扫描,只有同时出现在两集合中的
元素才链接到结果表中且仅保留一个,其他的结点全部释放。当一个链表遍历完毕后,释放另一个表中剩下的全部结点*/
LinkList Union(LinkList &la,LinkList &lb){
	LinkList pa,pb,pc,u;
	pa=la->next; //设工作指针分别为pa和pb
	pb=lb->next;
	pc=la; //结果表中当前合并结点的前驱指针 
	while(pa&&pb){
		if(pa->data==pb->data){ //交集并入结果表中 
			pc->next=pa; //A中结点链接到结果表
			pc=pa;
			pa=pa->next;
			u=pb; //B中结点释放 
			pb=pb->next;
			free(u); 
		}
		else if(pa->data<pb->data){ //若A中当前结点值小于B中当前结点值 
			u=pa;
			pa=pa->next; //后移指针 
			free(u); //释放B中当前结点 
		}
		else{ //若B中当前值小于A中当前结点值 
			u=pb; 
			pb=pb->next; //后移指针
			free(u); //释放B中当前结点 
		}
	}
	while(pa){ //B已遍历完,A未完 
		u=pa;
		pa=pa->next;
		free(u);
	}
	while(pb){ //A已遍历完,B未完 
		u=pb;
		pb=pb->next;
		free(u);
	}
	pc->next=NULL; //置结果链表尾指针为NULL
	free(lb);
	return la; 
}
/*链表归并类型的题在各学校历年真题中出现的频率很高,故应扎实掌握解决此类问题的思想。
该算法的时间复杂度为O(len1+len2),空间复杂度为O(1)。*/ 

int main(void){ 
	int min,max;
	LinkList l,q,m,n,r;
	l=CreatList2(q);
	m=CreatList2(n);
	printf("链表中的元素是:\n");
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
链表中的元素是:
1 3 4 5 6 7 8
1 2 4 6 8
1 4 6 8
*/
