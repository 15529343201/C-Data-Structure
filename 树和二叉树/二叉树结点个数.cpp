#include<stdio.h>
#include<stdlib.h>
typedef struct BiTreeNode
{
    char data;
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
}BiTreeNode,*BiTree;
 
//����������
void CreateBiTree(BiTree *tree)
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
      (*tree)=NULL;
    else
     {
        if(!(*tree=(BiTree)malloc(sizeof(BiTreeNode))))
          exit(-1);
        (*tree)->data=ch;
        CreateBiTree(&((*tree)->lchild));
        CreateBiTree(&((*tree)->rchild));
     }
}
 
//ͳ��Ҷ�ӽ����Ŀ
int LeafNum(BiTree tree)
{
    int LeafCount;
    if(tree==NULL)
      LeafCount=0;
    else if((tree->lchild==NULL) && (tree->rchild==NULL))
      LeafCount=1;
    else
      LeafCount=LeafNum(tree->lchild)+LeafNum(tree->rchild);
    return LeafCount;
}
 
//ͳ�ƶ�Ϊ1���ĸ���
int LeafCount1=0;
int LeafNum1(BiTree tree)
{
    if(tree!=NULL)
     {
        if((tree->lchild==NULL && tree->rchild!=NULL) ||
                    (tree->lchild!=NULL && tree->rchild==NULL))
          LeafCount1++;
        LeafNum1(tree->lchild);
        LeafNum1(tree->rchild);
     }
    return LeafCount1;
}
 
//ͳ�ƶ�Ϊ2���ĸ���
int LeafCount2=0;
int LeafNum2(BiTree tree)
{
    if(tree!=NULL)
     {
        if((tree->lchild!=NULL) && (tree->rchild!=NULL))
          LeafCount2++;
        LeafNum2(tree->lchild);
        LeafNum2(tree->rchild);
     }
    return LeafCount2;
}
 
//����������е�Ҷ�ӽ��
void OutPutdeafNode(BiTree tree)
{
    if(tree!=NULL)
     {
        OutPutdeafNode(tree->lchild);
        if(tree->lchild==NULL && tree->rchild==NULL)
          printf("%c",tree->data);
        OutPutdeafNode(tree->rchild);
     }
}
 
int main()
{
    BiTree T=NULL;
    CreateBiTree(&T);
    int number,number1,number2;
    number=LeafNum(T);
    number1=LeafNum1(T);
    number2=LeafNum2(T);
    printf("%d %d %d\n",number,number1,number2);
    OutPutdeafNode(T);
    return 0;
}
