```c++
//准备工作，根据图的信息初始化矩阵A和path

for (int k = 0; k < n; k++) //考虑以Vk作为中转点
{
    for (int i = 0; i < n; i++) //遍历整个矩阵A
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] > A[i][k] + A[k][j])
            {
                A[i][j] = A[i][k] + A[k][j]; //更新最短路径长度
                path[i][j] = k; //中转点
            }
        }
    }
}
```