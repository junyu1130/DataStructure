#include <stdio.h>

#define MaxSize 10

typedef struct
{
    int data[MaxSize];//用静态的数组存放数据元素
    int length;//顺序表的当前长度
}SqList;

void InitList(SqList &L)
{
    L.length = 0;
}

bool ListInsert(SqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)//判断i的范围是否有效
    {
        return false;
    }
    if (L.length >= MaxSize)//当前存储空间已满
    {
        return false;
    }
    for (int j = L.length; j >= i; j--)//将第i个及之后的元素后移
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, int &e)
{
    if (i < 1 || i > L.length)//判断i的范围是否有效
    {
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

bool GetElem(SqList L, int i, int &e)
{
    if(i < 1 || i > L.length)//判断i的范围是否有效
    {
        return false;
    }
    e = L.data[i - 1];
    return true;
}

//在顺序表中查找第一个元素值为e的元素，返回其位序
int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e) 
        {
            return i + 1;
        }
    }
    return 0;
}

int main()
{
    SqList L;
    InitList(L);
    if (ListInsert(L, 3, 3))
    {
        printf("插入成功\n");
    }
    else
    {
        printf("插入失败\n");
    }
    int e = -1;//用变量e把删除的元素"带回来"
    if (ListDelete(L, 3, e))
    {
        printf("删除成功，删除值为%d\n", e);
    }
    else
    {
        printf("删除失败\n");
    }
}
