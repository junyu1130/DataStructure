```c++
bool visited[MaxVertexNum]; //标记访问数组

void BFS(Graph G, int v)
{
    visit(v);
    visited[v] = True;
    EnQueue(Q, v);
  	while (!isEmpty(Q))
    {
      	DeQueue(Q, v);
      	for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
        {
          	if (!visited[w])
            {
              	visit(w);
              	visited[w] = TRUE;
              	EnQueue(Q, w);
            }
        }
    }
}

void BFSTraverse(Graph G)
{
  	for (i = 0; i < G.vexnum; ++i)
    {
      	visited[i] = FALSE;
    }
  	InitQueue(Q);
  	for (i = 0; i < G.vexnum; ++i) //从0号顶点开始遍历
    {
      	if (!visited[i]) BFS(G, i); //对每个连通分量调用一次BFS
    }
}
```

