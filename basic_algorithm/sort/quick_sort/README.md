## 快速排序——分治

① 确定分界点 q[l] q[(l+r)/2] q[r]

**② 调整区间 第一个区间中的数均小于等于x，第二个区间大于等于x**

③ 递归处理左右两段 分别排序

### 简单暴力实现步骤②

① 新开两个数组a[] b[]

② 扫描整个区间q[l~r] 当前目标小于x的话就插入a，反之则插入b

③ 先将a放入q，再将b放入q

### 优雅实现步骤②

左右两个指针，往中间走，碰到小于等于x（大于等于x）则停下来。都停下来则交换双方指针并往中间移动一位

直到双方相遇为止

```c++
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}
```