//顺序栈的描述方式3
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define STACK_INIT_SIZE 100//栈存储空间的初始分配量
#define STACKINCREMENT 10//存储空间分配增量
typedef int Status;
typedef char SElemType;

typedef struct
{
	SElemType *base;//存储数据元素的数组
	SElemType *top;//栈顶指针
	int stacksize;//当前分配的栈空间大小,以sizeof(SElemType)为单位
}SqStack;

//构造一个空栈
Status InitStack(SqStack *S)
{
	S->base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(S->base==NULL)
	  exit(OVERFLOW);
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return OK;
}

//销毁栈
Status DestroyStack(SqStack *S)
{
	free(S->base);
	S->base=NULL;
	S->top=NULL;
	S->stacksize=0;
	return OK;
}

//判断栈S是否为空
Status StackEmpty(SqStack *S)
{
	if(S->top==S->base)
	  printf("该栈为空\n");
	else
	  printf("该栈不为空\n");
	return OK;
}

//插入元素e为新的栈顶元素
Status Push(SqStack *S,SElemType e)
{
	if(S->top-S->base>==S->stacksize)
	 {
		//栈满，追加存储空间
	    S->base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
	    if(S->base==NULL)
		  exit(OVERFLOW);//存储空间配分失败
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	 }
	*(S->top++)=e;
	return OK;
}

//返回S的元素个数,及栈的长度
int StackLength(SqStack *S)
{
	return S->top-S->base;
}

//若栈不空，则用e返回S的栈顶元素
Status GetTop(SqStack *S,SElemType *e)
{
	if(S->top>S->base)
	 {
		*e=*(--S->top);
		return *e;
	 }
	else
	  return ERROR;
}

//若栈不空，删除S的栈顶元素
Status Pop(SqStack *S,SElemType *e)
{
	if(S->top==S->base)
	  return ERROR;
	*e=*(--S.top);
	return *e;
}

//遍历栈
Status StackTraverse(SqStack S,Status( *visit)(SElemType))
{
	while(S.top!=S.base)
	  visit(*--S.top);
	return OK;
}

Status visit(SElemType e)
{
	printf(" %c",e);
	printf("\n");
	return OK;
}

int main()
{
	SqStack S;
	SElemType e;
	printf("(1)初始化顺序栈.\n");
	InitStack(S);
	printf("(2)判断顺序栈是否为空:");
	StackEmpty(S);
	printf("(3)依次进栈元素a,b,c,d,e:\n");
	Push(S,'a');
	Push(S,'b');
	Push(S,'c');
	Push(S,'d');
	Push(S,'e');
	printf("(4)判断顺序栈是否为空:\n");
	StackEmpty(S);
	printf("(5)输出顺序栈长度:%d\n",StackLength(S));
	printf("(6)输出从栈顶到栈低的元素:\n");
	StackTraverse(S,visit);
	printf("(7)读出栈顶元素:%c\n",GetTop(S,e));
	printf("(8)删除栈顶元素:%c\n",Pop(S,e));
	printf("(9)(输出从栈顶到栈低的元素:\n");
	StackTraverse(S,visit);
	printf("(10)判断顺序栈是否为空:");
	StackEmpty(S);
	printf("(11)释放栈.\n");
	DestroyStack(S);
	return 0;
}



