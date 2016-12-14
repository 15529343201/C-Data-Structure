#include<stdio.h>
#include<stdlib.h>
//用图的邻接表表示
#define MAX 21
#define TRUE 1
#define FALSE 0
#define MAXSIZE 50

typedef struct
{
	int data[MAXSIZE];
	int rear,front;//队头队尾指针
}SeQueue;

//判断队列是否为空
int EmptyQueue(SeQueue *sq)
{
	int m;
	if((m=(sq->rear-sq->front))==0)
	  return 1;
	else
	  return 0;
}

//队列初始化
SeQueue *InitQueue()
{
	SeQueue *sq;
	sq=(SeQueue*)malloc(sizeof(SeQueue));
	sq->front=sq->rear=0;
	return sq;
}

//入队
int InQueue(SeQueue *sq,int x)
{
	int m;
	if((m=(sq->rear)-(sq->front))==MAXSIZE)
	  return 0;
	else
	 {
		sq->data[sq->rear]=x;
		sq->rear++;
		return 1;
	 }
}

//出队
int OutQueue(SeQueue *sq,int *x)
{
	int m;
	if((m=(sq->rear)-(sq->front))==0)
	  return 0;
	else
	 {
		*x=sq->data[sq->front];
		sq->front++;
		return 1;
	 }
}

//图的邻接表存储
typedef struct ArcNode
{
	int adjvex;//结点地址
	int weight;//权值
	struct ArcNode *next;//指向单链表下一个结点的指针
}ArcNode;//网的边结构

typedef struct VertexNode
{
	char vexdata;//顶点信息
	struct ArcNode *next;//指向该顶点边表的头指针
}VertexNode;//顶点结构

typedef struct 
{
	VertexNode vertex[MAX];
	int vexnum;     //顶点数
	int arcnum;     //弧数
}ALGraph;

int searcha(ALGraph *G,char a);

//建立图
void CreateDG(ALGraph *G)
{
	int i,j,k;
	char v1,v2;
	ArcNode *s,*p,*q;

	scanf("%d%d\n",&G->vexnum,&G->arcnum);

	for(i=1;i<=G->vexnum;i++)
	 {
		scanf("%c",&G->vertex[i].vexdata);
		G->vertex[i].next=NULL;
	 }

	for(i=1;i<=G->arcnum;i++)
	 {
		scanf("\n%c%c",&v1,&v2);
		ArcNode *s=(ArcNode*)malloc(sizeof(ArcNode));
		int k=searcha(G,v1);
		s->adjvex=searcha(G,v2);
		s->next=NULL;
		p=G->vertex[k].next;

		if(p==NULL)
		 {
			G->vertex[k].next=s;
		 }
		else if(p->adjvex>searcha(G,v2))
		 {
			s->next=p;
			G->vertex[k].next=s;
		 }
		else
		 {
			while(p&&p->adjvex<searcha(G,v2))
			 {
				q=p;
				p=p->next;
			 }
			s->next=q->next;
			q->next=s;
		 }
	 }
}

//查找点a的位置
int searcha(ALGraph *G,char a)
{
	int i;
	for(i=1;i<=G->vexnum;i++)
	 {
		if(G->vertex[i].vexdata==a)
		  return i;
	 }
}

//统计结点的入度和出度
void Degree(ALGraph *G,int od[],int id[])
{
	int i,j;
	ArcNode *p;

	for(i=1;i<=G->vexnum;i++)
	 {
		od[i]=id[i]=0;
	 }

	for(i=1;i<=G->vexnum;i++)
	 {
		p=G->vertex[i].next;
		while(p)
		 {
			od[i]++;
			j=p->adjvex;
			id[j]++;
			p=p->next;
		 }
	 }
	for(i=1;i<=G->vexnum;i++)
	 {
		printf("%c %d %d\n",G->vertex[i].vexdata,od[i],id[i]);
	 }
}

//深度优先遍历
int visited[MAX];
void DFS(ALGraph G,int vi)
{
	ArcNode *p;
	printf("%c",G.vertex[vi].vexdata);
    visited[vi]=TRUE;
	p=G.vertex[vi].next;
	while(p)
	 {
		if(!visited[p->adjvex])
		 {
			DFS(G,p->adjvex);
		 }
		p=p->next;
	 }
}

void TraverseDFS(ALGraph *G)
{
	int i;
	for(i=1;i<=G->vexnum;i++)
	 {
		visited[i]=FALSE;
	 }
	for(i=1;i<=G->vexnum;i++)
	 {
		if(!visited[i])
		 {
			DFS(*G,i);
		 }
	 }
}

void BFS(ALGraph *G,int vi);
//广度优先遍历
void TraverseBFS(ALGraph *G)
{
	int i;
	for(i=1;i<=G->vexnum;i++)
	 {
		visited[i]=FALSE;
	 }
	for(i=1;i<=G->vexnum;i++)
	 {
		if(!visited[i])
		 {
			BFS(G,i);
		 }
	 }
}

//输出遍历结点
void visit(ALGraph *G,int i)
{
	printf("%c",G->vertex[i].vexdata);
}

void BFS(ALGraph *G,int vi)
{
	int v;
	ArcNode *p;
	SeQueue *Q;
	Q=InitQueue();
	visit(G,vi);
	visited[vi]=TRUE;
	InQueue(Q,vi);
	while(!EmptyQueue(Q))
	 {
		OutQueue(Q,&v);
		p=G->vertex[v].next;
		while(p)
		 {
			if(!visited[p->adjvex])
			 {
				visit(G,p->adjvex);
				visited[p->adjvex]=TRUE;
				InQueue(Q,p->adjvex);
			 }
			p=p->next;
		 }
	 }
}

int main()
{
	ALGraph *G;
	G=(ALGraph*)malloc(sizeof(ALGraph));
	CreateDG(G);
	int od[G->vexnum];
	int id[G->vexnum];
	Degree(G,od,id);
	TraverseDFS(G);
	printf("\n");
	TraverseBFS(G);
	return 0;
}
