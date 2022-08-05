#include <stdio.h>
#include <stdlib.h>

typedef struct DNode//双链表结点类型
{
    int data;
    struct DNode *prior, *next;//前驱和后继指针
}DNode, *DLinkList;

bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));//分配一个头结点
    if (L == NULL)//内存不足，分配失败
    {
        return false;
    }
    L->prior = NULL;//头结点的prior永远指向NULL
    L->next = NULL;//头结点之后暂时还没有结点
    return true;
}

//在p结点后插入s结点
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
    {
        return false;
    }
    s->next = p->next;
    if (p->next != NULL)//p结点不是最后一个结点
    {
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
}

//删除p结点的后继结点
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL) 
    {
        return false;
    }
    DNode *q = p->next;//q是p的后继结点
    if (q == NULL) //p结点没有后继结点
    {
        return false;
    }
    p->next = q->next;
    if (q->next != NULL) //q结点不是最后一个结点
    {
        q->next->prior = p;
    }
    free(q);
    return true;
}

int main()
{
    DLinkList L;
    InitDLinkList(L);
    
}