//魔王语言解释
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FALSE 0
#define TRUE 1
#define size 300

typedef struct
{
    char elem[size];
    int top;
}Stack;

//初始化栈
void InitStack(Stack *S)
{
    S->top=-1;
}

//进栈
int Push(Stack *S,char x)
{
    if(S->top==size-1)//栈满
      return 0;
    S->top++;
    S->elem[S->top]=x;
    return 1;
}

//翻译函数2(即为输出函数),栈的参数e为传递参数
void Translation2(char e)
{
    switch(e)
     {
        case 'B':
          printf("天上一只鹅地上一只鹅");
          break;
        case 'A':
          printf("上一只鹅");
          break;
        case 't':
          printf("天");
          break;
        case 's':
          printf("上");
          break;
        case 'a':
          printf("一只");
          break;
        case 'e':
          printf("鹅");
          break;
        case 'h':
          printf("恨");
          break;
        case 'n':
          printf("蛋");
          break;
        case 'x':
          printf("下");
          break;
        case 'g':
          printf("干");
          break;
        case 'z':
          printf("追");
          break;
        case 'd':
          printf("地");
          break;
     }
}

void Translation1(Stack *S)
{
    printf("魔王语言解释成人能听懂的语言:");
    char e;
    while(S->top!=-1)//栈不空
     {
        e=S->elem[S->top];//e为栈顶元素
        S->top--;
        Translation2(e);
     }
}

int main()
{
    Stack S;
    InitStack(&S);
    printf("**************魔王语言解释***************\n");
    printf("魔王请说话(至多含一个括号):\n");
    char str[100];
    while(scanf("%s",str)!=EOF)
     {
        int flag=0,j,m=0,n=0;
        for(j=strlen(str)-1;j>=0;j--)
         {
            if(str[j]==')')
             {
                flag++;
                n=j;
             }
            if(str[j]=='(')
             {
                flag++;
                m=j;
             }
         }
        if(flag==0)
         {
            for(j=strlen(str)-1;j>=0;j--)
             {
                Push(&S,str[j]);
             }
            Translation1(&S);
            printf("\n");
         }
        if(flag==2)//有括号（至多一对)
         {
            for(j=strlen(str)-1;j>n;j--)
             {
                Push(&S,str[j]);
             }
            Push(&S,str[m+1]);
            for(j=m+2;j<n;j++)
             {
                Push(&S,str[j]);
                Push(&S,str[m+1]);
             }
            for(j=m-1;j>=0;j--)
             {
                Push(&S,str[j]);
             }
            Translation1(&S);
            printf("\n");
         }
        if(flag>2||flag==1)
         {
            printf("input wrong\n");
         }
     }
}
