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
 
//二叉树结点及其层序遍历 
void PreOrder(BiTree T,int i)
{
    if(T)
     {
        printf("(%c,%d)",T->data,i);
        PreOrder(T->lchild,i+1);
        PreOrder(T->rchild,i+1);
     }
}
  
int main()
{
    BiTree T=NULL;
    CreateBiTree(T);
    PreOrder(T,1);
    printf("\n");
    return 0;
}
