//顺序表的描述方式2:动态分配存储空间 
#include<stdio.h>
#include<stdlib.h>
#define TRUE  1
#define FALSE 0
#define OK   1
#define ERROR 0
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int status ;
typedef int ElemType ;
typedef struct
{
	ElemType *elem;
    int length;
	int listsize;
}SqList;

//初始化 
status InitList(SqList &L)
{
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem) 
      exit(OVERFLOW);
    L.listsize=LIST_INIT_SIZE;
    L.length=0;
    return OK;
}

//建立表 
status Build(SqList &L)
{
	int i,n;
    printf("请输入元素个数n:\n");
    scanf("%d",&n);
    if(n>LIST_INIT_SIZE)//如果n大于当前空间
    {
    	L.elem=(ElemType *)realloc(L.elem,(n+LISTINCREMENT)*sizeof(ElemType));
        if(!L.elem) 
		  exit(OVERFLOW);
        L.listsize=n+LISTINCREMENT;
    }
    for(i=0;i<n;i++)
    {
    	printf("请输入第%d个元素:",i+1);
    	scanf("%d",L.elem+i);
	}
    L.length=n;
    return OK;
}

//输出表中元素和长度
void Print(SqList &L)
{
	int i;
    for(i=0;i<L.length;i++)
    printf("%d ",*(L.elem+i));
    printf("\n长度为:%d\n\n",L.length);
}

//提示函数
void Tips()
{
	printf("请选择你的想要的操作：\n");
    printf("<1> 输出顺序表及顺序表的长度\n");
    printf("<2> 删除值为x的结点\n");
    printf("<3> 删除给定位置i的结点\n");
    printf("<4> 将顺序表逆置\n");
    printf("<5> 将顺序表按升序排序\n");
    printf("<6> 将x插入到顺序表的适当位置上\n");
    printf("<7> 将两个有序表合并\n");
    printf("<0> 退出\n\n");
}

//删除值为X的元素
status ListDelete1(SqList &L,int x)
{
	int i;
    for(i=0;i<L.length;i++)
      if(*(L.elem+i)==x)
        break;
    if(i==L.length)
      return ERROR;
    for(i++;i<L.length;i++)
      *(L.elem+i-1)=*(L.elem+i);
    L.length--;
    return OK;
}

//删除第X个元素
status ListDelete2(SqList &L,int x)
{
	int i;
    if(x<0||x>=L.length)
      return ERROR;
    for(i=x+1;i<L.length;i++)
      *(L.elem+i-1)=*(L.elem+i);
    L.length--;
    return OK;
}

//逆置函数
void Inverse(SqList &L)
{
	int i,t;
    for(i=0;i<L.length/2;i++)
    {
    	t=*(L.elem+i);
        *(L.elem+i)=*(L.elem+L.length-i-1);
        *(L.elem+L.length-i-1)=t;
    }
}

//冒泡排序（升序）
void Sort(SqList &L)
{
	int i,j,t;
    for(i=1;i<L.length;i++)
    { 
      for(j=0;j<L.length-i;j++)
      {
         if(*(L.elem+j)>*(L.elem+j+1))
         {
             t=*(L.elem+j);
             *(L.elem+j)=*(L.elem+j+1);
             *(L.elem+j+1)=t;
         }
      }
    } 
    printf("已按升序排列\n\n");
}

//将X插入，使仍然有序
status ListInsert(SqList &L,int x)
{
	int i,k;
    if(L.length>=L.listsize)
    {
       L.elem=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
       if(!L.elem) 
	     exit(OVERFLOW);
       L.listsize+=LISTINCREMENT;
    }
    for(i=0;i<L.length;i++)
      if(x<*(L.elem+i))
        break;
    k=i;
    for(i=L.length;i>k;i--)
      *(L.elem+i)=*(L.elem+i-1);
    *(L.elem+k)=x;
    L.length++;
    return OK;
}

//合并两个线性表
status Merger(SqList &L,SqList &Lb)
{
	int i,j,k;
    SqList Lc;
    InitList(Lc);
    if(Lc.listsize<L.length+Lb.length)
    {
       Lc.elem=(ElemType *)realloc(Lc.elem,(L.length+Lb.length+LISTINCREMENT)*sizeof(ElemType));
       if(!L.elem) 
	     exit(OVERFLOW);
       Lc.listsize=L.length+Lb.length+LISTINCREMENT;
    }
    i=j=k=0;
    while(i<L.length && j<Lb.length)
    {
    	if(*(L.elem+i) < *(Lb.elem+j))
        {
            *(Lc.elem+k)=*(L.elem+i);
            k++;i++;
        }
        else
        {
            *(Lc.elem+k)=*(Lb.elem+j);
            k++;j++;
        }
   }
   while(i<L.length)
   {
       *(Lc.elem+k)=*(L.elem+i);
       k++;i++;
   }
   while(j<Lb.length)
   {
       *(Lc.elem+k)=*(Lb.elem+j);
       k++;j++;
   }
   Lc.length=L.length+Lb.length;
   L=Lc;
   return OK;
}

int main()
{
	int op,x,flag;
    SqList L,Lb;
    InitList(L);
    Build(L);
    Tips();
    scanf("%d",&op);
    while(op)
    {
    	switch(op)
        {
            case 1:
                Print(L);
                break;
            case 2:
                printf("请输入要删除的数据X:\n");
                scanf("%d",&x);
                flag=ListDelete1(L,x);
                if(flag)
                    printf("删除成功!!\n\n");
                else
                    printf("元素不存在,删除失败!!\n\n");
                break;
            case 3:
                printf("请输入要删除的位置i:\n");
                scanf("%d",&x);
                flag=ListDelete2(L,x-1);//第i个元素对应的下标为i-1
                if(flag)
                    printf("删除成功!!\n\n");
                else
                    printf("元素不存在,删除失败!!\n\n");
                break;
            case 4:
                Inverse(L);
                break;
            case 5:
                Sort(L);
                break;
            case 6:
                printf("请输入要插入的数据X:\n");
                scanf("%d",&x);
                flag=ListInsert(L,x);   
                if(flag)
                    printf("插入成功!!\n\n");
                else
                    printf("插入失败!!\n\n");
                break;
            case 7:
                printf("请输入Lb的内容:\n");
                InitList(Lb);
                Build(Lb);
                flag=Merger(L,Lb);
                if(flag)
                    printf("合并成功!!\n\n");
                break;
        }
        Tips();
        scanf("%d",&op);
    }
    return 0;
}
