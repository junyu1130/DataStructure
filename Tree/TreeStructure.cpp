#include <stdlib.h>

typedef struct
{
    int value;
}ElemType;

//孩子兄弟表示法
typedef struct CSNode
{
    ElemType data;
    struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;

//平衡二叉树AVL
typedef struct AVLNode
{
    int key;
    int balance; //平衡因子
    struct AVLNode *lchild, *rchild;    
}AVLNode, *AVLTree;
