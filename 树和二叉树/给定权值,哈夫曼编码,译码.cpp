#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 6
#define M 2*N-1
#define MAXINT 32767
#define ch 30
#define NUM 100
typedef char numcode[NUM];
typedef char charcode[ch];
typedef char* HuffmanCode[N];
typedef struct
{
	int weight;//权值
	int parent,lchild,rchild;//左右子节点和父节点 
}HTNode,HuffmanTree[M];

void numtochar(numcode ns,HuffmanTree ht,char s[]);
void select(HuffmanTree ht,int pos,int *s1,int *s2);
void CreateHuffmanTree(HuffmanTree ht,int w[],int n);
void chartocode(charcode c,char s[],HuffmanCode hc);
void printcode(char s[],HuffmanCode hc);
void CreateHuffmanCode(HuffmanTree ht,HuffmanCode hc,int n);

int main()
{
	HuffmanTree ht;
	HuffmanCode hc;
	charcode c;
	numcode ns;
	char s[N] = {'A','B','C','D','E','F'};
	int w[N];
	int i;
	
	for(i = 0;i < N;i++)
	{
		scanf("%d",&w[i]);
	}
	scanf("%s",&c);
	scanf("%s",&ns);
	CreateHuffmanTree(ht,w,6);
	CreateHuffmanCode(ht,hc,6);
	printcode(s,hc);
	chartocode(c,s,hc);
	numtochar(ns,ht,s);
	return 0;
}

//建立哈夫曼树 
void CreateHuffmanTree(HuffmanTree ht,int w[],int n)
{
	int i,s1,s2,m;
	m = 2*n-1;
	for(i=0;i<n;i++)
	{
		ht[i].weight=w[i];
		ht[i].parent=-1;
		ht[i].lchild=-1;
		ht[i].rchild=-1;
	}
	for(i=n;i<m;i++)
	{
		ht[i].weight=0;
		ht[i].parent=-1;
		ht[i].lchild=-1;
		ht[i].rchild=-1; 
	}
	//选择合并
	for(i=n;i<m;i++)
	{
		select(ht,i-1,&s1,&s2);
		ht[i].weight = ht[s1].weight+ht[s2].weight;
		ht[s1].parent=i;
		ht[s2].parent=i;
		ht[i].lchild=s1;
		ht[i].rchild=s2;
	} 
}

//找出数组中无父节点且权值最小的两个节点下标，分别用s1和s2保存 
void select(HuffmanTree ht,int pos,int *s1,int *s2)
{
	//m1存放最小权值,s1是m1在数组的下标
	//m2存放次小权值,s2是m2在数组的下标
	int i,j,m1,m2;
	m1=m2=MAXINT;
	for(j=0;j<=pos;j++)
	{
		if(ht[j].weight<m1 && ht[j].parent==-1)
		{
			m2=m1;
			*s2=*s1;
			m1=ht[j].weight;
			*s1=j;
					
		}
		else if(ht[j].weight<m2 && ht[j].parent==-1)
		{
			m2=ht[j].weight;
			*s2=j;
		}
	} 
}

//ht:哈弗曼树,hc:哈夫曼编码,n:结点个数 
void CreateHuffmanCode(HuffmanTree ht,HuffmanCode hc,int n)
{
	char *cd;
	int start,c,p,i;
	cd=(char*)malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(i=0;i<n;i++)
	{
		start=n-1;
		c=i;
		p=ht[i].parent;
		while(p!=-1)
		{
			--start;
			if(ht[p].lchild==c)
			{
				cd[start]='0';
			}
			else
			{
				cd[start]='1';
			}
			c=p;
			p=ht[p].parent;
		}
		hc[i]=(char*)malloc((n-start)*sizeof(char));
		strcpy(hc[i],&cd[start]);
	}
	free(cd);
}

//依次输出各个字符及其对应编码，格式为【字符:编码】（冒号均为英文符号）
void printcode(char s[],HuffmanCode hc)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("%c:",s[i]);
		printf("%s\n",hc[i]);
	}
}

//输出编码串 
void chartocode(charcode c,char s[],HuffmanCode hc)
{
	int j;
	char *p=c;
	while(*p!='\0')
	{
		for(j=0;j<N;j++)
		{
			if(*p==s[j])
			  printf("%s",hc[j]);
		}
		p++;
	}
	printf("\n"); 
}

//输出译码串 
void numtochar(numcode ns,HuffmanTree ht,char s[])
{
	char *p=ns;
	int key;
	HTNode g;
	while(*p!='\0')
	{
		g=ht[M-1];
		while(g.lchild!=-1 && g.rchild!=-1 && (*p!='\0'))
		{
			switch(*p)
			{
				case '0':
					key=g.lchild;
					g=ht[g.lchild];
					break;
				case '1':
					key=g.rchild;
					g=ht[g.rchild];
					break;
			}
			p++;
		}
		printf("%c",s[key]);
	}
}


