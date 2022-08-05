#include <stdio.h>
#include <stdlib.h>

typedef struct ThreadNode
{
    char data;
    struct ThreadNode *lchild, *rchild; //左右孩子指针
    int ltag, rtag; //左右线索标志，1时为线索
}ThreadNode, *ThreadTree;

ThreadNode *pre = NULL; //指向访问结点的前驱

void visit(ThreadNode *T)
{
    printf("%c\n", T->data);
}

void CreateThread(ThreadNode *q)
{
    if (q->lchild == NULL) //左子树为空，建立前驱线索
    {
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) //建立前驱结点的后继线索
    {
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

/*******************先序*******************/
//先序遍历，线索化
void PreThread(ThreadTree T)
{
    if (T != NULL)
    {
        CreateThread(T); //访问根结点
        if (T->ltag == 0) PreThread(T->lchild); //不是前驱线索时才会递归遍历左子树
        PreThread(T->rchild); //递归遍历右子树
    }
}

//先序线索化二叉树
void CreatePreThread(ThreadTree T)
{
    pre = NULL;
    if (T != NULL)
    {
        PreThread(T); //先序线索化二叉树
        if (pre->rchild == NULL) //处理遍历的最后一个结点
        {
            pre->rtag = 1;
        }
    }
}

/*******************中序*******************/
//中序遍历，线索化
void InThread(ThreadTree T) 
{
    if (T != NULL) 
    {
        InThread(T->lchild);
        CreateThread(T);
        InThread(T->rchild);
    }
}

//中序线索化二叉树
void CreateInThread(ThreadTree T)
{
    pre = NULL;
    if (T != NULL)
    {
        InThread(T); //中序线索化二叉树
        if (pre->rchild == NULL) //处理遍历的最后一个结点
        {
            pre->rtag = 1;
        }
    }
}

//找到第一个被中序遍历的结点
ThreadNode *Firstnode(ThreadNode *p)
{
    while (p->ltag == 0) p = p->lchild;
    return p;
}

//找到最后一个被中序遍历的结点
ThreadNode *Lastnode(ThreadNode *p)
{
    while (p->rtag == 0) p = p->rchild;
    return p;
}

//中序线索二叉树中找后继结点
ThreadNode *Nextnode(ThreadNode *p)
{
    if (p->rtag == 0) return Firstnode(p->rchild);
    else return p->rchild;
}

//中序线索二叉树中找前驱结点
ThreadNode *Prenode(ThreadNode *p)
{
    if (p->ltag == 0) return Lastnode(p->lchild);
    else return p->lchild;
}

//利用线索实现中序遍历(非递归算法)
void InOrder(ThreadNode *T)
{
    for (ThreadNode *p = Firstnode(T); p != NULL; p = Nextnode(p))
    {
        visit(p);
    }
}

//利用线索实现逆向中序遍历
void RevInOrder(ThreadNode *T)
{
    for (ThreadNode *p = Lastnode(T); p != NULL; p = Prenode(p))
    {
        visit(p);
    }
}

/*******************后序*******************/
//后序遍历，线索化
void PostThread(ThreadTree T) 
{
    if (T != NULL) 
    {
        PostThread(T->lchild);
        PostThread(T->rchild);
        CreateThread(T);
    }
}

//后序线索化二叉树
void CreatePostThread(ThreadTree T)
{
    pre = NULL;
    if (T != NULL)
    {
        PostThread(T); //后序线索化二叉树
        if (pre->rchild == NULL) //处理遍历的最后一个结点
        {
            pre->rtag = 1;
        }
    }
}



int main()
{
    ThreadTree root = NULL;
    //插入根结点
    root = (ThreadTree)malloc(sizeof(ThreadNode));
    root->data = 1;
    root->lchild = NULL;
    root->rchild = NULL;
    root->ltag = 0;
    root->rtag = 0;
    //插入新结点
    ThreadNode *p = (ThreadNode *)malloc(sizeof(ThreadNode));
    p->data = 2;
    p->lchild = NULL;
    p->rchild = NULL;
    p->ltag = 0;
    p->rtag = 0;
    root->lchild = p; //作为根结点的左孩子
}

