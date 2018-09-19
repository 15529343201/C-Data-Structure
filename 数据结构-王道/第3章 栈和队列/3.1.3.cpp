#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//宏定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int ElemType;
typedef int Status;

//栈的顺序存储结构
typedef struct{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

//1.构建一个空栈
Status InitStack(SqStack &s){
	s.base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!s.base)
		exit(OVERFLOW);//存储分配失败
	s.top=s.base;
	s.stacksize=STACK_INIT_SIZE;
	return OK;
}

//2.销毁栈
Status DestroyStack(SqStack &s){
	s.top=NULL;
	s.stacksize=0;
	free(s.base);
	return OK;
}

//3.清空栈
Status ClearStack(SqStack &s){
	s.top=s.base;
	return OK;
}

//4.判断栈是否为空
Status StackEmpty(SqStack &s){
	if(s.top==s.base)
		return ERROR;
	else
		return TRUE;
}

//5.求栈的长度
Status StackLength(SqStack &s){
	if(s.top==s.base)
		return FALSE;
	else
		return (s.top-s.base);
}

//6.求栈顶元素
Status GetTop(SqStack &s,ElemType e){
	if(s.top==s.base)
		return FALSE;
	else
		e=*(s.top-1);
	return e;
}

//7.栈顶插入元素
Status Push(SqStack &s,ElemType e){
	if((s.top-s.base)>=STACK_INIT_SIZE){
		s.base=(ElemType*)realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(ElemType));
		if(!s.base)
			return FALSE;
		s.top=s.base+STACK_INIT_SIZE;//栈底地址可能改变,重新定位栈顶元素
		s.stacksize=s.stacksize+STACKINCREMENT;
	}
	*s.top=e;
	s.top++;
	return OK;
}

//8.删除栈顶元素
Status Pop(SqStack &s,ElemType e){
	if(s.top==s.base)
		return ERROR;
	else{
		s.top--;
		e = *s.top;//说明:此处容易使人迷惑,实际上此元素并没真正删除,仍在S.top中,但是如果插入元素,就会被更新,就像是删除了一样
		return e;
	}
}

//9.遍历栈
Status StackTraverse(SqStack &s){
	if(s.base==NULL)
		return ERROR;
	if(s.top==s.base)
		printf("栈中没有元素......\n");
	ElemType *p;
	p=s.top;
	while(p>s.base){
		p--;
		printf("%d ",*p);
	}
	return OK;
}

//主函数检验九种操作
int main(){
	SqStack s;
	printf("构造一个空栈......\n");
	InitStack(s);
	int i,n;
	printf("输入栈的长度:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("输入栈的第%d个元素\n",i);
		++s.top;
		scanf("%d",s.top-1);
	}
	printf("......本栈是空栈吗?......\n");
	if(StackEmpty(s)==1)
		printf("NO !!!\n");
	else
		printf("YES !!!\n");
	printf("......求出栈的长度......\n");
	int m;
	m=StackLength(s);
	printf("栈的长度是:\n");
	printf("%d\n",m);
	printf("遍历输出栈的所有元素:\n");
	StackTraverse(s);
	printf("\n");
	printf("......输出栈顶元素......\n");
	int e;
	e=GetTop(s,e);
	printf("栈顶元素是:\n");
	printf("%d\n",e);
	printf("......栈顶插入元素......\n");
	printf("请输入要插入的元素的值:\n");
	scanf("%d",&e);
	Push(s,e);
	printf("现在栈中的元素是:\n");
	StackTraverse(s);
	printf("\n");
	printf("......栈顶删除元素......\n");
	e=Pop(s,e);
	printf("被删除的元素是:\n");
	printf("%d\n",e);
	printf("现在栈中的元素是:\n");
	StackTraverse(s);
	printf("\n");
	printf("......清空栈......\n");
	ClearStack(s);
	printf("现在栈中的元素是:\n");
	StackTraverse(s);
	printf("......销毁栈......\n");
	if(DestroyStack(s)==1)
		printf("销毁栈成功\n");
	else
		printf("销毁栈失败\n");
	printf("恭喜您成功完成所有的功能,毕竟您那么帅!!!\n");
	return 0;
}
