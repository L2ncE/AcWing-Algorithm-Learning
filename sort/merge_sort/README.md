## 归并排序——分治

① 确定分界点 mid = (l+r)/2

② 递归排序左右两边

**③ 归并左右两个有序数组，合二为一**

### 归并实现

两个指针均从头开始比较，直到一个数组到头了就可以将另外一个数组剩下的补到后面