//一元多项式的建立与输出
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
if ((pHead = (POLY *)malloc(sizeof(POLY)))  == NULL)
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
     POLY *pHead;
     pHead = InitPoly();
     InputPoly(pHead);
     OutputPoly(pHead);
     return 0;
 }
