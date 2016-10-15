//一元多项式减法
#include<stdio.h>
#include<stdlib.h>
  
typedef struct Polynomial{
    int coef;
    int expn;
    struct Polynomial *next;    
}node,*Polyn;
  
Polyn CreatePoly(int n){
    node *head=NULL,*rear=NULL,*s=NULL;
    int c,e;
    head=(node*)malloc(sizeof(node));
    rear=head;  
    for(int i=1;i<=n;i++){   
        scanf("(%d,%d)",&c,&e);
        s=(node*)malloc(sizeof(node));
        s->coef=c;
        s->expn=e;
        rear->next=s;
        rear=s;     
    }
    rear->next=NULL;
    return(head);
}
  
void PrintPolyn(Polyn p){
    Polyn q=p->next;
    int flag=1;
    if(!q){
        putchar('0');
        printf("\n");
        return;
    }
    while(q){
        if(q->coef>0&&flag!=1) putchar('+');
        if(q->coef!=1&&q->coef!=1){
            printf("%d",q->coef);
            if(q->expn==1) putchar('X');
            else if(q->expn) printf("X^%d",q->expn);
        }
        else
        {
            if(q->coef==1){
                if(!q->expn) putchar('1');
                else if(q->expn==1) putchar('X');
                else printf("X^%d",q->expn);
            }
            if(q->coef==-1){
                if(!q->expn) printf("-1");
                else if(q->expn==1) printf("-X");
                else printf("-X^%d",q->expn);
            }
        }
        q=q->next;
        flag++;
    }
printf("\n");
}
Polyn BubbleSort(node *L)
{   node *p=NULL;
    node *tail=NULL;
    node *pnext=NULL;
    int temp;
    if(L->next->next==NULL)
         return L;
    for(p=L->next;p->next!=NULL;p=p->next)    /*尾指针初始化*/
        ;
    tail = p;
    while( tail != L->next->next )
    {
        for( p = L->next; p->next != tail; p = p->next )
            {
                pnext = p->next;
                if( p->expn > pnext->expn)    //相邻节点比较，数据交换
                {
                    temp = p->expn;              
                    p->expn = pnext->expn;
                    pnext->expn= temp;
                }
            }           
            tail = p;//p->next == tail，即把tail往前移动一位
                }
    return L;
}
Polyn AddPolyn(Polyn pa,Polyn pb){
    Polyn qa=pa->next;
    Polyn qb=pb->next;
    Polyn headc,pc,qc;
    pc=(Polyn)malloc(sizeof(node));
    pc->next=NULL;
    headc=pc;
    while(qa!=NULL&&qb!=NULL){//当两个多项式均未扫描结束时；
     qc=(Polyn)malloc(sizeof(node));
     if(qa->expn < qb->expn){//规则一 
        qc->coef=qa->coef;
        qc->expn=qa->expn;
        qa=qa->next;
    }
    else if(qa->expn==qb->expn)//规则二
    {
        qc->coef=qa->coef+qb->coef;
        qc->expn=qa->expn;
        qa=qa->next;
        qb=qb->next; 
     } 
     else //规则三 
     {
        qc->coef=qb->coef;
        qc->expn=qb->expn;
        qb=qb->next;
     }
     if(qc->coef!=0)
     {
        qc->next=pc->next;
        pc->next=qc;
        pc=qc;
     }
     else free(qc);
}
    while(qa!=NULL){//pa中如果有剩余项，将插入到pc当中 
        qc=(Polyn)malloc(sizeof(node));
        qc->coef=qa->coef;
        qc->expn=qa->expn;
        qa=qa->next;
        qc->next=pc->next;
        pc->next=qc;
        pc=qc; 
    }
    while(qb!=NULL){//pb中如果有剩余项，将插入到pc当中
        qc=(Polyn)malloc(sizeof(node));
        qc->coef=qb->coef;
        qc->expn=qb->expn;
        qb=qb->next;
        qc->next=pc->next;
        pc->next=qc;
        pc=qc;
    }
    return headc;
}
Polyn SubtractPolyn (Polyn pa,Polyn pb)
{
    Polyn h=pb;
    Polyn p=pb->next;
    Polyn pd;
    while(p){
        p->coef*=-1;
        p=p->next;
        }
    pd=AddPolyn(pa,h);
    for(p=h->next;p;p=p->next){
        p->coef*=-1;
        return pd;
    }
} 
int main(){
    int n=0,m=0;
    node *H=NULL,*P=NULL,*E=NULL;
    scanf("%d\n",&n);   
    H=CreatePoly(n);
    scanf("%d\n",&m);
    P=CreatePoly(m);
    H=BubbleSort(H);
    P=BubbleSort(P);
    E=SubtractPolyn (H,P);
    PrintPolyn(E); 
}
