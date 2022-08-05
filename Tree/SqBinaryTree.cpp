#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef struct
{
    int data;
    bool isEmpty;
}SqBiTree[MaxSize];

void InitSqBiTree(SqBiTree &bt)
{
    for (int i = 0; i < MaxSize; i++)
    {
        bt[i].isEmpty = true;
    }
}

int main()
{
    SqBiTree bt;
    InitSqBiTree(bt);
}