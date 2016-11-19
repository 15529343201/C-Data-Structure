#include<stdio.h>
#include<stdlib.h>
#define DataType char
#define MAXSIZE 50
 
int count=0;//统计叶子节点个数
int count1=0;//统计节点个数
typedef struct Node
{
    DataType data;
    struct Node *lchild;
    struct Node *rchild;
}BiTNode,*BiTree;
 
typedef struct
{
    BiTree data[MAXSIZE];
    int rear,front;//队头队尾指针 
}SeQueue;
 
//置空队
int EmptyQueue(SeQueue *sq)
{
    int m;
    if((m=(sq->rear-sq->front))==0)
      return 1;
    else
      return 0;
}
 
//初始化队列
SeQueue *InitQueue()
{
    SeQueue *sq;
    sq=(SeQueue*)malloc(sizeof(SeQueue));
    sq->front=sq->rear=0;
    return sq; 
}
 
//入队
int InQueue(SeQueue *sq,BiTree x)
{
    int m;
    if((m=(sq->rear-sq->front))==MAXSIZE)
      return 0;
    else
    {
        sq->data[sq->rear]=x;
        sq->rear++;
        return 1;
    }
}
 
//出队 
int OutQueue(SeQueue *sq,BiTree *x)
{
    int m;
    if((m=(sq->rear-sq->front))==0)
      return 0;
    else
    {
        *x=sq->data[sq->front];
        sq->front++;
        return 1;
    }
}
 
//取队头元素 
void FrontQueue(SeQueue *sq,BiTree *x)
{
    if(!EmptyQueue(sq))
      *x=sq->data[sq->front];
}
 
//建立二叉树
void CreateBiTree(BiTree *root)
{
    char ch;
    ch=getchar();
    if(ch=='#')
      *root=NULL;
    else
    {
        *root=(BiTree)malloc(sizeof(BiTNode));
        (*root)->data=ch;
        CreateBiTree(&((*root)->lchild));
        CreateBiTree(&((*root)->rchild));
    }
} 
 
SeQueue *A;
SeQueue *S;
void PostOrdertoQueue(BiTree root)
{
    if(root)
    {
        PostOrdertoQueue(root->lchild);
        PostOrdertoQueue(root->rchild);
        InQueue(A,root);
        if(root->lchild==NULL && root->rchild==NULL)
          InQueue(S,root);
    }
}
 
void SearchFirstCommonRoot(SeQueue *A,char *s)
{
    A->front=0;
    SeQueue *P=InitQueue();
    BiTree h,x;
    int i,j;
    SeQueue *R[2];
    for(i=0;i<2;i++)
    {
        R[i]=InitQueue();
    }
     
    for(i=A->front;i<A->rear;i++)
    {
        if(A->data[i]->data==s[0] || A->data[i]->data==s[1])
        {
            x=A->data[i];
            InQueue(P,x);
        }
    }
     
    for(i=0;i<2;i++)
    {
        for(j=A->front,h=P->data[i];j<A->rear;j++)
        {
            if(A->data[j]->lchild==h || A->data[j]->rchild==h)
            {
                h=A->data[j];
                InQueue(R[i],h);
            }
        }
    }
     
    int flag=0;
    for(i=0;i<R[0]->rear;i++)
    {
        for(j=0;j<R[1]->rear;j++)
        {
            if(R[0]->data[i]==R[1]->data[j])
            {
                printf("%c",R[0]->data[i]->data);
                flag=1;
                break;
            }
        }
        if(flag==1)
          break;
    }
}
 
int main()
{
    BiTree k,r,q,p,h;
    char ch1,ch2;
    char s[3];
    A=InitQueue();
    S=InitQueue();
    int j;
    CreateBiTree(&k);
    scanf("\n%c %c",&ch1,&ch2);
    s[0]=ch1;
    s[1]=ch2;
    PostOrdertoQueue(k);
    SearchFirstCommonRoot(A,s);
 } 
