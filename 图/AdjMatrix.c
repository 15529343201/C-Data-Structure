#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 20  //最大顶点个数

int visited[MAXVEX];//访问数组

typedef struct//图的结构体
{
	int arcs[MAXVEX][MAXVEX];//存储结点的邻接矩阵
	char vex[MAXVEX];//结点数组
	int vexnum;//结点个数
	int arcnum;//边的个数(关系个数)
}adjMatrix;

typedef struct
{
	int front,rear;//队头队尾指针
	int count;
	char data[MAXVEX];
}SeQueue,*Queue;

//定位
int Locate(adjMatrix *G,char x)
{
	int i;
	for(i=1;i<=G->vexnum;i++)
	 {
		if(x==G->vex[i])
		  return i;
	 }
	return -1;
}

//创建图(邻接矩阵)
void CreateDG(adjMatrix *G)
{
	int i,j,k;
	char v1,v2;
	scanf("%d %d",&G->vexnum,&G->arcnum);
	getchar();
	for(i=1;i<=G->vexnum;i++)
	 {
		scanf("%c",&G->vex[i]);
	 }

	//初始化邻接矩阵
	for(i=1;i<=G->vexnum;i++)
	 {
		for(j=1;j<=G->vexnum;j++)
		 {
			G->arcs[i][j]=0;
		 }
	 }

	for(k=1;k<=G->arcnum;k++)
	 {
		getchar();
		scanf("%c%c",&v1,&v2);
		i=Locate(G,v1);
		j=Locate(G,v2);
		G->arcs[i][j]=1;
	 }
}

//统计图顶点的出入度
void Degree(adjMatrix *G,int od[],int id[])
{
	int i,j,k;
	for(i=1;i<=G->vexnum;i++)
	 {
		od[i]=0;
		for(j=1;j<=G->vexnum;j++)
		 {
			if(G->arcs[i][j]!=0)
			  od[i]++;
		 }
	 }

	for(j=1;j<=G->vexnum;j++)
	 {
		id[j]=0;
		for(i=1;i<=G->vexnum;i++)
		 {
			if(G->arcs[i][j]!=0)
			  id[j]++;
		 }
	 }

	for(k=1;k<=G->vexnum;k++)
	 {
		printf("%c %d %d\n",G->vex[k],od[k],id[k]);
	 }
}

//深度优先遍历
void DFS(adjMatrix *G,int vi)
{
	printf("%c",G->vex[vi]);
	visited[vi]=1;
	int vj=0;
	while(vj<G->vexnum)
	 {
		if(!visited[vj] && G->arcs[vi][vj]==1)
		  DFS(G,vj);
		vj++;
	 }
}

void TraverseDFS(adjMatrix *G)
{
	int i;
	for(i=1;i<=G->vexnum;i++)
	 {
		visited[i]=0;
	 }

	for(i=1;i<=G->vexnum;i++)
	 {
		if(!visited[i])
		  DFS(G,i);
	 }
}

//广度优先遍历
void BFS(adjMatrix *G,int vi)
{
	int j,k;
	SeQueue *p;
	
	//置空队
	p=(Queue)malloc(sizeof(SeQueue));
	p->front=p->rear=MAXVEX-1;
	p->count=0;

    //入队
	p->rear=(p->rear+1)%MAXVEX;
	p->data[p->rear]=G->vex[vi];
	p->count++;

	printf("%c",G->vex[vi]);
	visited[vi]=1;

	//出队
	while(p->count!=0)
	 {
		p->front=(p->front+1)/MAXVEX;
		j=p->front;
		p->count--;

		for(k=1;k<=G->vexnum;k++)
		 {
			if(G->arcs[j][k]==1&&visited[k]==0)
			 {
				p->rear=(p->rear+1)%MAXVEX;
				p->data[p->rear]=G->vex[k];
				p->count++;


				printf("%c",G->vex[k]);
				visited[k]=1;
			 }
		 }
	 }
}

void TraverseBFS(adjMatrix *G)
{
	int i;
	for(i=1;i<=G->vexnum;i++)
	 {
		visited[i]=0;
	 }

	for(i=1;i<=G->vexnum;i++)
	 {
		if(!visited[i])
		  BFS(G,i);
	 }
}

int main()
{
	int od[20],id[20];
	adjMatrix G;
	CreateDG(&G);
	Degree(&G,od,id);
	TraverseDFS(&G);
	printf("\n");
	TraverseBFS(&G);
	return 0;
}

