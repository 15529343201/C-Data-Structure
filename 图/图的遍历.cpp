//图的遍历
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VERTEX_NUM 20

typedef int QElemType;
typedef int VRType;
typedef char VertexType;
typedef enum 
{
	DG,//有向图
	UDG//无向图 
}GKind;

typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QPtr;

typedef struct
{
	QPtr front;
	QPtr tail;
}LinkQueue;

typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];//顶点向量
	VRType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//邻接矩阵
	int vexnum,arcnum;//顶点数和弧数 
	GKind kind;//图的种类标识 
}MGraph; 

//初始化队列  
void InitQ(LinkQueue &Q);  
//从队尾插入元素  
void EnQueue(LinkQueue &Q,QElemType e);  
//从对首删除元素  
void DeQueue(LinkQueue &Q,QElemType &e);  
//队列是否为空，为空返回1，否则返回0  
int QEmpty(const LinkQueue &Q);  
  
//选择创建图的类型  
void CreateGraph(MGraph &G);  
//创建无向图  
void CreateUDG(MGraph &G);  
//创建有向图  
void CreateDG(MGraph &G);  
//打印邻接矩阵  
void printArcs(const MGraph &G);  
//返回字符在定点向量中的下标值  
int LocateVex(const MGraph &G,VertexType ch);  
//深度优先遍历函数  
void DFSTraverse(const MGraph &G);  
void DFS(const MGraph &G,int v);  
//广度优先遍历函数  
void BFSTraverse(const MGraph &G);  
//得到第一个未被访问的相邻节点下标，若无，则返回-1  
int firstAjdVex(const MGraph &G,int v);  
//得到下一个未被访问的相邻节点下标，若无，则返回-1  
int nextAjdVex(const MGraph &G,int v,int w);  
int *visited;   //记录顶点是否被访问  

//主函数
int main()
{
	MGraph G;
	CreateGraph(G);
	printf("\n原始邻接矩阵:\n");
	printArcs(G);
	//深度优先遍历结果
	printf("\n深度优先遍历:");
	DFSTraverse(G);
	//广度优先遍历结果
	printf("\n广度优先遍历:");
	BFSTraverse(G);
	printf("\n");
	return 0; 
}

//初始化队列
void InitQ(LinkQueue &Q)
{
	Q.front=Q.tail=(QPtr)malloc(sizeof(QNode));
	if(!Q.front)
	{
		printf("InitQ分配内存出错!\n");
		return;
	}
	Q.front->next=NULL;
}

//从队尾插入元素
void EnQueue(LinkQueue &Q,QElemType e)
{
	QPtr q=(QPtr)malloc(sizeof(QNode));
	if(!q)
	{
		printf("EnQueue分配内存出错!\n");
		return;
	}
	q->data=e;
	q->next=NULL;
	Q.tail->next=q;
	Q.tail=q;
}

//从队首删除元素
void DeQueue(LinkQueue &Q,QElemType &e)
{
	if(Q.front==Q.tail)
	{
		printf("DeQueue队列为空，不能删除元素");
		return;
	}
	QPtr q=Q.front->next;
	e=q->data;
	Q.front->next=q->next;
	if(Q.tail==q)
	  Q.tail=Q.front;
	free(q);
}

//队列是否为空，为空返回1，否则返回0
int QEmpty(const LinkQueue &Q)
{
	if(Q.front==Q.tail)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//选择创建图的类型
void CreateGraph(MGraph &G)  
{  
    int k; 
	printf("*******************\n"); 
    printf("创建有向图,输入0;\n");
    printf("创建无向图,输入1;\n");
    printf("并按下确认键.\n");
    printf("*******************\n");
    scanf("%d",&k);  
    switch(k)  
    {  
    case 0:  
        G.kind = DG;  
        CreateDG(G);  
        break;  
    case 1:  
        G.kind = UDG;  
        CreateUDG(G);  
        break;  
    default:  
        printf("图类型输入有误!");  
        break;  
    }   
} 

//创建无向图
void CreateUDG(MGraph &G)
{
	int i,j,k,w;
	char v1,v2;
	
	printf("输入顶点数和边数:");
	scanf("%d%d",&G.vexnum,&G.arcnum);
	
	visited=(int*)malloc(G.vexnum*sizeof(int));
	for(i=0;i<G.vexnum;i++)
	{
		visited[i]=0;
	}
	printf("请按次序输入%d个顶点字母标号(如ABC等):",G.vexnum);
	
	getchar();//弹出缓冲区中上次最后输入的换行符,及最后按下的回车键
	for(i=0;i<G.vexnum;i++)
	{
		scanf("%c",&G.vexs[i]);
	}
	
	getchar();//弹出缓冲区中上次最后出入的换行符，即最后按下的回车键  
	for(i=0;i<G.vexnum;i++)
	for(j=0;j<G.vexnum;j++)
	{//初始化邻接矩阵 
		if(i==j)
		  G.arcs[i][j]=0;
		else
		  G.arcs[i][j]=INT_MAX;
	}
	
	printf("输入边的顶点和权值(如A B 1):\n");
	
	for(k=0;k<G.arcnum;k++)
	{
		scanf("%c %c %d",&v1,&v2,&w);
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		G.arcs[i][j]=w;
		G.arcs[j][i]=w;
		getchar();//弹出缓冲区中上次最后出入的换行符，即最后按下的回车键
	} 
}  

//创建有向图  
void CreateDG(MGraph &G)  
{//和创建无向图类似，只是少了一句将G.arcs[j][i] = w;  
 //因为无向图是对称的，而有向图不是  
    int i,j,k,w;  
    char v1,v2;  
  
    printf("输入顶点数和边数：");  
    scanf("%d%d",&G.vexnum,&G.arcnum);   
  
    visited = (int *)malloc(G.vexnum*sizeof(int));  
    for ( i = 0; i < G.vexnum; i++ )  
        visited[i] = 0;  
    printf("请按次序输入%d个顶点字母标号(如ABC等)：",G.vexnum);  
  
    getchar();//弹出缓冲区中上次最后出入的换行符，即最后按下的回车键  
    for ( i = 0; i < G.vexnum; i++ )  
        scanf("%c",&G.vexs[i]);  
          
    getchar();//弹出缓冲区中上次最后出入的换行符，即最后按下的回车键  
    for ( i = 0; i < G.vexnum; ++i )  
    for ( j = 0; j < G.vexnum; ++j )  
    {//初始化邻接矩阵  
        if ( i == j )  
           G.arcs[i][j] = 0;  
        else  
           G.arcs[i][j] = INT_MAX;  
    }  
      
    printf("输入边的顶点和权值(如A B 1):\n");  
      
    for ( k = 0; k < G.arcnum; k++ )  
    {  
        scanf("%c %c %d",&v1,&v2,&w);  
        i = LocateVex(G,v1);  
        j = LocateVex(G,v2);  
        G.arcs[i][j] = w;  
        getchar();//弹出缓冲区中上次最后出入的换行符，即最后按下的回车键  
    }  
}

//打印邻接矩阵
void printArcs(const MGraph &G)
{
	int i;
	int j;
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			if(G.arcs[i][j]==INT_MAX)
			  printf("%6s","INF");
			else
			  printf("%6d",G.arcs[i][j]);
		}
		printf("\n");
	}
}

//返回字符在定点向量中的下标值
int LocateVex(const MGraph &G,VertexType ch)
{
	int i;
	for(i=0;G.vexnum;i++)
	{
		if(G.vexs[i]==ch)
		  return i;
	}
	return -1;
}

//深度优先遍历函数
void DFSTraverse(const MGraph &G)
{
	int i;
	for(i=0;i<G.vexnum;i++)
	   visited[i]=0;//初始化访问标记数组
	for(i=0;i<G.vexnum;i++)
	   if(!visited[i])
	   {//对尚未访问的顶点调用DFS
	        DFS(G,i); 
	   }
	   printf("\n"); 
}

void DFS(const MGraph &G,int v)
{
	int w;
	visited[v]=1;
	printf("%-4c",G.vexs[v]);
	for(w=firstAjdVex(G,v);w>=0;w=nextAjdVex(G,v,w))
	{
		if(!visited[w])
		  DFS(G,w);
	}
}

//广度优先遍历
void BFSTraverse(const MGraph &G)
{
	int i,w,v;
	LinkQueue Q;
	InitQ(Q);
	
	for(i=0;i<G.vexnum;i++)
	   visited[i]=0;//初始化访问标记数组
	
	for(i=0;i<G.vexnum;i++)
	{
		if(!visited[i])
		{
			visited[i]=1;
			printf("%-4c",G.vexs[i]);
			EnQueue(Q,i);
			while(!QEmpty(Q))
			{
				DeQueue(Q,v);
				for(w=firstAjdVex(G,v);w>=0;w=nextAjdVex(G,v,w))
				{
					if(!visited[w])
					{
						visited[w]=1;
						printf("%-4c",G.vexs[w]);
						EnQueue(Q,w);					
					}
				}
			}		
	    }   
    }
} 
//得到第一个未被访问的相邻节点下标，若无，则返回-1
int firstAjdVex(const MGraph &G,int v)
{
	int i;
	for(i=0;i<G.vexnum;i++)
	{
		if(!visited[i] && G.arcs[v][i]>0 && G.arcs[v][i]<INT_MAX)
		  return i;
	}
	return -1;
} 

//得到下一个未被访问的相邻节点下标，若无，则返回-1  
int nextAjdVex(const MGraph &G,int v,int w)  
{  
    int i;  
    for ( i = w; i < G.vexnum; i++ )  
    {  
        if ( !visited[i] && G.arcs[v][i] > 0 && G.arcs[v][i] < INT_MAX)  
            return i;  
    }  
    return -1;  
}    
