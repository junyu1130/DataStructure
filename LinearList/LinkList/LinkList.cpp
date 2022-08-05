#include <stdio.h>
#include <stdlib.h>

typedef struct LNode    //单链表结点类型
{
    int data;           //每个结点存放一个数据元素
    struct LNode *next; //指向下一个结点
}LNode, *LinkList;

//初始化一个带头结点的单链表
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));//分配一个头结点
    if (L == NULL)//内存不足，分配失败
    {
        return false;
    }
    L->next = NULL;//头结点之后暂时还没有结点
    return true;
}

//按位查找，返回第i个元素
LNode *GetElem(LinkList L, int i)
{
    if (i < 0) 
    {
        return NULL;
    }
    LNode *p;//当前扫描到的结点
    int j = 0;//当前p指向的是第几个结点
    p = L;//L指向头结点（第0个结点）
    while (p != NULL && j < i)//找到第i个结点
    {
        p = p->next;
        j++;
    }
    return p;
}

//后插，在p结点后插入元素e
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//在第i个位置插入元素e
bool ListInsert(LinkList &L, int i, int e)
{
    LNode *p = GetElem(L, i-1);//找到第i-1个结点
    return InsertNextNode(p, e);
}

//前插，在p结点前插入元素e
bool InsertPriorNode(LNode *p, int e)
{
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        return false;
    }
    s->next = p->next;
    p->next = s;
    s->data = p->data;//交换数据元素
    p->data = e;
    return true;
}

//按位序删除
bool ListDelete(LinkList &L, int i, int &e)
{
    LNode *p = GetElem(L, i-1);//找到第i-1个结点
    if (p == NULL)
    {
        return false;
    }
    if (p->next == NULL)//第i-1个结点之后已无其他结点
    {
        return false;
    }
    LNode *q = p->next;
    e = q->data;//返回删除元素的值
    p->next = q->next;
    free(q);
    return true;
}

//删除指定结点(对于最后一个结点不适用，应从表头开始找到前驱结点修改指针域)
bool DeleteNode(LNode *p)
{
    if (p == NULL)
    {
        return false;
    }
    LNode *q = p->next;
    p->data = q->data;//交换数据元素
    p->next = q->next;
    free(q);
    return true;
}

//按值查找
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;//找到后返回该结点指针，否则返回NULL    
}

//求表长
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

//尾插法建立单链表
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));//建立头结点
    LNode *s, *r = L;//r为表尾指针
    scanf("%d", &x);
    while (x != 9999)//输入9999结束输入
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;//尾结点指针置空
    return L;
}

//头插法建立单链表
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;//初始为空链表
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

int main()
{
    LinkList L; //声明一个指向单链表的指针
    InitList(L);
    
}