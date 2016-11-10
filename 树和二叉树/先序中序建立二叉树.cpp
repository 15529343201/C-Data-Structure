//����������������
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//���������
typedef struct BiTNode
{
	char data;//����
	struct BiTNode *lchild,*rchild;//���Һ���ָ�� 
}BiTNode,*BiTree;

//��������
char PreArray[101];
//��������
char InArray[101];

/*
    PreS    �������еĵ�һ��Ԫ���±�
	PreE    �������е����һ��Ԫ���±�
	InS     �������еĵ�һ��Ԫ���±�
	InE     �������е����һ��Ԫ���±�
	PreArray������������
	InArray ������������
*/

void PreInCreateTree(BiTree &T,int PreS,int PreE,int InS,int InE)
{
	int RootIndex;
	//�����һ���ַ�
	T = (BiTree)malloc(sizeof(BiTNode));
	T->data = PreArray[PreS];
	//Ѱ�Ҹý�������������е�λ��
	for(int i = InS;i <= InE;i++)
	{
		if(T->data == InArray[i])
		{
			RootIndex = i;
			break;
		}
	}
	
	//��������������Ϊ��
	if(RootIndex != InS)
	{
		//�Ը�����������Ϊ������
		PreInCreateTree(T->lchild,PreS+1,(RootIndex-InS)+PreS,InS,RootIndex-1); 
	}
	else
	{
		T->lchild = NULL;
	}
	
	//��������������Ϊ��
	if(RootIndex != InE)
	{
		//�Ը������ҽ��Ϊ������
		PreInCreateTree(T->rchild,PreS+1+(RootIndex-InS),PreE,RootIndex+1,InE); 
	}
	else
	{
		T->rchild = NULL;
	}
}

//�������
void PostOrder(BiTree T)
{
	if(T->lchild != NULL)
	{
		//�������ӽڵ�
		PostOrder(T->lchild); 
	}
	if(T->rchild != NULL)
	{
		//�������ӽڵ�
		PostOrder(T->rchild); 
	}
	//���ʸ��ڵ�
	printf("%c",T->data); 
}

int main()
{
	while(scanf("%s",PreArray) != EOF)
	{
		BiTree T;
		scanf("%s",InArray);
		PreInCreateTree(T,0,strlen(PreArray)-1,0,strlen(InArray)-1);
		PostOrder(T);
		printf("\n"); 
	}
	return 0;
}	  
