//˳����������ʽ2:��̬����洢�ռ� 
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

//��ʼ�� 
status InitList(SqList &L)
{
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem) 
      exit(OVERFLOW);
    L.listsize=LIST_INIT_SIZE;
    L.length=0;
    return OK;
}

//������ 
status Build(SqList &L)
{
	int i,n;
    printf("������Ԫ�ظ���n:\n");
    scanf("%d",&n);
    if(n>LIST_INIT_SIZE)//���n���ڵ�ǰ�ռ�
    {
    	L.elem=(ElemType *)realloc(L.elem,(n+LISTINCREMENT)*sizeof(ElemType));
        if(!L.elem) 
		  exit(OVERFLOW);
        L.listsize=n+LISTINCREMENT;
    }
    for(i=0;i<n;i++)
    {
    	printf("�������%d��Ԫ��:",i+1);
    	scanf("%d",L.elem+i);
	}
    L.length=n;
    return OK;
}

//�������Ԫ�غͳ���
void Print(SqList &L)
{
	int i;
    for(i=0;i<L.length;i++)
    printf("%d ",*(L.elem+i));
    printf("\n����Ϊ:%d\n\n",L.length);
}

//��ʾ����
void Tips()
{
	printf("��ѡ�������Ҫ�Ĳ�����\n");
    printf("<1> ���˳���˳���ĳ���\n");
    printf("<2> ɾ��ֵΪx�Ľ��\n");
    printf("<3> ɾ������λ��i�Ľ��\n");
    printf("<4> ��˳�������\n");
    printf("<5> ��˳�����������\n");
    printf("<6> ��x���뵽˳�����ʵ�λ����\n");
    printf("<7> �����������ϲ�\n");
    printf("<0> �˳�\n\n");
}

//ɾ��ֵΪX��Ԫ��
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

//ɾ����X��Ԫ��
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

//���ú���
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

//ð����������
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
    printf("�Ѱ���������\n\n");
}

//��X���룬ʹ��Ȼ����
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

//�ϲ��������Ա�
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
                printf("������Ҫɾ��������X:\n");
                scanf("%d",&x);
                flag=ListDelete1(L,x);
                if(flag)
                    printf("ɾ���ɹ�!!\n\n");
                else
                    printf("Ԫ�ز�����,ɾ��ʧ��!!\n\n");
                break;
            case 3:
                printf("������Ҫɾ����λ��i:\n");
                scanf("%d",&x);
                flag=ListDelete2(L,x-1);//��i��Ԫ�ض�Ӧ���±�Ϊi-1
                if(flag)
                    printf("ɾ���ɹ�!!\n\n");
                else
                    printf("Ԫ�ز�����,ɾ��ʧ��!!\n\n");
                break;
            case 4:
                Inverse(L);
                break;
            case 5:
                Sort(L);
                break;
            case 6:
                printf("������Ҫ���������X:\n");
                scanf("%d",&x);
                flag=ListInsert(L,x);   
                if(flag)
                    printf("����ɹ�!!\n\n");
                else
                    printf("����ʧ��!!\n\n");
                break;
            case 7:
                printf("������Lb������:\n");
                InitList(Lb);
                Build(Lb);
                flag=Merger(L,Lb);
                if(flag)
                    printf("�ϲ��ɹ�!!\n\n");
                break;
        }
        Tips();
        scanf("%d",&op);
    }
    return 0;
}
