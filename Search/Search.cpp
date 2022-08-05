#include <stdlib.h>

typedef struct 
{
    int *elem; //动态数组基址
    int TableLen; //表长
}SSTable;

//顺序查找
int Search_Seq(SSTable ST, int key)
{
    ST.elem[0] = key; //哨兵
    int i;
    for (i = ST.TableLen; ST.elem[i] != key; --i); //从后往前找
    return i;
}

//折半查找
int Binary_Search(SSTable L, int key)
{
    int low = 0, high = L.TableLen - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (L.elem[mid] == key) return mid;
        else if (L.elem[mid] > key) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

//分块查找
typedef struct //索引表
{
    int maxValue;
    int low, high;
}Index;

int List[100]; //顺序表存储的实际元素
