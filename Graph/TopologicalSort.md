```c++
#define MaxVertexNum 100

typedef struct ArcNode
{
    int adjvex; //边指向哪个结点
    struct ArcNode *nextarc; //指向下一条边的指针
    //InfoType info; //边权值
}ArcNode;

typedef struct VNode
{
    char data; //顶点信息
    ArcNode *firstarc; //第一条边
}VNode, AdjList[MaxVertexNum];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
}Graph;

bool TopologicalSort(Graph G)
{
    InitStack(S);
    for (int i = 0; i < G.vexnum; i++)
    {
        if (indegree[i] == 0) Push(S, i); //将所有入度为0的顶点进栈
    }
    int count = 0; //记录已经输出的顶点数
    while (!IsEmpty(S))
    {
        Pop(S, i);
        print[count++] = i; //输出顶点i
        for (p = G.vertices[i].firstarc; p; p = p->nextarc)
        {
            //将所有i指向的顶点入度减1，并且将入度减为0的顶点压入栈
            v = p->adjvex;
            if (!(--indegree[v])) Push(S, v); //入度为0则入栈
        }
    }
    if (count < G.vexnum) return false; //拓扑排序失败，有向图中有回路
    else return true; //拓扑排序成功
}
```