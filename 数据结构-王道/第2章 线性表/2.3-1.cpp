//设计一个递归算法,删除不带头结点的单链表L中所有值为x的结点 
/*解答:
  设f(L,x)的功能是删除以L为首结点指针的单链表中所有值等于x的结点,则显然有f(L->next,x)的
功能是删除以L->next为首结点指针的单链表中所有值等于x的结点.由此,可以推出递归模型如下:
	终止条件:f(L,x)=不做任何事情;               若L为空表
	递归主体:f(L,x)=删除*L结点;f(L->next,x);    若L->data==x 
			 f(L,x)=f(L->next,x);               其他情况
算法需要借助一个递归工作栈,深度为O(n),时间复杂度为O(n)。有读者认为直接free掉p结点
会造成断链,实际上因为L为引用,是直接对原链表的操作,因此不会断链。 
*/ 
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{ //定义单链表结点类型
	ElemType data;    //数据域 
	struct LNode *next;  //指针域 
}LNode,*LinkList;

//创建n个节点的链表
LinkList CreatLinkList(int n){
	LinkList p,r,list=NULL;
	ElemType e;
	int i;
	for(i=1;i<=n;i++){
		scanf("%d",&e); //输入结点的内容
		p=(LinkList)malloc(sizeof(LNode));//为新建的结点开辟内存空间
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
	//递归实现在单链表L中删除值为x的结点
	LNode *p; //p指向待删除结点
	if(L==NULL) //递归出口
		return;
	if(L->data==x){ //若L所指结点的值为x 
		p=L;   //删除*L,并让L指向下一个结点
		L=L->next;
		free(p);
		Del_X_3(L,x); //递归调用 
	} 
	else //若L所指结点的值不为x 
		Del_X_3(L->next,x);//递归调用 
}

//打印链表 
void print(LinkList L){
	while(L){
		printf("%d ",L->data);
		L=L->next;
	}
}

int main(void){
	int i,e,m;
	LinkList l,q;
	printf("请输入建立结点的个数:\n");
	scanf("%d",&e);
	l=CreatLinkList(e);
	printf("请输入你要删除的的数值:\n");
	scanf("%d",&m);
	Del_X_3(l,m);
	print(l);
	return 0;
}

/*
请输入建立结点的个数:
10
1 2 3 2 2 2 4 7 8 19
请输入你要删除的的数值:
2
1 3 4 7 8 19
*/

