//ħ�����Խ���
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

//��ʼ��ջ
void InitStack(Stack *S)
{
    S->top=-1;
}

//��ջ
int Push(Stack *S,char x)
{
    if(S->top==size-1)//ջ��
      return 0;
    S->top++;
    S->elem[S->top]=x;
    return 1;
}

//���뺯��2(��Ϊ�������),ջ�Ĳ���eΪ���ݲ���
void Translation2(char e)
{
    switch(e)
     {
        case 'B':
          printf("����һֻ�����һֻ��");
          break;
        case 'A':
          printf("��һֻ��");
          break;
        case 't':
          printf("��");
          break;
        case 's':
          printf("��");
          break;
        case 'a':
          printf("һֻ");
          break;
        case 'e':
          printf("��");
          break;
        case 'h':
          printf("��");
          break;
        case 'n':
          printf("��");
          break;
        case 'x':
          printf("��");
          break;
        case 'g':
          printf("��");
          break;
        case 'z':
          printf("׷");
          break;
        case 'd':
          printf("��");
          break;
     }
}

void Translation1(Stack *S)
{
    printf("ħ�����Խ��ͳ���������������:");
    char e;
    while(S->top!=-1)//ջ����
     {
        e=S->elem[S->top];//eΪջ��Ԫ��
        S->top--;
        Translation2(e);
     }
}

int main()
{
    Stack S;
    InitStack(&S);
    printf("**************ħ�����Խ���***************\n");
    printf("ħ����˵��(���ຬһ������):\n");
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
        if(flag==2)//�����ţ�����һ��)
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
