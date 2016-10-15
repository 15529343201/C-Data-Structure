//一元多项式求值
//编译gcc poly5.c -o poly5 -lm
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
 
void Calculate(POLY *head)
{
    POLY *p;
    int value=0,x;
    scanf("%d",&x);
    p=head->pNext;
    while(p)
     {
        value += p->coef * pow(x,p->expn);
        p = p->pNext;
     }
    printf("%d",value);
}
 
int main(void)
 {
     POLY *pHead;
     pHead = InitPoly();
     InputPoly(pHead);
     Calculate(pHead);
     return 0;
 }
