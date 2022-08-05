#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct
{
    LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue &Q)
{
    //初始时front、rear都指向头结点
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear) return true;
    else return false;
}

void EnQueue(LinkQueue &Q, int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;//插在表尾
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, int &x)
{
    if (IsEmpty(Q)) return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;//最后一个结点出队
    free(p);
    return true; 
}

int main()
{
    LinkQueue Q;
    InitQueue(Q);
}