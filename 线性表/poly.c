//一元多项式的基本操作
#include<stdio.h>
#include<stdlib.h>

//poly数据类型
typedef struct poly
{
	int coef;//系数
	int expn;//指数
	struct poly *pNext;
}POLY;

//初始化表达式
POLY *InitPoly(void)
{
	POLY *pHead;
	if ((pHead = (POLY *)malloc(sizeof(POLY))) == NULL)
	  exit(-1);
	pHead -> pNext = NULL;

	return pHead;
}

//释放链表
void FreeList(POLY *pHead)
{
	POLY *pTemp1,*pTemp2;
	pTemp1 = pHead -> pNext;
	while(pTemp1 != NULL)
	 {
		pTemp2 = pTemp1 -> pNext;
		free(pTemp1);
		pTemp1 = pTemp2;
	 }

	pHead -> pNext = NULL;
}

//销毁链表
void DesList(POLY *pHead)
{
	FreeList(pHead);
	free(pHead);
}

//输入表达式
void InputPoly(POLY *pHead)
{
	int coef,expn;
	POLY *pTail,*pNew;
	pTail = pHead;

    while(1)
	 {
		printf("请输入(系数,指数),需指数递增输入，系数为0时结束输入:");
		scanf("%d,%d",&coef,&expn);
		if(coef != 0)
		 {
			if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
			  exit(-1);
			pNew->coef = coef;
			pNew->expn = expn;
			pTail->pNext = pNew;
			pTail = pNew;
		 }
		else
		 {
			break;
		 }
	 }

	pTail->pNext = NULL;
}

//输出多项式
void OutputPoly(POLY *pHead)
{
	POLY *pTemp;
	pTemp = pHead->pNext;

	if (pTemp == NULL)
	 {
		printf("\n");
		return;
	 }
	printf("%dx^%d", pTemp->coef,pTemp->expn);
	pTemp = pTemp->pNext;

	while(pTemp != NULL)
	 {
		printf("%+dx^%d", pTemp->coef,pTemp->expn);
		pTemp = pTemp->pNext;
	 }

	printf("\n");
}

//表达式相加
POLY *AddPoly(POLY *pHead1,POLY *pHead2)
{
	int temp;
	POLY *pHead3,*pNew,*pTail;//结果链表相关变量
	POLY *pTemp1,*pTemp2;     //运算链表相关变量

	pTemp1 = pHead1->pNext;
	pTemp2 = pHead2->pNext;
	pHead3 = InitPoly();
	pTail = pHead3;

	//将两个多项式扫描运算后放入结果链表中
    while(pTemp1 != NULL && pTemp2 != NULL)
	 {
		//如果指数相等
		if (pTemp1->expn == pTemp2->expn)
		 {
			if ((temp = pTemp1->coef + pTemp2->coef) == 0)
			 {
				pTemp1= pTemp1->pNext;
                pTemp2= pTemp2->pNext;
				continue;
			 }
			if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
			  exit(-1);
			pNew->coef = temp;
			pNew->expn = pTemp1->expn;
			pTail->pNext = pNew;
			pNew->pNext = NULL;
			pTail = pNew;
			pTemp1 = pTemp1->pNext;
			pTemp2 = pTemp2->pNext;
		 }

		//如果表达式1指数小于2
        else if(pTemp1->expn < pTemp2->expn)
		 {
			if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
			  exit(-1);
			*pNew = *pTemp1;
			pNew->pNext = NULL;
			pTail->pNext = pNew;
			pTail = pNew;
			pTemp1 = pTemp1->pNext;
		 }

		//如果表达式1指数大于2
		else
		 {
			if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
			  exit(-1);
			*pNew = *pTemp2;
			pNew->pNext = NULL;
			pTail->pNext = pNew;
			pTail = pNew;
			pTemp2 = pTemp2->pNext;
		 }
	 }

	//将剩余的未扫描项放入结果链表中
	while(pTemp1 != NULL)
	 {
		if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
		  exit(-1);
		*pNew = *pTemp1;
		pNew->pNext = NULL;
		pTail->pNext = pNew;
		pTail = pNew;
		pTemp1 = pTemp1->pNext;
	 }
	while(pTemp2 != NULL)
	 {
		if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
		  exit(-1);
		*pNew = *pTemp2;
		pNew->pNext = NULL;
		pTail->pNext = pNew;
		pTail = pNew;
		pTemp2 = pTemp2->pNext;
	 }

	return pHead3;
}

//两个多项式相减
POLY *SubPoly(POLY *pHead1,POLY *pHead2)
{
	POLY *pHead3,*pTemp;
	pTemp = pHead2->pNext;

	//被减表达式每一项系数乘以-1
	while(pTemp != NULL)
	 {
		pTemp->coef = -1 * pTemp->coef;
		pTemp = pTemp->pNext;
	 }

	pHead3 = AddPoly(pHead1,pHead2);

	//将被减表达式复原
	pTemp = pHead2->pNext;
	while(pTemp != NULL)
	 {
		pTemp->coef = -1 * pTemp->coef;
		pTemp = pTemp->pNext;
	 }
	return pHead3;
}

//两个多项式相乘
POLY *MultPoly(POLY *pHead1,POLY *pHead2)
{
	POLY *pResult,*pTemp1,*pTemp2,*pMult1,*pMult2,*pNew,*pTail;

	pMult1 = InitPoly();
	pMult2 = InitPoly();
	pTemp1 = pHead1->pNext;

	while(pTemp1 != NULL)
	 {
		FreeList(pMult1);
		pTail = pMult1;
		pTemp2 = pHead2->pNext;
		while(pTemp2 != NULL)
		 {
			if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
			  exit(-1);
			pNew->coef = pTemp1->coef * pTemp2->coef;
			pNew->expn = pTemp1->expn + pTemp2->expn;
			pNew->pNext = NULL;
			pTail->pNext = pNew;
			pTail = pNew;
			pTemp2 = pTemp2->pNext;
		 }
		pResult = AddPoly(pMult1,pMult2);
		FreeList(pMult2);
		pMult2->pNext = pResult->pNext;
		pTemp1 = pTemp1->pNext;
	 }

	DesList(pMult1);
	free(pMult2);

	return pResult;
}

//多项式求导
POLY *DerPoly(POLY *pHead)
{
	POLY *pTemp = pHead->pNext;
	POLY *pNew,*pHead1,*pTail;
	pHead1 = InitPoly();
	pTail = pHead1;
	while(pTemp != NULL)
	 {
		if (pTemp->expn == 0)
		 {
			pTemp = pTemp->pNext;
			continue;
		 }
		if((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
		  exit(-1);
		pNew->coef = pTemp->coef * pTemp->expn;
		pNew->expn = pTemp->expn - 1;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
		pTemp = pTemp->pNext;
	 }

	return pHead1;
}

int main(void)
{
	POLY *pHead1,*pHead2,*result;
	pHead1 = InitPoly();
	InputPoly(pHead1);
    pHead2 = InitPoly();
	InputPoly(pHead2);
	printf("表达式1: ");
	OutputPoly(pHead1);
	printf("表达式2: ");
	OutputPoly(pHead2);
	result = AddPoly(pHead1,pHead2);
	printf("表达式1 + 表达式2 = ");
	OutputPoly(result);
	DesList(result);
	result = SubPoly(pHead1,pHead2);
	printf("表达式1 - 表达式2 = ");
	OutputPoly(result);
	DesList(result);
	result = DerPoly(pHead1);
	printf("表达式1求导 = ");
	OutputPoly(result);
	DesList(result);
	result = MultPoly(pHead1,pHead2);
	printf("表达式1 * 表达式2 = ");
	OutputPoly(result);
	DesList(result);
	DesList(pHead1);
	DesList(pHead2);

	return 0;
}

