学习笔记

### 一、Bloom Filter （布隆过滤器）
- **实现：** 一个很长的二进制向量和一系列随机映射函数。将值通过几个映射函数后，将对应位置的bit置1.
- **用途：** 布隆过滤器可以用于检索一个元素是否在一个集合中。
- **优点：** 空间效率和查询时间优秀。
- **缺点：** 有一定的误判率，删除也非常困难。

### 二、 高级排序
- **快速排序：**
  1.  使用左右指针（i，j），分别寻找大于，小于 pivot 的位置。
  2. 左指针的值小于等于 pivot 时，左指针++（i++），往右移动，直至值大于 pivot。
  3. 右指针的值大于 pivot 值时，右指针-- （j--），往左移动，直至值小于 pivot。
  4. 当出现 a[i] > pivot, a[j] < pivot 是时交换 i，j，此时依然满足 a[i] <= pivot , a[j] > pivot, 2，3 步骤继续。
  5. 当 j <= i 时，整个数组扫描完成，交换 j 值 和 pivot 值。

  6. 一定 return j 指针。此时分区为 [lo，j-1],[j],[j+1,hi]
  7. 再次 partition 区间，[lo，j-1] ,[j+1,hi]

```c++
// 参考算法4中java代码，书里面还有针对快速排序的优化，值得学习。
int partition(vector<int> nums, int lo, int hi)
{
    int i = lo;
    int j = hi + 1;   // 处理技巧，方便下面循环是直接 --
    int v = nums[lo]; // 以 lo 为pivot

    for (;;)
    {
        // 寻找左边大于 nums[pivot] 值
        for (;;)
        {
            i++;
            if (nums[i] > v || i >= hi)
                break;
        }
        // 寻找右边小于 nums[pivot] 值

        for (;;)
        {
            j--;
            if (nums[j] < v || j <= lo)
                break;
        }

        // 整个数组扫描完成，结束
        if (j <= i)
            break;
        // 此时 i 找一个一个比 pivot 大的，j 找一个比 pivot 小的，两者交换
        // 注意：交换后，i 位置的数值比 pivot 小，而 j 位置的 数值又比 pivot 大，进而又可以开始第二轮寻宝。
        swap(nums, i, j);
    }

    swap(nums, lo, j);
    return j;
}

void quick_sort(vector<int> nums, int lo, int hi)
{
    if (hi <= lo)
    {
        return;
    }
    int pivot = partition(nums, lo, hi);
    quick_sort(nums, lo, pivot - 1);
    quick_sort(nums, pivot + 1, hi);
}



```

- **归并排序：**
  1. 分治思想，递归调用注意terminator。
  2. 合并数组三步曲（3个while）要记牢。
  3. 可以先很配一个大数组，避免每次递归分配新数组。
```c++

void merge(vector<int> nums, const int left, const int mid, const int right, int sorted_nums[])
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= left && j <= right)
    {
        if (nums[i] < nums[j])
            sorted_nums[k++] = nums[i++];
        else
            sorted_nums[k++] = nums[j++];
    }

    while (i <= left)
        sorted_nums[k++] = nums[i++];

    while (j <= right)
        sorted_nums[k++] = nums[j++];

    for (k = left; k < = right; k++)
        nums[k] = sorted_nums[k];
}

void merge_sort(vector<int> nums, const int left, const int right, int sorted_nums[])
{
    // 1. terminator
    if (left > right)
        return;

    int mid = left + (right - left) / 2;
    merge_sort(nums, left, mid, sorted_nums);
    merge_sort(nums, mid + 1, right, sorted_nums);

    merge(nums, left, mid, right, sorted_nums);
}


```

- **堆排序：**

```c++
void heap_sort(int a[], int len)
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < len; i++)
    {
        q.push(a[i]);
    }
    for (int i = 0; i < len; i++)
    {
        a[i] = q.pop();
    }
}

```