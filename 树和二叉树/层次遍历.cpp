//����α��������� 
#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    char data;
    struct tree *lchild,*rchild;
}BiTNode,*BiTree;//���������ṹ 
typedef struct queue
{
    BiTree ch;
    struct queue *next;
}QueueNode,*Queueptr;//������н��ṹ
typedef struct
{
    Queueptr front;
    Queueptr rear;
}LinkQueue;//�������ָ��
 
//����������
void CreateBiTree(BiTree &T)
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
    {
        T=NULL;
    }
    else
    {
        if(!(T=(BiTree)malloc(sizeof(BiTNode))))
          return;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
} 
 
//��ʼ��һ����ͷ���Ķ���
void InitQueue(LinkQueue &q)
{
    q.front=q.rear=(Queueptr)malloc(sizeof(QueueNode));
    q.front->next=NULL;
}
 
//���
void EnQueue(LinkQueue &q,BiTree p)
{
    Queueptr s;
    int first=1;
    s=(Queueptr)malloc(sizeof(QueueNode));
    s->ch=p;
    s->next=NULL;
    q.rear->next=s;
    q.rear=s;
}
 
//����
void DeQueue(LinkQueue &q,BiTree &p)
{
    char data;
    Queueptr s;
    s=q.front->next;
    p=s->ch;
    data=p->data;
    q.front->next=s->next;
    if(q.rear==s)
       q.rear=q.front;
    free(s);
    printf("%c",data);
} 
 
//�жӿ�
int QueueEmpty(LinkQueue q)
{
    if(q.front->next==NULL)
       return 1;
    return 0;
}
 
//����α������н��
void Traverse(BiTree T) 
{
    LinkQueue q;
    BiTree p;
    InitQueue(q);
    p=T;
    EnQueue(q,p);
    while(QueueEmpty(q)!=1)
    {
        DeQueue(q,p);
        if(p->lchild!=NULL)
          EnQueue(q,p->lchild);
        if(p->rchild!=NULL)
          EnQueue(q,p->rchild);
    }
    printf("\n");
}
 
int main()
{
    BiTree T;
    CreateBiTree(T);
    Traverse(T);
    return 0;
}
