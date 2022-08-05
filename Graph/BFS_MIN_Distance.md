```c++
bool visited[MaxVertexNum]; //标记访问数组

//求顶点u到其他顶点的最短路径
void BFS_MIN_Distance(Graph G, int u)
{
    for (i = 0; i < G.vexnum; ++i)
    {
        d[i] = ∞; //初始化路径长度
        path[i] = -1; //最短路径从哪个顶点过来
    }
    d[u] = 0;
    visited[u] = TRUE;
    EnQueue(Q, u);
  	while (!isEmpty(Q))
    {
      	DeQueue(Q, u);
      	for (w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w))
        {
          	if (!visited[w])
            {
                d[w] = d[u] + 1; //路径长度加1
              	path[w] = u; //最短路径从u到w
              	visited[w] = TRUE;
              	EnQueue(Q, w);
            }
        }
    }
}
```

