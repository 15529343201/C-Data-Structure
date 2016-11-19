#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct BiTreeNode
{
    char data;
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
}BiTreeNode,*BiTree;
 
//建立二叉树 
void CreateBiTree(BiTree &t)
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
      t=NULL;
    else
    {
        t=(BiTree)malloc(sizeof(BiTreeNode));
        if(!t)
        {
            printf("内存分配错误!\n");
            return;
        }
        t->data=ch;
        CreateBiTree(t->lchild);
        CreateBiTree(t->rchild);
    }
} 
 
//输出所有结点到根结点的路径 
void AllPath1(BiTree T,char path[],int pathlen)
{
    int i;
    if(T!=NULL)
    {
        if(T->lchild==NULL && T->rchild==NULL)
        {
            printf("%c:",T->data);
            for(i=0;i<=pathlen-1;i++)
            {
                printf("%c",path[i]);
            }
            printf("\n");
        }
        else
        {
            path[pathlen]=T->data;
            AllPath1(T->lchild,path,pathlen+1);
            AllPath1(T->rchild,path,pathlen+1); 
        }
    }
}
int main()
{
    BiTree T=NULL;
    CreateBiTree(T);
    char path[MAXSIZE];
    AllPath1(T,path,0);
    return 0;
}
