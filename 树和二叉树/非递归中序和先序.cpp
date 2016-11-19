#include<stdio.h>
#include<stdlib.h>
 
#define STACKINITSIZE 100
#define STACKINCREASESIZE 20
 
typedef char ElemType;
//树结构
typedef struct tree
{
    ElemType data;
    struct tree *lchild;
    struct tree *rchild;
}TreeNode,*Tree;
 
//栈结构
typedef struct stack
{
    Tree *base;
    Tree *top;
    int stacksize;
}Sqstack;  
   
//初始化栈  
void InitStack( Sqstack &s );  
//元素入栈  
void Push( Sqstack &s, Tree e );  
//获得栈顶元素  
void GetTop( Sqstack s, Tree &e );  
//弹出栈顶元素  
void Pop( Sqstack &s, Tree &e );  
//判断栈是否为空，为空返回1，否则返回0  
int StackEmpty( Sqstack s );  
   
   
   
//创建树,以先序序列建立树  
void CreateTree(Tree &T);
//非递归先序遍历  
void PreOrder1(Tree t);  
 //非递归中序遍历  
void InOrder1(Tree t);  
//非递归后序遍历  
void PostOrder1(Tree t);  
 
 int main()  
{  
    Tree T;  
    CreateTree(T);  
    PreOrder1(T);
    printf("\n");  
    InOrder1(T);  
}  
 
/*****************栈的操作定义********************/
//初始化栈
void InitStack(Sqstack &s)
{
    s.base = (Tree *)malloc(STACKINITSIZE*sizeof(Tree));
    if (!s.base)
    {
        printf("InitStack内存分配失败!\n");
    }
    s.top = s.base;
    s.stacksize = STACKINITSIZE;
}
 
//元素入栈
void Push(Sqstack &s,Tree e)
{
    if(s.top - s.base >= s.stacksize)
    {
        s.base = (Tree *)realloc(s.base,(s.stacksize+STACKINCREASESIZE)*sizeof(Tree));
        if(!s.base)
        {
            printf("Push内存分配出错!\n");
            return;
        }
        s.top = s.base + s.stacksize;
        s.stacksize += STACKINCREASESIZE;
    }
    *s.top++ = e;
}
 
//获得栈顶元素
void GetTop(Sqstack s,Tree &e)
{
    e = *(s.top - 1);
}
 
//弹出栈顶元素
void Pop(Sqstack &s,Tree &e)
{
    if(s.top == s.base)
    {
        printf("栈为空!\n");
        return;
    }
    e = *(--s.top);
}
 
//判断栈是否为空，为空返回1，否则返回0
int StackEmpty(Sqstack s)
{
    if(s.top == s.base)
      return 1;
    return 0;
} 
   
//创建树，以先序序列建立树
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
            printf("分配内存出错!\n");
            return;
        }
        t->data = ch;
        CreateTree(t->lchild);
        CreateTree(t->rchild);
    }
} 
 
//非递归先序遍历
void PreOrder1(Tree t)
{
    Tree p = t;
    Sqstack s;
    InitStack(s);
     
    while(p || !StackEmpty(s))
    {
        if(p)
        {
            printf("%c",p->data);
            Push(s,p);
            p = p->lchild;
        }
        else
        {
            Pop(s,p);
            p = p->rchild;
        }
    }
}
 
 
 
//非递归中序遍历
void InOrder1(Tree t)
{
    Tree p = t;
    Sqstack s;
    InitStack(s);
     
    while(p || !StackEmpty(s))
    {
        if(p)
        {
            Push(s,p);
            p = p->lchild;
        }
        else
        {
            Pop(s,p);
            printf("%c",p->data);
            p = p->rchild;
        }
    }
}
