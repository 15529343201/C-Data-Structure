/*2010年计算机联考真题:设将n(n>1)个整数存放到一维数组R中。试设计一个在时间和空间两方面都尽可能
高效的算法。将R中保存的序列循环左移p(0<p<n)个位置,即将R中的数据由(X0,X1,...,Xn-1)变换为
(Xp,Xp+1,...,Xn-1,X0,X1,...,Xp-1)。要求:
(1)给出算法的基本设计思想
   可以将这个问题看作是把数组ab装换成数组ba(a代表数组的前p个元素,b代表数组中余下的n-p个
 元素),先将a逆置得到a^-1b,再将b逆置得到a^-1b^-1,最后将整个a^-1b^-1逆置得到(a^-1b^-1)^-1=ba
 设Reverse函数执行将数组元素逆置的操作,对abcdefgh向左循环移动3(p=3)个位置的过程如下:
   Reverse(0,p-1)得到cbadefgh;
   Reverse(p,n-1)得到cbahgfed;
   Reverse(0,n-1)得到defghabc; 
(2)根据设计思想,采用C++或C或Java语言描述算法,关键之处给出注释
(3)说明你所设计算法的时间复杂度和空间复杂度
  上述算法中三个Reverse函数的时间复杂度分别为O(p/2),O((n-p)/2)和O(n/2),故所设计
  的算法的时间复杂度为O(n),空间复杂度为O(1) 
*/
#include<stdio.h>
void print(int R[],int n){
	for(int i=0;i<n;i++)
		printf("%d ",R[i]);
}

void Reverse(int R[],int from,int to){
	int i,temp;
	for(i=0;i<(to-from+1)/2;i++){
		temp=R[from+i];
		R[from+i]=R[to-i];
		R[to-i]=temp;
	}
}
void Converse(int R[],int n,int p){
	Reverse(R,0,p-1);
	Reverse(R,p,n-1);
	Reverse(R,0,n-1);
	print(R,n);
}

int main(void){
	int R[]={1,2,3,4,5,6,7,8,9,10};
	int n=sizeof(R)/sizeof(R[0]);
	print(R,n);
	printf("\n");
	Converse(R,sizeof(R)/sizeof(R[0]),3);
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 10
4 5 6 7 8 9 10 1 2 3
*/
 
