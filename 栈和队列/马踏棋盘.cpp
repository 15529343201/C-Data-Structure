//马踏棋盘  
#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 100
#define STACKINCREMENT 10
#define N 8

int weight[N][N];
int Board[N][N][8];

typedef struct
{	int x;
	int y;
}PosType;

typedef struct
{	int ord;
	PosType seat;
	int di;
}ElemType;

typedef struct
{	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

SqStack s;

int InitStack()
{	s.base=(ElemType *)malloc(STACK_SIZE * sizeof(ElemType));
	if(!s.base) return 0;
	s.top=s.base;
	s.stacksize=STACK_SIZE;
	return 1;
}

ElemType GetTop()
{	if(s.top==s.base) exit(0);
	return *(s.top-1);
}

void Push(ElemType elem)
{	*s.top++=elem;
}

int Pop(ElemType *elem)
{	if(s.top==s.base) return 0;
	*elem=*--s.top;
	return 1;
}

int StackEmpty()
{	if(s.top==s.base) return 1;
	else return 0;
}

void OutputPath()
{	int i,f,k;
	SqStack s1=s;
	int path[N][N];
	for(i=0;s1.top!=s1.base;i++)
	{	path[(*s1.base).seat.x][(*s1.base).seat.y]=i+1;
		++s1.base;
	}
	for(f=0;f<N;f++)
	{	printf("\n");
		for(k=0;k<N;k++) printf("\t%d",(path[f][k]));
	}
	printf("\n");
}

int Pass(PosType curpos)
{	SqStack s1=s;
	if(curpos.x<0||curpos.x>(N-1)||curpos.y<0||curpos.y>(N-1)) return 0;
	for(;s1.top!=s1.base;)
	{	--s1.top;
		if(curpos.x==(*s1.top).seat.x&&curpos.y==(*s1.top).seat.y)
			return 0;
	}
	return 1;
}

PosType NextPos(PosType curpos,int direction)
{	switch(direction)
	{	case 1:curpos.x+=1;curpos.y-=2;break;
		case 2:curpos.x+=2;curpos.y-=1;break;
        case 3:curpos.x+=2;curpos.y+=1;break;
        case 4:curpos.x+=1;curpos.y+=2;break;
        case 5:curpos.x-=1;curpos.y+=2;break;
        case 6:curpos.x-=2;curpos.y+=1;break;
        case 7:curpos.x-=2;curpos.y-=1;break;
        case 8:curpos.x-=1;curpos.y-=2;break;
	}
	return curpos;
}

void setweight()
{	int i,j,k;
	PosType m;
	ElemType elem;
	for(i=0;i<N;i++)
	{	for(j=0;j<N;j++)
		{	elem.seat.x=i;
			elem.seat.y=j;
			weight[i][j]=0;
			for(k=0;k<8;k++)
			{	m=NextPos(elem.seat,k+1);
				if(m.x>=0&&m.x<N&&m.y>=0&&m.y<N)
					weight[i][j]++;
			}
		}
	}
}

void setmap()
{	int a[8];
	int i,j,k,m,min,s,h;
	PosType n1,n2;
	for(i=0;i<N;i++)
	{	for(j=0;j<N;j++)
		{	for(h=0;h<8;h++)
			{	n2.x=i;
				n2.y=j;
				n1=NextPos(n2,h+1);
				if(n1.x>=0&&n1.x<N&&n1.y>=0&&n1.y<N)
					a[h]=weight[n1.x][n1.y];
				else a[h]=0;
			}
			for(m=0;m<8;m++)
			{	min=9;
				for(k=0;k<8;k++)
				if(min>a[k])
				{	min=a[k];
					Board[i][j][m]=k;
					s=k;
				}
				a[s]=9;
			}
		}
	}
}

int HorsePath(PosType start)
{	PosType curpos;
	int horsestep=0,off;
	ElemType elem;
	curpos=start;
	do
	{	if(Pass(curpos))
		{	horsestep++;
			elem.di=0;
			elem.ord=horsestep;
			elem.seat=curpos;
			Push(elem);
			if(N*N==horsestep)
				return 1;
			off=Board[elem.seat.x][elem.seat.y][elem.di]+1;
			curpos=NextPos(elem.seat,off);
		}
		else
		{	if(!StackEmpty())
			{	while(!StackEmpty()&&elem.di==8)
				{	Pop(&elem);
					if(!StackEmpty())
					{
						elem=GetTop();
						horsestep=elem.ord;
					}
				}
				if(!StackEmpty()&&elem.di<8)
				{
					Pop(&elem);
					off=Board[elem.seat.x][elem.seat.y][++elem.di];
					curpos=NextPos(elem.seat,off+1);
					Push(elem);
				}
			}
		}
		
	}while(!StackEmpty());
	printf("走不通");
	return 0; 
}

int main()
{	PosType start;
	InitStack();
	printf("输入起始位置:(0-7)\nX:");
	scanf("%d",&start.x);
	printf("Y:");scanf("%d",&start.y);
	setweight();
	setmap();
	HorsePath(start);
	OutputPath();
}

