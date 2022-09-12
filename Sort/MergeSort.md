```c++
int *B = (int *)malloc(n * sizeof(int)); //辅助数组B

//A[low...mid]和A[mid+1...high]各自有序，将两个部分合并
void Merge(int A[], int low, int mid, int high)
{
    int i, j, k;
    for (k = low; k <= high; k++) //将A中所有元素复制到B中
    {
        B[k] = A[k];
    }
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (B[i] <= B[j]) A[k] == B[i++]; //将较小值复制到A中
        else A[k] = B[j++];
    }
    while (i <= mid) A[k++] = B[i++];
    while (j <= high) A[k++] = B[j++];
}

//归并排序
void MergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2; //从中间划分
        MergeSort(A, low, mid); //对左半部分归并排序
        MergeSort(A, mid + 1, high); //对右半部分归并排序
        Merge(A, low, mid, high); //归并
    }
}
```