//先序中序建立二叉树
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//二叉树结点
typedef struct BiTNode
{
	char data;//数据
	struct BiTNode *lchild,*rchild;//左右孩子指针 
}BiTNode,*BiTree;

//先序序列
char PreArray[101];
//中序序列
char InArray[101];

/*
    PreS    先序序列的第一个元素下表
	PreE    先序序列的最后一个元素下标
	InS     中序序列的第一个元素下标
	InE     中序序列的最后一个元素下标
	PreArray先序序列数组
	InArray 中序序列数组
*/

void PreInCreateTree(BiTree &T,int PreS,int PreE,int InS,int InE)
{
	int RootIndex;
	//先序第一个字符
	T = (BiTree)malloc(sizeof(BiTNode));
	T->data = PreArray[PreS];
	//寻找该结点在中序序列中的位置
	for(int i = InS;i <= InE;i++)
	{
		if(T->data == InArray[i])
		{
			RootIndex = i;
			break;
		}
	}
	
	//根结点的左子树不为空
	if(RootIndex != InS)
	{
		//以根结点的左子树为根建树
		PreInCreateTree(T->lchild,PreS+1,(RootIndex-InS)+PreS,InS,RootIndex-1); 
	}
	else
	{
		T->lchild = NULL;
	}
	
	//根结点的右子树不为空
	if(RootIndex != InE)
	{
		//以根结点的右结点为根建树
		PreInCreateTree(T->rchild,PreS+1+(RootIndex-InS),PreE,RootIndex+1,InE); 
	}
	else
	{
		T->rchild = NULL;
	}
}

//后序遍历
void PostOrder(BiTree T)
{
	if(T->lchild != NULL)
	{
		//访问左子节点
		PostOrder(T->lchild); 
	}
	if(T->rchild != NULL)
	{
		//访问右子节点
		PostOrder(T->rchild); 
	}
	//访问根节点
	printf("%c",T->data); 
}

int main()
{
	while(scanf("%s",PreArray) != EOF)
	{
		BiTree T;
		scanf("%s",InArray);
		PreInCreateTree(T,0,strlen(PreArray)-1,0,strlen(InArray)-1);
		PostOrder(T);
		printf("\n"); 
	}
	return 0;
}	  
