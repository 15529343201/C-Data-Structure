//中序后序建立二叉树
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}BiTNode,*BiTree;
 
//中序后序建立二叉树
void PostOrder1(char *last,char *mid,BiTree &T,int len)
{
    if(len==0)
    {
        T=NULL;
        return;
    }
    char ch=last[len-1];//取出后序序列的最后一个节点
    int index=0;//在中序序列中查找根结点，并用index记录其在序列中的索引
    while(mid[index]!=ch)
    {
        index++;
    }
    T=(BiTree)malloc(sizeof(BiTNode));//给根结点分配空间
    T->data=mid[index];
    PostOrder1(last,mid,T->lchild,index);//建立左子树
    PostOrder1(last+index,mid+index+1,T->rchild,len-index-1);//建立右子树
} 
 
//先序遍历
void PreOrder(BiTree T)
{
    if(T!=NULL)
    {
        printf("%c",T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
 
int main()
{
    char mid[26],last[26];
    while(scanf("%s%s",mid,last)!=EOF)
    {
        BiTree T=NULL;
        PostOrder1(last,mid,T,strlen(last));
        PreOrder(T);
        printf("\n");
    }
    return 0;
 } 
