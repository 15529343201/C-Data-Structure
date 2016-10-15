#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct jose
{
    int id;
    int password;
    struct jose *next;
}jose;
 
void CreateL(jose **h,int n)
{
    int i,password;
    jose *pNew=NULL,*pCur=NULL;
    for(i=1;i<=n;i++)
     {
        scanf("%d",&password);
        pNew=(jose*)malloc(sizeof(jose));
        pNew->id=i;
        pNew->password=password;
        pNew->next=NULL;
        if(*h==NULL)
         {
            *h=pCur=pNew;
            pCur->next=*h;
         }
        else
         {
            pNew->next=pCur->next;
            pCur->next=pNew;
            pCur=pNew;
         }
     }
}
 
void Jose(jose **h,int password)
{
    int count,flag;
    count=0,flag=1;
    jose *pPrv=NULL,*pCur=NULL,*pDel=NULL;
    pPrv=pCur=*h;
    while(pPrv->next!=*h)
     {
        pPrv=pPrv->next;
     }
    while(flag)
     {
        for(count=1;count<password;count++)
         {
            pPrv=pCur;
            pCur=pCur->next;
         }
        if(pPrv==pCur)
          flag=0;
        pDel=pCur;
        pPrv->next=pCur->next;
        pCur=pCur->next;
        password=pDel->password;
        printf("%d ",pDel->id);
        free(pDel);
     }
    *h=NULL;
    getchar();
}
 
int main()
{
    int n,m;
    jose *h=NULL;
    scanf("%d%d",&n,&m);
    CreateL(&h,n);
    Jose(&h,m);
    return 0;
}
