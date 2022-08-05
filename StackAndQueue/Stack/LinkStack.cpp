#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
}LinkNode, *LinkStack;

//不带头结点
bool InitStack(LinkStack &S)
{
    S = NULL;//构造一个空栈，栈顶指针置空
    return true;
}

bool Push(LinkStack &S, int e)
{
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    if (p == NULL) return false;
    p->data = e;
    p->next = S;//新结点插入栈顶
    S = p;//修改栈顶指针为p
    return true;
}

bool Pop(LinkStack &S, int &e)
{
    if (S == NULL) return false;
    e = S->data;
    LinkNode *p = S;//临时保存当前栈顶指针以备释放
    S = S->next;//修改栈顶指针
    free(p);
    return true;
}

bool GetTop(LinkStack S, int &x)
{
    if (S == NULL) return false;
    x = S->data;
    return true;
}

int main()
{
    LinkStack S;
    InitStack(S);

}