#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct //循环队列
{
    int data[MaxSize];
    int front, rear;
}SqQueue;

void InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
}

bool QueueEmpty(SqQueue Q)
{
    return Q.front == Q.rear;
}

//为区别队满队空，牺牲了一个元素空间；也可通过增加一个变量（长度、插入/删除操作标志）的定义来区别
bool QueueFull(SqQueue Q)
{
    return (Q.rear + 1) % MaxSize == Q.front;
}

int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}

//入队
bool EnQueue(SqQueue &Q, int x)
{
    if (QueueFull(Q)) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

//出队
bool DeQueue(SqQueue &Q, int &x)
{
    if (QueueEmpty(Q)) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

bool GetHead(SqQueue Q, int &x)
{
    if (QueueEmpty(Q)) return false;
    x = Q.data[Q.front];
    return true;
}

int main()
{
    SqQueue Q;
    InitQueue(Q);
}