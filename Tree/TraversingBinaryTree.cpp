#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild; //左右孩子指针
}BiTNode, *BiTree;

void visit(BiTNode *T)
{
    printf("%c\n", T->data);
}

//先序遍历
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        visit(T); //访问根结点
        PreOrder(T->lchild); //递归遍历左子树
        PreOrder(T->rchild); //递归遍历右子树
    }
}

//中序遍历
void InOrder(BiTree T) 
{
    if (T != NULL) 
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

//后序遍历
void PostOrder(BiTree T) 
{
    if (T != NULL) 
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

int treeDepth(BiTree T)
{
    if (T == NULL) 
    {
        return 0;
    }
    else 
    {
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        //树的深度=Max(左子树深度，右子树深度)+1
        return l > r ? l + 1 : r + 1;
    }
}

//中序遍历找前驱
BiTNode *p; //指向目标结点
BiTNode *pre = NULL; //指向访问结点的前驱
BiTNode *final = NULL; //记录最终结果

void findPre(BiTNode *q) 
{
    if (q == p) final = pre;
    else pre = q;
}

void InOrderFindPre(BiTree T) 
{
    if (T != NULL) 
    {
        InOrder(T->lchild);
        findPre(T);
        InOrder(T->rchild);
    }
}

//链式队列结点
typedef struct LinkNode
{
    BiTNode *data;
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

void EnQueue(LinkQueue &Q, BiTree x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;//插在表尾
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, BiTree &x)
{
    if (IsEmpty(Q)) return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;//最后一个结点出队
    free(p);
    return true; 
}

//层序遍历
void LevelOrder(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q); //初始化辅助队列
    BiTree p;
    EnQueue(Q, T); //根结点入队
    while (!IsEmpty(Q)) //队列不空则继续
    {
        DeQueue(Q, p); //队头结点出队
        visit(p); //访问出队结点
        if (p->lchild != NULL) EnQueue(Q, p->lchild); //左孩子入队
        if (p->rchild != NULL) EnQueue(Q, p->rchild); //右孩子入队
    }
}

int main()
{
    BiTree root = NULL;
    //插入根结点
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = 1;
    root->lchild = NULL;
    root->rchild = NULL;
    //插入新结点
    BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
    p->data = 2;
    p->lchild = NULL;
    p->rchild = NULL;
    root->lchild = p; //作为根结点的左孩子
}