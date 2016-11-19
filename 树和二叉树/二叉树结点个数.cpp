#include<stdio.h>
#include<stdlib.h>
typedef struct BiTreeNode
{
    char data;
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
}BiTreeNode,*BiTree;
 
//建立二叉树
void CreateBiTree(BiTree *tree)
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
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
 
//统计叶子结点数目
int LeafNum(BiTree tree)
{
    int LeafCount;
    if(tree==NULL)
      LeafCount=0;
    else if((tree->lchild==NULL) && (tree->rchild==NULL))
      LeafCount=1;
    else
      LeafCount=LeafNum(tree->lchild)+LeafNum(tree->rchild);
    return LeafCount;
}
 
//统计度为1结点的个数
int LeafCount1=0;
int LeafNum1(BiTree tree)
{
    if(tree!=NULL)
     {
        if((tree->lchild==NULL && tree->rchild!=NULL) ||
                    (tree->lchild!=NULL && tree->rchild==NULL))
          LeafCount1++;
        LeafNum1(tree->lchild);
        LeafNum1(tree->rchild);
     }
    return LeafCount1;
}
 
//统计度为2结点的个数
int LeafCount2=0;
int LeafNum2(BiTree tree)
{
    if(tree!=NULL)
     {
        if((tree->lchild!=NULL) && (tree->rchild!=NULL))
          LeafCount2++;
        LeafNum2(tree->lchild);
        LeafNum2(tree->rchild);
     }
    return LeafCount2;
}
 
//输出二叉树中的叶子结点
void OutPutdeafNode(BiTree tree)
{
    if(tree!=NULL)
     {
        OutPutdeafNode(tree->lchild);
        if(tree->lchild==NULL && tree->rchild==NULL)
          printf("%c",tree->data);
        OutPutdeafNode(tree->rchild);
     }
}
 
int main()
{
    BiTree T=NULL;
    CreateBiTree(&T);
    int number,number1,number2;
    number=LeafNum(T);
    number1=LeafNum1(T);
    number2=LeafNum2(T);
    printf("%d %d %d\n",number,number1,number2);
    OutPutdeafNode(T);
    return 0;
}
