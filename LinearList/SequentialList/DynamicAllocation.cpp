#include <stdio.h>
#include <stdlib.h>

#define InitSize 10

typedef struct
{
    int *data;//指示动态分配数组的指针
    int MaxSize;//顺序表的最大容量
    int length;//顺序表的当前长度
}SqList;

void InitList(SqList &L)
{
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

//增加动态数组的长度
void IncreaseSize(SqList &L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];//将数据复制到新区域
    }
    L.MaxSize = L.MaxSize + len;
    free(p);//释放原来存数据的内存空间    
}

int main()
{
    SqList L;
    InitList(L);
    
    IncreaseSize(L, 5);   
}