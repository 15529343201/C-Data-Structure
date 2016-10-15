#include<stdio.h>
#include<stdlib.h>
 
typedef struct poly
{
    int coef;
    int expn;
    struct poly *pNext;
}POLY;
 
POLY *InitPoly(void)
{
    POLY *pHead;
    if ((pHead = (POLY *)malloc(sizeof(POLY))) == NULL)
      exit(-1);
    pHead -> pNext = NULL;
    return pHead;
}
 
void InputPoly(POLY *pHead)
{
    int coef,expn,i;
    int j=0;
    POLY *pTail,*pNew;
    pTail = pHead;
    //输入非零项个数
    scanf("%d\n",&i);
    while(j<i)
     {
        scanf("(%d,%d)",&coef,&expn);
        if(coef != 0)
         {
            if((pNew=(POLY *)malloc(sizeof(POLY)))==NULL)
              exit(-1);
            pNew->coef = coef;
            pNew->expn = expn;
            pTail->pNext = pNew;
            pTail = pNew;
            j++;
         }
         
     }
    pTail->pNext = NULL;
}
//表达式相加
POLY *AddPoly(POLY *pHead1,POLY *pHead2)
{
    int temp;
    POLY *pHead3,*pNew,*pTail;//结果链表相关变量
    POLY *pTemp1,*pTemp2;     //运算链表相关变量
 
    pTemp1 = pHead1->pNext;
    pTemp2 = pHead2->pNext;
    pHead3 = InitPoly();
    pTail = pHead3;
 
    //将两个多项式扫描运算后放入结果链表中
    while(pTemp1 != NULL && pTemp2 != NULL)
     {
        //如果指数相等
        if (pTemp1->expn == pTemp2->expn)
         {
            if ((temp = pTemp1->coef + pTemp2->coef) == 0)
             {
                pTemp1= pTemp1->pNext;
                pTemp2= pTemp2->pNext;
                continue;
             }
            if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
              exit(-1);
            pNew->coef = temp;
            pNew->expn = pTemp1->expn;
            pTail->pNext = pNew;
            pNew->pNext = NULL;
            pTail = pNew;
            pTemp1 = pTemp1->pNext;
            pTemp2 = pTemp2->pNext;
         }
 
        //如果表达式1指数小于2
        else if(pTemp1->expn < pTemp2->expn)
         {
            if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
              exit(-1);
            *pNew = *pTemp1;
            pNew->pNext = NULL;
            pTail->pNext = pNew;
            pTail = pNew;
            pTemp1 = pTemp1->pNext;
         }
 
        //如果表达式1指数大于2
        else
         {
 
            if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
              exit(-1);
            *pNew = *pTemp2;
            pNew->pNext = NULL;
            pTail->pNext = pNew;
            pTail = pNew;
            pTemp2 = pTemp2->pNext;
         }
     }
 
    //将剩余的未扫描项放入结果链表中
    while(pTemp1 != NULL)
     {
        if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
          exit(-1);
        *pNew = *pTemp1;
        pNew->pNext = NULL;
        pTail->pNext = pNew;
        pTail = pNew;
        pTemp1 = pTemp1->pNext;
     }
    while(pTemp2 != NULL)
     {
        if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
          exit(-1);
        *pNew = *pTemp2;
        pNew->pNext = NULL;
        pTail->pNext = pNew;
        pTail = pNew;
        pTemp2 = pTemp2->pNext;
     }
 
    return pHead3;
}
 
 
//输出多项式
void OutputPoly(POLY *pHead)
{
    POLY *pTemp;
    pTemp = pHead->pNext;
    int flag=1;
    if(pTemp == NULL)
     {
        printf("\n");
        return;
     }
    while(pTemp)
     {
        if(pTemp->coef>0&&flag!=1)
          putchar('+');
        if(pTemp->coef!=1&&pTemp->coef!=-1)
         {
            printf("%d",pTemp->coef);
            if(pTemp->expn==1)
              putchar('X');
            else if(pTemp->expn)
              printf("X^%d",pTemp->expn);
         }
        else
         {
            if(pTemp->coef==1)
             {
                if(!pTemp->expn)
                  putchar('1');
                else if(pTemp->expn==1)
                  putchar('X');
                else
                  printf("X^%d",pTemp->expn);
             }
            if(pTemp->coef==-1)
             {
                if(!pTemp->expn)
                  printf("-1");
                else if(pTemp->expn==1)
                  printf("-X");
                else
                  printf("-X^%d",pTemp->expn);
             }
         }
        pTemp=pTemp->pNext;
        flag++;
     }
    printf("\n");
}
             
 
 
int main(void)
{
    POLY *pHead1,*result,*pHead2;
    pHead1 = InitPoly();
    pHead2 = InitPoly();
    InputPoly(pHead1);
    InputPoly(pHead2);
    result=AddPoly(pHead1,pHead2);
    OutputPoly(result);
    return 0;
}
