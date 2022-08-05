#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct//静态链表结点类型
{
    int data;
    int next; //下一个元素的数组下标
}SLinkList[MaxSize];

int main()
{
    SLinkList L;
}