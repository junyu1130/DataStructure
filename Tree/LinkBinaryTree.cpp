#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
}ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild; //左右孩子指针
}BiTNode, *BiTree;

int main()
{
    BiTree root = NULL;
    //插入根结点
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = {1};
    root->lchild = NULL;
    root->rchild = NULL;
    //插入新结点
    BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
    p->data = {2};
    p->lchild = NULL;
    p->rchild = NULL;
    root->lchild = p; //作为根结点的左孩子
}