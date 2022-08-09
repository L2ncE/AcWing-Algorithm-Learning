//
// Created by 袁鑫浩 on 2022/8/6.
//
#include <iostream>

using namespace std;

const int N = 100010;

int q[N];

void quick_sort(int q[], int l, int r) {
    // 相遇则已排好序
    if (l >= r) return;

    //取边界点，这里取的是中间，指针取两侧
    int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        // 若还未相遇则进行交换
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++) printf("%d ", q[i]);

    return 0;
}