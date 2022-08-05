#include <stdlib.h>

//直接插入排序
void InsertSort1(int A[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++) //将各元素插入已排好序的序列中
    {
        if (A[i] < A[i - 1])
        {
            temp = A[i];
            for (j = i - 1; j >= 0 && A[j] > temp; --j)
            {
                A[j + 1] = A[j]; //所有大于temp的元素向后移
            }
            A[j + 1] = temp;
        }
    }
}

//直接插入排序(带哨兵)
void InsertSort2(int A[], int n)
{
    int i, j;
    for (i = 2; i <= n; i++)
    {
        if (A[i] < A[i - 1])
        {
            A[0] = A[i]; //哨兵
            for (j = i - 1; A[j] > A[0]; --j)
            {
                A[j + 1] = A[j]; //所有大于temp的元素向后移
            }
            A[j + 1] = A[0];
        }
    }
}

//折半插入排序
void InsertSort3(int A[], int n)
{
    int i, j, low, high, mid;
    for (i = 2; i <= n; i++)
    {
        A[0] = A[i];
        low = 1; high = i - 1;
        while (low <= high) //折半查找
        {
            mid = (low + high) / 2;
            if (A[mid] > A[0]) high = mid - 1;
            else low = mid + 1;
        }
        for (j = i - 1; j >= high + 1; --j)
        {
            A[j + 1] = A[j]; //后移
        }
        A[high + 1] = A[0]; //插入
    }
}

//希尔排序
void ShellSort(int A[], int n)
{
    int d, i, j;
    for (d = n / 2; d >= 1; d = d / 2) //步长变化
    {
        for (i = d + 1; i <= n; ++i)
        {
            if (A[i] < A[i - d]) //需将A[i]插入到有序增量子表
            {
                A[0] = A[i];
                for (j = i - d; j > 0 && A[0] < A[j]; j -= d)
                {
                    A[j + d] = A[j]; //记录后移，查找插入的位置
                }
                A[j + d] = A[0]; //插入
            }
        }
    }
}

//交换
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//冒泡排序
void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false; //表示本趟冒泡是否发生交换
        for (int j = n - 1; j > i; j--) //一趟冒泡过程
        {
            if (A[j - 1] > A[j])
            {
                swap(A[j - 1], A[j]);
                flag = true;
            }
        }
        if (flag = false) return; //本趟遍历没有发生交换，说明已经有序
    }
}

//用第一个元素将待排序序列划分成左右两个部分
int Partition(int A[], int low, int high)
{
    int pivot = A[low]; //第一个元素作为枢轴
    while (low < high) //用low、high搜索枢轴的最终位置
    {
        while (low < high && A[high] >= pivot) --high;
        A[low] = A[high]; //比枢轴小的元素移动到左端
        while (low < high && A[low] <= pivot) ++low;
        A[high] = A[low]; //比枢轴大的元素移动到右端
    }
    A[low] = pivot; //枢轴元素存放到最终位置
    return low; //返回存放枢轴的最终位置
}

//快速排序
void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = Partition(A, low, high); //划分
        QuickSort(A, low, pivotpos - 1); //划分左子表
        QuickSort(A, pivotpos + 1, high); //划分右子表
    }
}

//简单选择排序
void SelectSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++) //一共进行n-1趟
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min]) min = j;
        }
        if (min != i) swap(A[i], A[min]);
    }
}

//将以k为根的子树调整为大根堆
void HeadAdjust(int A[], int k, int len)
{
    A[0] = A[k]; //A[0]暂存子树的根结点
    for (int i = 2 * k; i <= len; i *= 2) //沿key较大的子结点向下筛选
    {
        if (i < len && A[i] < A[i + 1]) i++; //取key较大的子结点的下标
        if (A[0] >= A[i]) //筛选结束
        {
            break;
        }
        else 
        {
            A[k] = A[i]; //将A[i]调整到双亲结点上
            k = i; //修改k值，以便继续向下筛选
        }
    }
    A[k] = A[0]; //将筛选结点的值放入最终位置
}

//建立大根堆
void BuildMaxHeap(int A[], int len)
{
    for (int i = len / 2; i > 0; i--) //从后往前调整所有非终端结点
    {
        HeadAdjust(A, i, len);
    }
}

//堆排序
void HeapSort(int A[], int len)
{
    BuildMaxHeap(A, len);
    for (int i = len; i > 1; i--) //n-1趟交换和建堆过程
    {
        swap(A[i], A[1]); //堆顶元素和堆底元素交换
        HeadAdjust(A, 1, i - 1); //把剩余的待排序元素整理成堆
    }
}
