#include <stdlib.h>

#define MaxVertexNum 100

//邻接矩阵法(顺序存储)
typedef struct
{
    char Vex[MaxVertexNum]; //顶点表
    int Edge[MaxVertexNum][MaxVertexNum]; //邻接矩阵，边表
    int vexnum, arcnum; //图的当前顶点树和边数
}MGraph;

//邻接表法(顺序+链式存储)
typedef struct ArcNode
{
    int adjvex; //边指向哪个结点
    struct ArcNode *next; //指向下一条边的指针
    //InfoType info; //边权值
}ArcNode;

typedef struct VNode
{
    char data; //顶点信息
    ArcNode *first; //第一条边
}VNode, AdjList[MaxVertexNum];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;

//十字链表(有向图)
typedef struct ArcBox
{
    int tailvex, headvex; //该弧的尾和头顶点的位置
    struct ArcBox *hlink, *tlink; //分别为弧头、弧尾相同的下一条弧
    //InfoType *info; //该弧相关信息的指针
}ArcBox;

typedef struct VexNode
{
    char data;
    ArcBox *firstin, *firstout; //分别指向该顶点第一条入弧和出弧
}VecNode;

typedef struct
{
    VexNode xlist[MaxVertexNum]; //表头向量
    int vexnum, arcnum; //有向图的当前顶点数和弧数
}OLGraph;

//邻接多重表(无向图)
typedef enum{unvisited, visited} VisitIf;
typedef struct EBox
{
    VisitIf mark; //访问标记
    int ivex, jvex; //该边依附的两个顶点的位置
    struct EBox *ilink, *jlink; //分别指向该边依附这两个顶点的下一条边
    //InfoType *info; //该边信息指针
}Ebox;

typedef struct VexBox
{
    char data;
    EBox *firstedge; //指向第一条依附该顶点的边
}VexBox;

typedef struct 
{
    VexBox adjmulist[MaxVertexNum];
    int vexnum, edgenum; //无向图的当前顶点数和边数
}AMLGraph;
