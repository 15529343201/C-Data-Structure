#include<stdio.h>
#include<stdlib.h>
typedef struct BiTreeNode
{
	char data;
	struct BiTreeNode *lchild;
	struct BiTreeNode *rchild;
}BiTreeNode,*BiTree;

void CreateBiTree(BiTree *tree)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='.')
	  (*tree)=NULL;
	else
	 {
		if(!(*tree=(BiTree)malloc(sizeof(BiTreeNode))))
		  exit(-1);
		(*tree)->data=ch;
		CreateBiTree(&((*tree)->lchild));
		CreateBiTree(&((*tree)->rchild));
	 }
}

void PreOrder(BiTree T)
{
	if(T)
	 {
		printf("%c",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	 }
}

void InOrder(BiTree T)
{
	if(T)
	 {
		InOrder(T->lchild);
		printf("%c",T->data);
		InOrder(T->rchild);
	 }
}

void PostOrder(BiTree T)
{
	if(T)
	 {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c",T->data);
	 }
}

int main()
{
	BiTree T=NULL;
	printf("请输入您要建立的二叉树的先序扩展序列(用.表示空)\n");
	CreateBiTree(&T);
	printf("构造二叉树成功!\n");
	printf("先序遍历:");
	PreOrder(T);
	printf("\n中序遍历:");
	InOrder(T);
	printf("\n后序遍历:");
	PostOrder(T);
	printf("\n");
	return 0;
}
