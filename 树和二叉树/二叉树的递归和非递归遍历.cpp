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
	unsigned int isOut;//רΪ����������õģ�0Ϊ����Ҫ�������1Ϊ��Ҫ�����
}TreeNode,*Tree;

//ջ�ṹ
typedef struct stack
{
	Tree *base;
	Tree *top;
	int stacksize;
}Sqstack;

/*****************ջ�Ĳ�������********************/  
  
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
  
/*****************ջ�Ĳ�������********************/  
  
  
/*****************���Ĳ�������********************/  
//������,���������н�����  
void CreateTree(Tree &t);  
//�ݹ��������  
void PreOrder(Tree t);  
//�ǵݹ��������  
void PreOrder1(Tree t);  
//�ݹ��������  
void InOrder(Tree t);  
//�ǵݹ��������  
void InOrder1(Tree t);  
//�ݹ�������  
void PostOrder(Tree t);  
//�ǵݹ�������  
void PostOrder1(Tree t);  
/*****************���Ĳ�������********************/

 int main()  
{  
    Tree T;  
    printf("�������������������У�'#'����գ�\n");  
    CreateTree(T);  
  
    printf("\n�ǵݹ���������Ľ����");  
    PreOrder1(T);  
    printf("\n�ݹ���������Ľ����  ");  
    PreOrder(T);  
  
    printf("\n�ǵݹ���������Ľ����");  
    InOrder1(T);  
    printf("\n�ݹ���������Ľ����  ");  
    InOrder(T);  
  
    printf("\n�ǵݹ��������Ľ����");  
    PostOrder1(T);  
    printf("\n�ݹ��������Ľ����  ");  
    PostOrder(T);  
    printf("\n");  
  
}  

/*****************ջ�Ĳ�������********************/ 
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
	e->isOut = 0;
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

 /*****************ջ�Ĳ�������********************/  
  
  
  
/*****************���Ĳ�������********************/
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

//�ݹ��������
void PreOrder(Tree t)
{
	 if ( t )  
    {  
    printf("%c",t->data);  
    PreOrder(t->lchild);  
    PreOrder(t->rchild);  
    }  
}

//�ǵݹ��������
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

//�ݹ��������
void InOrder(Tree t)
{
	if(t)
	{
		InOrder(t->lchild);
		printf("%c",t->data);
		InOrder(t->rchild);
	}
}

//�ǵݹ��������
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

//�ݹ�������
void PostOrder(Tree t)
{
	if ( t )  
    {
    	PostOrder(t->lchild);
    	PostOrder(t->rchild);
    	printf("%c",t->data);
	}
}

//�ǵݹ�������  
void PostOrder1(Tree t)  
{  
    t->isOut = 0;  
    Tree p = t;  
    Sqstack s;  
    InitStack(s);   
  
    while ( p || !StackEmpty(s) )  
    {  
    if(p)  
    {  
        if ( p->isOut )  
        {//�������������������ýڵ�Ҳ���          
            Pop(s,p);  
            printf("%c",p->data);  
            if (!StackEmpty(s))  
                GetTop(s,p); //�õ������ڵ�Ԫ�صĸ��ڵ�  
            else  
                p = NULL;  
        }  
        else  
        {      
            if ( (p->lchild) && (p->lchild->isOut == 1) )  
            {//�������������,�����������Ѿ������꣬��˵���ýڵ��Ѿ���ջ�������ٴ�Push,ֱ������������            
                p->isOut = 1;  
                p = p->rchild;     
            }  
            else  
            {  
                Push(s,p);  
                p = p->lchild;  
            }            
        }  
    }  
    else  
    {  
        if (!StackEmpty(s))  
            GetTop(s,p);   
        else  
            p = NULL;  
  
        if ( p->rchild )  
        {  
            p = p->rchild;  
        }  
        else  
        {  
            Pop(s,p);  
            printf("%c",p->data);  
            p->isOut = 1;  
            if (!StackEmpty(s))  
            {  
                GetTop(s,p);  
                if ( p->lchild == NULL )  
                    p->isOut = 1; //������������������ڵ�isOut��1  
            }  
            else  
                p = NULL;  
        }  
          
    }  
   }  
} 
