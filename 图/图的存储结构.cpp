//ͼ�Ĵ洢�ṹ

//�ڽӾ���
/*�ڽӾ���ȿ��������洢����ͼ��Ҳ���������洢����ͼ��
�ýṹʵ���Ͼ�����һ����ά����(�ڽӾ���)���洢�����
��Ϣ�Ͷ���֮��Ĺ�ϵ(����ͼ�Ļ�������ͼ�ı�)*/
 
//ͼ���ڽӾ���洢��ʾ
#define MAX_NUM 20//��󶥵����
enum GraphKind{GY,GN};//{����ͼ,����ͼ}
typedef struct
{
	VRType adj;//�����ϵ���͡�����Ȩͼ����1(��)��0(��)��ʾ�Ƿ�����;�Դ�Ȩͼ,��ΪȨֵ
	InfoType *info;//��û���������Ϣ��ָ��(����) 
}ArcCell,AdjMatrix[MAX_NUM][MAX_NUM];//��ά����
typedef struct
{
	VertexType vexs[MAX_NUM];//��������
	AdjMatrix arcs;//�ڽӾ���
	int vexnum,arcnum;//ͼ�ĵ�ǰ�������ͻ�(��)��
	GraphKind kind;//ͼ�������־ 
}Graph; 

//�ڽӱ�
/*�ڽӱ���ͼ��һ����ʽ�洢�ṹ�����ʺϴ洢����ͼ��Ҳ�ʺ��ڴ洢
����ͼ�����ڽӱ��У���һ��һά����洢ͼ�е�ÿ�����㣬ͬʱΪÿ������
����һ�������������еĽڵ㱣�������ڸö����ϵı߻򻡵���Ϣ��*/ 
//ͼ���ڽӱ�洢��ʾ
#define MAX_NUM 20
enum GraphKind {GY,GN};//{����ͼ,����ͼ} 
typedef struct
{
	int adjvex;//�û���ָ��Ķ����ߵ���һ�������λ��
	ArcNode *nextarc;//ָ����һ������ߵ�ָ��
	InfoType *info;//�뻡��������Ϣ��ָ��(����) 
}ArcNode;//����
typedef struct
{
	VertexType data;//������Ϣ
	ArcNode *firstarc;//��һ������ĵ�ַ,ָ���һ�������ö���Ļ���ߵ�ָ�� 
}VNode,AdjList[MAX_NUM];//ͷ���
struct
{
	AdjList vertices;
	int vexnum,arcnum;//ͼ�ĵ�ǰ�������ͻ�(��)��
	GraphKind kind;//ͼ�������ʶ 
}Graph; 

//ʮ������
/*ʮ������Ҳ��һ����ʽ�洢�ṹ��������ʾ����ͼ����������ͼ�ڽӱ�Ļ����ϼ�����ָ��β��ָ��*/ 
//����ͼ��ʮ�������ʾ 
#define MAX_NUM 20
typedef struct//�����
{
	int tailvex,headvex;//�û���β��ͷ�����λ��
	ArcBox *hlink,*tlink;//�ֱ�Ϊ��ͷ��ͬ�ͻ�β��ͬ�Ļ�������
	InfoType *info;//�û������Ϣ��ָ�룬��ָ��Ȩֵ��������Ϣ(����)
}ArcBox;
typedef struct//������
{
	VertexType data;
	ArcBox *firstin,*firstout;//�ֱ�ָ��ö����һ���뻡�ͳ��� 
}VexNode;
struct
{
	VexNode xlist[MAX_NUM];//��ͷ����(����)
	int vexnum,arcnum;//����ͼ�ĵ�ǰ����ͻ��� 
}Graph; 

//�ڽӶ��ر�
/*�ڽӶ��ر�Ҳ��һ����ʽ�洢�ṹ��������ʾ����ͼ��
������ͼ��ʮ����������*/
//����ͼ���ڽӶ��ر�洢��ʾ
#define MAX_NUM 20
typedef struct
{
	VisitIf mark;//���ʱ��
	int ivex,jvex;//�����������������λ��
	EBox *ilink,*jlink;//�ֱ�ָ�������������������һ����
	InfoType *info;//�ñ���Ϣָ�룬��ָ��Ȩֵ��������Ϣ 
}EBox;
typedef struct
{
	VertexType data;
	EBox *firstedge;//ָ���һ�������ö���ı� 
}VexBox;
typedef struct
{
	VexBox adjmulist[MAX_NUM];
	int vexnum,edgenum;//����ͼ�ĵ�ǰ�������ͱ��� 
}Graph; 
