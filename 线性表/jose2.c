#include<stdio.h>
#include<stdlib.h>
#define MAX 100
  
typedef struct NodeType 
{ 
	int id; 
    struct NodeType *next;
}NodeType;

void CreaList(NodeType **pphead,int n);
int IsEmptyList(NodeType *pHead);
int JosephusOperate2(NodeType **ppHead,int iPassword,int p[],int j[]);
int compare(int p[],int j[],int n,int k);
  
int p[50]={0};
int j[50]={0};
int n=0;
int i=0;
int r=0;
int k=0;
int fg=0;

int main()
{
    int key=0;
    NodeType *pHead=NULL;
    scanf("%d %d\n",&n,&k);
      
    for(i=0;i<k;i++)
	 {
        scanf("%d",&p[i]);
     }

    for(i=1;i<n;i++)
	 {       
		CreaList(&pHead,n);
        key=JosephusOperate2(&pHead,i,p,j);
        if(key==6)
        {
		   printf("%d",i);
           break;
        }
	 }
}
void CreaList(NodeType **ppHead,int n)
{   
	int i=0;
    NodeType *pNew=NULL;
    NodeType *pCur=NULL;
    
	for( i=1;i<=n;i++)
	 {
		pNew=(NodeType*)malloc(sizeof(NodeType));
        pNew->id=i;  
        pNew->next=NULL; 
        if(*ppHead==NULL)
		 {
			*ppHead=pCur=pNew;
            pCur->next=*ppHead;
         }
        else
		 {
			pNew->next=pCur->next;
            pCur->next=pNew;
            pCur=pNew;
         }   
     }
}
  
int IsEmptyList(NodeType *pHead)
{
    if(!pHead)
	 {
		printf("The list is empty!\n");
        return 1;
     }
     return 0;
}

int JosephusOperate2(NodeType **ppHead,int ipassword,int p[],int j[])
{
    int v=0;
    int iCounter=0;
    int iFlag=1;
    int fg=0;
    NodeType *pPrv=NULL;
    NodeType *pCur=NULL;
    NodeType *pDel=NULL;
    pPrv=pCur=*ppHead;
  
    while(pPrv->next!=*ppHead)
        pPrv=pPrv->next;
    while(iFlag)
	 {
		for(iCounter=1;iCounter<ipassword;iCounter++)
		 {
			pPrv=pCur;
            pCur=pCur->next;
         }
		if(pPrv==pCur) 
		  iFlag=0;
        pDel=pCur;
        pPrv->next=pCur->next;
        pCur=pCur->next;
        j[v]=pDel->id;
        v++;
        free(pDel);
    }
    *ppHead=NULL;
    fg=compare(p,j,n,k);
    return fg;
}
      
int compare(int p[],int j[],int n1,int k1)
{
	int v=0;
    for(v=0,r=n1-k1;v<k1,r<n1;v++,r++)
        if(p[v]!=j[r])
            return 5;
    return 6;
}
