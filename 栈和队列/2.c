//顺序栈的描述方式2
#include<stdio.h>  
#include<stdlib.h>   
  
typedef int ElemType;  
  
#define STACK_INIT_SIZE 8  
#define true 1
#define false 0
  
typedef struct Stack  
{  
    ElemType *base;  
    int       top;  
    int       capacity;  
}Stack;  
  
int IsFull(Stack *st);
int IsEmpty(Stack *st);  
void InitStack(Stack *st);  
int Push(Stack *st, ElemType x);  
int Pop(Stack *st);  
int Pop2(Stack *st,ElemType *v);  
ElemType GetTop(Stack *st);  
void clear(Stack *st);  
void destroy(Stack *st);  
void ShowStack(Stack *st); 

      
int IsFull(Stack *st)  
{  
    return st->top >= st->capacity;  
}  
    
int IsEmpty(Stack *st)  
{  
    return st->top == 0;  
}  
    
void InitStack(Stack *st)  
{  
    st->base = (ElemType *)malloc(sizeof(ElemType)*STACK_INIT_SIZE);  
    if(st->base == NULL)
		exit(0);
    st->capacity = STACK_INIT_SIZE;  
    st->top = 0;  
}  
      
int Push(Stack *st, ElemType x)  
{  
    if(IsFull(st))  
    {  
        printf("栈已满，%d不能入栈!",x);  
        return false;  
    }  
    st->base[st->top++] = x;  
    return true;  
}  
      
int Pop(Stack *st)  
{  
    if(IsEmpty(st))  
    {  
        printf("栈已空,不能出栈!");  
        return false;  
    }  
    st->top--;  
    return true;  
}  
      
int Pop2(Stack *st,ElemType *v)  
{  
    if(IsEmpty(st))  
    {  
        printf("栈已空,不能出栈!");
        return false;  
    }  
    *v = st->base[--st->top];  
    return true;  
}  
      
ElemType GetTop(Stack *st)  
{  
    if(IsEmpty(st))  
    {  
        printf("栈已空,不能出栈!");
    }  
    return st->base[st->top-1];  
}  
      
void clear(Stack *st)  
{  
    st->top = 0;  
}  
    
void destroy(Stack *st)  
{  
    free(st->base);  
    st->base = NULL;  
    st->top = 0;  
    st->capacity = 0;  
}  
      
void ShowStack(Stack *st)  
{  
    for(int i=st->top-1; i>=0; --i)  
    {  
        printf("%d ",st->base[i]);
    }  
}  

int main()  
{  
    Stack st;  
    ElemType e;  
    InitStack(&st);  
    Push(&st,1);  
    Push(&st,2);  
    Push(&st,3);  
    Push(&st,4);  
    Push(&st,5);  
    Push(&st,6);  
    Pop2(&st,&e);  
    printf("出栈的元素为: ");
    Pop(&st);  
    ShowStack(&st);  
	return 0;
}  
