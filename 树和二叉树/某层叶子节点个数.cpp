//计算第k层叶子节点数 
#include<stdio.h>
#include<stdlib.h>
typedef struct BiTreeNode
{
    char data;
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
}BiTreeNode,*BiTree;
  
void CreateBiTree(BiTree &t)
{
    char ch;
    scanf("%c",&ch);
    if(ch == '#')
      t=NULL;
    else
    {
        t = (BiTree)malloc(sizeof(BiTreeNode));
        if(!t)
        {
            printf("分配内存出错!\n");
            return;
        }
        t->data = ch;
        CreateBiTree(t->lchild);
        CreateBiTree(t->rchild);
    }
} 
 
int GetBTreeKthLevelLeafNodesTotal(BiTree T,int k)
{
    if(T==NULL || k <= 0)
      return 0;
    if(T!=NULL && k==1)
    {
      if(T->lchild==NULL && T->rchild==NULL)
        return 1;
      else
        return 0;
    }
    return (GetBTreeKthLevelLeafNodesTotal(T->lchild,k-1)+GetBTreeKthLevelLeafNodesTotal(T->rchild,k-1));
}
  
int main()
{
    BiTree T=NULL;
    CreateBiTree(T);
    int k,h;
    scanf("%d",&k);
    h=GetBTreeKthLevelLeafNodesTotal(T,k);
    printf("%d\n",h);
    return 0;
}
