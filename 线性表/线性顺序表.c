    //线性顺序表  
    #include <stdio.h>  
    #include <stdlib.h>  
    #define LIST_INIT_SIZE 1000 //线性表存储空间的初始分配量  
    #define LISTINCRESEMENT 100 //线性表存储空间的分配增量  
    #define OK 1  
    #define ERROR 0  
    #define OVERFLOW -2  
    typedef int elemType;//元素类型  
    typedef struct  
    {  
        elemType *List;//线性表首地址  
        int length;//当前的长度  
        int listsize;//当前分配的存储容量，以elemType为单位  
    } SqList;  
      
    void AgainMalloc(SqList *L)//空间不够时重新分配空间的函数  
    {  
        elemType *newbase;//分配一个临时基址  
        newbase=(elemType *)realloc(L->List,(L->listsize+LISTINCRESEMENT)*sizeof(elemType));  
        if(!newbase) exit(OVERFLOW);  
        L->List=newbase;  
        L->listsize+=LISTINCRESEMENT;  
    }  
      
    //初始化一个空的线性表  
    int InitList_Sq(SqList *L)  
    {  
        L->List=(elemType *)malloc(LIST_INIT_SIZE*sizeof(elemType));  
        if(!L->List)exit(OVERFLOW);//overflow  
        L->length=0;//初始表为空表  
        L->listsize=LIST_INIT_SIZE;//初始表的存储容量，为LIST_INIT_SIZE个elemType单位  
        return OK;  
    }  
    //求表中元素的个数  
    int ListLength(SqList *L)  
    {  
        return L->length;  
    }  
      
    //遍历顺序表  
    void TraverseList(SqList *L)  
    {  
        int i;  
        for(i=0; i<L->length; i++)  
        {  
            printf("%d ",L->List[i]);  
        }  
        printf("\n");  
        return;  
    }  
    //向表头插入元素  
    void InsertFirst(SqList *L,elemType e)  
    {  
        int i;  
        if(L->length>=L->listsize)  
            AgainMalloc(L);  
        for(i=L->length-1; i>=0; i--)  
            L->List[i+1]=L->List[i];  
        L->List[0]=e;  
        L->length++;  
        return;  
    }  
      
    //向表尾插入元素  
    void InsertLast(SqList *L,elemType e)  
    {  
      
        if(L->length>=L->listsize)  
            AgainMalloc(L);  
        L->List[L->length]=e;  
        L->length++;  
        return;  
    }  
    //在表中第pos个位置之前插入新元素e  
    int Insert_Sq(SqList *L,elemType e,int pos)  
    {  
        int i;  
        if(pos<1||pos>L->length+1) return ERROR;  
        if(L->length>=L->listsize)//存储空间不够，要分配新的空间  
            AgainMalloc(L);  
        for(i=L->length-1; i>=pos-1; i--)  
            L->List[i+1]=L->List[i];  
        L->List[pos-1]=e;  
        L->length++;  
        return OK;  
    }  
    //查找给出元素的位置，若存在，给出位置(从1开始算)；若不存在，返回-1  
    void Search(SqList *L,elemType e)  
    {  
        int i;  
        for(i=0; i<L->length; i++)  
        {  
            if(L->List[i]==e)  
            {  
                printf("找到，%d在第%d个位置\n",e,i+1);  
                return;  
            }  
        }  
        printf("没找到\n");  
        return;  
    }  
    //删除第pos个元素，并返回其值  
    elemType DeleteElem(SqList *L,int pos)  
    {  
        int i;  
        elemType temp;  
        if(pos<1||pos>L->length)  
        {  
            printf("pos值越界\n");  
            exit(1);  
        }  
        temp=L->List[pos-1];  
        for(i=pos; i<L->length; i++)  
            L->List[i-1]=L->List[i];  
        L->length--;  
        return temp;  
    }  
    //判断线性表是否为空，为空返回1，不为空返回0  
    int isEmpty(SqList *L)  
    {  
        if(L->length==0)  
            return 1;  
        else  
            return 0;  
    }  
      
    //顺序表的逆置  
    void Inverse(SqList *L)  
    {  
        int low=0,high=L->length-1;  
        elemType temp;  
        int i;  
        for(i=0; i<L->length/2; i++)  
        {  
            temp=L->List[low];  
            L->List[low++]=L->List[high];  
            L->List[high--]=temp;  
        }  
    }  
      
    void MergeList(SqList *La,SqList *Lb,SqList *Lc)  
    {  
        //elemType *pa=La->List;elemType *pb=Lb->List;  
        Lc->listsize=Lc->length=La->length+Lb->length;  
        Lc->List=(elemType *)malloc(sizeof(elemType));  
        if(!Lc->List) exit(OVERFLOW);  
        int i=0,j=0,k=0;  
        while(i<La->length&&j<Lb->length)  
        {  
            if(La->List[i]<=Lb->List[j])  
            {  
                Lc->List[k++]=La->List[i++];  
            }  
            else  
            {  
                Lc->List[k++]=Lb->List[j++];  
            }  
        }  
        while(i<La->length)  
        {  
            Lc->List[k++]=La->List[i++];  
        }  
        while(j<Lb->length)  
        {  
            Lc->List[k++]=Lb->List[j++];  
        }  
    }  
    int main()  
    {  
        SqList list1;  
        InitList_Sq(&list1);  
        int length;  
        scanf("%d",&length);  
        int i;  
        elemType temp;  
        for(i=0; i<length; i++)  
        {  
            scanf("%d",&temp);  
            InsertLast(&list1,temp);  
        }  
        printf("创建好的线性表La=");  
        TraverseList(&list1);//创建好的顺序表  
        int pos;  
        scanf("%d%d",&temp,&pos);  
        Insert_Sq(&list1,temp,pos);  
        printf("插入一个元素后的线性表La=");  
        TraverseList(&list1);//插入一个数字后的线性表  
        scanf("%d",&pos);  
        DeleteElem(&list1,pos);  
        printf("删除一个元素后的线性表La=");  
        TraverseList(&list1);  
        scanf("%d",&temp);  
        Search(&list1,temp);//查找元素  
        printf("逆置后的线性表La=");  
        Inverse(&list1);  
        TraverseList(&list1);  
        SqList list2;  
        InitList_Sq(&list2);  
        scanf("%d",&length);  
        for(i=0; i<length; i++)  
        {  
            scanf("%d",&temp);  
            InsertLast(&list2,temp);  
        }  
      
        SqList list3;  
        MergeList(&list1,&list2,&list3);  
        printf("合并La和Lb后的线性表=");  
        TraverseList(&list3);  
        return 0;  
    }  
