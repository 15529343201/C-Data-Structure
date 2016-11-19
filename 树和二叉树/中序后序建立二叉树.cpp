//���������������
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}BiTNode,*BiTree;
 
//���������������
void PostOrder1(char *last,char *mid,BiTree &T,int len)
{
    if(len==0)
    {
        T=NULL;
        return;
    }
    char ch=last[len-1];//ȡ���������е����һ���ڵ�
    int index=0;//�����������в��Ҹ���㣬����index��¼���������е�����
    while(mid[index]!=ch)
    {
        index++;
    }
    T=(BiTree)malloc(sizeof(BiTNode));//����������ռ�
    T->data=mid[index];
    PostOrder1(last,mid,T->lchild,index);//����������
    PostOrder1(last+index,mid+index+1,T->rchild,len-index-1);//����������
} 
 
//�������
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
