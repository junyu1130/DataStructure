#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int top;//栈顶指针（数组下标）
}SqStack;

void InitStack(SqStack &S)
{
    S.top = -1;
}

bool StackEmpty(SqStack S)
{
    return S.top == -1;
}

bool StackFull(SqStack S)
{
    return S.top == MaxSize - 1;
}

bool Push(SqStack &S, int x)
{
    if (StackFull(S)) return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, int &x)
{
    if (StackEmpty(S)) return false;
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, int &x)
{
    if (S.top == -1) return false;
    x = S.data[S.top];
    return true;
}

int main()
{
    SqStack S;
    InitStack(S);
}
