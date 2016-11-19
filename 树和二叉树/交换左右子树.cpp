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
            printf("·ÖÅäÄÚ´æ³ö´í!\n");
            return;
        }
        t->data = ch;
        CreateBiTree(t->lchild);
        CreateBiTree(t->rchild);
    }
} 
 
void exchange(BiTree T)
{
    BiTree temp=NULL;
    if(T->lchild==NULL && T->rchild==NULL)
      return;
    else
    {
        temp=T->lchild;
        T->lchild=T->rchild;
        T->rchild=temp;
    }
    if(T->lchild)
      exchange(T->lchild);
    if(T->rchild)
      exchange(T->rchild);
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
    CreateBiTree(T);
    exchange(T);
    PreOrder(T);
    printf("\n");
    InOrder(T);
    printf("\n");
    PostOrder(T);
    printf("\n");
    return 0;
}
