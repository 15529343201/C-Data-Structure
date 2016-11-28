//图的存储结构

//邻接矩阵
/*邻接矩阵既可以用来存储无向图，也可以用来存储有向图。
该结构实际上就是用一个二维数组(邻接矩阵)来存储顶点的
信息和顶点之间的关系(有向图的弧或无向图的边)*/
 
//图的邻接矩阵存储表示
#define MAX_NUM 20//最大顶点个数
enum GraphKind{GY,GN};//{有向图,无向图}
typedef struct
{
	VRType adj;//顶点关系类型。对无权图，用1(是)或0(否)表示是否相邻;对带权图,则为权值
	InfoType *info;//与该弧或边相关信息的指针(可无) 
}ArcCell,AdjMatrix[MAX_NUM][MAX_NUM];//二维数组
typedef struct
{
	VertexType vexs[MAX_NUM];//顶点向量
	AdjMatrix arcs;//邻接矩阵
	int vexnum,arcnum;//图的当前顶点数和弧(边)数
	GraphKind kind;//图的种类标志 
}Graph; 

//邻接表
/*邻接表是图的一种链式存储结构，既适合存储有向图，也适合于存储
无向图。在邻接表中，用一个一维数组存储图中的每个顶点，同时为每个顶点
建立一个单链表，链表中的节点保存依附在该顶点上的边或弧的信息。*/ 
//图的邻接表存储表示
#define MAX_NUM 20
enum GraphKind {GY,GN};//{有向图,无向图} 
typedef struct
{
	int adjvex;//该弧所指向的顶点或边的另一个顶点的位置
	ArcNode *nextarc;//指向下一条弧或边的指针
	InfoType *info;//与弧或边相关信息的指针(可无) 
}ArcNode;//表结点
typedef struct
{
	VertexType data;//顶点信息
	ArcNode *firstarc;//第一个表结点的地址,指向第一条依附该顶点的弧或边的指针 
}VNode,AdjList[MAX_NUM];//头结点
struct
{
	AdjList vertices;
	int vexnum,arcnum;//图的当前顶点数和弧(边)数
	GraphKind kind;//图的种类标识 
}Graph; 

//十字链表
/*十字链表也是一种链式存储结构，用来表示有向图，它在有向图邻接表的基础上加入了指向弧尾的指针*/ 
//有向图的十字链表表示 
#define MAX_NUM 20
typedef struct//弧结点
{
	int tailvex,headvex;//该弧的尾和头顶点的位置
	ArcBox *hlink,*tlink;//分别为弧头相同和弧尾相同的弧的链域
	InfoType *info;//该弧相关信息的指针，可指向权值或其他信息(可无)
}ArcBox;
typedef struct//顶点结点
{
	VertexType data;
	ArcBox *firstin,*firstout;//分别指向该顶点第一条入弧和出弧 
}VexNode;
struct
{
	VexNode xlist[MAX_NUM];//表头向量(数组)
	int vexnum,arcnum;//有向图的当前顶点和弧数 
}Graph; 

//邻接多重表
/*邻接多重表也是一种链式存储结构，用来表示无向图，
与有向图的十字链表相似*/
//无向图的邻接多重表存储表示
#define MAX_NUM 20
typedef struct
{
	VisitIf mark;//访问标记
	int ivex,jvex;//边依附的两个顶点的位置
	EBox *ilink,*jlink;//分别指向依附这两个顶点的下一条边
	InfoType *info;//该边信息指针，可指向权值或其他信息 
}EBox;
typedef struct
{
	VertexType data;
	EBox *firstedge;//指向第一条依附该顶点的边 
}VexBox;
typedef struct
{
	VexBox adjmulist[MAX_NUM];
	int vexnum,edgenum;//无向图的当前顶点数和边数 
}Graph; 
