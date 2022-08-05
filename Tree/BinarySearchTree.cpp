#include <stdlib.h>

typedef struct BSTNode
{
    int key;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

//在二叉排序树中查找值为key的结点
BSTNode *BST_Search(BSTree T, int key)
{
    while (T != NULL && key != T->key)
    {
        if (key < T->key) T = T->lchild;
        else T = T->rchild;
    }
    return T;
}

//插入新结点（递归实现）
int BST_Insert(BSTree &T, int k)
{
    if (T == NULL)
    {
        T = (BSTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1;
    }
    else if (k == T->key) return 0;
    else if (k < T->key) return BST_Insert(T->lchild, k);
    else return BST_Insert(T->rchild, k);
}

void Create_BST(BSTree &T, int str[], int n)
{
    T = NULL;
    int i = 0;
    while (i < n)
    {
        BST_Insert(T, str[i]);
        i++;
    }
}

int main()
{

}