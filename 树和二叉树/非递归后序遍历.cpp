#include<stdio.h>
#include<stdlib.h>
  
#define STACKINITSIZE 100
#define STACKINCREASESIZE 20
  
typedef char ElemType;
//���ṹ
typedef struct tree
{
    ElemType data;
    struct tree *lchild;
    struct tree *rchild;
}TreeNode,*Tree;
  
//ջ�ṹ
typedef struct stack
{
    Tree *base;
    Tree *top;
    int stacksize;
}Sqstack;  
    
//��ʼ��ջ  
void InitStack( Sqstack &s );  
//Ԫ����ջ  
void Push( Sqstack &s, Tree e );  
//���ջ��Ԫ��  
void GetTop( Sqstack s, Tree &e );  
//����ջ��Ԫ��  
void Pop( Sqstack &s, Tree &e );  
//�ж�ջ�Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0  
int StackEmpty( Sqstack s );  
    
    
    
//������,���������н�����  
void CreateTree(Tree &T); 
//�ǵݹ�������  
void PostOrder1(Tree t);  
  
 int main()  
{  
    Tree T;  
    CreateTree(T);  
    PostOrder1(T);  
}  
  
//��ʼ��ջ
void InitStack(Sqstack &s)
{
    s.base = (Tree *)malloc(STACKINITSIZE*sizeof(Tree));
    if (!s.base)
    {
        printf("InitStack�ڴ����ʧ��!\n");
    }
    s.top = s.base;
    s.stacksize = STACKINITSIZE;
}
  
//Ԫ����ջ
void Push(Sqstack &s,Tree e)
{
    if(s.top - s.base >= s.stacksize)
    {
        s.base = (Tree *)realloc(s.base,(s.stacksize+STACKINCREASESIZE)*sizeof(Tree));
        if(!s.base)
        {
            printf("Push�ڴ�������!\n");
            return;
        }
        s.top = s.base + s.stacksize;
        s.stacksize += STACKINCREASESIZE;
    }
    *s.top++ = e;
}
  
//���ջ��Ԫ��
void GetTop(Sqstack s,Tree &e)
{
    e = *(s.top - 1);
}
  
//����ջ��Ԫ��
void Pop(Sqstack &s,Tree &e)
{
    if(s.top == s.base)
    {
        printf("ջΪ��!\n");
        return;
    }
    e = *(--s.top);
}
  
//�ж�ջ�Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0
int StackEmpty(Sqstack s)
{
    if(s.top == s.base)
      return 1;
    return 0;
} 
    
//�����������������н�����
void CreateTree(Tree &t)
{
    char ch;
    scanf("%c",&ch);
    if(ch == '#')
      t=NULL;
    else
    {
        t = (Tree)malloc(sizeof(TreeNode));
        if(!t)
        {
            printf("�����ڴ����!\n");
            return;
        }
        t->data = ch;
        CreateTree(t->lchild);
        CreateTree(t->rchild);
    }
}
 
//�ǵݹ�������������
void PostOrder1(Tree root)
{
    Sqstack S;
    InitStack(S);
    TreeNode *p,*q;
    p=root;
    q=NULL;
    while(p || !StackEmpty(S))
    {
        if(p)
        {
            Push(S,p);
            p=p->lchild;
        }
        else
        {
            GetTop(S,p);
            if(p->rchild==NULL || p->rchild==q)
            {
                Pop(S,p);
                printf("%c",p->data);
                q=p;
                p=NULL;
            }
            else
            {
                p=p->rchild;
            }
        }
    }
 } 
