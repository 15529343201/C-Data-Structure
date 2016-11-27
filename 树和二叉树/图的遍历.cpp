//ͼ�ı���
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VERTEX_NUM 20

typedef int QElemType;
typedef int VRType;
typedef char VertexType;
typedef enum 
{
	DG,//����ͼ
	UDG//����ͼ 
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
	VertexType vexs[MAX_VERTEX_NUM];//��������
	VRType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ڽӾ���
	int vexnum,arcnum;//�������ͻ��� 
	GKind kind;//ͼ�������ʶ 
}MGraph; 

//��ʼ������  
void InitQ(LinkQueue &Q);  
//�Ӷ�β����Ԫ��  
void EnQueue(LinkQueue &Q,QElemType e);  
//�Ӷ���ɾ��Ԫ��  
void DeQueue(LinkQueue &Q,QElemType &e);  
//�����Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0  
int QEmpty(const LinkQueue &Q);  
  
//ѡ�񴴽�ͼ������  
void CreateGraph(MGraph &G);  
//��������ͼ  
void CreateUDG(MGraph &G);  
//��������ͼ  
void CreateDG(MGraph &G);  
//��ӡ�ڽӾ���  
void printArcs(const MGraph &G);  
//�����ַ��ڶ��������е��±�ֵ  
int LocateVex(const MGraph &G,VertexType ch);  
//������ȱ�������  
void DFSTraverse(const MGraph &G);  
void DFS(const MGraph &G,int v);  
//������ȱ�������  
void BFSTraverse(const MGraph &G);  
//�õ���һ��δ�����ʵ����ڽڵ��±꣬���ޣ��򷵻�-1  
int firstAjdVex(const MGraph &G,int v);  
//�õ���һ��δ�����ʵ����ڽڵ��±꣬���ޣ��򷵻�-1  
int nextAjdVex(const MGraph &G,int v,int w);  
int *visited;   //��¼�����Ƿ񱻷���  

//������
int main()
{
	MGraph G;
	CreateGraph(G);
	printf("\nԭʼ�ڽӾ���:\n");
	printArcs(G);
	//������ȱ������
	printf("\n������ȱ���:");
	DFSTraverse(G);
	//������ȱ������
	printf("\n������ȱ���:");
	BFSTraverse(G);
	printf("\n");
	return 0; 
}

//��ʼ������
void InitQ(LinkQueue &Q)
{
	Q.front=Q.tail=(QPtr)malloc(sizeof(QNode));
	if(!Q.front)
	{
		printf("InitQ�����ڴ����!\n");
		return;
	}
	Q.front->next=NULL;
}

//�Ӷ�β����Ԫ��
void EnQueue(LinkQueue &Q,QElemType e)
{
	QPtr q=(QPtr)malloc(sizeof(QNode));
	if(!q)
	{
		printf("EnQueue�����ڴ����!\n");
		return;
	}
	q->data=e;
	q->next=NULL;
	Q.tail->next=q;
	Q.tail=q;
}

//�Ӷ���ɾ��Ԫ��
void DeQueue(LinkQueue &Q,QElemType &e)
{
	if(Q.front==Q.tail)
	{
		printf("DeQueue����Ϊ�գ�����ɾ��Ԫ��");
		return;
	}
	QPtr q=Q.front->next;
	e=q->data;
	Q.front->next=q->next;
	if(Q.tail==q)
	  Q.tail=Q.front;
	free(q);
}

//�����Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0
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

//ѡ�񴴽�ͼ������
void CreateGraph(MGraph &G)  
{  
    int k; 
	printf("*******************\n"); 
    printf("��������ͼ,����0;\n");
    printf("��������ͼ,����1;\n");
    printf("������ȷ�ϼ�.\n");
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
        printf("ͼ������������!");  
        break;  
    }   
} 

//��������ͼ
void CreateUDG(MGraph &G)
{
	int i,j,k,w;
	char v1,v2;
	
	printf("���붥�����ͱ���:");
	scanf("%d%d",&G.vexnum,&G.arcnum);
	
	visited=(int*)malloc(G.vexnum*sizeof(int));
	for(i=0;i<G.vexnum;i++)
	{
		visited[i]=0;
	}
	printf("�밴��������%d��������ĸ���(��ABC��):",G.vexnum);
	
	getchar();//�������������ϴ��������Ļ��з�,������µĻس���
	for(i=0;i<G.vexnum;i++)
	{
		scanf("%c",&G.vexs[i]);
	}
	
	getchar();//�������������ϴ�������Ļ��з���������µĻس���  
	for(i=0;i<G.vexnum;i++)
	for(j=0;j<G.vexnum;j++)
	{//��ʼ���ڽӾ��� 
		if(i==j)
		  G.arcs[i][j]=0;
		else
		  G.arcs[i][j]=INT_MAX;
	}
	
	printf("����ߵĶ����Ȩֵ(��A B 1):\n");
	
	for(k=0;k<G.arcnum;k++)
	{
		scanf("%c %c %d",&v1,&v2,&w);
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		G.arcs[i][j]=w;
		G.arcs[j][i]=w;
		getchar();//�������������ϴ�������Ļ��з���������µĻس���
	} 
}  

//��������ͼ  
void CreateDG(MGraph &G)  
{//�ʹ�������ͼ���ƣ�ֻ������һ�佫G.arcs[j][i] = w;  
 //��Ϊ����ͼ�ǶԳƵģ�������ͼ����  
    int i,j,k,w;  
    char v1,v2;  
  
    printf("���붥�����ͱ�����");  
    scanf("%d%d",&G.vexnum,&G.arcnum);   
  
    visited = (int *)malloc(G.vexnum*sizeof(int));  
    for ( i = 0; i < G.vexnum; i++ )  
        visited[i] = 0;  
    printf("�밴��������%d��������ĸ���(��ABC��)��",G.vexnum);  
  
    getchar();//�������������ϴ�������Ļ��з���������µĻس���  
    for ( i = 0; i < G.vexnum; i++ )  
        scanf("%c",&G.vexs[i]);  
          
    getchar();//�������������ϴ�������Ļ��з���������µĻس���  
    for ( i = 0; i < G.vexnum; ++i )  
    for ( j = 0; j < G.vexnum; ++j )  
    {//��ʼ���ڽӾ���  
        if ( i == j )  
           G.arcs[i][j] = 0;  
        else  
           G.arcs[i][j] = INT_MAX;  
    }  
      
    printf("����ߵĶ����Ȩֵ(��A B 1):\n");  
      
    for ( k = 0; k < G.arcnum; k++ )  
    {  
        scanf("%c %c %d",&v1,&v2,&w);  
        i = LocateVex(G,v1);  
        j = LocateVex(G,v2);  
        G.arcs[i][j] = w;  
        getchar();//�������������ϴ�������Ļ��з���������µĻس���  
    }  
}

//��ӡ�ڽӾ���
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

//�����ַ��ڶ��������е��±�ֵ
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

//������ȱ�������
void DFSTraverse(const MGraph &G)
{
	int i;
	for(i=0;i<G.vexnum;i++)
	   visited[i]=0;//��ʼ�����ʱ������
	for(i=0;i<G.vexnum;i++)
	   if(!visited[i])
	   {//����δ���ʵĶ������DFS
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

//������ȱ���
void BFSTraverse(const MGraph &G)
{
	int i,w,v;
	LinkQueue Q;
	InitQ(Q);
	
	for(i=0;i<G.vexnum;i++)
	   visited[i]=0;//��ʼ�����ʱ������
	
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
//�õ���һ��δ�����ʵ����ڽڵ��±꣬���ޣ��򷵻�-1
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

//�õ���һ��δ�����ʵ����ڽڵ��±꣬���ޣ��򷵻�-1  
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
