/*2010��������������:�轫n(n>1)��������ŵ�һά����R�С������һ����ʱ��Ϳռ������涼������
��Ч���㷨����R�б��������ѭ������p(0<p<n)��λ��,����R�е�������(X0,X1,...,Xn-1)�任Ϊ
(Xp,Xp+1,...,Xn-1,X0,X1,...,Xp-1)��Ҫ��:
(1)�����㷨�Ļ������˼��
   ���Խ�������⿴���ǰ�����abװ��������ba(a���������ǰp��Ԫ��,b�������������µ�n-p��
 Ԫ��),�Ƚ�a���õõ�a^-1b,�ٽ�b���õõ�a^-1b^-1,�������a^-1b^-1���õõ�(a^-1b^-1)^-1=ba
 ��Reverse����ִ�н�����Ԫ�����õĲ���,��abcdefgh����ѭ���ƶ�3(p=3)��λ�õĹ�������:
   Reverse(0,p-1)�õ�cbadefgh;
   Reverse(p,n-1)�õ�cbahgfed;
   Reverse(0,n-1)�õ�defghabc; 
(2)�������˼��,����C++��C��Java���������㷨,�ؼ�֮������ע��
(3)˵����������㷨��ʱ�临�ӶȺͿռ临�Ӷ�
  �����㷨������Reverse������ʱ�临�Ӷȷֱ�ΪO(p/2),O((n-p)/2)��O(n/2),�������
  ���㷨��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1) 
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
 
